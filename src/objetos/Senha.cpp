//
// Criado por Nyvea em 08/04/2025.
// Matricula: 241040207

#include "senha.h"
#include <string>
#include <cctype>

bool Senha::validaSenha(std::string senha){
    int i, j;
    bool numero, maiuscula, minuscula, caractereEspecial;                               //variaveis para conferir se a senha inserida possui todos os caracteres necessarios
    numero = maiuscula = minuscula = caractereEspecial = false;                         //inicializacao das variaveis como falsas

    if((senha.length() > CARACTERES)||(senha.length() < CARACTERES)) return false;      //confere se a senha possui 6 caracteres

    for(i = 0; i < CARACTERES; i++){                                                    //iteracoes para conferir caracter por caracter
        if(isupper(senha[i])){                                                          //se ha letra maiucula, a variavel eh verdadeira
            maiuscula = true;
        }

        if(islower(senha[i])){                                                          //se ha letra minuscula, a variavel eh verdadeira
            minuscula = true;
        }

        if(isdigit(senha[i])){                                                          //se ha numero, a variavel eh verdadeira
            numero = true;
        }

        if((senha[i] == '#')||(senha[i] == '$')||(senha[i] == '%')||(senha[i] == '&')){ //se ha um dos caracteres especiais previstos, a variavel eh verdadeira
            caractereEspecial = true;
        }

        for(j = 0; j < i; j++){                                                         //iteracoes para comparar com os outros caracteres
            if(senha[i] == senha[j]){                                                   //se ha dois caracteres iguais, a senha eh invalida
                return false;
            }
        }
    }

    if(!maiuscula || !minuscula || !numero || !caractereEspecial){                      //se algum dos ccaracteres exigidos nao aparecem, a senha eh invalida
        return false;
    }

    return true;                                                                        //a senha cumpre todos os requisitos e eh valida
}

bool Senha::setSenha(std::string senha){
    if(!Senha::validaSenha(senha)){                                                     //se a senha for invalida, retorna falso
        return false;
    }

    this->senha = senha;                                                                //se a senha for valida, atribui a string a variavel do objeto senha

    return true;
}
