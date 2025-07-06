//
// Created by Henrique on 29/06/2025.
//

#ifndef SERVICOCARTEIRA_HPP_INCLUDED
#define SERVICOCARTEIRA_HPP_INCLUDED

#include "interfaces.hpp"
#include "DominioException.hpp"
#include "sqlite3.h"

///
/// @file servicoCarteira.hpp
/// @brief Serviço de gestão de carteiras de investimento
/// @details
/// Implementa as operações de CRUD para carteiras de investimento,
/// incluindo funcionalidades específicas como cálculo de saldo.
/// Utiliza SQLite como mecanismo de persistência de dados.
///
class ServicoCarteira {
private:
    sqlite3 *db;
    void conectar();
    void desconectar();
    void criarTabela();

public:
    ///
    /// @brief Construtor que inicializa a conexão com o banco de dados
    /// @throw DominioException Se falhar na conexão ou criação de tabelas
    ///
    ServicoCarteira();

    ///
    /// @brief Destrutor que encerra a conexão com o banco de dados
    ///
    ~ServicoCarteira();

    ///
    /// @brief Cria uma nova carteira para um usuário
    /// @param cpf CPF do titular da carteira (devidamente validado)
    /// @param carteira Objeto Carteira com dados validados
    /// @return true se criada com sucesso, false caso contrário
    /// @throw DominioException Se:
    /// - O código da carteira já existir
    /// - Falhar na persistência dos dados
    ///
    bool criarCarteiraPara(const CPF &cpf, const Carteira &carteira);

    ///
    /// @brief Lista todas as carteiras de um usuário
    /// @param cpf CPF do titular das carteiras
    /// @return Lista de objetos Carteira ordenados por código
    /// @throw DominioException Se falhar na consulta ao banco
    ///
    std::list<Carteira> listarCarteirasPor(const CPF &cpf);

    ///
    /// @brief Recupera os dados completos de uma carteira
    /// @param codigo Código único da carteira
    /// @return Objeto Carteira com todos os atributos
    /// @throw DominioException Se a carteira não existir
    ///
    Carteira ler(const Codigo &codigo);

    ///
    /// @brief Atualiza os dados de uma carteira existente
    /// @param carteira Objeto Carteira com dados atualizados
    /// @return true se editada com sucesso, false caso contrário
    /// @throw DominioException Se:
    /// - A carteira não existir
    /// - Falhar na atualização
    ///
    bool editar(const Carteira &carteira);

    ///
    /// @brief Remove uma carteira do sistema
    /// @param codigo Código da carteira a ser removida
    /// @return true se excluída com sucesso, false caso contrário
    /// @throw DominioException Se:
    /// - A carteira não existir
    /// - Houver ordens vinculadas à carteira
    ///
    bool excluir(const Codigo &codigo);

    ///
    /// @brief Calcula o saldo total de uma carteira
    /// @param codigoCarteira Código da carteira
    /// @return Valor double com o saldo atual
    /// @throw DominioException Se:
    /// - A carteira não existir
    /// - Falhar no cálculo do saldo
    /// @note Considera todas as transações associadas à carteira
    ///
    double obterSaldoCarteira(const Codigo &codigoCarteira);
};

#endif // SERVICOCARTEIRA_HPP_INCLUDED
