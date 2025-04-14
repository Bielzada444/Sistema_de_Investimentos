//
// Criado por Henrique em 04/04/2025.
// Matricula: 241020840

#ifndef DINHEIRO_H
#define DINHEIRO_H

#include <stdexcept> // Biblioteca onde esta contida a  calsse base runtime_error 
 
 class DominioException : public std::runtime_error { // Classe publica de tratamento de erros
     public:
         explicit DominioException(const std::string& mensagem) // Construtor da classe que recebe as mensagens de erro
         : std::runtime_error(mensagem) {} // Passa a mensagem para o construtor da classe base
 };
 
class Dinheiro {
      private:
        double valor; // Armazena o valor do dinheiro como double
        
        bool validarValor(const double& valor); // Metodo que faz a validacao do valor digitado
        
        double arrendodar(const double& valor); // Metodo que arrendonda o valor para duas casas decimais depois do ponto
        double stringParaDouble(std::string& valor);// Metodo para converter o input recebido como string para ser armazenado como double
       public:
         void setValor(std::string& valor); // Recebe o input do usuario
        inline double getValor()  { // Retorna o valor armazenado do atributo 
           return valor;
    }
};
#endif //DINHEIRO_H
