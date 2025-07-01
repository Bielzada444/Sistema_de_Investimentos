//
// Criado por Henrique em 07/05/2025
// Matricula: 241020840

/// @file Ordem.hpp
/// @brief Sistema de Ordens Financeiras
/// @details Esta classe representa uma ordem de compra/venda no sistema de investimentos.
/// Ela armazena todas as informações necessárias para realizar operações com segurança.

#ifndef ORDEM_HPP
#define ORDEM_HPP

#include "Dominios.hpp"

/// @class Ordem
/// @brief  Esta classe representa a ordem de compra/venda de ativos no sistema de investimentos.
/// @details Garante integridade dos dados através de domínios especializados que validam:
/// - Formato de códigos
/// - Datas cronológicas
/// - Valores monetários
/// - Quantidades negociáveis\n
/// Integrado com exceções específicas (DominioException) para tratamento de erros.
class Ordem {
    private:
        Codigo codigo;
        CodigoNegociacao codigoNegociacao;
        Data data;
        Dinheiro preco;
        Quantidade quantidade;

    public:
        /// @brief Como registrar o ID da ordem:
        /// - Deve ser um código de 5 números (ex: "12345")
        /// - O sistema verifica automaticamente se é válido
        void setCodigo(const Codigo& novoCodigo);

        /// @brief Como registrar o ativo financeiro:
        /// - Use o código do ativo (ex: "VALE3" para ações da Vale)
        /// - Pode conter até 12 letras/números (ex: "OUROPRT", "DOLAR")
        void setCodigoNegociacao(const CodigoNegociacao& novoCodigoNegociacao);

        /// @brief Como definir a data da operação:
        /// - Formato: AAAAMMDD (ex: "20240507" para 07/05/2024)
        /// - O sistema bloqueia datas inválidas ou futuras
        void setData(const Data& novaData);

        /// @brief Como informar o preço:
        /// - Valor unitário (ex: R$ 72.50 por ação)
        /// - Aceita de R$ 0.01 até R$ 1,000,000.00
        /// - O sistema ajusta para 2 casas decimais automaticamente
        void setDinheiro(const Dinheiro& novoPreco);

        /// @brief Como informar a quantidade:
        /// - Número inteiro de unidades (ex: 100 ações)
        /// - Mínimo: 1 | Máximo: 1,000,000
        void setQuantidade(const Quantidade& novaQuantidade);

        /// @brief Consultar o ID da ordem
        /// @return Código de 5 dígitos (ex: "54321")
        Codigo getCodigo() const {
            return codigo;
        }

        /// @brief Consultar o ativo negociado
        /// @return Código do ativo (ex: "PETR4")
        CodigoNegociacao getCodigoNegociacao() const {
            return codigoNegociacao;
        }

        /// @brief Consultar a data da ordem
        /// @return Data no formato AAAAMMDD (ex: "20240507")
        Data getData() const {
            return data;
        }

        /// @brief Consultar o preço unitário
        /// @return Valor com 2 casas decimais (ex: R$ 150.99)
        Dinheiro getDinheiro() const {
            return preco;
        }

        /// @brief Consultar a quantidade
        /// @return Número inteiro de unidades (ex: 200)
        Quantidade getQuantidade() const {
            return quantidade;
        }
};
#endif //ORDEM_HPP
