#include "servicoOrdem.hpp"
#include <iostream>
#include <filesystem>
#include <sstream>
#include <iomanip>

void ServicoOrdem::setServicoCarteira(ServicoCarteira* servico) {
    this->servicoCarteira = servico;
}

ServicoOrdem::ServicoOrdem() {
    conectar();
    criarTabela();
    desconectar();
}

ServicoOrdem::~ServicoOrdem() {
    if (db) {
        sqlite3_close(db);
    }
}

void ServicoOrdem::conectar() {
    std::filesystem::create_directory("Data");
    if (sqlite3_open("Data/ordens.db", &db)) {
        throw std::runtime_error("Erro ao abrir banco de dados de investimentos.");
    }
}

void ServicoOrdem::desconectar() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

void ServicoOrdem::criarTabela() {
    conectar();
    const char* sql_ordens =
        "CREATE TABLE IF NOT EXISTS ordens ("
        "codigo TEXT PRIMARY KEY, "
        "codigo_negociacao TEXT NOT NULL, "
        "data TEXT NOT NULL, "
        "preco REAL NOT NULL, "
        "quantidade INTEGER NOT NULL, "
        "codigo_carteira TEXT NOT NULL, "
        "FOREIGN KEY(codigo_carteira) REFERENCES carteiras(codigo));";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql_ordens, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::string error = "Erro ao criar tabela ordens: ";
        error += errMsg;
        sqlite3_free(errMsg);
        throw std::runtime_error(error);
    }
    desconectar();
}

double ServicoOrdem::obterPrecoMedio(const CodigoNegociacao& codigoNegociacao, const Data& data) {
    std::ifstream arquivo("DADOS_HISTORICOS.txt");
    std::string linha;
    std::string codPapel = codigoNegociacao.getCodigoNegociacao();
    std::string dataStr = data.getData();

    if (!arquivo.is_open()) {
        throw std::runtime_error("Arquivo DADOS_HISTORICOS.txt nao encontrado.");
    }

    /*=====VERIFICAR CODIGO=====*/
    /*!!!!!!!!!!!!!!!!!!!!!!!!!!*/

    while (std::getline(arquivo, linha)) {
        // Formato da linha conforme especificado no documento
        std::string dataLinha = linha.substr(2, 8);
        std::string codLinha = linha.substr(12, 12);

        // Remove espaços em branco do código do arquivo para comparação
        codLinha.erase(codLinha.find_last_not_of(" \n\r\t")+1);

        if (codPapel == codLinha && dataStr == dataLinha) {
            arquivo.close();
            return std::stod(linha.substr(113, 13)) / 100.0;
        }
    }
    arquivo.close();
    throw std::runtime_error("Codigo de negociacao ou data nao encontrados nos dados historicos.");
}

bool ServicoOrdem::criar(const Ordem& ordem, const Codigo& codigoCarteira) {



    try {
        if (!servicoCarteira) throw std::runtime_error("Servico de carteira nao configurado.");
        //servicoCarteira->ler(codigoCarteira);

        //Verificar se a carteira existe
        Carteira carteiraVerificada = servicoCarteira->ler(codigoCarteira);
        if (carteiraVerificada.getCodigo().getCodigo().empty()) {
            throw std::runtime_error("Carteira nao encontrada.");
        }

        double preco_unitario = obterPrecoMedio(ordem.getCodigoNegociacao(), ordem.getData());
        double preco_total = preco_unitario * ordem.getQuantidade().getQuantidade();


        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << preco_total;
        std::string precoStr = stream.str();

        // Cria uma cópia da ordem para setar o preço calculado
        Ordem ordemFinal = ordem;
        Dinheiro precoCalculado;
        precoCalculado.setDinheiro(precoStr);
        ordemFinal.setDinheiro(precoCalculado);

        //Inserir a ordem final no banco de dados
        conectar();
        const char* sql = "INSERT INTO ordens (codigo, codigo_negociacao, data, preco, quantidade, codigo_carteira) VALUES (?,?,?,?,?,?);";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Erro ao preparar SQL para criar ordem: " << sqlite3_errmsg(db) << std::endl;
            desconectar();
            return false;
        }

        sqlite3_bind_text(stmt, 1, ordemFinal.getCodigo().getCodigo().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, ordemFinal.getCodigoNegociacao().getCodigoNegociacao().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, ordemFinal.getData().getData().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 4, ordemFinal.getDinheiro().getDinheiro());
        sqlite3_bind_int(stmt, 5, ordemFinal.getQuantidade().getQuantidade());
        sqlite3_bind_text(stmt, 6, codigoCarteira.getCodigo().c_str(), -1, SQLITE_STATIC);

        bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);

        sqlite3_finalize(stmt);
        desconectar();

        if (!sucesso) {
            std::cerr << "Erro ao executar SQL para criar ordem." << std::endl;
        }
        return sucesso;

    } catch (const std::exception& e) {
        std::cerr << "Erro ao criar ordem: " << e.what() << std::endl;
        return false;
    }
    return true;
}

