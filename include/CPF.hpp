#ifndef CPF_HPP
 #define CPF_HPP
 
 #include <string>
 #include <stdexcept> // biblioteca onde esta contida a  calsse base runtime_error 
 
 class DominioException : public std::runtime_error { // classe publica de tratamento de erros
     public:
         explicit DominioException(const std::string& mensagem) // construtor da classe que recebe as mensagens de erro
         : std::runtime_error(mensagem) {} // passa a mensagem para o construtor da classe base
 };
 
 class CPF {
 private:
 	std::string numeroCpf;
 	bool validar(const std::string& cpfInserido);
 	bool validarDigitosVerificadores(const std::string& cpf);
 public:
 	void setCPF(const std::string& novoCpf); // "escreve/muda" o conteudo do atributo numeroCpf
 	inline std::string getCPF() const { 
 	    return numeroCpf; 
 	} // "retorna" uma copia do atributo numeroCpf
 };
 
 
 #endif
