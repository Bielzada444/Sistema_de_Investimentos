//
// Criado por Gabriel em 22/04/2025.
// Matricula: 241038942

/// @file TUData.hpp
/// @brief Teste de unidade para a classe Data (Domínio).
/// @details
/// Testa:
/// - Datas no formato AAAAMMDD (incluindo validaçăo de anos bissextos)
/// - Rejeiçăo de dias/meses fora do intervalo válido
/// - Conversăo correta entre string e valores numéricos (dia, męs, ano)

#ifndef TUDATA_HPP
#define TUDATA_HPP
#include "Data.hpp" //inclui o header da classe Data que vai ser testada
#include <string> //inclui header string padrao do C++
/// @class TUData
/// @brief Classe de teste de unidade para o domínio Data.
/// @details Verifica se o domínio Data aceita corretamente valores válidos
/// e rejeita valores inválidos, garantindo consistência.
class TUData { //declaracao da classe
    private:
        const static std::string DATA_VALIDA; // string usada para teste da DATA_VALIDA
        const static std::string DATA_INVALIDA; //  string usada para teste da DATA_INVALIDA
        Data* data; //  ponteiro do objeto data que sera usado nos testes
        int estadoData; // inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA

        void setUpData(); // inicializa o ambiente de teste
        void tearDownData(); // limpa o ambiente de teste
        void testarCenarioValidoData(); // testa uma data valida
        void testarCenarioInvalidoData(); // testa uma data invalida
    public:
     /// @brief Código de retorno para teste bem-sucedido
    const static int SUCESSO = 0;

    /// @brief Código de retorno para teste falho
    const static int FALHA = -1;

    /// @brief Executa todos os testes do domínio Data.
    /// @details Verifica:
    /// - Cenário de sucesso com uma data válida (formato AAAAMMDD).
    /// - Cenário de falha com uma data inválida (dia ou mês fora do intervalo).
    /// - Armazena corretamente a data e converte entre string e valores numéricos.
    /// @return SUCESSO se todos os testes passarem, FALHA caso contrário.
        int runData(); // dereciona a execucaco de todos os testes
};

#endif
