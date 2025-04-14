//
// Criado por Henrique em 10/04/2025
//  Matricula 241020840

#include <iostream>
#include "Quantidade.h"
int main(){
    Quantidade qtd;
    std::string input;
    bool valido = false;
    
    while(!valido){
           std::cout << "Digite a quantidade: ";
        std::getline(std::cin, input); // Atribuicao da quantidade digitado
       try{ // Tentativa da operacao do bloco
            qtd.setQuantidade(input); // envio para validacao
            std::cout << "Quantidade valida: " << qtd.getQuantidade() << std::endl;
            valido = true;
       }
        catch (const DominioException& qtdError) { // No caso de erro, executado 
           std::cerr << "Erro de validacao: " << qtdError.what() << std::endl; // No caso de excecao, exibe mens de erro contida em DE

        }  
    }
    
    return 0;
}
