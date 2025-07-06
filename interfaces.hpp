//
// Created by Henrique on 22/06/2025.
//

#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "Entidades.hpp"
#include <list>
using std::list;

///
/// @file interfaces.hpp
/// @brief Declaração das interfaces do sistema
/// @details
/// Define os contratos entre as camadas de:
/// - Lógica de Negócio (LN)
/// - Apresentação (IU)
/// Organizado por módulos funcionais (Conta, Carteira, Ordem, Autenticação)
/// @note Todas as interfaces são classes abstratas com métodos puramente virtuais
///

// ======================================
// INTERFACES DA CAMADA DE LÓGICA (ILN)
// ======================================

///
/// @brief Interface de serviços para gestão de contas
/// @details Operações básicas CRUD para entidades Conta
///
class ILNConta {
public:
    ///
    /// @brief Cria uma nova conta
    /// @param conta Objeto Conta válido e completo
    /// @return true se criada com sucesso, false caso contrário
    ///
    virtual bool criar(const Conta &conta) = 0;

    ///
    /// @brief Recupera os dados de uma conta
    /// @param cpf CPF da conta a ser recuperada
    /// @return Objeto Conta completo
    /// @throw std::runtime_error Se a conta não existir
    ///
    virtual Conta ler(const CPF &cpf) = 0;

    ///
    /// @brief Atualiza os dados de uma conta
    /// @param conta Objeto Conta com dados atualizados
    /// @return true se atualizada com sucesso
    ///
    virtual bool editar(const Conta &conta) = 0;

    ///
    /// @brief Remove uma conta do sistema
    /// @param cpf CPF da conta a ser removida
    /// @return true se removida com sucesso
    /// @note Deve validar relacionamentos antes de excluir
    ///
    virtual bool excluir(const CPF &cpf) = 0;

    virtual ~ILNConta() {}
};

///
/// @brief Interface de serviços para gestão de carteiras
/// @details Operações básicas CRUD para entidades Carteira
///
class ILNCarteira {
public:
    ///
    /// @brief Cria uma nova carteira
    /// @param carteira Objeto Carteira válido
    /// @return true se criada com sucesso
    ///
    virtual bool criar(const Carteira &carteira) = 0;

    ///
    /// @brief Recupera dados de uma carteira
    /// @param codigo Código único da carteira
    /// @return Objeto Carteira completo
    ///
    virtual Carteira ler(const Codigo &codigo) = 0;

    ///
    /// @brief Atualiza dados de uma carteira
    /// @param carteira Objeto com dados atualizados
    /// @return true se atualizada com sucesso
    ///
    virtual bool editar(const Carteira &carteira) = 0;

    ///
    /// @brief Remove uma carteira do sistema
    /// @param codigo Código da carteira a remover
    /// @return true se removida com sucesso
    ///
    virtual bool excluir(const Codigo &codigo) = 0;

    ///
    /// @brief Lista carteiras associadas a uma conta
    /// @param cpf CPF do titular das carteiras
    /// @return Lista de objetos Carteira
    ///
    virtual list<Carteira> listarPorConta(const CPF &cpf) = 0;

    virtual ~ILNCarteira() {}
};

///
/// @brief Interface de serviços para gestão de ordens
/// @details Operações para criação e gestão de ordens de investimento
///
class ILNOrdem {
public:
    ///
    /// @brief Registra uma nova ordem de investimento
    /// @param cpf CPF do solicitante
    /// @param codigoCarteira Código da carteira destino
    /// @param ordem Dados completos da ordem
    /// @return true se criada com sucesso
    /// @throw std::invalid_argument Se dados forem inconsistentes
    ///
    virtual bool criar(const CPF &cpf, const Codigo &codigoCarteira, const Ordem &ordem) = 0;

    ///
    /// @brief Recupera dados de uma ordem específica
    /// @param codigo Código único da ordem
    /// @return Objeto Ordem completo
    ///
    virtual Ordem ler(const Codigo &codigo) = 0;

    ///
    /// @brief Cancela/remove uma ordem do sistema
    /// @param codigo Código da ordem a cancelar
    /// @return true se cancelada com sucesso
    ///
    virtual bool excluir(const Codigo &codigo) = 0;

    ///
    /// @brief Lista ordens associadas a uma carteira
    /// @param cpf CPF do titular para validação
    /// @param codigoCarteira Código da carteira
    /// @return Lista de objetos Ordem
    /// @details
    /// Retorna lista ordenada por:
    /// 1. Status (pendentes primeiro)
    /// 2. Data (mais recentes primeiro)
    ///
    virtual std::list<Ordem> listarPorCarteira(const CPF &cpf, const Codigo &codigoCarteira) = 0;

    virtual ~ILNOrdem() {}
};

///
/// @brief Interface de serviços de autenticação
/// @details Gerencia credenciais e acesso ao sistema
///
class ILNAutenticacao {
public:
    ///
    /// @brief Valida credenciais de usuário
    /// @param cpf CPF do usuário
    /// @param senha Senha de acesso
    /// @return true se credenciais forem válidas
    ///
    virtual bool autenticar(const CPF &cpf, const Senha &senha) = 0;

    ///
    /// @brief Registra novo usuário no sistema
    /// @param cpf CPF do novo usuário
    /// @param senha Senha de acesso
    /// @param nome Nome completo
    /// @throw std::invalid_argument Se CPF já existir
    ///
    virtual void registrar(const CPF &cpf, const Senha &senha, const Nome &nome) = 0;

    virtual ~ILNAutenticacao() {}
};

// ======================================
// INTERFACES DA CAMADA DE UI (IU)
// ======================================

///
/// @brief Interface UI para gestão de contas
/// @details Define o contrato para a camada de apresentação
///
class IUConta {
public:
    virtual void criar() = 0;
    virtual void editar() = 0;
    virtual void excluir() = 0;
    virtual void ler() = 0;

    ///
    /// @brief Controla o fluxo do menu de conta
    /// @param cpf CPF do usuário autenticado
    ///
    virtual void menu(const CPF& cpf) = 0;

    virtual ~IUConta() {}
};

///
/// @brief Interface UI para gestão de carteiras
///
class IUCarteira {
public:
    virtual void criar() = 0;
    virtual void editar() = 0;
    virtual void excluir() = 0;
    virtual void ler() = 0;

    ///
    /// @brief Exibe lista de carteiras
    /// @details Mostra formato tabular com:
    /// - Código
    /// - Nome
    /// - Perfil
    /// - Saldo atual
    ///
    virtual void listar() = 0;

    virtual ~IUCarteira() {}
};

///
/// @brief Interface UI para gestão de ordens
///
class IUOrdem {
public:
    virtual void criar() = 0;
    virtual void excluir() = 0;
    virtual void ler() = 0;

    ///
    /// @brief Lista ordens por carteira
    /// @details Mostra visualização filtrada e paginada
    ///
    virtual void listarPorCarteira() = 0;

    virtual ~IUOrdem() {}
};

///
/// @brief Interface UI para autenticação
///
class IUAutenticacao {
public:
    ///
    /// @brief Executa fluxo de autenticação
    /// @return true se autenticado com sucesso
    ///
    virtual bool autenticar() = 0;

    ///
    /// @brief Configura o serviço de autenticação
    /// @param cntr Ponteiro para implementação de ILNAutenticacao
    ///
    virtual void setCntr(ILNAutenticacao *cntr) = 0;

    virtual ~IUAutenticacao() {}
};

#endif // INTERFACES_HPP_INCLUDED
