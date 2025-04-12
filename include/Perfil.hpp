//Autor Cleriston
//Matricula 232001433

#ifndef PERFIL_HPP
#define PERFIL_HPP

#include <string>
#include <stdexcept>

class DominioException : public std::runtime_error { // classe publica de tratamento de erros
    public:
        explicit DominioException(const std::string& mensagem) // construtor da classe que recebe as mensagens de erro
         : std::runtime_error(mensagem) {} // passa a mensagem para o construtor da classe base
};

class Perfil {
    private:
        std::string tipoPerfil;
        bool validar(const std::string& tipoPerfil);

    public:
        void setPerfil(const std::string& tipoPerfil);
        std::string getPerfil() const {
            return tipoPerfil;
        };
};

#endif // PERFIL_HPP
