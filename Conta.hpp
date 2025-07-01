//
// Criado por Gabriel em 04/05/2025
// Matricula: 241038942

/// @file Conta.hpp
/// @brief Entidade (um conjunto que reune algumas das classes já implementadas) que agrupa as classes "Cpf", "Nome" e "Senha". Representa uma conta, que é um registro que representa um usuário no sistema.
/// @details Agrega os dados essenciais para autenticação:
/// - CPF (identificador único do titular)
/// - Nome do usuário (para exibição e verificação)
/// - Senha (credencial de acesso com requisitos de segurança)

#ifndef CONTA_HPP
#define CONTA_HPP

#include "Dominios.hpp"
/// @class Conta
/// @brief  Esta classe representa o registro do usuário no sistema de investimentos.
/// @details Agrega os dados essenciais para autenticação:
/// - CPF (identificador único do titular)
/// - Nome do usuário (para exibição e verificação)
/// - Senha (credencial de acesso com requisitos de segurança)

class Conta {
    private:
        CPF cpf;
        Nome nome;
        Senha senha;

    public:
        /// @brief Define o CPF do titular
        /// @param novoCpf Objeto do domínio CPF já validado na classe Cpf
        void setCpf(const CPF& novoCpf);

        /// @brief Define o nome do titular
        /// @param novoNome Objeto do domínio Nome já validado na classe Nome
        void setNome(const Nome& novoNome);

        /// @brief Define a senha de acesso
        /// @param novaSenha Objeto do domínio Senha já validado na classe Senha
        void setSenha(const Senha& novaSenha);

        /// @brief Retorna o CPF armazenado
        /// @return Retorna um objeto do tipo Cpf já armazenado em Conta
        CPF getCpf() const {
            return cpf;
        }

        /// @brief Retorna o nome do titular
        /// @return Retorna um objeto do tipo Nome já armazenado em Conta
        Nome getNome() const {
            return nome;
        }

        /// @brief Retorna a senha de acesso
        /// @return Retorna um objeto do tipo Senha já armazenado em Conta
        Senha getSenha() const {
            return senha;
        }
};

#endif //CONTA_HPP
