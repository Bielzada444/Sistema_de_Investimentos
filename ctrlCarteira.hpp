#ifndef CTRLCARTEIRA_HPP_INCLUDED
#define CTRLCARTEIRA_HPP_INCLUDED

#include "servicoCarteira.hpp"

class CtrlCarteira {
private:
    ServicoCarteira *servico;

public:
    explicit CtrlCarteira(ServicoCarteira *servico);
    void menu(const CPF &cpf);
};

#endif // CTRLCARTEIRA_HPP_INCLUDED
