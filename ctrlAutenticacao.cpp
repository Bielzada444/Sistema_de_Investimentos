// ctrlAutenticacao.cpp
#include "ctrlAutenticacao.hpp"
#include "servicoConta.hpp"
#include "ctrlConta.hpp"
#include "utils.hpp"


void CtrlAutenticacao::setCntr(ILNAutenticacao *cntr) {
    servico = cntr;
}

void CtrlAutenticacao::setCtrlConta(ILNConta *cntrConta) {
    servicoConta = cntrConta;
}
void CtrlAutenticacao::setCtrlConta(IUConta *cntrConta) {
    ctrlConta = cntrConta;
}

bool CtrlAutenticacao::autenticar() {
    std::string entradaCpf, entradaSenha;

    std::cout << "Digite CPF: ";
    std::getline(std::cin, entradaCpf);

    std::cout << "Digite Senha: ";
    std::getline(std::cin, entradaSenha);

    try {
        CPF cpf;
        cpf.setCPF(entradaCpf);

        Senha senha;
        senha.setSenha(entradaSenha);

        if (servico->autenticar(cpf, senha)) {
            std::cout << "\nAutenticado com sucesso!\n";
            if (servicoConta && ctrlConta) {
                auto *ctrlReal = dynamic_cast<CtrlConta *>(ctrlConta);
                if (ctrlReal) {
                    ctrlReal->menu(cpf);
                } else {
                    std::cerr << "Erro interno: ctrlConta não é CtrlConta*.\n";
                }
            }
            return true;
        } else {
            std::cout << "CPF ou senha incorretos.\n";
            return false;
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
}


void CtrlAutenticacao::menu() {
    int opcao;
    do {
        limparTela();
        std::cout << "\n--- MENU AUTENTICACAO ---\n";
        std::cout << "1 - Login\n";
        std::cout << "2 - Registrar usuario\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();
        limparTela();

        switch (opcao) {
            case 0: // Sair
                std::cout << "Saindo do sistema...\n";
                break;

            case 1: // Login
                autenticar();
                break;

            case 2: // Registrar usuario
            {
                std::string entradaCpf, entradaSenha, entradaNome;
                std::cout << "Digite o seu CPF: ";
                std::getline(std::cin, entradaCpf);
                std::cout << "Digite sua senha: ";
                std::getline(std::cin, entradaSenha);
                std::cout << "Digite o seu nome: ";
                std::getline(std::cin, entradaNome);

                try {
                    CPF cpf;
                    Senha senha;
                    Nome nome;

                    cpf.setCPF(entradaCpf);
                    senha.setSenha(entradaSenha);
                    nome.setNome(entradaNome);

                    // Registrar no serviço de autenticação
                    servico->registrar(cpf, senha, nome);

                    // Criar conta no sistema
                    Conta conta;
                    conta.setCpf(cpf);
                    conta.setNome(nome);
                    conta.setSenha(senha);

                    if (servicoConta) {
                        if (servicoConta->criar(conta)) {
                            std::cout << "\nConta registrada com sucesso!\n";
                        } else {
                            std::cerr << "\nFalha ao registrar conta.\n";
                        }
                    } else {
                        std::cerr << "\nServico de conta nao disponivel.\n";
                    }

                    std::cout << "\nAperte ENTER para continuar\n";
                    std::cin.get();

                } catch (const std::exception &e) {
                    std::cerr << "Erro: " << e.what() << std::endl;
                    std::cout << "\nAperte ENTER para continuar\n";
                    std::cin.get();
                }
                break;
            }

            default:
                std::cout << "Opcao invalida!\n";
                std::cout << "\nAperte ENTER para continuar\n";
                std::cin.get();
                break;
        }

    } while (opcao != 0);
}
