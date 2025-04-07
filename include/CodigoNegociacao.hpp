//Autor Cleriston
//Matricula 232001433

#ifndef CODIGONEGOCIACAO_H
#define CODIGONEGOCIACAO_H

#include<iostream>
#include<string>

class CodigoNegociacao {

    private:
        std::string codigo;
        bool validarCodigo(const std::string& codigo);

    public:
        void setCodigo(const std::string& codigo);
        std::string getCodigo() const {
            return codigo;
        }
};

#endif // CODIGONEGOCIACAO_H
