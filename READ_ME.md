Sistema de Investimentos 💰
Sistema desenvolvido para a disciplina de Técnicas de Programação 1 na Universidade de Brasília (UnB). Uma aplicação C++ para gerenciamento de investimentos financeiros com foco em educação financeira.

📋 Sobre o Projeto
Sistema completo para aprendizado sobre investimentos financeiros, permitindo que usuários criem contas, gerenciem carteiras de investimento e realizem operações com ordens de compra/venda baseadas em dados históricos reais.

Funcionalidades Principais
✅ Gestão de Contas: Criar, autenticar, ler, editar e excluir contas

✅ Gestão de Carteiras: Criar, ler, editar e excluir carteiras de investimento

✅ Ordens de Investimento: Criar, ler e excluir ordens baseadas em dados históricos

✅ Cálculos Automáticos: Preços médios baseados em dados históricos

✅ Relatórios: Listagem de carteiras e ordens com saldos calculados

🏗️ Estrutura do Projeto
text
Sistema_de_Investimentos/
├── CMakeLists.txt                 # Configuração principal do CMake
├── Doxyfile                       # Configuração da documentação Doxygen
├── cmake-build-debug/             # Diretório de build para debug
├── Dominios/                      # Domínios do sistema
├── Entidades/                     # Entidades principais
├── Testes/                        # Testes unitários
├── source_lib/                    # Bibliotecas de código
├── src/                           # Código fonte principal
│   ├── Sistema_de_Investimentos.cbp
│   ├── Sistema_de_Investimentos.depend
│   └── Sistema_de_Investimentos.layout
└── README.md                      # Este arquivo
⚡ Compilação e Execução
Pré-requisitos
CMake ≥ 3.10

Compiler C++ (g++ ≥ 7.0 ou Clang ≥ 5.0)

Make ou Ninja

🛠️ Compilação com CMake
bash
# Clone o repositório
git clone https://github.com/Bielzada444/Sistema_de_Investimentos.git
cd Sistema_de_Investimentos

# Configuração e compilação
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j4

# Execução
./SistemaInvestimentos
🎯 Comandos Rápidos
bash
# Desenvolvimento (com debug)
cmake -DCMAKE_BUILD_TYPE=Debug .. && make && ./SistemaInvestimentos

# Produção (com otimizações)
cmake -DCMAKE_BUILD_TYPE=Release .. && make -j4 && ./SistemaInvestimentos

# Com testes
cmake -DBUILD_TESTS=ON .. && make && ./Testes/run_tests
🌿 Estrutura de Branches
main (Recomendada)
Versão final organizada com sistema de build CMake

Estrutura modular em pastas organizadas

Código limpo e pronto para produção

Codeblocks (Histórica)
Versão original para IDE Code::Blocks

Arquivos espalhados conforme exigência do professor

Mantida para fins acadêmicos

🚀 Como Usar o Sistema
1. Criação de Conta
bash
# Após executar o sistema
> criar_conta "123.456.789-00" "João Silva" "senha123"
2. Autenticação
bash
> autenticar "123.456.789-00" "senha123"
3. Gestão de Carteiras
bash
> criar_carteira "CART001" "Minha Carteira" "MODERADO"
> listar_carteiras
4. Ordens de Investimento
bash
> criar_ordem "CART001" "PETR4" "2024-01-15" 100
> listar_ordens "CART001"
🧪 Testes
bash
# Executar suite de testes
cd build && make test

# Ou executar diretamente
./Testes/test_dominios
./Testes/test_entidades
👥 Equipe de Desenvolvimento
Equipe TP1 - UnB 2024

Gabriel Alexandre

Henrique Almeida

Nyvea Paulla

Cleriston

🐛 Reportar Problemas
Encontrou um bug? Abra uma issue descrevendo o problema encontrado.

📄 Licença
Projeto acadêmico desenvolvido para Técnicas de Programação 1 - UnB. Distribuído para fins educacionais.

Desenvolvido com 🎓 para o aprendizado em investimentos financeiros

💡 Dicas para Desenvolvedores
bash
# Compilação rápida para desenvolvimento
cmake --build build --target SistemaInvestimentos

# Limpar build e recompilar
rm -rf build/ && mkdir build && cd build && cmake .. && make
