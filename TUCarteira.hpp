//
// Criado por Gabriel em 11/05/2025
// Matricula: 241038942

/// @file TUCarteira.hpp
/// @brief Teste de unidade para a entidade Carteira.
/// @details Esta classe realiza testes automatizados para garantir que a
/// entidade Carteira se comporte corretamente, validando os atributos:
/// - Código (5 dígitos numéricos)
/// - Nome (até 20 caracteres)
/// - Perfil (Conservador, Moderado, Agressivo)

#ifndef TUCARTEIRA_HPP_INCLUDED
#define TUCARTEIRA_HPP_INCLUDED

#include "Carteira.hpp"
#include "Dominios.hpp"
#include <string>

/// @class TUCarteira
/// @brief Classe de teste de unidade para a entidade Carteira.
/// @details Verifica se a entidade Carteira armazena e valida corretamente
/// seus atributos (Código, Nome e Perfil), garantindo consistência.
/// Esta classe realiza testes automatizados para garantir que a
/// entidade Carteira se comporte corretamente, validando os atributos:
/// - Código (5 dígitos numéricos)
/// - Nome (até 20 caracteres)
/// - Perfil (Conservador, Moderado, Agressivo)
class TUCarteira {
private:
    const std::string CODIGO_VALIDO = "12345";
    const std::string NOME_VALIDO = "Joao Silva";
    const std::string PERFIL_VALIDO = "Conservador";

    Carteira* carteira;
    int estadoCarteira;

    void setUpCarteira();
    void tearDownCarteira();
    void testarCenarioValidoCarteira();

public:
    /// @brief Código de retorno para teste bem-sucedido.
    const static int SUCESSO = 0;

    /// @brief Código de retorno para teste falho.
    const static int FALHA = -1;

    /// @brief Executa todos os testes da entidade Carteira.
    /// @details Verifica se a entidade Carteira lida corretamente com os atributos,
    /// garantindo que set() e get() funcionem corretamente e que as validações
    /// sejam aplicadas.
    /// @return SUCESSO se todos os testes passarem, FALHA caso contrário.
    int runCarteira();
};

#endif // TUCARTEIRA_HPP_INCLUDED
