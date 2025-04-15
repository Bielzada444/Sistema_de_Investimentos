//
// Criado por Gabriel em 03/04/2025.
// Matricula: 241038942

#include <iostream>
#include "Cpf.hpp"

int main()
{
    
    CPF cpf; //  objeto cpf da classe CPF
    std::string cpfInput = "10145408108"; //  string cpfInput para armazenar o CPF
    try{
    cpf.setCPF(cpfInput);
    std::cout << "CPF valido: " << cpf.getCPF() << std::endl;
    } catch (const DominioException& cpfError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << cpfError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    cpfInput = "123";
    
    try{
    cpf.setCPF(cpfInput);
    std::cout << "CPF valido: " << cpf.getCPF() << std::endl;
    } catch (const DominioException& cpfError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << cpfError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    cpfInput = "11111111111";
    
    try{
    cpf.setCPF(cpfiInput);
    std::cout << "CPF valido: " << cpf.getCPF() << std::endl;
    } catch (const DominioException& cpfError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << cpfError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    cpfInput = "123.456.789-09";
    
    try{
    cpf.setCPF(cpfInput);
    std::cout << "CPF valido: " << cpf.getCPF() << std::endl;
    } catch (const DominioException& cpfError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << cpfError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    cpfInput = "52998224724";
    
    try{
    cpf.setCPF(cpfInput);
    std::cout << "CPF valido: " << cpf.getCPF() << std::endl;
    } catch (const DominioException& cpfError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << cpfError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    cpfInput = "1234567890a";
    
    try{
    cpf.setCPF(cpfInput);
    std::cout << "CPF valido: " << cpf.getCPF() << std::endl;
    } catch (const DominioException& cpfError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << cpfError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    
    bool valido = false; // bool para controle do loop
    
    while(!valido){
        std::cout << "Digite o CPF: " << std::endl;
        std::getline(std::cin,cpfInput); // atribuicao do CPF digitado
       try{ // tentativa da operacao do bloco
            cpf.setCPF(cpfInput); // envio para validacao
            std::cout << "CPF valido: " << cpf.getCPF() << std::endl;
            valido = true;
        } catch (const DominioException& cpfError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << cpfError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
        }
        
    }
    
    return 0;
}
