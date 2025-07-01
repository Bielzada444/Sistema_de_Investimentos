//
// Criado por Gabriel em 07/05/2025
// Matricula: 241038942
#include "Ordem.hpp"

void Ordem::setCodigo(const Codigo& novoCodigo) {
	this->codigo = novoCodigo;
}

void Ordem::setCodigoNegociacao(const CodigoNegociacao& novoCodigoNegociacao) {
	this->codigoNegociacao = novoCodigoNegociacao;
}

void Ordem::setData(const Data& novaData) {
	this->data = novaData;
}
void Ordem::setDinheiro(const Dinheiro& novoPreco) {
	this->preco = novoPreco;
}
void Ordem::setQuantidade(const Quantidade& novaQuantidade) {
	this->quantidade = novaQuantidade;
}
