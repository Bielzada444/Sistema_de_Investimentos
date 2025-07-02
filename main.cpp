#include <iostream>
#include "Dominios.hpp"


#include "ctrlAutenticacao.hpp"
#include "ctrlConta.hpp"
#include "servicoAutenticacao.hpp"
#include "servicoConta.hpp"
#include "ctrlCarteira.hpp"
#include "servicoCarteira.hpp"
#include "ctrlOrdem.hpp"
#include "servicoOrdem.hpp"

int main() {
    // Autenticacao
    CtrlAutenticacao ctrlAut;
    ServicoAutenticacao servAut;

    // Conta
    CtrlConta ctrlConta;
    ServicoConta servConta;

    // Carteira
    ServicoCarteira servCarteira;
    CtrlCarteira ctrlCarteira(&servCarteira);

    //Ordem
    ServicoOrdem servOrdem;
    CtrlOrdem ctrlOrdem;

    // Injecao de dependencias
    ctrlAut.setCntr(&servAut);
    ctrlAut.setCtrlConta(&servConta);   // serviço
    ctrlAut.setCtrlConta(&ctrlConta);   // controlador
    ctrlConta.setCntr(&servConta);
    ctrlConta.setCtrlCarteira(&ctrlCarteira);
    ctrlConta.setCtrlOrdem(&ctrlOrdem);
    ctrlOrdem.setServicoOrdem(&servOrdem);
    servOrdem.setServicoCarteira(&servCarteira);

    // Menu inicial
    ctrlAut.menu();

    return 0;
}
