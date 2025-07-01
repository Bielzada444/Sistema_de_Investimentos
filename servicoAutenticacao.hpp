//
// Created by Henrique on 22/06/2025.
//

#ifndef SERVICOAUTENTICACAO_HPP_INCLUDED
#define SERVICOAUTENTICACAO_HPP_INCLUDED

#include "interfaces.hpp"
#include "sqlite3.h"
#include <string>
#include <iostream>


class ServicoAutenticacao : public ILNAutenticacao {
private:
    sqlite3 *db = nullptr;
    void conectar();
    void desconectar();
    void criarTabelaUsuarios();

public:
    ServicoAutenticacao();
    ~ServicoAutenticacao();
    bool autenticar(const CPF &, const Senha &) override;
    void registrar(const CPF &, const Senha &, const Nome &) override;
};

#endif // SERVICOAUTENTICACAO_HPP_INCLUDED
