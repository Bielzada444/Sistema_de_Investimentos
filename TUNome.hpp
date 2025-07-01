//
// Criado por Gabriel em 22/04/2025.
// Matrícula: 241038942

/// @file TUNome.hpp
/// @brief Teste de unidade para a classe Nome (Domínio).
/// @details
/// Testa os cenários:
/// - Nomes com até 20 caracteres (letras, dígitos ou espaços únicos).
/// - Rejeição de strings com espaços consecutivos ou apenas espaços.

#ifndef TUNOME_HPP
#define TUNOME_HPP

#include "Nome.hpp"
#include <string>

/// @class TUNome
/// @brief Classe de teste de unidade para o domínio Nome.
/// @details Verifica se o domínio Nome aceita corretamente valores válidos
/// e rejeita valores inválidos, garantindo que os nomes respeitem o formato.
class TUNome {
private:
    const static std::string NOME_VALIDO;
    const static std::string NOME_INVALIDO;
    Nome* nome;
    int estadoNome;

    void setUpNome();
    void tearDownNome();
    void testarCenarioValidoNome();
    void testarCenarioInvalidoNome();

public:
    /// @brief Código de retorno para teste bem-sucedido
    const static int SUCESSO = 0;

    /// @brief Código de retorno para teste falho
    const static int FALHA = -1;

    /// @brief Executa todos os testes do domínio Nome.
    /// @details Verifica:
    /// - Cenário de sucesso com um nome válido (até 20 caracteres, letras, dígitos ou espaços únicos).
    /// - Cenário de falha com strings que possuem espaços consecutivos ou apenas espaços.
    /// @return SUCESSO se todos os testes passarem, FALHA caso contrário.
    int runNome();
};

#endif // TUNOME_HPP
