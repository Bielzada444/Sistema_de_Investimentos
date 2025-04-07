#ifndef SENHA_H_INCLUDED
#define SENHA_H_INCLUDED

#include <string>

class Senha{
    private:
        static const int CARACTERES = 6;        //a senha deve possuir 6 caracteres
        std::string senha;                      //a senha é lida como uma string
        bool validaSenha(std::string);          //retorna true se a senha for valida e false se nao for

    public:
        bool setSenha(std::string);             //inicializa a senha de acordo input
        std::string getSenha();                 //retorna a string senha
};

inline std::string Senha::getSenha(){
    return senha;
}

#endif // SENHA_H_INCLUDED
