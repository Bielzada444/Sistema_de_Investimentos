//Autor Cleriston
//Matricula 232001433

/**
 * @file TUPerfil.cpp
 * @brief Implementação dos testes para a classe Perfil.
 */

#include "TUPerfil.hpp"

// Valores pre-definidos para os testes
const std::string TUPerfil::VALOR_VALIDO = "Conservador";
const std::string TUPerfil::VALOR_INVALIDO = "Agresssivo";

/**
 * @brief Prepara o ambiente antes de cada teste.
 * - Aloca uma nova instância de Perfil.
 * - Define o estado inicial como SUCESSO.
*/

void TUPerfil::setUp() {
    perfil = new Perfil();
    estado = SUCESSO;
}

/**
 * @brief Libera recursos após cada teste.
 * - Deleta a instância de Perfil.
*/

void TUPerfil::tearDown() {
    delete perfil; // Libera memoria alocada
}

/**
 * @brief Testa a aceitação de um valor válido.
 * - Verifica se setPerfil() não lança exceção.
 * - Verifica se o valor foi armazenado corretamente.
*/

void TUPerfil::testarCenarioValido() {
    try {
        perfil->setPerfil(VALOR_VALIDO);
        if (perfil->getPerfil() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (DominioException &e) {
        estado = FALHA;
    }
}

/**
 * @brief Testa a rejeição de um valor inválido.
 * - Verifica se setPerfil() lança exceção.
 * - Verifica se o valor inválido não foi armazenado.
*/

void TUPerfil::testarCenarioInvalido() {
    try {
        perfil->setPerfil(VALOR_INVALIDO);
        estado = FALHA;
    } catch (DominioException &e) {
        if (perfil->getPerfil() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}

/**
 * @brief Executa o conjunto completo de testes.
 * @return int `SUCESSO` (0) se todos os testes passarem, `FALHA` (-1) caso contrário.
 */

int TUPerfil::runPerfil() {
    setUp();              // Prepara ambiente de teste
    testarCenarioValido();   // Executa teste válido
    testarCenarioInvalido(); // Executa teste inválido
    tearDown();           // Limpa recursos
    return estado;        // Retorna resultado dos testes
}
