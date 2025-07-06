#include "ctrlConta.hpp"
#include "utils.hpp"
#include <limits>
#include <iomanip>
void CtrlConta::setCntr(ILNConta *cntr) {
    servico = cntr;
}

void CtrlConta::setCtrlCarteira(CtrlCarteira *cntrCarteira) {
    ctrlCarteira = cntrCarteira;
}

void CtrlConta::setCtrlOrdem(CtrlOrdem *cntrOrdem) {
    ctrlOrdem = cntrOrdem;
}

void CtrlConta::setServicoCarteira(ServicoCarteira *servicoCarteira) {
    this->servicoCarteira = servicoCarteira;
}

void CtrlConta::setServicoOrdem(ServicoOrdem *servicoOrdem) {
    this->servicoOrdem = servicoOrdem;
}

void CtrlConta::setServicoDados(ServicoDadosHistoricos *servicoDados) {
    this->servicoDados = servicoDados;
}

void CtrlConta::menu(const CPF &cpf) {
    int opcao;
    bool sair = false;

    do {
        limparTela();
        std::cout << "\n--- MENU CONTA ---\n";
        std::cout << "1 - Gerenciar carteiras\n";
        std::cout << "2 - Gerenciar ordens\n";
        std::cout << "3 - Visualizar conta\n";
        std::cout << "4 - Editar conta\n";
        std::cout << "5 - Excluir conta\n";
        std::cout << "0 - Logout\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();
        limparTela();

        switch (opcao) {
            case 0: // Logout
                sair = true;
                break;

            case 1: // Gerenciar carteiras
                if (ctrlCarteira) ctrlCarteira->menu(cpf);
                break;

            case 2: // Gerenciar ordens
                gerenciarOrdens(cpf);
                break;

            case 3: // Visualizar conta
                try {
                    Conta conta = servico->ler(cpf);
                    std::cout << "CPF: " << cpf.getCPF() << "\n";
                    std::cout << "Nome: " << conta.getNome().getNome() << "\n";
                    std::cout << "Senha: " << conta.getSenha().getSenha() << "\n";

                    if (servicoCarteira) {
                        auto lista = servicoCarteira->listarCarteirasPor(cpf);
                        std::cout << "Total de carteiras: " << lista.size() << "\n";
                        double saldoTotal = 0.0;
                        for (const auto &c : lista) {
                            double saldo = servicoCarteira->obterSaldoCarteira(c.getCodigo());
                            saldoTotal += saldo;

                            std::cout << "- [" << c.getCodigo().getCodigo() << "] "
                                      << c.getNome().getNome() << " - "
                                      << c.getPerfil().getPerfil() << "\n";
                        }

                        std::cout << "\nSaldo total da conta: R$ " << std::fixed << std::setprecision(2) << saldoTotal << "\n";
                    }

                    std::cout << "Aperte ENTER para continuar\n";
                    std::cin.get();

                } catch (const std::exception &e) {
                    std::cerr << "Erro: " << e.what() << "\n";
                }
                break;


            case 4: // Editar conta
                editar(cpf);
                break;

            case 5: // Excluir conta
                excluir(cpf);
                sair = true; // Forca saida depois de excluir a conta
                break;

            default:
                std::cout << "Opcao invalida!\n";
                std::cout << "Aperte ENTER para continuar\n";
                std::cin.get();
                break;

        }

    } while (!sair);

}
void CtrlConta::criar() {
    std::string cpfStr, nomeStr;
    std::cout << "CPF: ";
    std::getline(std::cin, cpfStr);
    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    try {
        CPF cpf; cpf.setCPF(cpfStr);
        Nome nome; nome.setNome(nomeStr);

        Conta conta;
        conta.setCpf(cpf);
        conta.setNome(nome);

        if (servico->criar(conta))
            std::cout << "Conta criada com sucesso.\n";
        else
            std::cout << "Falha ao criar conta.\n";
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void CtrlConta::editar(const CPF &cpf) {
    int opcao;
    limparTela();
    std::cout << "\n--- EDITAR CONTA ---\n";
    std::cout << "1 - Editar nome\n";
    std::cout << "2 - Editar senha\n";
    std::cout << "3 - Editar ambos\n";
    std::cout << "0 - Cancelar\n";
    std::cout << "Escolha: ";
    std::cin >> opcao;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    limparTela();

    switch (opcao) {
        case 0:
            std::cout << "Edicao cancelada.\n";
            return;

        case 1:
        case 2:
        case 3: {
            Conta conta;
            conta.setCpf(cpf);

            try {
                if (opcao == 1 || opcao == 3) {
                    std::string nomeStr;
                    std::cout << "Novo Nome: ";
                    std::getline(std::cin, nomeStr);
                    Nome nome; nome.setNome(nomeStr);
                    conta.setNome(nome);
                }

                if (opcao == 2 || opcao == 3) {
                    std::string senhaStr;
                    std::cout << "Nova Senha: ";
                    std::getline(std::cin, senhaStr);
                    Senha senha; senha.setSenha(senhaStr);
                    conta.setSenha(senha);
                }

                if (servico->editar(conta)) {
                    std::cout << "Conta atualizada.\n";
                } else {
                    std::cout << "Falha ao atualizar conta.\n";
                }

            } catch (const std::exception &e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
            break;
        }

        default:
            std::cout << "Opicao invalida! Edicao cancelada.\n";
            std::cout << "Aperte ENTER para continuar" << "\n";
            std::cin.get();
            break;
    }

}

void CtrlConta::excluir(const CPF &cpf) {
    try {
        // Verifica se existem carteiras associadas
        if (servicoCarteira) {
            auto carteiras = servicoCarteira->listarCarteirasPor(cpf);
            if (!carteiras.empty()) {
                std::cerr << "Nao eh possivel excluir a conta: ha carteiras associadas a ela.\n";
                std::cout << "Aperte ENTER para continuar\n";
                std::cin.get();
                return;
            }
        }

        // Continua com a exclusao se não houver carteiras
        if (servico->excluir(cpf))
            std::cout << "Conta excluida.\n";
        else
            std::cout << "Falha ao excluir conta.\n";

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}


void CtrlConta::ler() {
    std::string cpfStr;
    std::cout << "CPF da conta a visualizar: ";
    std::getline(std::cin, cpfStr);

    try {
        CPF cpf; cpf.setCPF(cpfStr);
        Conta conta = servico->ler(cpf);

        std::cout << "Nome: " << conta.getNome().getNome() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void CtrlConta::gerenciarOrdens(const CPF &cpf) {
    if (!ctrlOrdem) {
        std::cerr << "Controle de ordens nao configurado.\n";
        return;
    }

    ctrlOrdem->setCpfLogado(cpf);

    if (servicoOrdem) ctrlOrdem->setServicoOrdem(servicoOrdem);
    if (servicoCarteira) ctrlOrdem->setServicoCarteira(servicoCarteira);
    if (servicoDados) ctrlOrdem->setServicoDados(servicoDados);

    ctrlOrdem->menu(cpf);
}
