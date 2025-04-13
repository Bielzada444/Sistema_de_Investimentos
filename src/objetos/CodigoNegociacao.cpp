//Autor Cleriston
//Matricula 232001433

#include "CodigoNegociacao.hpp"
#include<ctype.h>
#include<stdexcept>

bool CodigoNegociacao::validarCodigo(const std::string& codigo) {
    if(codigo.empty() || codigo.length() > 12) { // Verifica se a string ta vazia ou tem mais de 12 caracteres
        throw DominioException("Tamanho do codigo invalido!");
    }
    for(char c : codigo) { // percorre a string char por char e verifica se e letra, numero ou espaco
        if(!(isalnum(c) || c == ' ')) { // caso contrario retorna uma excessao
            throw DominioException("Caractere invalido");
        }
    }
    return true;
}

void CodigoNegociacao::setCodigo(const std::string& codigo) {
    if(validarCodigo(codigo)){
    }
    this->codigo = codigo;
}
