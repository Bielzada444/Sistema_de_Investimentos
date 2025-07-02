#ifndef SERVICOORDEM_HPP
#define SERVICOORDEM_HPP

#include "interfaces.hpp"
#include "sqlite3.h"
#include <fstream>
#include <string>
#include <stdexcept>

#include "servicoCarteira.hpp"


class ServicoOrdem : public ILNOrdem {
private:
    sqlite3 *db;
    ServicoCarteira* servicoCarteira;

    void conectar();
    void desconectar();
    void criarTabela();
    double obterPrecoMedio(const CodigoNegociacao&, const Data&);

public:

    void setServicoCarteira(ServicoCarteira* servico);

    ServicoOrdem();
    ~ServicoOrdem();

    bool criar(const Ordem& ordem, const Codigo& codigoCarteira) override;
    Ordem ler(const Codigo& codigo) override;
    bool excluir(const Codigo& codigo) override;
    list<Ordem> listarPorCarteira(const Codigo& codigoCarteira) override;
};

#endif // SERVICOORDEM_HPP
