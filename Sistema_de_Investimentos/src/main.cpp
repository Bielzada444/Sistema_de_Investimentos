#include <iostream>
#include "TUDominios.hpp"
#include "TUEntidades.hpp"
#include "Entidades/TUConta.hpp"
using namespace std;

int main()
{
    /*
    TUCodigo codigo;
    TUCodigoNegociacao negociacao;
    TUCpf cpf;
    TUData data;
    TUDinheiro dinheiro;
    TUNome nome;
    TUPerfil perfil;
    TUQuantidade quant;
    TUSenha senha;

    cout << codigo.runCodigo() << endl;
    cout << negociacao.runCodigoNegociacao() << endl;
    cout << cpf.runCpf() << endl;
    cout << data.runData() << endl;
    cout << dinheiro.runDinheiro() << endl;
    cout << nome.runNome() << endl;
    cout << perfil.runPerfil() << endl;
    cout << quant.runQuantidade() << endl;
    cout << senha.runSenha() << endl;
    */


    TUOrdem ordem;
    TUConta conta;

    cout << ordem.runOrdem() << endl;
    cout << conta.runConta() << endl;


    return 0;
}
