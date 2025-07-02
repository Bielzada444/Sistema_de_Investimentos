#ifndef CTRLORDEM_HPP
#define CTRLORDEM_HPP

#include "interfaces.hpp"

class CtrlOrdem : public IUOrdem {
private:
    ILNOrdem* servicoOrdem;
    ILNCarteira* servicoCarteira;

public:
    void setServicoOrdem(ILNOrdem* servico) { this->servicoOrdem = servico; }
    void setServicoCarteira(ILNCarteira* servico) { this->servicoCarteira = servico; }
    void menu(const CPF &cpf);

    void criar() override;
    void excluir() override;
    void ler() override;
    void listarPorCarteira() override;
};

#endif // CTRLORDEM_HPP
