//
// Criado por Gabriel em 03/04/2025.
// Matricula: 241038942

/// @file Codigo.hpp
/// @brief Domínio que representa um identificador numérico único.
/// @details  Um código é uma sequência de 5 dígitos numéricos (0-9) que serve como
/// identificador único para entidades no sistema.

#ifndef CODIGO_HPP
#define CODIGO_HPP

#include <stdexcept>
#include <string>
#include "DominioException.hpp"

/// @class Codigo
/// @brief Classe responsável por armazenar e validar um código numérico de exatamente 5 dígitos (0-9).
/// @details Esta classe verifica se o código inserido segue o formato correto, garantindo que ele contenha
/// apenas dígitos numéricos e tenha o tamanho esperado. Caso contrário, impede seu armazenamento.

class Codigo {
    private:
        std::string numeroCodigo;
        void validarCodigo(const std::string& codigoInserido);

    public:
        /// @brief Define e armazena o código após validação.
        /// Este método verifica se o código inserido atende aos requisitos antes de armazená-lo na variável interna.
        /// Se o código não for válido, uma exceção será gerada, garantindo que apenas códigos corretos sejam mantidos.
        /// @param novoCodigo String contendo exatamente 5 dígitos numéricos.
        /// @throw DominioException Se o código não seguir o formato esperado.

        void setCodigo(const std::string& novoCodigo);

        /// @brief Retorna o código atualmente armazenado.
        /// Sempre garante que o código retornado tenha sido previamente validado e esteja correto.
        /// @return String contendo os 5 dígitos numéricos do código.

        inline std::string getCodigo() const {
            return numeroCodigo;
        }
};

#endif
