// ctrlOrdem.cpp

#include "ctrlOrdem.hpp"
#include "utils.hpp"
#include <iostream>

void CtrlOrdem::setServicoOrdem(ServicoOrdem *servico) {
    servicoOrdem = servico;
}

void CtrlOrdem::setServicoCarteira(ServicoCarteira *servico) {
    servicoCarteira = servico;
}

void CtrlOrdem::setServicoDados(ServicoDadosHistoricos *servico) {
    servicoDados = servico;
}

void CtrlOrdem::setCpfLogado(const CPF &cpf) {
    cpfLogado = cpf;
}

void CtrlOrdem::menu(const CPF &cpf) {
    setCpfLogado(cpf);
    int opcao;
    do {
        limparTela();
        std::cout << "\n--- MENU ORDEM ---\n";
        std::cout << "1 - Criar ordem\n";
        std::cout << "2 - Listar ordens por carteira\n";
        std::cout << "3 - Excluir ordem\n";
        std::cout << "4 - Ver detalhes da ordem\n";
        std::cout << "0 - Voltar\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: criar(); break;
            case 2: listarPorCarteira(); break;
            case 3: excluir(); break;
            case 4: ler(); break;
            case 0: break;
            default: std::cout << "Opcao invalida.\n";
             std::cout << "Pressione ENTER para sair" << "\n";
                std::cin.get();
        }

    } while (opcao != 0);
}

void CtrlOrdem::criar() {
    std::string codCarteiraStr, codNegStr, qtdStr, dataStr, codOrdemStr;
    std::cout << "Codigo da carteira: ";
    std::getline(std::cin, codCarteiraStr);
    std::cout << "Codigo de negociacao: ";
    std::getline(std::cin, codNegStr);
    std::cout << "Quantidade: ";
    std::getline(std::cin, qtdStr);
    std::cout << "Data (AAAAMMDD): ";
    std::getline(std::cin, dataStr);
    std::cout << "Codigo da ordem: ";
    std::getline(std::cin, codOrdemStr);

    try {
        Codigo codigoCarteira;
        codigoCarteira.setCodigo(codCarteiraStr);

        if (!servicoDados->ativoExiste(codNegStr)) {
            std::cerr << "Ativo nao encontrado no historico.\n";
            return;
        }

        CodigoNegociacao codNeg;
        codNeg.setCodigoNegociacao(codNegStr);

        Data data;
        data.setData(dataStr);

        Quantidade qtd;
        qtd.setQuantidade(qtdStr);

        Dinheiro preco;
        auto [dataHistorica, precoHistorico] = servicoDados->consultar(codNeg);
        preco = precoHistorico;  // usa o preço extraído do histórico

        Ordem ordem;
        Codigo codOrdem;
        codOrdem.setCodigo(codOrdemStr);

        ordem.setCodigo(codOrdem);
        ordem.setCodigoNegociacao(codNeg);
        ordem.setData(data);
        ordem.setQuantidade(qtd);
        ordem.setDinheiro(preco);

        if (servicoOrdem->criar(cpfLogado, codigoCarteira, ordem)) {
            std::cout << "Ordem criada com sucesso.\n";
        } else {
            std::cerr << "Erro ao criar ordem.\n";
        }

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }
         std::cout << "Aperte ENTER para continuar" << "\n";
         std::cin.get();
}

void CtrlOrdem::listarPorCarteira() {
    std::string codCarteiraStr;
    std::cout << "Codigo da carteira: ";
    std::getline(std::cin, codCarteiraStr);

    try {
        Codigo codigoCarteira;
        codigoCarteira.setCodigo(codCarteiraStr);


        auto ordens = servicoOrdem->listarPorCarteira(cpfLogado, codigoCarteira);

        if (ordens.empty()) {
            std::cout << "Nenhuma ordem encontrada.\n";
            return;
        }

        for (const auto &ordem : ordens) {
            std::cout << "\n--- Ordem " << ordem.getCodigo().getCodigo() << " ---\n";
            std::cout << "Ativo: " << ordem.getCodigoNegociacao().getCodigoNegociacao() << "\n";
            std::cout << "Data: " << ordem.getData().getData() << "\n";
            std::cout << "Preco: R$ " << ordem.getDinheiro().getDinheiro() << "\n";
            std::cout << "Quantidade: " << ordem.getQuantidade().getQuantidade() << "\n";
        }

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }
    std::cout << "Aperte ENTER para continuar" << "\n";
         std::cin.get();
}

void CtrlOrdem::excluir() {
    std::string cod;
    std::cout << "Codigo da ordem a excluir: ";
    std::getline(std::cin, cod);

    try {
        Codigo codigo;
        codigo.setCodigo(cod);

        if (servicoOrdem->excluir(codigo)) {
            std::cout << "Ordem excluida com sucesso.\n";
        } else {
            std::cerr << "Falha ao excluir ordem.\n";
        }

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }
}

void CtrlOrdem::ler() {
    std::string cod;
    std::cout << "Codigo da ordem: ";
    std::getline(std::cin, cod);

    try {
        Codigo codigo;
        codigo.setCodigo(cod);
        Ordem ordem = servicoOrdem->ler(codigo);

        std::cout << "\n--- Detalhes da Ordem ---\n";
        std::cout << "Codigo: " << ordem.getCodigo().getCodigo() << "\n";
        std::cout << "Ativo: " << ordem.getCodigoNegociacao().getCodigoNegociacao() << "\n";
        std::cout << "Data: " << ordem.getData().getData() << "\n";
        std::cout << "Preco: R$ " << ordem.getDinheiro().getDinheiro() << "\n";
        std::cout << "Quantidade: " << ordem.getQuantidade().getQuantidade() << "\n";

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << "\n";
    }
}
