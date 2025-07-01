//
// Criado por Henrique em 22/04/2025.
// Matrícula: 241020840

/// @file TUDinheiro.hpp
/// @brief Teste de unidade para a classe Dinheiro (Domínio).
/// @details
/// Verifica:
/// - Valores monetários entre R$ 0.01 e R$ 1,000,000.00.
/// - Arredondamento automático para 2 casas decimais.
/// - Rejeição de valores negativos ou acima do limite máximo.

#ifndef TUDINHEIRO_HPP
#define TUDINHEIRO_HPP

#include "Dinheiro.hpp"
#include <string>

/// @class TUDinheiro
/// @brief Classe de teste de unidade para o domínio Dinheiro.
/// @details Verifica se o domínio Dinheiro aceita corretamente valores válidos,
/// realiza arredondamento automático e rejeita valores inválidos.
class TUDinheiro {
private:
    static std::string DINHEIRO_VALIDO;
    static std::string DINHEIRO_INVALIDO;
    Dinheiro* dinheiro;
    int estadoDinheiro;

    void setUpDinheiro();
    void tearDownDinheiro();
    void testarCenarioValidoDinheiro();
    void testarCenarioInvalidoDinheiro();

public:
    /// @brief Código de retorno para teste bem-sucedido
    const static int SUCESSO = 0;

    /// @brief Código de retorno para teste falho
    const static int FALHA = -1;

    /// @brief Executa todos os testes do domínio Dinheiro.
    /// @details Verifica:
    /// - Cenário de sucesso com um valor monetário válido (R$ 0,01 a R$ 1.000.000,00).
    /// - Cenário de falha com valores negativos, zero ou acima do limite.
    /// - Arredondamento correto para 2 casas decimais.
    /// @return SUCESSO se todos os testes passarem, FALHA caso contrário.
    int runDinheiro(); ///< Direciona a execução de todos os testes
};

#endif // TUDINHEIRO_HPP
