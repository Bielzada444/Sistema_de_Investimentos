//
// Criado por Henrique em 10/04/2025
// Matricula: 241020840

/// @file Quantidade.hpp
/// @brief Domínio que representa quantidades inteiras não negativas.
/// @details - Intervalo válido: 1 a 1,000,000 unidades
/// - Usado para operações como lotes de ações ou unidades de produtos
/// - Exemplos válidos: 1 (mínimo), 500000, 1000000 (máximo)

#ifndef QUANTIDADE_HPP
#define QUANTIDADE_HPP
#include <stdexcept>
#include "DominioException.hpp"

/// @class Quantidade
/// @brief Classe que gerencia quantidades inteiras dentro de um intervalo seguro.
/// @details Armazena e valida valores inteiros garantindo que estejam dentro do intervalo permitido,
/// possibilitando cálculos e operações seguras.\n
/// - Intervalo válido: 1 a 1,000,000 unidades
/// - Usado para operações como lotes de ações ou unidades de produtos
/// - Exemplos válidos: 1 (mínimo), 500000, 1000000 (máximo)

class Quantidade {
    private:
        int quantidade;
        void validarQuantidade(int &quantidade);
        int stringParaInteiro(std::string &quantiade);

    public:
          /// @brief Define a quantidade a partir de uma string numérica válida.
        /// @details
        /// - Converte a string para um número inteiro válido.
        /// - Garante que o valor esteja entre 1 e 1,000,000.
        /// - Valida a entrada para evitar valores inválidos ou fora do intervalo permitido.
        /// @param quantidade String contendo o valor numérico a ser armazenado.
        /// @throw DominioException Se o valor estiver fora dos limites aceitos, contiver caracteres inválidos ou for uma string vazia.
        void setQuantidade(std::string &quantidade);

         /// @brief Obtém a quantidade armazenada na instância.
        /// @details
        /// - Retorna um número inteiro dentro do intervalo válido (mínimo: 1, máximo: 1.000.000).
        /// - Pode ser utilizado diretamente em cálculos e operações sem necessidade de validação adicional.
        /// @return Quantidade armazenada, representada como um número inteiro (`int`).
        inline int getQuantidade() const {
            return quantidade;
        }
};
#endif
