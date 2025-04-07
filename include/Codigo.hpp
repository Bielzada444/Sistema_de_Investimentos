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
         std::string numeroCodigo;
         bool validarCodigo(const std::string& codigoInserido);
     public:
         void setCodigo(const std::string& novoCodigo); // "escreve/muda" o conteudo do atributo numeroCodigo
 	    inline std::string getCodigo() const { 
 	        return numeroCodigo; 
 	    } // "retorna" uma copia do atributo numeroCodigo
 };
 
 #endif
