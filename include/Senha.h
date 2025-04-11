//
// Criado por Nyvea em 11/04/2025.
// Matricula: 241040207

#ifndef SENHA_H_INCLUDED
#define SENHA_H_INCLUDED

#include <string>
#include <stdexcept>

class DominioException : public std::runtime_error { // classe publica de tratamento de erros
     public:
         explicit DominioException(const std::string& mensagem) // construtor da classe que recebe as mensagens de erro
         : std::runtime_error(mensagem) {} // passa a mensagem para o construtor da classe base
 };
 
class Senha{
    private:
        static const int CARACTERES = 6;        //a senha deve possuir 6 caracteres
        std::string senha;                      //a senha é lida como uma string
        bool validaSenha(std::string senha);          //retorna true se a senha for valida e false se nao for

    public:
        bool setSenha(std::string senha);             //inicializa a senha de acordo input
        std::string getSenha() const;           //retorna a string senha
};

inline std::string Senha::getSenha() const{
    return senha;
}

#endif // SENHA_H_INCLUDED
