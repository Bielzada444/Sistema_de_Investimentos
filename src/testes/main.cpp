//
// Criado por Nyvea em 08/04/2025.
// Matricula: 241040207

#include <iostream>
#include "nome.h"

int main()
{
    Nome a;                                                                                 //cria um objeto da classe "Nome"
    std::string nome = "Nyvea Paulla";                                                      //ex de nome valido

    if(a.setNome(nome)){
        std::cout << "O nome eh " << a.getNome() << '\n';                               //se o nome for valido
    }

    else{
        std::cout << "O nome \"" << nome << "\" eh invalido\n";                  //se o nome for invalido
    }

    nome = "Julio  Cesar";                                                                 //ex nome invalido (dois espa�os em branco seguidos)

    if(a.setNome(nome)){
        std::cout << "O nome eh " << a.getNome() << '\n';
    }
    else{
        std::cout << "O nome \"" << nome << "\" eh invalido\n";
    }

    nome = "Maria das Dores dos Anjos";                                                    //ex nome invalido (maior que 20 caracters)

    if(a.setNome(nome)){
        std::cout << "O nome eh " << a.getNome() << '\n';
    }
    else{
        std::cout << "O nome \"" << nome << "\" eh invalido\n";
    }

    nome = "vinic1us_13";                                                                  //ex nome invalido (caracter especial '_')

    if(a.setNome(nome)){
        std::cout << "O nome eh " << a.getNome() << '\n';
    }
    else{
        std::cout << "O nome \"" << nome << "\" eh invalido\n";
    }

    std::cout << "Digite o nome para teste (para terminar o programa, digite '0')\n";      //para mais testes
    std::getline(std::cin, nome);

    while(nome.compare("0")){

        if(a.setNome(nome)){
            std::cout << "O nome eh: " << a.getNome() << '\n';
        }
        else{
            std::cout << "O nome inserido \"" << nome << "\" eh invalida!\n";
        }

        std::cout << "Digite o nome para teste (para terminar o programa, digite '0')\n";
        std::getline(std::cin, nome);
    }

    return 0;
}
