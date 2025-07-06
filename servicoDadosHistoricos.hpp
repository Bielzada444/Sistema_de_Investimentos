#ifndef SERVICODADOSHISTORICOS_HPP_INCLUDED
#define SERVICODADOSHISTORICOS_HPP_INCLUDED

#include "Dominios.hpp"
#include <string>
#include <utility>
#include "sqlite3.h"

///
/// @file servicoDadosHistoricos.hpp
/// @brief Serviço de gestão de dados históricos de ativos financeiros
/// @details
/// Responsável por operações com dados históricos de mercado, incluindo:
/// - Importação de dados de fontes externas
/// - Consulta de informações históricas
/// - Verificação de existência de ativos
///
/// Utiliza SQLite como mecanismo de persistência com índices otimizados
/// para consultas frequentes por código de negociação.
///
class ServicoDadosHistoricos {
private:
    sqlite3 *db;
    void conectar();
    void desconectar();
    void criarTabela();
    void criarIndice();

public:
    ///
    /// @brief Inicializa o serviço e prepara a estrutura de dados
    /// @throw std::runtime_error Se falhar na inicialização do banco
    /// @note Cria tabelas e índices necessários durante a construção
    ///
    ServicoDadosHistoricos();

    ///
    /// @brief Finaliza o serviço e libera recursos
    /// @details Garante o fechamento seguro da conexão com o banco
    ///
    ~ServicoDadosHistoricos();

    ///
    /// @brief Importa dados históricos de arquivo texto
    /// @param caminho Caminho completo do arquivo .txt a ser importado
    /// @return true se importação for bem-sucedida
    /// @throw std::runtime_error Se:
    /// - Arquivo não existir ou estiver mal formatado
    /// - Falhar na persistência dos dados
    /// @note Formato esperado do arquivo:
    /// CODIGO;DATA;VALOR\n
    /// Ex: PETR4;20230101;42;
    ///
    bool importarTxt(const std::string &caminho);

    ///
    /// @brief Verifica a existência de um ativo no histórico
    /// @param codigoNegociacao Código de negociação do ativo (ex: PETR4)
    /// @return true se o ativo existir no banco de dados
    /// @throw std::runtime_error Se falhar na consulta ao banco
    ///
    bool ativoExiste(const std::string &codigoNegociacao);

    ///
    /// @brief Consulta o preço e data de um ativo específico
    /// @param codigo Código de negociação validado
    /// @return Par contendo:
    /// - first: Data do registro mais recente
    /// - second: Valor monetário correspondente
    /// @throw std::runtime_error Se:
    /// - Ativo não existir
    /// - Falhar na recuperação dos dados
    /// @note Retorna sempre o registro mais recente disponível
    ///
    std::pair<Data, Dinheiro> consultar(const CodigoNegociacao &codigo);
};

#endif // SERVICODADOSHISTORICOS_HPP_INCLUDED
