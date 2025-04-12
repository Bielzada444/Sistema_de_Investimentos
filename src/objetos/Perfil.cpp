//Autor Cleriston
//Matricula 232001433

#include "Perfil.hpp"

bool Perfil::validar(const std::string& tipoPerfil) {
    // Retorna true caso a string tipoPerfil for igual a estes
    return  tipoPerfil == "Conservador" ||
            tipoPerfil == "Moderado" ||
            tipoPerfil == "Agressivo"; // Aceita somente com a primeira letra maiuscula
}

void Perfil::setPerfil(const std::string& tipoPerfil) {
    if(!validar(tipoPerfil)) { // lanca uma excessao caso o tipoPerfil nao passe no metodo validar
        throw DominioException("Tipo de perfil incorreto!");
    }
    this->tipoPerfil = tipoPerfil;
}
