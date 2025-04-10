//
// Criado por Henrique em 10/04/2025
//  Matricula 241020840

#ifndef QUANTIDADE_H
#define QUANTIDADE_H
#include <stdexcept> // Biblioteca onde esta contida a  calsse base runtime_error 
 
 class DominioException : public std::runtime_error { // Classe publica de tratamento de erros
     public:
         explicit DominioException(const std::string& mensagem) // Construtor da classe que recebe as mensagens de erro
         : std::runtime_error(mensagem) {} // Passa a mensagem para o construtor da classe base
 };
class Quantidade{
        private:
        int quantidade; // Armazena o valor quantidade como um inteiro
        
        bool validarQuantidade(int &quantidade); // Metodo para conferir se a quantidade digitada eh valida
        
        int stringParaInteiro(std::string &quantiade); // Metodo para converter o input recebido como string para ser armazenado como inteiro
        
        public: 
        void setQuantidade(std::string &quantidade); // Recebe o input do usuario
        inline int getQuantidade() const{ // Retorna o valor do atributo quantidade 
            return quantidade;
        }
        
        
    
};
#endif
