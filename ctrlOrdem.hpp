#ifndef CTRLORDEM_HPP_INCLUDED
#define CTRLORDEM_HPP_INCLUDED

#include "interfaces.hpp"
#include "servicoOrdem.hpp"
#include "servicoCarteira.hpp"
#include "servicoDadosHistoricos.hpp"
#include "Dominios.hpp"

class CtrlOrdem : public IUOrdem {
private:
    ServicoOrdem *servicoOrdem = nullptr;
    ServicoCarteira *servicoCarteira = nullptr;
    ServicoDadosHistoricos *servicoDados = nullptr;
    CPF cpfLogado;

public:
    void setServicoOrdem(ServicoOrdem *servico);
    void setServicoCarteira(ServicoCarteira *servico);
    void setServicoDados(ServicoDadosHistoricos *servico);
    void setCpfLogado(const CPF &cpf);  

    void menu(const CPF &cpf);  

    void criar() override;
    void excluir() override;
    void ler() override;
    void listarPorCarteira() override;
};

#endif // CTRLORDEM_HPP_INCLUDED
