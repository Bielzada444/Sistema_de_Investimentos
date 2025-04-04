#include <iostream>
#include "Codigo.hpp"

int main()
{
    
    Codigo codigo; //  objeto codigo da classe Codigo
    std::string input; //  string input para armazenar o Codigo
    bool valido = false; // bool para controle do loop
    
    while(!valido){
        std::cout << "Digite o Codigo: " << std::endl;
        std::cin >> input; // atribuicao do Codigo digitado
       try{ // tentativa da operacao do bloco
            codigo.setCodigo(input); // envio para validacao
            std::cout << "Codigo valido: " << input << std::endl;
            valido = true;
        } catch (const DominioException& codigoError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << codigoError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
        }
        
    }
    
    return 0;
}