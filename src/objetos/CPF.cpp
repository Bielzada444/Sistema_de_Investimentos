//
// Criado por Gabriel em 03/04/2025.
// Matricula: 241038942

#include "CPF.hpp"
#include <string>
#include <algorithm>

bool CPF::validar(const std::string& cpfInserido) {
	
	if(cpfInserido.length() != 11){ // verificacao se foi inserido exatamente 11 caracteres
	    throw DominioException("O tamanho esta invalido! CPF deve conter exatamente 11 digitos.");
	}
	
	bool todos_digitos = std::all_of(cpfInserido.begin(), cpfInserido.end(), [](char c) { // verificacao se sao todos caracteres numericos
		return std::isdigit(static_cast<unsigned char>(c));
	});

    if(!todos_digitos){ // tratamento em caso de input invalido
        throw DominioException("O CPF deve conter apenas digitos!");
    }

    bool todos_iguais = std::all_of(cpfInserido.begin(), cpfInserido.end(), [primeiro_char = cpfInserido[0]](char c) { // verificacao se sao digitos diferentes
     return c == primeiro_char;  
    });
    
    if(todos_iguais){ // tratamento em caso de input invalido
        throw DominioException("O CPF deve conter digitos diferentes!");
    }
    
    if (!validarDigitosVerificadores(cpfInserido)) {
        throw DominioException("Digitos verificadores do CPF invalidos");
    }
    
	return true;

}

bool CPF::validarDigitosVerificadores(const std::string& cpf) {
    
    if (!std::all_of(cpf.begin(), cpf.end(), ::isdigit)) { // verifica se todos sao digitos primeiro
        return false;
    }

    int soma = 0;
    for (int i = 0; i < 9; i++) { // calcula primeiro digito verificador
        soma += (cpf[i] - '0') * (10 - i);
    }
    
    int resto = soma % 11;
    int digito1 = (resto < 2) ? 0 : 11 - resto;

    soma = 0;
    for (int i = 0; i < 10; i++) { // calcula segundo digito verificador
        soma += (cpf[i] - '0') * (11 - i);
    }
    
    resto = soma % 11;
    int digito2 = (resto < 2) ? 0 : 11 - resto;

    return (cpf[9] - '0' == digito1) && (cpf[10] - '0' == digito2); // verifica se os digitos calculados batem com os informados
}

void CPF::setCPF(const std::string& numeroCpf) {
	if(!validar(numeroCpf)){
	}
	this->numeroCpf = numeroCpf;
}

