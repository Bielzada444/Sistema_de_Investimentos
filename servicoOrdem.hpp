#ifndef SERVICOORDEM_HPP_INCLUDED
#define SERVICOORDEM_HPP_INCLUDED

#include "interfaces.hpp"
#include "Dominios.hpp"
#include "Ordem.hpp"
#include <list>
#include "sqlite3.h"

///
/// @file servicoOrdem.hpp
/// @brief Serviço de gestão de ordens de investimento
/// @details
/// Implementação concreta da interface ILNOrdem para operações com ordens:
/// - Registro de novas ordens (compra/venda)
/// - Consulta de ordens existentes
/// - Cancelamento de ordens
/// - Listagem de ordens por carteira
///
/// Persistência em banco de dados SQLite com garantias de integridade
///
class ServicoOrdem : public ILNOrdem {
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
    ServicoOrdem();

    ///
    /// @brief Finaliza o serviço e libera recursos do banco de dados
    ///
    ~ServicoOrdem();

    ///
    /// @brief Registra uma nova ordem no sistema
    /// @param cpf CPF do investidor (validado)
    /// @param codigoCarteira Código da carteira destino (validado)
    /// @param ordem Objeto Ordem completo e validado
    /// @return true se registrada com sucesso
    /// @throw DominioException Se:
    /// - Carteira não existir
    /// - Limites de investimento forem excedidos
    /// - Falha na persistência
    ///
    bool criar(const CPF &cpf, const Codigo &codigoCarteira, const Ordem &ordem) override;

    ///
    /// @brief Recupera os dados completos de uma ordem
    /// @param codigo Código único da ordem
    /// @return Objeto Ordem com todos atributos
    /// @throw DominioException Se:
    /// - Ordem não existir
    /// - Falha na consulta
    ///
    Ordem ler(const Codigo &codigo) override;

    ///
    /// @brief Cancela uma ordem existente
    /// @param codigo Código da ordem a cancelar
    /// @return true se cancelada com sucesso
    /// @throw DominioException Se:
    /// - Ordem não existir
    /// - Ordem já processada
    /// - Falha na exclusão
    ///
    bool excluir(const Codigo &codigo) override;

    ///
    /// @brief Lista ordens associadas a uma carteira
    /// @param cpf CPF do titular (para validação)
    /// @param codigoCarteira Código da carteira
    /// @return Lista de ordens ordenadas por:
    ///         1. Status (pendentes primeiro)
    ///         2. Data (mais recentes primeiro)
    /// @throw DominioException Se:
    /// - Carteira não existir
    /// - Falha na consulta
    ///
    std::list<Ordem> listarPorCarteira(const CPF &cpf, const Codigo &codigoCarteira) override;
};

#endif // SERVICOORDEM_HPP_INCLUDED
