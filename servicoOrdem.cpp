#include "servicoOrdem.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <filesystem>

ServicoOrdem::ServicoOrdem() {
    conectar();
    criarTabela();
    desconectar();
}

ServicoOrdem::~ServicoOrdem() {
    desconectar();
}

void ServicoOrdem::conectar() {
    std::filesystem::create_directory("Data");
    sqlite3_open("Data/ordens.db", &db);
}

void ServicoOrdem::desconectar() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

void ServicoOrdem::criarTabela() {
    const char *sql =
        "CREATE TABLE IF NOT EXISTS ordens ("
        "codigo TEXT PRIMARY KEY,"
        "codigo_negociacao TEXT NOT NULL,"
        "data TEXT NOT NULL,"
        "preco REAL NOT NULL,"
        "quantidade INTEGER NOT NULL,"
        "codigo_carteira TEXT NOT NULL,"
        "cpf_usuario TEXT NOT NULL);";

    char *errMsg = nullptr;
    sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
    if (errMsg) {
        std::cerr << "Erro ao criar tabela ordens: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool ServicoOrdem::criar(const CPF &cpf, const Codigo &codigoCarteira, const Ordem &ordem) {
    conectar();

    const char *sql = "INSERT INTO ordens (codigo, codigo_negociacao, data, preco, quantidade, codigo_carteira, cpf_usuario) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?);";
    sqlite3_stmt *stmt;
    bool sucesso = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, ordem.getCodigo().getCodigo().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, ordem.getCodigoNegociacao().getCodigoNegociacao().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, ordem.getData().getData().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 4, ordem.getDinheiro().getDinheiro());
        sqlite3_bind_int(stmt, 5, ordem.getQuantidade().getQuantidade());
        sqlite3_bind_text(stmt, 6, codigoCarteira.getCodigo().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 7, cpf.getCPF().c_str(), -1, SQLITE_STATIC);

        sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    } else {
        std::cerr << "Erro ao preparar inserção: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
    desconectar();
    return sucesso;
}

Ordem ServicoOrdem::ler(const Codigo &codigo) {
    conectar();

    const char *sql = "SELECT codigo_negociacao, data, preco, quantidade FROM ordens WHERE codigo = ?;";
    sqlite3_stmt *stmt;
    Ordem ordem;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            CodigoNegociacao codNeg;
            Data data;
            Dinheiro preco;
            Quantidade qtd;

            std::ostringstream precoStr;
            precoStr << std::fixed << std::setprecision(2) << sqlite3_column_double(stmt, 2);

            std::string qtdStr = std::to_string(sqlite3_column_int(stmt, 3));

            codNeg.setCodigoNegociacao(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
            data.setData(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
            std::string precoStrVal = precoStr.str();
            preco.setDinheiro(precoStrVal);

            qtd.setQuantidade(qtdStr);

            ordem.setCodigo(codigo);
            ordem.setCodigoNegociacao(codNeg);
            ordem.setData(data);
            ordem.setDinheiro(preco);
            ordem.setQuantidade(qtd);
        }
    }

    sqlite3_finalize(stmt);
    desconectar();
    return ordem;
}

bool ServicoOrdem::excluir(const Codigo &codigo) {
    conectar();

    const char *sql = "DELETE FROM ordens WHERE codigo = ?;";
    sqlite3_stmt *stmt;
    bool sucesso = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_STATIC);
        sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    }

    sqlite3_finalize(stmt);
    desconectar();
    return sucesso;
}

std::list<Ordem> ServicoOrdem::listarPorCarteira(const CPF &cpf, const Codigo &codigoCarteira) {
    conectar();
    std::list<Ordem> lista;
    const char *sql =
        "SELECT codigo, codigo_negociacao, data, preco, quantidade "
        "FROM ordens WHERE cpf_usuario = ? AND codigo_carteira = ?;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, cpf.getCPF().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, codigoCarteira.getCodigo().c_str(), -1, SQLITE_STATIC);

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Codigo codigo;
            codigo.setCodigo(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));

            CodigoNegociacao codNeg;
            codNeg.setCodigoNegociacao(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));

            Data data;
            data.setData(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));

            std::ostringstream precoStr;
            precoStr << std::fixed << std::setprecision(2) << sqlite3_column_double(stmt, 3);

            std::string qtdStr = std::to_string(sqlite3_column_int(stmt, 4));

            Dinheiro preco;
            std::string precoStrVal = precoStr.str();
            preco.setDinheiro(precoStrVal);

            Quantidade qtd;
            qtd.setQuantidade(qtdStr);

            Ordem ordem;
            ordem.setCodigo(codigo);
            ordem.setCodigoNegociacao(codNeg);
            ordem.setData(data);
            ordem.setDinheiro(preco);
            ordem.setQuantidade(qtd);

            lista.push_back(ordem);
        }
    }

    sqlite3_finalize(stmt);
    desconectar();
    return lista;
}
