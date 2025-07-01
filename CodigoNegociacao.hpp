//
// Criado por Cleriston em 05/04/2025
// Matricula: 232001433

/// @file CodigoNegociacao.hpp
/// @brief Domínio que representa um código alfanumérico de negociação.
/// @details
/// Código utilizado em transações financeiras, composto por até 12 caracteres
/// que podem ser letras (A-Z, a-z), dígitos (0-9) ou espaços. Usado para
/// identificar ativos como ações ou contratos.

#ifndef CODIGO_NEGOCIACAO_HPP
#define CODIGO_NEGOCIACAO_HPP

#include <stdexcept>
#include <string>
#include "DominioException.hpp"

/// @class CodigoNegociacao
/// @brief Classe responsável por armazenar e validar um código de negociação.
/// @details
/// Esta classe permite o armazenamento de um código alfanumérico de até 12 caracteres,
/// garantindo que ele siga as regras de formatação estabelecidas. O código pode conter
/// letras maiúsculas (A-Z), letras minúsculas (a-z), números (0-9) e espaços.


class CodigoNegociacao {
    private:
        std::string codigo;
        void validarCodigoNegociacao(const std::string& codigoInserido);

    public:
        /// @brief Define e armazena o código de negociação após validação.
        /// Antes de armazenar o código, este método verifica se ele atende às regras de formatação.
        /// Caso contrário, impede o armazenamento lançando uma exceção.
        /// @param novoCodigo String contendo até 12 caracteres alfanuméricos e espaços.
        /// @throw DominioException Se o código estiver fora do padrão especificado.

        void setCodigoNegociacao(const std::string& novoCodigo);

        /// @brief Obtém o código de negociação armazenado.
        /// Retorna o código previamente validado e armazenado na classe.
        /// @return String contendo o código de negociação válido.

        inline std::string getCodigoNegociacao() const {
            return codigo;
        }
};

#endif // CODIGONEGOCIACAO_HPP
