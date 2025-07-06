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

///
/// @file ctrlConta.hpp
/// @brief Interface da controladora de contas de usuário
/// @details
/// Gerencia todas as operações relacionadas a contas de usuário,
/// incluindo criação, edição, visualização e exclusão. Coordena
/// a integração entre os serviços de conta, carteira e ordens.
///

class CtrlConta : public IUConta {
private:
    ILNConta *servico = nullptr;
    CtrlCarteira *ctrlCarteira = nullptr;
    CtrlOrdem *ctrlOrdem = nullptr;
    ServicoCarteira *servicoCarteira = nullptr;
    ServicoOrdem *servicoOrdem = nullptr;
    ServicoDadosHistoricos *servicoDados = nullptr;

public:
    ///
    /// @brief Configura o serviço principal de conta
    /// @param cntr Ponteiro para o serviço de conta (ILNConta)
    ///
    void setCntr(ILNConta *cntr);

    ///
    /// @brief Configura a controladora de carteira
    /// @param cntrCarteira Ponteiro para a controladora de carteira
    ///
    void setCtrlCarteira(CtrlCarteira *cntrCarteira);

    ///
    /// @brief Configura a controladora de ordens
    /// @param cntrOrdem Ponteiro para a controladora de ordens
    ///
    void setCtrlOrdem(CtrlOrdem *cntrOrdem);

    ///
    /// @brief Configura o serviço de carteira
    /// @param servicoCarteira Ponteiro para o serviço de carteira
    ///
    void setServicoCarteira(ServicoCarteira *servicoCarteira);

    ///
    /// @brief Configura o serviço de ordens
    /// @param servicoOrdem Ponteiro para o serviço de ordens
    ///
    void setServicoOrdem(ServicoOrdem *servicoOrdem);

    ///
    /// @brief Configura o serviço de dados históricos
    /// @param servicoDados Ponteiro para o serviço de dados
    ///
    void setServicoDados(ServicoDadosHistoricos *servicoDados);

    ///
    /// @brief Exibe e gerencia o menu principal da conta
    /// @param cpf CPF do usuário logado
    ///
    void menu(const CPF &cpf);

    ///
    /// @brief Cria uma nova conta de usuário
    /// @override Implementação da interface IUConta
    ///
    void criar() override;

    /// @brief Método não utilizado (implementação vazia)
    void editar() override {}
    
    /// @brief Método não utilizado (implementação vazia)
    void excluir() override {}
    
    ///
    /// @brief Visualiza os dados de uma conta
    /// @override Implementação da interface IUConta
    ///
    void ler() override;

    ///
    /// @brief Edita os dados da conta do usuário
    /// @param cpf CPF do usuário a ser editado
    ///
    void editar(const CPF &cpf);

    ///
    /// @brief Exclui a conta do usuário
    /// @param cpf CPF do usuário a ser excluído
    /// @note Verifica a existência de carteiras antes de excluir
    ///
    void excluir(const CPF &cpf);

    ///
    /// @brief Gerencia as ordens associadas à conta
    /// @param cpf CPF do usuário logado
    ///
    void gerenciarOrdens(const CPF &cpf);
};

#endif // CTRLCONTA_HPP_INCLUDED
