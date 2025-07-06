//
// Created by Henrique on 28/06/2025.
//

#ifndef CTRLAUTENTICACAO_HPP_INCLUDED
#define CTRLAUTENTICACAO_HPP_INCLUDED

#include "interfaces.hpp"
#include "servicoAutenticacao.hpp"
#include <iostream>

///
/// @file ctrlAutenticacao.hpp
/// @brief Interface da controladora de autenticação do sistema
/// @details
/// Responsável por coordenar o fluxo de autenticação de usuários,
/// integrando a interface do usuário com os serviços de autenticação
/// e gestão de contas. Implementa operações de login, registro
/// e navegação entre menus.
///

class CtrlAutenticacao : public IUAutenticacao {
private:
    ILNAutenticacao *servico;
    ILNConta *servicoConta;
    IUConta *ctrlConta = nullptr;

public:
    ///
    /// @brief Configura a controladora de conta para redirecionamento pós-autenticação
    /// @param cntrConta Ponteiro para a interface de usuário IUConta
    /// @note Deve ser chamado antes de autenticar() para habilitar navegação para o menu da conta
    ///
    void setCtrlConta(IUConta *cntrConta);

    ///
    /// @brief Define o serviço de autenticação a ser utilizado
    /// @param cntr Ponteiro para a implementação concreta de ILNAutenticacao
    /// @pre O parâmetro cntr deve ser uma instância válida e não nula
    ///
    void setCntr(ILNAutenticacao *cntr) override;

    ///
    /// @brief Executa o processo de autenticação do usuário
    /// @return true se as credenciais forem válidas e a autenticação for bem-sucedida
    /// @return false se as credenciais forem inválidas ou ocorrer um erro
    /// @throw std::invalid_argument Se o CPF ou senha não estiverem no formato correto
    /// @throw std::runtime_error Se ocorrer falha na comunicação com o serviço
    /// @note Solicita entrada do usuário via console para CPF e senha
    ///
    bool autenticar() override;

    ///
    /// @brief Exibe e gerencia o menu principal de autenticação
    /// @details Controla o fluxo de:
    /// - Login de usuários existentes
    /// - Registro de novos usuários
    /// - Saída do sistema
    /// @note Opera em loop até que o usuário selecione a opção de saída
    ///
    void menu();

    ///
    /// @brief Configura o serviço de conta para operações de registro
    /// @param cntrConta Ponteiro para a implementação concreta de ILNConta
    /// @pre O parâmetro cntrConta deve ser uma instância válida e não nula
    ///
    void setCtrlConta(ILNConta *cntrConta);
};

#endif // CTRLAUTENTICACAO_HPP_INCLUDED
