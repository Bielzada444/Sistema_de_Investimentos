//Autor Cleriston
//Matricula 232001433

#include <iostream>
#include <cassert>
#include "CodigoNegociacao.hpp"

class TesteCodigoNegociacao {

public:
    void testarCodigoValido() {
        CodigoNegociacao c;
        c.setCodigo("Abc123     o");
        assert(c.getCodigo() == "Abc123     o");
    }

    void testarCodigoInvalido() {
        CodigoNegociacao c;
        try {
            c.setCodigo("###"); // verifica lançamento de excessao
            assert(false);
        } catch (const std::invalid_argument&) {
            assert(true);
        }
        try {
            c.setCodigo("Testar Meu codigo"); // verifica lançamento de excessao
            assert(false);
        } catch (const std::length_error&) {
            assert(true);
        }
    }

    void rodarTodosTestes() {
        testarCodigoValido();
        testarCodigoInvalido();
        std::cout << "Todos os testes passaram!\n";
    }
};

int main() {
    TesteCodigoNegociacao teste;
    teste.rodarTodosTestes();
    return 0;
}
