//
// Criado por Gabriel em 03/04/2025.
// Matricula: 241038942

#include <iostream>
#include "Codigo.hpp"

int main()
{
    
    Codigo codigo; //  objeto codigo da classe Codigo
    std::string codigoInput = "12345"; //  string codigoInput para armazenar o Codigo
    try{
    codigo.setCodigo(codigoInput);
    std::cout << "Codigo valido: " << codigo.getCodigo() << std::endl;
    } catch (const DominioException& codigoError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << codigoError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    codigoInput = "123"; //  string input para armazenar o Codigo
    
    try{
    codigo.setCodigo(codigoInput);
    std::cout << "Codigo valido: " << codigo.getCodigo() << std::endl;
    } catch (const DominioException& codigoError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << codigoError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    
    codigoInput = "123##"; //  string input para armazenar o Codigo
    
    try{
    codigo.setCodigo(codigoInput);
    std::cout << "Codigo valido: " << codigo.getCodigo() << std::endl;
    } catch (const DominioException& codigoError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << codigoError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    
    codigoInput = "123235"; //  string input para armazenar o Codigo
    
    try{
    codigo.setCodigo(codigoInput);
    std::cout << "Codigo valido: " << codigo.getCodigo() << std::endl;
    } catch (const DominioException& codigoError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << codigoError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    
    codigoInput = "abcde"; //  string input para armazenar o Codigo
    
    try{
    codigo.setCodigo(codigoInput);
    std::cout << "Codigo valido: " << codigo.getCodigo() << std::endl;
    } catch (const DominioException& codigoError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << codigoError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    
    codigoInput = " 12 1"; //  string input para armazenar o Codigo
    
    try{
    codigo.setCodigo(codigoInput);
    std::cout << "Codigo valido: " << codigo.getCodigo() << std::endl;
    } catch (const DominioException& codigoError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << codigoError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    
    codigoInput = ""; //  string input para armazenar o Codigo
    
    try{
    codigo.setCodigo(codigoInput);
    std::cout << "Codigo valido: " << codigo.getCodigo() << std::endl;
    } catch (const DominioException& codigoError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << codigoError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    bool valido = false; // bool para controle do loop
    
    
    while(!valido){
        std::cout << "Digite o Codigo: " << std::endl;
        std::getline(std::cin,codigoInput); // atribuicao do Codigo digitado
       try{ // tentativa da operacao do bloco
            codigo.setCodigo(codigoInput); // envio para validacao
            std::cout << "Codigo valido: " << codigo.getCodigo() << std::endl;
            valido = true;
        } catch (const DominioException& codigoError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << codigoError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
        }
        
    }
    
    return 0;
}
