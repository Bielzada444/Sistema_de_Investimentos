//
// Criado por Gabriel em 06/05/2025
// Matricula: 241038942

/// @file Carteira.hpp
/// @brief Entidade (um conjunto que reune algumas das classes já implementadas) que agrupa as classes "Codigo", "Nome" e "Perfil". Representa os dados monetários do usuário.
/// @details
/// Componentes (classes já implementadas anteriormente):
/// - Código: é um identificador característico único de cada usuário composto por cinco algarismos (ex: "12345")
/// - Nome: Nome do usuário definido na classe "Nome" (ex: "João Silva")
/// - Perfil: Define estratégia de investimento do usuário (Conservador/Moderado/Agressivo)

#ifndef CARTEIRA_HPP_INCLUDED
#define CARTEIRA_HPP_INCLUDED

#include "Dominios.hpp"
/// @class Carteira
/// @brief  Esta classe representa a carteira que possui ativos no sistema de investimentos.
class Carteira {
    private:
        Codigo codigo;
        Nome nome;
        Perfil perfil;

    public:
        /// @brief Define o código (ex: "12345") da carteira
        /// @param novoCodigo Objeto do domínio Codigo já validado seguindo os parâmetros definidos na classe Codigo
        void setCodigo(const Codigo& novoCodigo);

        /// @brief Define o nome associado à carteira
        /// @param novoNome Objeto do domínio Nome já validado seguindo os parâmetros definidos na classe Nome
        void setNome(const Nome& novoNome);

        /// @brief Define o perfil de investimento
        /// @param novoPerfil Objeto do domínio Perfil já validado seguindo os parâmetros definidos na classe Perfil
        void setPerfil(const Perfil& novoPerfil);

        /// @brief Retorna o código definido na carteira
        /// @return Retorna um objeto do tipo Codigo
        Codigo getCodigo() const {
            return codigo;
        }

        /// @brief Retorna o nome associado à carteira
        /// @return Retorna um objeto do tipo Nome
        Nome getNome() const{
            return nome;
        }

        /// @brief Retorna o perfil de investimento associado à carteira
        /// @return Retorna um objeto do tipo Perfil
        Perfil getPerfil() const{
            return perfil;
        }
};

#endif // CARTEIRA_HPP_INCLUDED
