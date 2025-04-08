#include <iostream>
#include "CPF.hpp"

int main()
{
    
    CPF cpf; //  objeto cpf da classe CPF
    std::string input; // c string input para armazenar o CPF
    bool valido = false; // bool para controle do loop
    
    while(!valido){
        std::cout << "Digite o CPF: " << std::endl;
        std::cin >> input; // atribuicao do CPF digitado
       try{ // tentativa da operacao do bloco
            cpf.setCPF(input); // envio para validacao
            std::cout << "CPF valido: " << input << std::endl;
            valido = true;
        } catch (const DominioException& cpfError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << cpfError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
        }
        
    }
    
    return 0;
}