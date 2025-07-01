//
// Criado por Gabriel em 05/05/2025
// Matricula: 241038942

/// @file TUConta.hpp
/// @brief Teste de unidade para a entidade Conta.
/// @details
/// Testa a validação dos atributos da entidade Conta:
/// - CPF (formato XXXXXXXXXXX)
/// - Nome (até 20 caracteres)
/// - Senha (6 caracteres complexos)
/// Verifica o comportamento dos métodos set() e get().

#ifndef TUCONTA_HPP
#define TUCONTA_HPP

#include "Conta.hpp"
#include "Dominios.hpp"
#include <string>

/// @class TUConta
/// @brief Classe de teste de unidade para a entidade Conta.
/// @details Verifica se a entidade Conta armazena e valida corretamente
/// os atributos CPF, Nome e Senha.
/// Testa a validação dos atributos da entidade Conta:
/// - CPF (formato XXXXXXXXXXX)
/// - Nome (até 20 caracteres)
/// - Senha (6 caracteres complexos)
/// Verifica o comportamento dos métodos set() e get().
class TUConta {
    private:
        const std::string CPF_VALIDO = "18222122002";
        const std::string NOME_VALIDO = "Joao Silva";
        const std::string SENHA_VALIDA = "A1b2C#";

        Conta* conta;
        int estadoConta;

        void setUpConta();
        void tearDownConta();
        void testarCenarioValidoConta();

    public:
        /// @brief Código de retorno para teste bem-sucedido
    const static int SUCESSO = 0;

    /// @brief Código de retorno para teste falho
    const static int FALHA = -1;

    /// @brief Executa todos os testes da entidade Conta.
    /// @details Verifica:
    /// - CPF válido (11 dígitos numéricos).
    /// - Nome válido (até 20 caracteres).
    /// - Senha válida (6 caracteres complexos).
    /// @return SUCESSO se todos os testes passarem, FALHA caso contrário.
        int runConta();
};

#endif // TUCONTA_HPP
