//
// Criado por Henrique em 04/04/2025.
// Matricula: 241020840
#ifndef DATA_H
#define DATA_H

#include <chrono>
#include <stdexcept>
#include <string>
 class DominioException : public std::runtime_error { // Classe publica de tratamento de erros
     public:
         explicit DominioException(const std::string& mensagem) // Construtor da classe que recebe as mensagens de erro
         : std::runtime_error(mensagem) {} // Passa a mensagem para o construtor da classe base
 };
class Data {
private:
    std::chrono::year_month_day valor; // Armazena a data no formato AAAA/MM/DD
    
    /**
     * Valida a data conforme os requisitos do domínio
     * @param data Data a ser validada
     * @return true se a data é válida
     * @throws std::invalid_argument se a data for inválida
     */
    bool validarData(const std::chrono::year_month_day& data);
    
    /**
     * Converte uma string no formato AAAAMMDD para year_month_day
     * @param dataString String no formato AAAAMMDD
     * @return Objeto year_month_day correspondente
     * @throws std::invalid_argument se a string for inválida
     */
    static std::chrono::year_month_day stringParaData(const std::string& dataString);

public:
    /**
     * Construtor que recebe uma string no formato AAAAMMDD
     * @param dataString String no formato AAAAMMDD
     * @throws std::invalid_argument se a data for inválida
     */
   // explicit Data(const std::string& dataString);
    
    /**
     * Construtor que recebe um objeto year_month_day
     * @param data Objeto year_month_day
     * @throws std::invalid_argument se a data for inválida
     */
//explicit Data(const std::chrono::year_month_day& data);
    
    /**
     * Define o valor da data a partir de uma string no formato AAAAMMDD
     * @param dataString String no formato AAAAMMDD
     * @throws std::invalid_argument se a data for inválida
     */
    void setValor(const std::string& dataString);
    
    /**
     * Define o valor da data a partir de um objeto year_month_day
     * @param data Objeto year_month_day
     * @throws std::invalid_argument se a data for inválida
     */
    void setValor(const std::chrono::year_month_day& data);
    
    /**
     * Retorna o valor da data como string no formato AAAAMMDD
     * @return String no formato AAAAMMDD
     */
    std::string getValor() const;
    
    /**
     * Retorna o valor da data como objeto year_month_day
     * @return Objeto year_month_day
     */
    std::chrono::year_month_day getData() const;
};

#endif // DATA_H
