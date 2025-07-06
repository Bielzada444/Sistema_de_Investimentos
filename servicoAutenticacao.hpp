//
// Created by Henrique on 22/06/2025.
//

#ifndef SERVICOAUTENTICACAO_HPP_INCLUDED
#define SERVICOAUTENTICACAO_HPP_INCLUDED

#include "interfaces.hpp"
#include "sqlite3.h"
#include <string>
#include <iostream>

///
/// @file servicoAutenticacao.hpp
/// @brief Implementação concreta do serviço de autenticação
/// @details
/// Classe que implementa a interface ILNAutenticacao, responsável por:
/// - Autenticação de usuários via CPF/senha
/// - Registro de novas contas com validação
/// - Persistência em banco de dados SQLite3
///
class ServicoAutenticacao : public ILNAutenticacao {
private:
    sqlite3 *db = nullptr;
    void conectar();
    void desconectar();
    void criarTabelaUsuarios();

public:
    ///
    /// @brief Inicializa o serviço e conecta ao banco de dados
    /// @throw std::runtime_error Se falhar na conexão ou criação da tabela
    ///
    ServicoAutenticacao();

    ///
    /// @brief Encerra a conexão com o banco de dados
    ///
    ~ServicoAutenticacao();

    ///
    /// @brief Autentica um usuário no sistema
    /// @param cpf CPF válido do usuário
    /// @param senha Senha válida do usuário
    /// @return true se as credenciais forem válidas
    /// @throw std::runtime_error Em erros de banco de dados
    /// @note Compara hashes de senha (não armazena em texto claro)
    ///
    bool autenticar(const CPF &cpf, const Senha &senha) override;

    ///
    /// @brief Registra um novo usuário no sistema
    /// @param cpf CPF válido do novo usuário
    /// @param senha Senha válida (será hasheada)
    /// @param nome Nome completo válido
    /// @throw std::runtime_error Se CPF já existir ou em falhas no banco
    ///
    void registrar(const CPF &cpf, const Senha &senha, const Nome &nome) override;
};

#endif // SERVICOAUTENTICACAO_HPP_INCLUDED
