//
//Criado por Cleriston em 26/04/2025
//Matricula: 232001433

/// @file TUPerfil.hpp
/// @brief Teste de unidade para a classe Perfil.
/// @details
/// Implementa testes para validar o domínio Perfil, verificando:\n
/// - Aceitação de perfis válidos (Conservador/Moderado/Agressivo)\n
/// - Rejeição de valores fora do conjunto permitido\n
/// - Consistência entre métodos set() e get()

#ifndef TUPERFIL_HPP
#define TUPERFIL_HPP

#include "Perfil.hpp"
#include <string>

/// @class TUPerfil
/// @brief Classe de teste de unidade para o domínio Perfil.
/// @details
/// Implementa testes para validar o domínio Perfil, verificando:\n
/// - Aceitação de perfis válidos (Conservador/Moderado/Agressivo)\n
/// - Rejeição de valores fora do conjunto permitido\n
/// - Consistência entre métodos set() e get()

class TUPerfil {
    private:
        const static std::string PERFIL_VALIDO;
        const static std::string PERFIL_INVALIDO;
        Perfil* perfil;
        int estadoPerfil;

        void setUpPerfil();
        void tearDownPerfil();
        void testarCenarioValidoPerfil();
        void testarCenarioInvalidoPerfil();

    public:
        /// @brief Código de retorno para teste bem-sucedido
        const static int SUCESSO = 0;

        /// @brief Código de retorno para teste falho
        const static int FALHA = -1;

        /// @brief Executa todos os testes do domínio Perfil
        /// @return SUCESSO se todos os testes passarem, FALHA caso contrário
        int runPerfil();
};

#endif // TUPERFIL_HPP
