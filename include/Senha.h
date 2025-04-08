//
// Criado por Nyvea em 08/04/2025.
// Matricula: 241040207

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
        std::string getSenha() const;           //retorna a string senha
};

inline std::string Senha::getSenha() const{
    return senha;
}

#endif // SENHA_H_INCLUDED
