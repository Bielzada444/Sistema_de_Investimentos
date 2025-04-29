//Autor Cleriston
//Matricula 232001433

/**
 * @file CodigoNegociacao.hpp
 * @brief Definição da classe CodigoNegociacao para representar códigos de negociação financeira.
 */

#ifndef CODIGONEGOCIACAO_HPP
#define CODIGONEGOCIACAO_HPP

#include<iostream>
#include<string>
#include <stdexcept> // biblioteca onde esta contida a  classe base runtime_error
#include "DominioException.hpp"

/**
 * @class CodigoNegociacao
 * @brief Representa um código de negociação (ex: "TEST4") com validação.
 *
 * Regras de validação:
 * - Tamanho máximo: 12 caracteres.
 * - Caracteres permitidos: alfanuméricos (A-Z, a-z, 0-9) e espaços.
 */

class CodigoNegociacao {

    private:
        std::string codigo;
        bool validarCodigo(const std::string& codigo);

    public:

        /**
        * @brief Define um código após validação.
        * @param codigo String a ser validada (max 12 caracteres alfanuméricos ou espaços).
        * @throw DominioException Se o código for inválido.
        */

        void setCodigo(const std::string& codigo);

        /**
        * @brief Retorna o código armazenado (garantidamente válido ou string vazia).
        */

        std::string getCodigo() const {
            return codigo;
        }
};

#endif // CODIGONEGOCIACAO_HPP
