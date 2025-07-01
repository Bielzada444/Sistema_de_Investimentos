//
// Criado por Gabriel em 03/04/2025.
// Matricula: 241038942

/// @file Cpf.hpp
/// @brief Domínio que representa um Cadastro de Pessoa Física (CPF) válido.
/// @details
/// Armazena um CPF no formato brasileiro (XXXXXXXXXXX), validando:
/// 1) Formato sem pontos e hífen
/// 2) Dígitos verificadores
/// 3) Não aceita CPFs com todos os dígitos iguais (ex: 11111111111)
/// 4) Tamanho de 11 digitos

#ifndef CPF_HPP
#define CPF_HPP

#include <string>
#include <stdexcept>
#include "DominioException.hpp"

/// @class CPF
/// @brief Classe que representa um CPF (Cadastro de Pessoas Físicas) e realiza sua validação conforme as normas brasileiras.
/// @details Esta classe permite armazenar um CPF válido e verificar sua autenticidade por meio da análise dos dígitos verificadores e seu tamanho.
/// Armazena um CPF no formato brasileiro (XXXXXXXXXXX), validando:
/// 1) Formato sem pontos e hífen
/// 2) Dígitos verificadores
/// 3) Não aceita CPFs com todos os dígitos iguais (ex: 11111111111)
/// 4) Tamanho de 11 digitos
class CPF {
    private:
        std::string numeroCpf;
        void validar(const std::string& cpfInserido);
        bool validarDigitosVerificadores(const std::string& cpf);

    public:
        /// @brief Define o CPF após a validação completa do número.
        /// Este método verifica se o número do CPF passado é válido antes de armazená-lo.
        /// Caso o número seja inválido, uma exceção é lançada, impedindo o armazenamento de CPFs incorretos.
        /// @param novoCpf String contendo 11 dígitos numéricos sem pontuações ou espaços.
        /// @throw DominioException Se o formato ou os dígitos verificadores forem inválidos.
        void setCPF(const std::string& novoCpf);

        /// @brief Obtém o CPF armazenado.
        /// Retorna o CPF atualmente armazenado no objeto, garantindo que seja sempre um número válido.
        /// @return String contendo os 11 dígitos numéricos do CPF.
        inline std::string getCPF() const {
            return numeroCpf;
        }
};

#endif
