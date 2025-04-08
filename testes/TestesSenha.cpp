//
// Criado por Henrique em 08/04/2025.
// Matricula: 241040207

#include <iostream>
#include "senha.h"


int main()
{
    Senha a;                                                        //cria objeto tipo senha
    std::string senha = "56gH&n";                                   //atribui um valor a uma string (no caso, senha valida)

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';        //se a senha for valida
    }
    else{
        std::cout << "A senha inserida eh invalida!\n";             //se a senha for invalida
    }

    senha = "m%12s5";                                               //ex senha invalida (sem letra maiuscula)

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';
    }
    else{
        std::cout << "A senha inserida (" << a.getSenha() << ") eh invalida!\n";
    }

    senha = "JK&67%";                                               //ex senha invalida (sem letra minuscula)

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';
    }
    else{
        std::cout << "A senha inserida (" << a.getSenha() << ") eh invalida!\n";
    }

    senha = "KmSt#&";                                               //ex senha invalida (sem numero)

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';
    }
    else{
        std::cout << "A senha inserida (" << a.getSenha() << ") eh invalida!\n";
    }

    senha = "JKmtS9";                                               //ex senha invalida (sem caracter especial)

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';
    }
    else{
        std::cout << "A senha inserida (" << a.getSenha() << ") eh invalida!\n";
    }

    senha = "Tsjs#5";                                               //ex senha invalida (caracter duplicado)

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';
    }
    else{
        std::cout << "A senha inserida (" << a.getSenha() << ") eh invalida!\n";
    }

    senha = "Nj7#SQt%";                                             //ex senha invalida (maior que 6 caracteres)

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';
    }
    else{
        std::cout << "A senha inserida (" << a.getSenha() << ") eh invalida!\n";
    }

    senha = "7$Sn";                                                 //ex senha invalida (menor que 6 caracteres)

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';
    }
    else{
        std::cout << "A senha inserida (" << a.getSenha() << ") eh invalida!\n";
    }

    std::cout << "Digite a senha para teste (para terminar o programa, digite '0'\n";               //para mais testes
    std::getline(std::cin, senha);

    while(senha.compare("0")){

        if(a.setSenha(senha)){
            std::cout << "A senha eh: " << a.getSenha() << '\n';
        }
        else{
            std::cout << "A senha inserida (" << a.getSenha() << ") eh invalida!\n";
        }

        std::cout << "Digite a senha para teste (para terminar o programa, digite '0')\n";
        std::getline(std::cin, senha);
    }

    return 0;
}
