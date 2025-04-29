//
// Criado por  Henrique em 14/04/2025.
// Matricula: 241020840
#include <iostream>
#include "Dinheiro.h"

int main(){
    Dinheiro valor;
    std::string input;
    bool valido = false;
    
    while(!valido){
           std::cout << "Digite o valor: ";
        std::getline(std::cin, input); // Atribuicao da valor digitado
       try{ // Tentativa da operacao do bloco
            valor.setValor(input); // envio para validacao
            std::cout << "Valor valido: " << valor.getValor() << std::endl;
            valido = true;
       }
        catch (const DominioException& valorError) { // No caso de erro, executado 
           std::cerr << "Erro de validacao: " << valorError.what() << std::endl; // No caso de excecao, exibe mens de erro contida em DE

        }  
    }
    
    return 0;
}
