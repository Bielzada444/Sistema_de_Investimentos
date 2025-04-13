//Autor Cleriston
//Matricula 232001433

#include <iostream>
#include "CodigoNegociacao.hpp"
#include <string>

int main() {
    CodigoNegociacao codigo; // objeto da classe CodigoNegociacao
    std::string input; // string input para armazenar o codigo
    bool valido = false; // bool para controle do loop
    
    while(!valido) {
        std::cout << "Digite o Codigo: " << std::endl;
        std::getline(std::cin, input); // atribuicao do Codigo digitado
       try { // tentativa da operacao do bloco
            codigo.setCodigo(input); // envio para validacao
            std::cout << "Codigo valido: " << codigo.getCodigo() << std::endl;
            valido = true;
        } catch (const DominioException& e) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << e.what() << std::endl; // no caso de excecao, exibe msg de erro continda na excecao 
        }
    }
    return 0;
}
