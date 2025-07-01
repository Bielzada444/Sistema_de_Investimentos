//
// Criado por Nyvea em 08/04/2025.
// Matricula: 241040207

/// @file Nome.hpp
/// @brief Representação de um domínio para nomes de usuários.
/// @details Esta classe fornece um modelo para armazenar e validar nomes seguindo as seguintes regras:
/// - O nome pode conter, no máximo, 20 caracteres.
/// - Caracteres permitidos incluem letras maiúsculas e minúsculas (A-Z, a-z), dígitos (0-9) e espaços. Caracteres fora desse escopo não são válidos.
/// - Espaços consecutivos ou nomes compostos apenas por espaços são proibidos.
/// - Exemplos de nomes válidos: "João Silva", "Empresa XYZ 123".

#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>
#include "DominioException.hpp"

/// @class Nome
/// @brief Classe responsável por gerenciar nomes respeitando regras de validação.
/// @details
/// A classe Nome armazena um nome validado, seguindo as seguintes especificações:
/// - O nome pode conter até 20 caracteres.
/// - Caracteres válidos são letras maiúsculas e minúsculas (A-Z, a-z), dígitos (0-9) e espaços.
/// - Não é permitido espaços consecultivos ou nomes constituidos de apenas um espaço.
/// O propósito é garantir um formato padronizado para nomes em sistemas que necessitam de validação.

class Nome {
    private:
        static const int MAXIMO = 21;
        std::string nome;
        void validaNome(std::string nome);

    public:
        /// @brief Define e armazena um nome após a validação baseada nas regras anteriormente especificados.
        /// @param nome recebe uma string contendo até 20 caracteres válidos conforme regras estabelecidas.
        /// @throw DominioException Se o nome não atender aos critérios de formatação, uma exceção é lançada, interrompendo o processo de armazenamento com uma mensagem especificando o erro.
        void setNome(std::string nome);

        /// @brief Quando o nome cumpre todos os requisitos espericifados e o armazenamento é realizado com sucesso, o nome armazenado é retornado.
        /// @return Retorna uma string que representa o nome armazenado.
        inline std::string getNome() const {
            return nome;
        }
};

#endif // NOME_HPP_INCLUDED
