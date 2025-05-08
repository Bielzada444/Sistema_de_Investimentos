#ifndef TUORDEM_HPP
#define TUORDEM_HPP

#include "Ordem.hpp"
#include "Dominios.hpp"

class TUOrdem {
	const std::string CODIGO_VALIDO = "12345";
	const std::string CODIGONEGOCIACAO_VALIDO = "TEST4";
	const std::string DATA_VALIDA = "20250508";
	const std::string DINHEIRO_VALIDO = "20863.67";
	const std::string QUANTIDADE_VALIDA = "150000";

	Ordem* ordem;
	int estadoOrdem;

	void setUpOrdem();
	void tearDownOrdem();
	void testarCenarioValidoOrdem();

public:
	const static int SUCESSO = 0;
	const static int FALHA = -1;
	int runOrdem();
};
};

#endif // TUORDEM_HPP
