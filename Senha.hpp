//
//Criado por Nyvea em 11/04/2025.
//Matricula: 241040207

/// @file Senha.hpp
/// @brief Representação de um domínio para armazenamento de senhas, que correspondem a um conjunto de caracteres destinado a identificar o usuário ou a permitir acesso a dados, programas ou sistemas.
/// @details
/// Esta classe define um modelo para gerenciar senhas seguindo requisitos rigorosos de segurança.
/// As regras de formatação incluem:
/// - A senha deve conter exatamente 6 caracteres.
/// - Cada senha deve incluir pelo menos:
///   - Uma letra maiúscula (A-Z)
///   - Uma letra minúscula (a-z)
///   - Um dígito numérico (0-9)
///   - Um caractere especial (#, $, %, &)
/// - Não é permitido repetir caracteres dentro da senha.
/// - Exemplos de senhas válidas: `"A1b#C2"`
/// - Exemplos de senhas inválidas: `"senha123"` (falta caractere especial), `"A1bB#C"` (tem repetição).

#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>
#include <stdexcept>
#include "DominioException.hpp"

/// @class Senha
/// @brief Classe responsável pelo gerenciamento e validação de senhas.
/// @details
/// A classe Senha implementa um mecanismo para validar credenciais seguindo critérios predefinidos:
/// - A senha deve conter exatamente 6 caracteres.
/// - Cada senha deve incluir pelo menos:
///   - Uma letra maiúscula (A-Z)
///   - Uma letra minúscula (a-z)
///   - Um dígito numérico (0-9)
///   - Um caractere especial (#, $, %, &)
/// - Não é permitido repetir caracteres dentro da senha.
/// Seu propósito é garantir um alto nível de segurança em sistemas que necessitam de autenticação confiável.
class Senha {
    private:
        static const int CARACTERES = 6;
        std::string senha;
        void validaSenha(std::string senha);

    public:
        /// @brief Define e armazena a senha após validação rigorosa.
        /// @param senha String contendo exatamente 6 caracteres válidos conforme os critérios de segurança.
        /// @throw DominioException Se a senha não respeitar os requisitos de composição, é lançada uma exceção, que interrompe o processo e exibe uma mensagem contendo o erro encontrado.
        void setSenha(std::string senha);

        /// @brief Retorna a senha armazenada se o processo de validação for completado.
        /// @return Retorna uma string contendo a senha válida inserida.
        inline std::string getSenha() const {
            return senha;
        }
};

#endif // SENHA_HPP_INCLUDED
