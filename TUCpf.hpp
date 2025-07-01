//
// Criado por Gabriel em 15/04/2025.
// Matricula: 241038942

/// @file TUCpf.hpp
/// @brief Teste de unidade para a classe CPF (Domínio).
/// @details
/// Valida os seguintes cenários:
/// - CPFs no formato XXXXXXXXXXX com dígitos verificadores corretos
/// - Rejeiçăo de CPFs inválidos (dígitos iguais, formato incorreto)
/// - Armazenamento consistente (sem formataçăo após validaçăo)

#ifndef TUCPF_HPP
#define TUCPF_HPP
#include "Cpf.hpp" //inclui o header da classe CPF que vai ser testada
#include <string> //inclui header string padrao do C++

/// @class TUCpf
/// @brief Classe de teste de unidade para o domínio CPF.
/// @details Verifica se o domínio CPF aceita corretamente valores válidos e rejeita valores inválidos.
/// Testa a validação do domínio CPF, garantindo que os valores sejam corretamente armazenados e validados.
/// Os cenários incluem:
/// - CPF válido: no formato XXXXXXXXXXX com dígitos verificadores corretos.
/// - CPF inválido: formatos incorretos, dígitos repetidos ou dígitos verificadores incorretos.
/// - Armazenamento consistente: o CPF é armazenado sem formatação após a validação.
class TUCpf { //declaracao da classe
    private:
        const static std::string CPF_VALIDO; // string usada para teste do CPF_VALIDO
        const static std::string CPF_INVALIDO; //  string usada para teste do CPF_INVALIDO
        CPF* cpf; //  ponteiro do objeto cpf que sera usado nos testes
        int estadoCpf; // inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA

        void setUpCpf(); // inicializa o ambiente de teste
        void tearDownCpf(); // limpa o ambiente de teste
        void testarCenarioValidoCpf(); // testa um cpf valido
        void testarCenarioInvalidoCpf(); // testa um cpf invalido
    public:
       /// @brief Código de retorno para teste bem-sucedido
    const static int SUCESSO = 0;

    /// @brief Código de retorno para teste falho
    const static int FALHA = -1;

    /// @brief Executa todos os testes do domínio Cpf.
    /// @details Verifica:
    /// - Cenário de sucesso com um CPF válido (dígitos verificadores corretos).
    /// - Cenário de falha com um CPF inválido (dígitos incorretos, formato errado).
    /// - Armazenamento do CPF sem formatação, garantindo consistência.
    /// @return SUCESSO se todos os testes passarem, FALHA caso contrário.
        int runCpf(); // dereciona a execucaco de todos os testes
};

#endif
