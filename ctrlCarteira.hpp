//
// Created by Henrique on 29/06/2025.
//

#ifndef CTRLCARTEIRA_HPP_INCLUDED
#define CTRLCARTEIRA_HPP_INCLUDED

#include "servicoCarteira.hpp"

///
/// @file ctrlCarteira.hpp
/// @brief Interface da controladora de carteiras de investimento
/// @details
/// Responsável por gerenciar as operações relacionadas a carteiras de investimento,
/// incluindo criação, listagem, edição e exclusão. Atua como intermediário entre
/// a interface do usuário e o serviço de carteiras.
///

class CtrlCarteira {
private:
    ServicoCarteira *servico;

public:
    ///
    /// @brief Construtor da controladora de carteiras
    /// @param servico Ponteiro para o serviço de carteira (não pode ser nulo)
    /// @pre O parâmetro servico deve ser uma instância válida de ServicoCarteira
    ///
    explicit CtrlCarteira(ServicoCarteira *servico);

    ///
    /// @brief Exibe e gerencia o menu de operações com carteiras
    /// @param cpf CPF do usuário associado às carteiras
    /// @details
    /// Apresenta um menu interativo com as seguintes opções:
    /// 1. Criar nova carteira
    /// 2. Listar carteiras existentes
    /// 3. Editar carteira
    /// 4. Excluir carteira
    /// 0. Voltar
    ///
    void menu(const CPF &cpf);
};

#endif // CTRLCARTEIRA_HPP_INCLUDED
