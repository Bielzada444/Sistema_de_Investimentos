//
// Created by Henrique on 29/06/2025.
//

#ifndef SERVICOCARTEIRA_HPP_INCLUDED
#define SERVICOCARTEIRA_HPP_INCLUDED

#include "interfaces.hpp"
#include "DominioException.hpp"
#include "sqlite3.h"

class ServicoCarteira {
private:
    sqlite3 *db;
    void conectar();
    void desconectar();
    void criarTabela();

public:
    ServicoCarteira();
    ~ServicoCarteira();


    bool criarCarteiraPara(const CPF &, const Carteira &);
    std::list<Carteira> listarCarteirasPor(const CPF &);
    Carteira ler(const Codigo &);
    bool editar(const Carteira &);
    bool excluir(const Codigo &);
    double obterSaldoCarteira(const Codigo &codigoCarteira);
};

#endif // SERVICOCARTEIRA_HPP_INCLUDED
