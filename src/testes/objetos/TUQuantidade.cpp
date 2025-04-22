
#include "TUQuantidade.h"
#include <string>


const std::string TUQuantidade::QUANTIDADE_VALIDO = "150000"; // inicializacao de Quantidade que passa em todos os testes
const std::string TUQuantidade::QUANTIDADE_INVALIDO = "111111111";// inicializacao de Quantidade que falha na validacao


void TUQuantidade::setUpQuantidade() { 
    quantidade = new Quantidade(); // aloca um novo objeto Quantidade para teste
    estadoQuantidade = SUCESSO; // incializa o estado para SUCESSO
}

void TUQuantidade::tearDownQuantidade() {
    delete quantidade; // libera memoria usado do objeto Quantidade alocado para teste
}

void TUQuantidade::testarCenarioValidoQuantidade() {
    try { 
        quantidade->setQuantidade(QUANTIDADE_VALIDO); // tenta definir um Quantidade valido
        if( quantidade->getQuantidade() != QUANTIDADE_VALIDO){ // verifica se o valor foi armazenado corretamente
            estadoQuantidade = FALHA; // se for diferente do esperado marca como FALHA
        }
    } catch(DominioException &excecao) { // lanca excecao
        estadoQuantidade = FALHA; // marca o teste como FALHA
    }
}

void TUQuantidade::testarCenarioInvalidoQuantidade() {
    try {
        quantidade->setQuantidade(QUANTIDADE_INVALIDO); //tenta definir um Quantidade invalido
        estadoQuantidade = FALHA; // se conseguir marca como FALHA
    } catch(DominioException &excecao) { //lanca excecao
        if(quantidade->getQuantidade() == QUANTIDADE_INVALIDO){ //verifica se o Quantidade invalido nao foi armazenado
            estadoQuantidade = FALHA; // se foi armazenado marca como FALHA
        }
    }
}

int TUQuantidade::runQuantidade() {
    setUpQuantidade(); // prepara para o teste
    testarCenarioValidoQuantidade(); // executa o teste para cenario valido
    testarCenarioInvalidoQuantidade(); // executa o teste para cenario invalido
    tearDownQuantidade(); // libera a memoria do objeto alocado para teste
    return estadoQuantidade; // retorna o resultado final do teste
}
