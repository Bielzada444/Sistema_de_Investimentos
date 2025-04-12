//Autor Cleriston
//Matricula 232001433

#include <iostream>
#include "Perfil.hpp"
#include <string>

int main() {

    Perfil perfil;  // Objeto da classe Perfil
    std::string tiposPerfis[] = {   "Conservador", "Moderado", "Agressivo",  // caso correto
                                    "Agresssivo", "conservador", "Testando"}; // caso incorreto

    // loop para testar metodos setPerfil e getPerfil
    for (const std::string& tipoPerfil : tiposPerfis) {
        try {
            perfil.setPerfil(tipoPerfil);
            std::cout << "Caso correto: " << perfil.getPerfil() << std::endl; // imprime o perfil setado
        } catch (const DominioException& e) {
            std::cerr << "Exceção lançada para '" << tipoPerfil << "': " << e.what() << std::endl; // imprime a excessao
        }
    }

    return 0;
}
