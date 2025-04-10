//
// Criado por Nyvea em 08/04/2025.
// Matricula: 241040207

#ifndef NOME_H_INCLUDED
#define NOME_H_INCLUDED

#include <string>

class Nome{
    private:
        static const int MAXIMO = 21;                                   //limite de caracters do nome: 20 + 1 (do '\0')
        std::string nome;                                               //o nome eh lido como uma string
        bool validaNome(std::string nome);                                   //retorna true se o nome eh válido e false se nao for

    public:
        bool setNome(std::string nome);                                      //inicializa o nome se for valido
        std::string getNome() const;                                    //retorna o "nome" do objeto
};

inline std::string Nome::getNome() const{                               //metodo inline para retornar o nome do objeto
    return nome;
}


#endif // NOME_H_INCLUDED
