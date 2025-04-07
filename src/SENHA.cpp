#include "SENHA.h"
#include <string>
#include <cctype>

bool Senha::validaSenha(std::string senha){
    int i, j;
    bool numero, maiuscula, minuscula, caractereEspecial;                               //variaveis para conferir se a senha inserida possui todos os caracteres necessarios
    numero = maiuscula = minuscula = caractereEspecial = false;                         //inicializacao das variaveis como falsas

    if((senha.length() > CARACTERES)||(senha.length() < CARACTERES)) return false;      //confere se a senha possui 6 caracteres

    for(i = 0; i < CARACTERES; i++){                                                    //iteracoes para conferir caracter por caracter
        if(isupper(senha[i])) maiuscula = true;                                         //se ha letra maiucula, a variavel eh verdadeira
        if(islower(senha[i])) minuscula = true;                                         //se ha letra minuscula, a variavel eh verdadeira
        if(isdigit(senha[i])) numero = true;                                            //se ha numero, a variavel eh verdadeira
        if((senha[i] == '#')||(senha[i] == '$')||(senha[i] == '%')||(senha[i] == '&')) caractereEspecial = true;        //se ha um dos caracteres especiais previstos, a variavel eh verdadeira

        for(j = 0; j < i; j++){                                                         //iteracoes para comparar com os outros caracteres
            if(senha[i] == senha[j]) return false;                                      //se ha dois caracteres iguais, a senha eh invalida
        }
    }

    if(!maiuscula || !minuscula || !numero || !caractereEspecial) return false;         //se algum dos ccaracteres exigidos nao aparecem, a senha eh invalida

    return true;                                                                        //a senha cumpre todos os requisitos e eh valida
}

bool Senha::setSenha(std::string senha){
    if(!Senha::validaSenha(senha)) return false;                                        //se a senha for invalida, retorna falso
    this->senha = senha;                                                                //se a senha for valida, atribui a string a variavel do objeto senha

    return true;
}
