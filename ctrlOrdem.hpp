#ifndef CTRLORDEM_HPP_INCLUDED
#define CTRLORDEM_HPP_INCLUDED

#include "interfaces.hpp"
#include "servicoOrdem.hpp"
#include "servicoCarteira.hpp"
#include "servicoDadosHistoricos.hpp"
#include "Dominios.hpp"

///
/// @file ctrlOrdem.hpp
/// @brief Interface da controladora de ordens de investimento
/// @details
/// Responsável por gerenciar todo o ciclo de vida das ordens de investimento,
/// incluindo criação, exclusão, consulta e listagem. Coordena a integração entre:
/// - Serviço de ordens (ServicoOrdem)
/// - Serviço de carteiras (ServicoCarteira)
/// - Serviço de dados históricos (ServicoDadosHistoricos)
/// 
/// Implementa a interface IUOrdem para garantir o contrato com a camada de apresentação.
///

class CtrlOrdem : public IUOrdem {
private:
    ServicoOrdem *servicoOrdem = nullptr;          ///< Serviço de gestão de ordens (injetado)
    ServicoCarteira *servicoCarteira = nullptr;    ///< Serviço de carteiras (injetado)
    ServicoDadosHistoricos *servicoDados = nullptr;///< Serviço de dados históricos (injetado)
    CPF cpfLogado;                                 ///< CPF do usuário autenticado

public:
    ///
    /// @brief Configura o serviço de ordens
    /// @param servico Ponteiro para instância válida de ServicoOrdem
    /// @pre O parâmetro servico deve ser não-nulo e válido
    /// @post O serviço estará disponível para todas as operações de ordem
    ///
    void setServicoOrdem(ServicoOrdem *servico);

    ///
    /// @brief Configura o serviço de carteiras
    /// @param servico Ponteiro para instância válida de ServicoCarteira
    /// @pre O parâmetro servico deve ser não-nulo e válido
    /// @post O serviço estará disponível para consulta de carteiras
    ///
    void setServicoCarteira(ServicoCarteira *servico);

    ///
    /// @brief Configura o serviço de dados históricos
    /// @param servico Ponteiro para instância válida de ServicoDadosHistoricos
    /// @pre O parâmetro servico deve ser não-nulo e válido
    /// @post O serviço estará disponível para consulta de dados históricos
    ///
    void setServicoDados(ServicoDadosHistoricos *servico);

    ///
    /// @brief Define o CPF do usuário logado
    /// @param cpf Objeto CPF válido contendo a identificação do usuário
    /// @note Deve ser chamado antes de qualquer operação que requira identificação
    ///
    void setCpfLogado(const CPF &cpf);  

    ///
    /// @brief Exibe e gerencia o menu de operações com ordens
    /// @param cpf CPF do usuário autenticado (para validação adicional)
    /// @details
    /// Controla o fluxo completo do menu de ordens, incluindo:
    /// - Criação de novas ordens
    /// - Exclusão de ordens existentes
    /// - Consulta individual
    /// - Listagem por carteira
    /// - Integração com serviços relacionados
    ///
    void menu(const CPF &cpf);  

    ///
    /// @brief Cria uma nova ordem de investimento
    /// @override Implementação obrigatória de IUOrdem
    /// @throw std::invalid_argument Se dados da ordem forem inválidos
    /// @throw std::runtime_error Se falhar na comunicação com serviços
    /// @note Interage com o usuário via console para coleta de dados
    ///
    void criar() override;

    ///
    /// @brief Exclui uma ordem existente
    /// @override Implementação obrigatória de IUOrdem
    /// @throw std::runtime_error Se a ordem não existir ou falhar a exclusão
    /// @note Solicita confirmação do usuário antes da exclusão
    ///
    void excluir() override;

    ///
    /// @brief Consulta os detalhes de uma ordem específica
    /// @override Implementação obrigatória de IUOrdem
    /// @throw std::runtime_error Se a ordem não for encontrada
    /// @note Exibe informações completas incluindo dados da carteira associada
    ///
    void ler() override;

    ///
    /// @brief Lista todas as ordens associadas a uma carteira
    /// @override Implementação obrigatória de IUOrdem
    /// @details
    /// Exibe lista formatada contendo:
    /// - Código da ordem
    /// - Data e hora
    /// - Tipo (compra/venda)
    /// - Quantidade e valor
    /// - Status atual
    ///
    void listarPorCarteira() override;
};

#endif // CTRLORDEM_HPP_INCLUDED
