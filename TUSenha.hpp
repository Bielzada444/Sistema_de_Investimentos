//
// Criado por Nyvea em 18/04/2025.
// Matricula: 241040207

/// @file TUSenha.hpp
/// @brief Teste de unidade para a classe Senha (Domínio).
/// @details
/// Valida os requisitos de complexidade da senha:\n
/// - 6 caracteres exatos (1 maiúscula, 1 minúscula, 1 dígito, 1 especial)\n
/// - Rejeição de caracteres repetidos ou padrões inválidos\n
/// - Verificação de casos extremos (ex: sequências óbvias)

#ifndef TUSENHA_HPP
#define TUSENHA_HPP
#include "Senha.hpp"
#include <string>

/// @class TUSenha
/// @brief Classe de teste de unidade para o domínio Senha.
/// @details
/// Valida os requisitos de complexidade da senha:\n
/// - 6 caracteres exatos (1 maiúscula, 1 minúscula, 1 dígito, 1 especial)\n
/// - Rejeição de caracteres repetidos ou padrões inválidos\n
/// - Verificação de casos extremos (ex: sequências óbvias)
class TUSenha {
    private:
        const static std::string SENHA_VALIDA;
        const static std::string SENHA_INVALIDA;
        Senha* senha;
        int estadoSenha;

        void setUpSenha();
        void tearDownSenha();
        void testarCenarioValidoSenha();
        void testarCenarioInvalidoSenha();

    public:
        /// @brief Código de retorno para teste bem-sucedido
        const static int SUCESSO = 0;

        /// @brief Código de retorno para teste falho
        const static int FALHA = -1;

        /// @brief Executa todos os testes do domínio Senha
        /// @return SUCESSO se todos os testes passarem, FALHA caso contrário
        int runSenha();
};

#endif
