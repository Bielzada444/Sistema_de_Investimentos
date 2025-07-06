#ifndef CTRLCONTA_HPP_INCLUDED
#define CTRLCONTA_HPP_INCLUDED

#include <iostream>
#include "interfaces.hpp"
#include "servicoConta.hpp"
#include "ctrlCarteira.hpp"
#include "ctrlOrdem.hpp"
#include "servicoCarteira.hpp"
#include "servicoOrdem.hpp"
#include "servicoDadosHistoricos.hpp"

class CtrlConta : public IUConta {
private:
    ILNConta *servico = nullptr;
    CtrlCarteira *ctrlCarteira = nullptr;
    CtrlOrdem *ctrlOrdem = nullptr;
    ServicoCarteira *servicoCarteira = nullptr;
    ServicoOrdem *servicoOrdem = nullptr;
    ServicoDadosHistoricos *servicoDados = nullptr;

public:
    void setCntr(ILNConta *cntr);
    void setCtrlCarteira(CtrlCarteira *cntrCarteira);
    void setCtrlOrdem(CtrlOrdem *cntrOrdem);
    void setServicoCarteira(ServicoCarteira *servicoCarteira);
    void setServicoOrdem(ServicoOrdem *servicoOrdem);
    void setServicoDados(ServicoDadosHistoricos *servicoDados);

    void menu(const CPF &cpf);

    void criar() override;
    void editar() override {}     // não usado diretamente
    void excluir() override {}    // não usado diretamente
    void ler() override;

    void editar(const CPF &cpf);
    void excluir(const CPF &cpf);
    void gerenciarOrdens(const CPF &cpf);
};

#endif // CTRLCONTA_HPP_INCLUDED
