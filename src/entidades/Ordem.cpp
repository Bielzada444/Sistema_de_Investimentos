#include "Ordem.hpp"

void setCodigo(const Codigo& novoCodigo) {
	this->codigo = novoCodigo;
}

void setCodigoNegociacao(const CodigoNegociacao& novoCodigoNegociacao) {
	this->codigoNegociacao = novoCodigoNegociacao;
}

void setData(const Data& novaData) {
	this->data = novaData;
}
void setDinheiro(const Dinheiro& novoPreco) {
	this->preco = novoPreco;
}
void setQuantidade(const Quantidade& novaQuantidade) {
	this->quantidade = novaQuantidade;
}
