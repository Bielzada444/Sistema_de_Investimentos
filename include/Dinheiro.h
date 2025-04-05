//
// Criado por Henrique em 04/04/2025.
// Matricula: 241020840

#ifndef DINHEIRO_H
#define DINHEIRO_H


class Dinheiro {
      private:
        double valor;
        bool validarValor(const double &valor);
        double arrendodar(const double &valor);
       public:
         void setValor(const double &valor);
        inline double getValor()  {
           return valor;
    }
};
#endif //DINHEIRO_H
