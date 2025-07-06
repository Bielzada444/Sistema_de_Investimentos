#include <iostream>
#include "Dominios.hpp"
#include "ctrlAutenticacao.hpp"
#include "ctrlConta.hpp"
#include "ctrlOrdem.hpp"
#include "servicoAutenticacao.hpp"
#include "servicoConta.hpp"
#include "servicoCarteira.hpp"
#include "servicoOrdem.hpp"
#include "servicoDadosHistoricos.hpp"

int main() {
    // Serviços
    ServicoAutenticacao servAut;
    ServicoConta servConta;
    ServicoCarteira servCarteira;
    ServicoOrdem servOrdem;
    ServicoDadosHistoricos servDados;

    // Controladores
    CtrlAutenticacao ctrlAut;
    CtrlConta ctrlConta;
    CtrlCarteira ctrlCarteira(&servCarteira);
    CtrlOrdem ctrlOrdem;

    // Configuração de dependências
    ctrlAut.setCntr(&servAut);
    ctrlAut.setCtrlConta(&ctrlConta);

    ctrlConta.setCntr(&servConta);
    ctrlConta.setCtrlCarteira(&ctrlCarteira);
    ctrlConta.setCtrlOrdem(&ctrlOrdem);
    ctrlConta.setServicoCarteira(&servCarteira);
    ctrlConta.setServicoOrdem(&servOrdem);  
    ctrlConta.setServicoDados(&servDados);  

    ctrlOrdem.setServicoOrdem(&servOrdem);
    ctrlOrdem.setServicoCarteira(&servCarteira);
    ctrlOrdem.setServicoDados(&servDados);

  
    servDados.importarTxt("Data/DADOS_HISTORICOS.txt");

    // Iniciar sistema
    ctrlAut.menu();

    return 0;
}
