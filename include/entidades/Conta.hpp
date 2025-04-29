#ifndef CONTA_HPP
#define CONTA_HPP

#include "dominios.hpp"


class Conta{
    private:
        CPF cpf;
        Nome nome;
        Senha senha;
    
    public:
        void  const setCpf(CPF& cpf);
        void const setNome(Nome& nome);
        void const setSenha(Senha& senha);
        
        inline CPF getCpf() const {
            return cpf.getCpf();
        }
        inline Nome getNome() const {
            return nome;
        }
        inline Senha getSenha() const{
            return senha
        }
};


#endif //CONTA_HPP
