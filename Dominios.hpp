/// @file Dominios.hpp
/// @brief Cabeçalho unificado para inclusão de todas as classes de domínio do sistema.
/// @details Agrupa todas as classes de domínio necessárias para o sistema, garantindo acesso centralizado às regras de validação\n
/// e estruturas de dados específicas. Ideal para simplificar includes em outros módulos do projeto.
///
/// ### Domínios Incluídos:
/// - **Codigo**: Identificador numérico único (5 dígitos, ex: 12345)\n
/// - **CodigoNegociacao**: Código de negociação padrão B3 (4 letras + 1 número, ex: PETR4)\n
/// - **Cpf**: Validador de CPF (formato XXXXXXXXXXX)\n
/// - **Data**: Manipulação de datas (formato AAAAMMDD)\n
/// - **Dinheiro**: Valores monetários (ex: R$ 1,234.56)\n
/// - **Nome**: Nomes de usuário/entidades (1-20 caracteres alfabéticos)\n
/// - **Perfil**: Perfis de risco (Agressivo, Moderado, Conservador)\n
/// - **Quantidade**: Quantidades de ativos (100-50000 unidades)\n
/// - **Senha**: Senhas seguras (6 caracteres com mix case e símbolos)\n
///
/// @note Inclui DominioException para tratamento de erros específicos (exceções lançadas durante validações).
#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include "Codigo.hpp"
#include "CodigoNegociacao.hpp"
#include "Cpf.hpp"
#include "Data.hpp"
#include "Dinheiro.hpp"
#include "DominioException.hpp"
#include "Nome.hpp"
#include "Perfil.hpp"
#include "Quantidade.hpp"
#include "Senha.hpp"

#endif // DOMINIOS_HPP_INCLUDED
