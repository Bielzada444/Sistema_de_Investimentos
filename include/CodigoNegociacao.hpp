//Autor Cleriston
//Matricula 232001433

#ifndef CODIGONEGOCIACAO_HPP
#define CODIGONEGOCIACAO_HPP

#include<iostream>
#include<string>
#include <stdexcept> // biblioteca onde esta contida a  classe base runtime_error 
 
 class DominioException : public std::runtime_error { // classe publica de tratamento de erros
     public:
         explicit DominioException(const std::string& mensagem) // construtor da classe que recebe as mensagens de erro
         : std::runtime_error(mensagem) {} // passa a mensagem para o construtor da classe base
 };
 
class CodigoNegociacao {

    private:
        std::string codigo;
        bool validarCodigo(const std::string& codigo);

    public:
        void setCodigo(const std::string& codigo);
        std::string getCodigo() const {
            return codigo;
        }
};

#endif // CODIGONEGOCIACAO_HPP
