#include "TUOrdem.hpp"

    
void TUOrdem::setUpOrdem() {
    ordem = new Ordem();
    estadoOrdem = SUCESSO;
}

void TUOrdem::tearDownOrdem() {
    delete ordem;
}

void TUOrdem::testarCenarioValidoOrdem() {
    Codigo codigo;
    CodigoNegociacao codigoNegociacao;
    Data data;
    Dinheiro dinheiro;
    Quantidade quantidade;
    
    codigo.setCodigo(CODIGO_VALIDO);
    codigoNegociacao.setCodigoNegociacao(CODIGONEGOCIACAO_VALIDO);
    data.setData(DATA_VALIDA);
    dinheiro.setDinheiro(DINHEIRO_VALIDO);
    quantidade.setQuantidade(QUANTIDADE_VALIDA);
        
    ordem->setCodigo(codigo);
    ordem->setCodigoNegociacao(codigoNegociacao);
    ordem->setData(data);
    ordem->setDinheiro(dinheiro);
    ordem->setQuantidade(quantidade);
        
    // Verifica se os valores foram armazenados corretamente
    if (ordem->getCodigo().getCodigo() != CODIGO_VALIDO ||
        ordem->getCodigoNegociacao().getCodigoNegociacao() != CODIGONEGOCIACAO_VALIDO ||
        ordem->getData().getData() != DATA_VALIDA ||
        ordem->getDinheiro().getDinheiro() != DINHEIRO_VALIDO ||
        ordem->getQuantidade().getQuantidade() != QUANTIDADE_VALIDA ) {
        estadoOrdem = FALHA;
    }
    
}

int TUOrdem::runOrdem() {
    setUpOrdem();
    testarCenarioValidoOrdem();
    tearDownOrdem();
    return estadoOrdem;
}
