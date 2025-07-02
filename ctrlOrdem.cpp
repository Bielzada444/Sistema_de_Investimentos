#include "ctrlOrdem.hpp"
#include <iostream>
#include <stdexcept>

void CtrlOrdem::menu(const CPF &cpf) {
    int opcao;
    do {
        std::cout << "\n--- Gerenciar Ordens ---\n";
        std::cout << "1 - Criar Nova Ordem\n";
        std::cout << "2 - Listar Ordens de uma Carteira\n";
        std::cout << "3 - Visualizar Ordem Específica\n";
        std::cout << "4 - Excluir Ordem\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: criar(); break;
            case 2: listarPorCarteira(); break;
            case 3: ler(); break;
            case 4: excluir(); break;
        }
    } while (opcao != 0);
}

void CtrlOrdem::criar() {
    std::string codigoCarteiraStr, codigoNegociacaoStr, dataStr, quantidadeStr, codigoOrdemStr;

    std::cout << "Digite o codigo da Ordem: ";
    std::getline(std::cin, codigoOrdemStr);

    std::cout << "Digite o codigo da Carteira onde a ordem sera criada: ";
    std::getline(std::cin, codigoCarteiraStr);

    std::cout << "Digite o codigo de negociacao do papel (ex: IVVB11): ";
    std::getline(std::cin, codigoNegociacaoStr);

    std::cout << "Digite a data (AAAAMMDD): ";
    std::getline(std::cin, dataStr);

    std::cout << "Digite a quantidade: ";
    std::getline(std::cin, quantidadeStr);

    try {
        Codigo codigoCarteira;
        codigoCarteira.setCodigo(codigoCarteiraStr);
        Codigo codigoOrdem;
        codigoOrdem.setCodigo(codigoOrdemStr);
        CodigoNegociacao codigoNegociacao;
        codigoNegociacao.setCodigoNegociacao(codigoNegociacaoStr);
        Data data;
        data.setData(dataStr);
        Quantidade quantidade;
        quantidade.setQuantidade(quantidadeStr);

        Ordem ordem;
        ordem.setCodigo(codigoOrdem);
        ordem.setCodigoNegociacao(codigoNegociacao);
        ordem.setData(data);
        ordem.setQuantidade(quantidade);

        bool sucesso = servicoOrdem->criar(ordem , codigoCarteira);

        if (sucesso) {
            std::cout << "Ordem criada com sucesso!\n";
        } else {
            std::cout << "Nao foi possivel criar a ordem.\n";
        }

    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro de formato nos dados: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void CtrlOrdem::listarPorCarteira() {
    std::string codigoCarteiraStr;
    std::cout << "\nDigite o codigo da carteira: ";
    std::getline(std::cin, codigoCarteiraStr);

    try {
        Codigo codigoCarteira;
        codigoCarteira.setCodigo(codigoCarteiraStr);

        list<Ordem> ordens = servicoOrdem->listarPorCarteira(codigoCarteira);

        if (ordens.empty()) {
            std::cout << "Nenhuma ordem encontrada para esta carteira." << std::endl;
            return;
        }

        std::cout << "\n--- Ordens da Carteira " << codigoCarteira.getCodigo() << " ---\n";
        for (const auto& ordem : ordens) {
            std::cout << "Codigo da Ordem: " << ordem.getCodigo().getCodigo() << "\n";
            std::cout << "  - Ativo: " << ordem.getCodigoNegociacao().getCodigoNegociacao() << "\n";
            std::cout << "  - Data: " << ordem.getData().getData() << "\n";
            std::cout << "  - Quantidade: " << ordem.getQuantidade().getQuantidade() << "\n";
            std::cout << "  - Preco Total: R$ " << ordem.getDinheiro().getDinheiro() << "\n\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void CtrlOrdem::ler() {
    std::string codigoOrdemStr;
    std::cout << "\nDigite o codigo da ordem: ";
    std::getline(std::cin, codigoOrdemStr);

    try {
        Codigo codigoOrdem;
        codigoOrdem.setCodigo(codigoOrdemStr);

        Ordem ordem = servicoOrdem->ler(codigoOrdem);

        std::cout << "\n--- Detalhes da Ordem " << ordem.getCodigo().getCodigo() << " ---\n";
        std::cout << "Codigo de Negociacao: " << ordem.getCodigoNegociacao().getCodigoNegociacao() << "\n";
        std::cout << "Data: " << ordem.getData().getData() << "\n";
        std::cout << "Quantidade: " << ordem.getQuantidade().getQuantidade() << "\n";
        std::cout << "Preco Total: R$ " << ordem.getDinheiro().getDinheiro() << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void CtrlOrdem::excluir() {
    std::string codigoOrdemStr;
    std::cout << "\nDigite o codigo da ordem que deseja excluir: ";
    std::getline(std::cin, codigoOrdemStr);

    try {
        Codigo codigoOrdem;
        codigoOrdem.setCodigo(codigoOrdemStr);

        if (servicoOrdem->excluir(codigoOrdem)) {
            std::cout << "Ordem excluida com sucesso." << std::endl;
        } else {
            std::cout << "Nao foi possivel excluir a ordem. Verifique se o codigo esta correto." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}
