#ifndef TUQUANTIDADE_H
#define TUQUANTIDADE_H
#include "Quantidade.h"
#include <string>

class TUQuantidade{
        private:
         static std::string QUANTIDADE_VALIDA; // string usada para teste do QUANTIDADE_VALIDO
         static std::string QUANTIDADE_INVALIDA; //  string usada para teste do QUANTIDADE_INVALIDO
        Quantidade* quantidade; //  ponteiro do objeto Quantidade que sera usado nos testes
        int estadoQuantidade; // inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA
        
        void setUpQuantidade(); // inicializa o ambiente de teste
        void tearDownQuantidade(); // limpa o ambiente de teste
        void testarCenarioValidoQuantidade(); // testa um Quantidade valido
        void testarCenarioInvalidoQuantidade(); // testa um Quantidade invalido
    public:
        const static int SUCESSO = 0; // inteiro que define sucesso do caso de teste
        const static int FALHA = -1; // inteiro que define falha do caso de teste
        int runQuantidade(); // dereciona a execucaco de todos os testes 

    
};
#endif 
