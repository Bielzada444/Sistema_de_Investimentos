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
	std::string NumeroCpf;
	bool Validar(const std::string& CpfInserido);
	bool ValidarDigitosVerificadores(const std::string& Cpf);
public:
	void SetCPF(const std::string& NovoCpf); // "escreve/muda" o conteudo do atributo NumeroCpf
	inline std::string GetCPF() const { 
	    return NumeroCpf; 
	} // "retorna" uma copia do atributo NumeroCpf
};


#endif
