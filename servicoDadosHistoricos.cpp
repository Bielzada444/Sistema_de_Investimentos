// servicoDadosHistoricos.cpp

#include "servicoDadosHistoricos.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
//#include <filesystem>
#include <stdexcept>

ServicoDadosHistoricos::ServicoDadosHistoricos() : db(nullptr) {
    conectar();
    criarTabela();
    criarIndice();
}

ServicoDadosHistoricos::~ServicoDadosHistoricos() {
    desconectar();
}

void ServicoDadosHistoricos::conectar() {
    //std::filesystem::create_directory("Data");

    int rc = sqlite3_open("Data/dados_historicos.db", &db);
    if (rc != SQLITE_OK) {
        std::string msg = "Erro ao abrir banco de dados histĂłricos: ";
        msg += sqlite3_errmsg(db);
        throw std::runtime_error(msg);
    }
}

void ServicoDadosHistoricos::desconectar() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

void ServicoDadosHistoricos::criarTabela() {
    const char *sql =
        "CREATE TABLE IF NOT EXISTS historico ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "codigo_negociacao TEXT NOT NULL,"
        "data TEXT NOT NULL,"
        "preco REAL NOT NULL);";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::string erro = "Erro ao criar tabela historico: ";
        erro += errMsg;
        sqlite3_free(errMsg);
        throw std::runtime_error(erro);
    }
}

void ServicoDadosHistoricos::criarIndice() {
    const char *sql =
        "CREATE INDEX IF NOT EXISTS idx_codigo_negociacao ON historico(codigo_negociacao);";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Erro ao criar indice: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool ServicoDadosHistoricos::importarTxt(const std::string &caminho) {
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << caminho << "\n";
        return false;
    }

    sqlite3_exec(db, "BEGIN TRANSACTION;", nullptr, nullptr, nullptr);

    const char *sql =
        "INSERT INTO historico (codigo_negociacao, data, preco) VALUES (?, ?, ?);";

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erro ao preparar statement: " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    std::string linha;
    int contador = 0;
    while (std::getline(arquivo, linha)) {

        try {
            std::string cod = linha.substr(12, 12);
            std::string data = linha.substr(2, 8);
            std::string precoRaw = linha.substr(113, 13);

            // limpa legal
            cod.erase(0, cod.find_first_not_of(" "));
            cod.erase(cod.find_last_not_of(" ") + 1);

            // converter legal o preco
            double preco = std::stod(precoRaw) / 100.0;



            cod.erase(0, cod.find_first_not_of(" "));
            cod.erase(cod.find_last_not_of(" ") + 1);

            sqlite3_bind_text(stmt, 1, cod.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, data.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_double(stmt, 3, preco);

            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Erro ao inserir: " << sqlite3_errmsg(db) << "\n";
            }

            sqlite3_reset(stmt);
            contador++;

        } catch (...) {
            std::cerr << "Erro ao processar linha.\n";
        }
    }

    sqlite3_exec(db, "COMMIT;", nullptr, nullptr, nullptr);
    sqlite3_finalize(stmt);
    arquivo.close();

    std::cout << "Importacao concluida: " << contador << " registros inseridos.\n";
    return contador > 0;
}

bool ServicoDadosHistoricos::ativoExiste(const std::string &codigoNegociacao) {
    const char *sql = "SELECT 1 FROM historico WHERE codigo_negociacao = ? LIMIT 1;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, codigoNegociacao.c_str(), -1, SQLITE_STATIC);
    bool existe = (sqlite3_step(stmt) == SQLITE_ROW);
    sqlite3_finalize(stmt);

    return existe;
}

std::pair<Data, Dinheiro> ServicoDadosHistoricos::consultar(const CodigoNegociacao &codigo) {
    const char *sql =
        "SELECT data, preco FROM historico WHERE codigo_negociacao = ? LIMIT 1;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar SELECT.");
    }

    sqlite3_bind_text(stmt, 1, codigo.getCodigoNegociacao().c_str(), -1, SQLITE_STATIC);

    std::pair<Data, Dinheiro> resultado;

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        Data data;
        data.setData(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));

        Dinheiro preco;

        double precoValor = sqlite3_column_double(stmt, 1);
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << precoValor;
        std::string precoStr = oss.str();
        preco.setDinheiro(precoStr);

        resultado = std::make_pair(data, preco);
    } else {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Ativo nao encontrado.");
    }

    sqlite3_finalize(stmt);
    return resultado;
}
