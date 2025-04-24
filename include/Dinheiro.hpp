//
// Criado por Henrique em 04/04/2025.
// Matricula: 241020840

#ifndef DINHEIRO_HPP
#define DINHEIRO_HPP
#include "DominioException.hpp"

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
#endif //DINHEIRO_HPP
