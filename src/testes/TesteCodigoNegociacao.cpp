//Autor Cleriston
//Matricula 232001433

#include <iostream>
#include <cassert>
#include "CodigoNegociacao.hpp"
#include <string>

/*class TesteCodigoNegociacao {

public:
    void testarCodigoValido() {
        CodigoNegociacao c;
        c.setCodigo("Abc123     o");
        assert(c.getCodigo() == "Abc123     o");
    }

    void testarCodigoInvalido() {
        CodigoNegociacao c;
        try {
            c.setCodigo("###"); // verifica lan�amento de excessao
            assert(false);
        } catch (const std::invalid_argument&) {
            assert(true);
        }
        try {
            c.setCodigo("Testar Meu codigo"); // verifica lan�amento de excessao
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
};*/

int main() {
    CodigoNegociacao codigo;//  objeto cpf da classe CPF
    std::string input; // c string input para armazenar o CPF
    bool valido = false; // bool para controle do loop
    
    while(!valido){
        std::cout << "Digite o Codigo: " << std::endl;
        std::cin >> input; // atribuicao do CPF digitado
       try{ // tentativa da operacao do bloco
            codigo.setCodigo(input); // envio para validacao
            std::cout << "CPF valido: " << input << std::endl;
            valido = true;
        } catch (const DominioException& cpfError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << cpfError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
        }
        
    }
    return 0;
}
