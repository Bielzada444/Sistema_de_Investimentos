//Autor Cleriston
//Matricula 232001433

/**
 * @file TUCodigoNegociacao.cpp
 * @brief Implementação dos testes para CodigoNegociacao.
*/

#include "TUCodigoNegociacao.hpp"

// Valores pré-definidos para os testes
const std::string TUCodigoNegociacao::VALOR_VALIDO = "TEST4";  // Código válido (5 caracteres alfanuméricos)
const std::string TUCodigoNegociacao::VALOR_INVALIDO = "TEST#4"; // Código inválido (contém caractere especial)

/**
 * @brief Prepara o ambiente antes de cada teste.
 * - Aloca uma nova instância de CodigoNegociacao.
 * - Define o estado inicial como SUCESSO.
*/

void TUCodigoNegociacao::setUp() {
    codigoNegociacao = new CodigoNegociacao();  // Cria nova instância para teste
    estado = SUCESSO;                           // Inicializa como sucesso
}

/**
 * @brief Libera recursos após cada teste.
 * - Deleta a instância de codigoNegociacao.
*/

void TUCodigoNegociacao::tearDown() {
    delete codigoNegociacao; // Libera memória alocada
}

/**
 * @brief Testa a aceitação de um valor válido.
 * - Verifica se setPerfil() não lança exceção.
 * - Verifica se o valor foi armazenado corretamente.
*/

void TUCodigoNegociacao::testarCenarioValido() {
    try {
        codigoNegociacao->setCodigo(VALOR_VALIDO);
        // Verifica se o valor foi armazenado corretamente
        if (codigoNegociacao->getCodigo() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (DominioException &e) {
        estado = FALHA; // Falha se lançar exceção com valor válido
    }
}

/**
 * @brief Testa a rejeição de um valor inválido.
 * - Verifica se setCodigo() lança exceção.
 * - Verifica se o valor inválido não foi armazenado.
*/

void TUCodigoNegociacao::testarCenarioInvalido() {
    try {
        codigoNegociacao->setCodigo(VALOR_INVALIDO);
        estado = FALHA; // Falha se aceitar valor inválido
    } catch (DominioException &e) {
        // Verifica se valor inválido não foi armazenado
        if (codigoNegociacao->getCodigo() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}

/**
 * @brief Executa o conjunto completo de testes.
 * @return int `SUCESSO` (0) se todos os testes passarem, `FALHA` (-1) caso contrário.
 */

int TUCodigoNegociacao::runCodigoNegociacao() {
    setUp();              // Prepara ambiente de teste
    testarCenarioValido();   // Executa teste válido
    testarCenarioInvalido(); // Executa teste inválido
    tearDown();           // Limpa recursos
    return estado;        // Retorna resultado dos testes
}
