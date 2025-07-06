//
// Created by Henrique on 29/06/2025.
//
#include "ctrlCarteira.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>
CtrlCarteira::CtrlCarteira(ServicoCarteira *servico) {
    this->servico = servico;
}

void CtrlCarteira::menu(const CPF &cpf) {
    int opcao;
    do {
        limparTela();
        std::cout << "\n--- MENU CARTEIRA ---\n";
        std::cout << "1 - Criar carteira\n";
        std::cout << "2 - Listar carteiras\n";
        std::cout << "3 - Editar carteira\n";
        std::cout << "4 - Excluir carteira\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();
        limparTela();

        switch (opcao) {
            case 0:
                break;

            case 1: {
                std::string codigoStr, nomeStr, perfilStr;
                std::cout << "Codigo: "; std::getline(std::cin, codigoStr);
                std::cout << "Nome: "; std::getline(std::cin, nomeStr);
                std::cout << "Perfil (Conservador, Moderado, Agressivo): ";
                std::getline(std::cin, perfilStr);

                try {
                    Codigo codigo; codigo.setCodigo(codigoStr);
                    Nome nome; nome.setNome(nomeStr);
                    Perfil perfil; perfil.setPerfil(perfilStr);

                    Carteira carteira;
                    carteira.setCodigo(codigo);
                    carteira.setNome(nome);
                    carteira.setPerfil(perfil);

                    if (servico->criarCarteiraPara(cpf, carteira))
                        std::cout << "Carteira criada com sucesso.\n";
                    else
                        std::cout << "Falha ao criar carteira.\n";
                } catch (const std::exception &e) {
                    std::cerr << "Erro: " << e.what() << "\n";
                }
                break;
            }

            case 2: {
                auto lista = servico->listarCarteirasPor(cpf);
                for (const auto &c : lista) {
                    double saldo = servico->obterSaldoCarteira(c.getCodigo());

                    std::cout << "- " << c.getCodigo().getCodigo()
                              << " | " << c.getNome().getNome()
                              << " | " << c.getPerfil().getPerfil()
                              << " | Saldo: R$ " << std::fixed << std::setprecision(2) << saldo
                              << "\n";
                }
                std::cout << "\nAperte ENTER para continuar" << "\n";
                std::cin.get();
                break;
            }

            case 3: {
                std::string codigoStr, nomeStr, perfilStr;
                std::cout << "Codigo da carteira: "; std::getline(std::cin, codigoStr);
                std::cout << "Novo Nome: "; std::getline(std::cin, nomeStr);
                std::cout << "Novo Perfil (Conservador, Moderado, Agressivo): ";
                std::getline(std::cin, perfilStr);

                try {
                    Codigo codigo; codigo.setCodigo(codigoStr);
                    Nome nome; nome.setNome(nomeStr);
                    Perfil perfil; perfil.setPerfil(perfilStr);

                    Carteira carteira;
                    carteira.setCodigo(codigo);
                    carteira.setNome(nome);
                    carteira.setPerfil(perfil);

                    if (servico->editar(carteira))
                        std::cout << "Carteira atualizada.\n";
                    else
                        std::cout << "Falha ao atualizar carteira.\n";
                } catch (const std::exception &e) {
                    std::cerr << "Erro: " << e.what() << "\n";
                }
                std::cout << "Pressione ENTER para continuar" << "\n";
                std::cin.get();
                break;
            }

            case 4: {
                std::string codigoStr;
                std::cout << "Codigo da carteira: "; std::getline(std::cin, codigoStr);
                try {
                    Codigo codigo; codigo.setCodigo(codigoStr);
                    if (servico->excluir(codigo))
                        std::cout << "Carteira excluida.\n";
                    else
                        std::cout << "Falha ao excluir carteira.\n";
                } catch (const std::exception &e) {
                    std::cerr << "Erro: " << e.what() << "\n";
                }
                break;
            }

            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                std::cout << "\nAperte ENTER para continuar" << "\n";
                std::cin.get();
                break;
        }

    } while (opcao != 0);
}
