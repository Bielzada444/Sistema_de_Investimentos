//
// Criado por Gabriel em 18/04/2025.
// Matrícula: 241038942

/// @file TUCodigo.hpp
/// @brief Teste de unidade para a classe Codigo (Domínio).
/// @details
/// Testa os cenários válidos e inválidos para o domínio Codigo, verificando:
/// - Formato correto (5 dígitos numéricos).
/// - Rejeição de valores fora do padrão.
/// - Consistência dos métodos set/get.

#ifndef TUCODIGO_HPP
#define TUCODIGO_HPP

#include "Codigo.hpp"
#include <string>

/// @class TUCodigo
/// @brief Classe de teste de unidade para o domínio Codigo.
/// @details Verifica se o domínio Codigo aceita corretamente valores válidos e rejeita valores inválidos.
class TUCodigo {
private:
    const static std::string CODIGO_VALIDO;
    const static std::string CODIGO_INVALIDO;
    Codigo* codigo;
    int estadoCodigo;

    void setUpCodigo();
    void tearDownCodigo();
    void testarCenarioValidoCodigo();
    void testarCenarioInvalidoCodigo();

public:
    /// @brief Código de retorno para teste bem-sucedido.
    const static int SUCESSO = 0;

    /// @brief Código de retorno para teste falho.
    const static int FALHA = -1;

    /// @brief Executa todos os testes do domínio Codigo.
    /// @details Verifica se o domínio Codigo aceita corretamente valores válidos e rejeita valores inválidos.
    /// @return SUCESSO se todos os testes passarem, FALHA caso contrário.
    int runCodigo(); ///< Direciona a execução de todos os testes
};

#endif // TUCODIGO_HPP
