//
// Criado por Henrique em 08/05/2025
// Matrícula: 241020840

/// @file TUOrdem.hpp
/// @brief Teste de unidade para a entidade Ordem.
/// @details
/// Testa a validação dos atributos da entidade Ordem:
/// - Código (5 dígitos)
/// - Código de Negociação (até 12 caracteres)
/// - Data (formato AAAAMMDD)
/// - Dinheiro (R$ 0.01 a R$ 1,000,000.00)
/// - Quantidade (1 a 1,000,000 unidades)
/// Verifica a integridade dos dados após manipulação.

#ifndef TUORDEM_HPP
#define TUORDEM_HPP

#include "Ordem.hpp"
#include "Dominios.hpp"
#include <string>

/// @class TUOrdem
/// @brief Classe de teste de unidade para a entidade Ordem.
/// @details
/// Testa a validação dos atributos da entidade Ordem:
/// - Código (5 dígitos)
/// - Código de Negociação (até 12 caracteres)
/// - Data (formato AAAAMMDD)
/// - Dinheiro (R$ 0.01 a R$ 1,000,000.00)
/// - Quantidade (1 a 1,000,000 unidades)
/// Verifica a integridade dos dados após manipulação.
class TUOrdem {
private:
    const std::string CODIGO_VALIDO = "12345";
    const std::string CODIGONEGOCIACAO_VALIDO = "TEST4";
    const std::string DATA_VALIDA = "20250508";
    std::string DINHEIRO_VALIDO = "20863.67";
    std::string QUANTIDADE_VALIDA = "150000";

    Ordem* ordem;
    int estadoOrdem;

    void setUpOrdem();
    void tearDownOrdem();
    void testarCenarioValidoOrdem();

public:
    /// @brief Código de retorno para teste bem-sucedido
    const static int SUCESSO = 0;

    /// @brief Código de retorno para teste falho
    const static int FALHA = -1;

    /// @brief Executa todos os testes da entidade Ordem
    /// @return SUCESSO se todos os testes passarem, FALHA caso contrário
    int runOrdem();
};

#endif // TUORDEM_HPP
