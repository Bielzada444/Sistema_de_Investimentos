//Autor Cleriston
//Matricula 232001433

/**
 * @file Perfil.cpp
 * @brief Implementação dos métodos da classe Perfil.
 */

#include "Perfil.hpp"

/**
 * @brief Valida se o perfil está entre as opções permitidas.
 *
 * @param tipoPerfil String a ser validada.
 * @return true se for "Conservador", "Moderado" ou "Agressivo" (exatos, case-sensitive).
 *
 * @note Comparação direta sem transformação de caso (case-sensitive).
 */

bool Perfil::validar(const std::string& tipoPerfil) {
    // Retorna true caso a string tipoPerfil for igual a estes
    return  tipoPerfil == "Conservador" ||
            tipoPerfil == "Moderado" ||
            tipoPerfil == "Agressivo"; // Aceita somente com a primeira letra maiuscula
}

/**
 * @brief Armazena o perfil se for válido.
 *
 * @param tipoPerfil Perfil a ser definido.
 * @throw DominioException Com mensagem "Tipo de perfil incorreto!" se a validação falhar.
 *
 */

void Perfil::setPerfil(const std::string& tipoPerfil) {
    if(!validar(tipoPerfil)) {
        throw DominioException("Tipo de perfil incorreto!");
    }
    this->tipoPerfil = tipoPerfil;
}
