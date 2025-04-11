//
// Criado por Nyvea em 11/04/2025.
// Matricula: 241040207

#include <iostream>
#include "Senha.h"

int main()
{
    Senha a;                                                                         //cria objeto tipo senha
    std::string senha = "56gH&n";                                                //atribui um valor a uma string (no caso, senha valida)
    try{
    a.setSenha(senha);
    std::cout << "Senha valida: " << senha << std::endl;
    } catch (const DominioException& senhaError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << senhaError.what() << std::endl;    // no caso de excecao, exibe mens de erro contida em DE 
    }
    senha = "m%12s5";
    
    try{
    a.setSenha(senha);
    } catch (const DominioException& senhaError) {                                  // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << senhaError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
    }
    senha = "JK&67%";
    
    try{
    a.setSenha(senha);
    } catch (const DominioException& senhaError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << senhaError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
    }
    senha = "KmSt#&";
    try{
    a.setSenha(senha);
    } catch (const DominioException& senhaError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << senhaError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
    }
    senha = "JKmtS9";
    
    try{
    a.setSenha(senha);
    } catch (const DominioException& senhaError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << senhaError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
    }
    senha = "Tsjs#5";
    
    try{
    a.setSenha(senha);
    } catch (const DominioException& senhaError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << senhaError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
    }
    senha = "Nj7#SQt%";
    
    try{
    a.setSenha(senha);
    } catch (const DominioException& senhaError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << senhaError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
    }
    
    senha = "7$Sn";
    try{
    a.setSenha(senha);
    } catch (const DominioException& senhaError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << senhaError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
    }
    
    std::cout << "Digite a senha para teste (para terminar o programa, digite '0'\n";               //para mais testes
    std::getline(std::cin, senha);

    while(senha.compare("0")){

        try{
            a.setSenha(senha);
            std::cout << "Senha valida: " << senha << std::endl;
        } catch (const DominioException& senhaError) { // no caso de erro, executado 
           std::cerr << "Erro de validacao: " << senhaError.what() << std::endl; // no caso de excecao, exibe mens de erro contida em DE 
        }

        std::cout << "Digite a senha para teste (para terminar o programa, digite '0')\n";
        std::getline(std::cin, senha);
    }

    return 0;
}
