#include <iostream>
#include "TUConta.hpp"
using namespace std;

int main()
{
    TUConta testeConta;
    
    switch(testeConta.runConta()){
        case TUConta::SUCESSO: cout<<"SUCESSO"<<endl;
        break;
        case TUConta::FALHA: cout<<"FALHA"<<endl;
    }
    

    return 0;
}
