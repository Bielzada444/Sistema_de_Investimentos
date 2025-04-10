#include "nome.h"
#include <string>
#include <cctype>

bool Nome::validaNome(std::string nome){
    int i;

    if((nome.length() > MAXIMO)||(nome.length() < 1)){                          //confere se o nome ultrapassa o limite de caracteres ou eh menor que 1
        return false;                                                           //se sim, o nome eh invalido
    }

    for(i = 0; i < nome.length() - 1; i++){                                     //perpassa caracter por caracter
        if((nome[i] == ' ')&&(nome[i+1] == ' ')){                               //se houver dois espaços consecutivos, o nome eh invalido
            return false;
        }

        if(!isdigit(nome[i]) && !isupper(nome[i]) && !islower(nome[i]) && nome[i] != ' '){        //se o caracter nao for um numero e/ou nao for uma letra, o nome eh invalido
            return false;
        }
    }

    if(!isdigit(nome[i]) && !isupper(nome[i]) && !islower(nome[i]) && nome[i] != ' '){           //confere o ultimo digito, ja que na iteracao o ultimo digito nao eh conferido
        return false;
    }

    return true;
}

bool Nome::setNome(std::string nome){
    if(!Nome::validaNome(nome)){
        return false;
    }

    this->nome = nome;

    return true;
}
