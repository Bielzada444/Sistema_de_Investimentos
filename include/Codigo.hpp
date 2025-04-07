#ifndef CODIGO_HPP
#define CODIGO_HPP

#include <stdexcept> // biblioteca onde esta contida a  calsse base runtime_error 
#include <string>

class DominioException : public std::runtime_error { // classe publica de tratamento de erros
    public:
        explicit DominioException(const std::string& mensagem) // construtor da classe que recebe as mensagens de erro
        : std::runtime_error(mensagem) {} // passa a mensagem para o construtor da classe base
};

class Codigo {
    private:
        std::string NumeroCodigo;
        bool ValidarCodigo(const std::string& CodigoInserido);
    public:
        void SetCodigo(const std::string& NovoCodigo); // "escreve/muda" o conteudo do atributo numeroCodigo
	    inline std::string GetCodigo() const { 
	        return NumeroCodigo; 
	    } // "retorna" uma copia do atributo numeroCodigo
};

#endif
