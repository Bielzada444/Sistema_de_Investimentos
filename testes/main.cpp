#include <iostream>
#include "SENHA.h"


int main()
{
    Senha a;                                                        //cria objeto tipo senha
    std::string senha = "56gH&n";                                   //atribui um valor a uma string (no caso, senha valida)

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';        //se a senha for valida
    }
    else{
        std::cout << "A senha inserida eh invalida!\n";             //a senha eh invalida
    }

    senha = "58ijha";                                               //senha invalida

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';
    }
    else{
        std::cout << "A senha inserida eh invalida!\n";
    }

    senha = "ASHUsd";                                               //senha invalida

    if(a.setSenha(senha)){
        std::cout << "A senha eh: " << a.getSenha() << '\n';
    }
    else{
        std::cout << "A senha inserida eh invalida!\n";
    }

    return 0;
}
