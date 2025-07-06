//
// Created by Henrique on 27/06/2025.
//

#ifndef SERVICOCONTA_HPP_INCLUDED
#define SERVICOCONTA_HPP_INCLUDED

#include "interfaces.hpp"
#include "DominioException.hpp"
#include "sqlite3.h"

///
/// @file servicoConta.hpp
/// @brief Serviço de gestão de contas de usuário
/// @details
/// Implementação concreta da interface ILNConta para operações de:
/// - Criação de novas contas
/// - Consulta de dados cadastrais
/// - Atualização de informações
/// - Exclusão de contas
///
/// Utiliza SQLite3 como mecanismo de persistência com garantias ACID
///
class ServicoConta : public ILNConta {
private:
    sqlite3 *db;
    void conectar();
    void desconectar();
    void criarTabela();

public:
    ///
    /// @brief Inicializa o serviço e conexão com o banco de dados
    /// @throw DominioException Se falhar na conexão ou criação de tabelas
    ///
    ServicoConta();

    ///
    /// @brief Finaliza o serviço e libera recursos do banco de dados
    ///
    ~ServicoConta();

    ///
    /// @brief Cadastra uma nova conta no sistema
    /// @param conta Objeto Conta completo e validado
    /// @return true se cadastrada com sucesso
    /// @throw DominioException Se:
    /// - CPF já cadastrado
    /// - Falha na persistência dos dados
    /// @note Realiza validação de unicidade de CPF
    ///
    bool criar(const Conta &conta) override;

    ///
    /// @brief Recupera os dados de uma conta existente
    /// @param cpf CPF da conta a ser consultada
    /// @return Objeto Conta completo
    /// @throw DominioException Se:
    /// - Conta não encontrada
    /// - Falha na consulta ao banco
    ///
    Conta ler(const CPF &cpf) override;

    ///
    /// @brief Atualiza os dados de uma conta existente
    /// @param conta Objeto Conta com dados atualizados
    /// @return true se atualizada com sucesso
    /// @throw DominioException Se:
    /// - Conta não encontrada
    /// - Falha na atualização
    ///
    bool editar(const Conta &conta) override;

    ///
    /// @brief Remove uma conta do sistema
    /// @param cpf CPF da conta a ser removida
    /// @return true se removida com sucesso
    /// @throw DominioException Se:
    /// - Conta não encontrada
    /// - Existirem carteiras vinculadas
    /// - Falha na exclusão
    ///
    bool excluir(const CPF &cpf) override;
};

#endif // SERVICOCONTA_HPP_INCLUDED
