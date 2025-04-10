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
        std::cin >> input; // Atribuicao da quantidade digitado
       try{ // Tentativa da operacao do bloco
            qtd.setQuantidade(input); // envio para validacao
            std::cout << "Quantidade valida: " << qtd.getQuantidade() << std::endl;
            valido = true;
        }     catch (const std::out_of_range& qtdError) { // Lanca uma excecao para para valores fora da faixa permitida pelo stoi
    std::cerr << "O valor digitado deve estar entre 0 e 1,000,000\n";
  } 
        catch (const DominioException& qtdError) { // No caso de erro, executado 
           std::cerr << "Erro de validacao: " << qtdError.what() << std::endl; // No caso de excecao, exibe mens de erro contida em DE

        }  
    }
    
    return 0;
}
