//
//Criado por Henrique em 22/04/2025
//Matricula: 241020840

/// @file TUQuantidade.hpp
/// @brief Teste de unidade para a classe Quantidade (Domínio).
/// @details
/// Valida:\n
/// - Quantidades inteiras entre 1 e 1,000,000 unidades;\n
/// - Rejeição de valores zero, negativos ou acima do limite;\n
/// - Conversão correta de strings para valores numéricos.


#ifndef TUQUANTIDADE_HPP
#define TUQUANTIDADE_HPP
#include "Quantidade.hpp"
#include <string>

///
/// @class TUQuantidade
/// @brief Classe de teste de unidade para o domínio Quantidade.
/// @details
/// Valida:\n
/// - Quantidades inteiras entre 1 e 1,000,000 unidades;\n
/// - Rejeição de valores zero, negativos ou acima do limite;\n
/// - Conversão correta de strings para valores numéricos.
class TUQuantidade {
    private:
        static std::string QUANTIDADE_VALIDA;
        static std::string QUANTIDADE_INVALIDA;
        Quantidade* quantidade;
        int estadoQuantidade;

        void setUpQuantidade();
        void tearDownQuantidade();
        void testarCenarioValidoQuantidade();
        void testarCenarioInvalidoQuantidade();

    public:
        /// @brief Código de retorno para teste bem-sucedido
        const static int SUCESSO = 0;

        /// @brief Código de retorno para teste falho
        const static int FALHA = -1;

        /// @brief Executa todos os testes do domínio Quantidade
        /// @return SUCESSO se todos os testes passarem, FALHA caso contrário
        int runQuantidade();
};

#endif
