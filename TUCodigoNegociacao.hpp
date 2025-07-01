//
//Criado por Cleriston em em 19/04/2025
//Matricula: 232001433

///@file TUCodigoNegociacao.hpp
///@brief Definição dos testes unitários para o domínio CodigoNegociacao.
///@details Esta classe testa os cenários válidos e inválidos para o domínio CodigoNegociacao,
///garantindo que a classe armazene e valide corretamente os códigos de negociação.
///Os cenários incluem:
///- Código válido: formado por 5 caracteres alfanuméricos.
///- Código inválido: qualquer valor que não atenda ao formato esperado.


#ifndef TUCODIGONEGOCIACAO_HPP
#define TUCODIGONEGOCIACAO_HPP

#include "CodigoNegociacao.hpp"
#include <string>

///
/// @class TUCodigoNegociacao
/// @brief Teste de unidade para o domínio CodigoNegociacao.
/// @details Esta classe realiza testes automatizados para garantir que o domínio
/// CodigoNegociacao aceite apenas códigos válidos (5 caracteres alfanuméricos).

class TUCodigoNegociacao {
    private:
        const static std::string CODIGO_NEGOCIACAO_VALIDO;
        const static std::string CODIGO_NEGOCIACAO_INVALIDO;
        CodigoNegociacao* codigoNegociacao;
        int estadoCodigoNegociacao;


        void setUpCodigoNegociacao();

        void tearDownCodigoNegociacao();

        void testarCenarioValidoCodigoNegociacao();

        void testarCenarioInvalidoCodigoNegociacao();

    public:
    /// @brief Código de retorno para teste bem-sucedido.
    const static int SUCESSO = 0;

    /// @brief Código de retorno para teste falho.
    const static int FALHA = -1;

        /// @brief Executa o conjunto de testes para CodigoNegociacao.
     /// @details Verifica:
     /// - Cenário de sucesso com um código válido.
     /// - Cenário de falha com um código inválido.
     /// @return int SUCESSO se todos os testes passarem, FALHA caso contrário.

        int runCodigoNegociacao();
};
#endif // TUCODIGONEGOCIACAO_HPP
