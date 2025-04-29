/**
 * @file TUCodigoNegociacao.hpp
 * @brief Definição dos testes unitários para CodigoNegociacao.
 */

#ifndef TUCODIGONEGOCIACAO_HPP
#define TUCODIGONEGOCIACAO_HPP

#include "CodigoNegociacao.hpp"
#include <string>

/**
 * @class TUCodigoNegociacao
 * @brief Testa os cenários válidos e inválidos para CodigoNegociacao.
 */

class TUCodigoNegociacao {
  private:
        const static std::string VALOR_VALIDO;   ///< Código válido padrão ("TEST4")
        const static std::string VALOR_INVALIDO; ///< Código inválido padrão ("TEST#4")
        CodigoNegociacao* codigoNegociacao;      ///< Instância sob teste
        int estado;                              ///< Estado do teste (SUCESSO/FALHA)

        /**
        * @brief Configura o ambiente de teste.
        */
        void setUp();

        /**
        * @brief Libera recursos após o teste.
        */
        void tearDown();

        /**
        * @brief Testa cenário com código válido.
        */
        void testarCenarioValido();

        /**
        * @brief Testa cenário com código inválido.
        */
        void testarCenarioInvalido();

    public:
        const static int SUCESSO = 0; ///< Código de sucesso
        const static int FALHA = -1;  ///< Código de falha

        /**
        * @brief Executa o conjunto de testes.
        * @return int SUCESSO se todos os testes passarem, FALHA caso contrário.
        */
        int runCodigoNegociacao();
};
#endif // TUCODIGONEGOCIACAO_HPP