list<Ordem> ServicoOrdem::listarPorCarteira(const Codigo& codigoCarteira) {
    conectar();
    list<Ordem> ordens;
    const char* sql = "SELECT * FROM ordens WHERE codigo_carteira = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        desconectar();
        throw std::runtime_error("Erro ao preparar SQL para listar ordens.");
    }

    sqlite3_bind_text(stmt, 1, codigoCarteira.getCodigo().c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Ordem ordem;
        Codigo cod; cod.setCodigo((const char*)sqlite3_column_text(stmt, 0));
        CodigoNegociacao codNeg; codNeg.setCodigoNegociacao((const char*)sqlite3_column_text(stmt, 1));
        Data data; data.setData((const char*)sqlite3_column_text(stmt, 2));

        double precoDouble = sqlite3_column_double(stmt, 3);
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << precoDouble;
        std::string precoStr = stream.str();

        std::string quantidade = std::to_string(sqlite3_column_int(stmt, 4));

        Dinheiro preco; preco.setDinheiro(precoStr);
        Quantidade qtd; qtd.setQuantidade(quantidade);

        ordem.setCodigo(cod);
        ordem.setCodigoNegociacao(codNeg);
        ordem.setData(data);
        ordem.setDinheiro(preco);
        ordem.setQuantidade(qtd);

        ordens.push_back(ordem);
    }

    sqlite3_finalize(stmt);
    desconectar();
    return ordens;
}

Ordem ServicoOrdem::ler(const Codigo& codigo) {
conectar();
    const char* sql = "SELECT * FROM ordens WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        desconectar();
        throw std::runtime_error("Erro ao preparar SQL para ler ordem.");
    }

    sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        Ordem ordem;
        Codigo cod; cod.setCodigo((const char*)sqlite3_column_text(stmt, 0));
        CodigoNegociacao codNeg; codNeg.setCodigoNegociacao((const char*)sqlite3_column_text(stmt, 1));
        Data data; data.setData((const char*)sqlite3_column_text(stmt, 2));

        std::string quantidade = std::to_string(sqlite3_column_int(stmt, 4));

        double precoDouble = sqlite3_column_double(stmt, 3);
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << precoDouble;
        std::string precoStr = stream.str();

        Dinheiro preco; preco.setDinheiro(precoStr);
        Quantidade qtd; qtd.setQuantidade(quantidade);

        ordem.setCodigo(cod);
        ordem.setCodigoNegociacao(codNeg);
        ordem.setData(data);
        ordem.setDinheiro(preco);
        ordem.setQuantidade(qtd);

        sqlite3_finalize(stmt);
        desconectar();
        return ordem;
    }

    sqlite3_finalize(stmt);
    desconectar();
    throw std::runtime_error("Ordem nao encontrada.");}


bool ServicoOrdem::excluir(const Codigo& codigo) {
conectar();
    const char* sql = "DELETE FROM ordens WHERE codigo = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        desconectar();
        return false;
    }

    sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_STATIC);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);

    sqlite3_finalize(stmt);
    desconectar();
    return sucesso;
    }

