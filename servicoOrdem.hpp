#ifndef SERVICOORDEM_HPP_INCLUDED
#define SERVICOORDEM_HPP_INCLUDED

#include "interfaces.hpp"
#include "Dominios.hpp"
#include "Ordem.hpp"
#include <list>
#include "sqlite3.h"

class ServicoOrdem : public ILNOrdem {
private:
    sqlite3 *db;
    void conectar();
    void desconectar();
    void criarTabela();

public:
    ServicoOrdem();
    ~ServicoOrdem();

    bool criar(const CPF &cpf, const Codigo &codigoCarteira, const Ordem &ordem) override;
    Ordem ler(const Codigo &codigo) override;
    bool excluir(const Codigo &codigo) override;
    std::list<Ordem> listarPorCarteira(const CPF &cpf, const Codigo &codigoCarteira) override;
};

#endif // SERVICOORDEM_HPP_INCLUDED
