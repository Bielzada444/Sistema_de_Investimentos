//
// Criado por  Henrique em 05/04/2025.
// Matricula: 241020840

#include "Dinheiro.h"

#include <cmath>
#include <stdexcept>

// Metodo que arredonda o valor para ter algo significante somente ate a 2a casa decimal
double Dinheiro::arrendodar(const double &valor) {
    return std::round(valor *100.00) / 100.00;
};

bool Dinheiro::validarValor(const double &valor) {
    if (valor < 0.00 || valor > 1000000.00) {
        throw std::invalid_argument("Valor invalido, voce deve inserir um valor entre 0.01 e 1,000,000.00 ");
    }
    //Se passou por todas as verificacoes, o valor e valida
    return true;

}

void Dinheiro::setValor(const double &valor) {
    double valor_T = arrendodar(valor);
    if (validarValor(valor_T)) {} // Essa condicao nao faz nada, mas a validacao acontece
    this->valor = valor_T;   // Atribui valor arredondado
}


