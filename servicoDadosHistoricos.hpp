#ifndef SERVICODADOSHISTORICOS_HPP_INCLUDED
#define SERVICODADOSHISTORICOS_HPP_INCLUDED

#include "Dominios.hpp"
#include <string>
#include <utility>
#include "sqlite3.h"

class ServicoDadosHistoricos {
private:
    sqlite3 *db;

    void conectar();
    void desconectar();
    void criarTabela();
    void criarIndice();

public:
    ServicoDadosHistoricos();
    ~ServicoDadosHistoricos();

    // Importa dados de um arquivo .txt
    bool importarTxt(const std::string &caminho);

    // Verifica se um código de negociação existe
    bool ativoExiste(const std::string &codigoNegociacao);

    // Consulta preco e data pelo código de negociação
    std::pair<Data, Dinheiro> consultar(const CodigoNegociacao &codigo);
};

#endif // SERVICODADOSHISTORICOS_HPP_INCLUDED
