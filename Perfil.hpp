//
//Criado por Cleriston em 12/04/2025
//Matricula: 232001433

/// @file Perfil.hpp
/// @brief Definição da classe Perfil para representar tipos de perfil de investimento.


#ifndef PERFIL_HPP
#define PERFIL_HPP

#include <string>
#include "DominioException.hpp"


/// @class Perfil
/// @brief Classe responsável por armazenar e validar um perfil de investimento.
/// @details
/// O perfil de investimento define a tolerância ao risco do investidor.
/// Esta classe permite armazenar apenas valores válidos, garantindo que o perfil seja sempre um dos três aceitos:
/// - "Conservador": Preferência por investimentos de baixo risco e alta segurança.
/// - "Moderado": Equilíbrio entre segurança e potencial de retorno.
/// - "Agressivo": Disposição a correr mais riscos para obter maiores retornos.

class Perfil {
    private:
        std::string tipoPerfil;
        void validarPerfil(const std::string& tipoPerfil);

    public:
        /// @brief Define e armazena o perfil de investimento após validação.
        /// O perfil é validado antes do armazenamento para garantir que seja um dos três valores permitidos.
        /// Se o perfil for inválido, uma exceção será lançada impedindo seu armazenamento.
        /// @param tipoPerfil String contendo um dos perfis aceitos ("Conservador", "Moderado" ou "Agressivo").
        /// @throw DominioException Se o perfil não corresponder a um dos valores permitidos.

        void setPerfil(const std::string& tipoPerfil);
        /// @brief Obtém o perfil de investimento armazenado.
        /// Retorna o perfil atualmente armazenado na classe, garantindo que seja um valor válido.
        /// Se nenhum perfil foi definido corretamente, pode retornar uma string vazia.
        /// @return String com o perfil de investimento ("Conservador", "Moderado" ou "Agressivo"), ou uma string vazia caso não tenha sido definido corretamente.

        std::string getPerfil() const {
            return tipoPerfil;
        };
};

#endif // PERFIL_HPP
