//Autor Cleriston
//Matricula 232001433

#include "CodigoNegociacao.hpp"
#include<ctype.h>
#include<stdexcept>

bool CodigoNegociacao::validarCodigo(const std::string& codigo) {
    if(codigo.empty() || codigo.length() > 12) {
        throw std::length_error("Tamanho do codigo invalido!");
    }
    for(char c : codigo) {
        if(!(isalnum(c) || c == ' ')) {
            throw std::invalid_argument("Caractere invalido");
        }
    }
    return true;
}

void CodigoNegociacao::setCodigo(const std::string& codigo) {
    validarCodigo(codigo);
    this->codigo = codigo;
}
