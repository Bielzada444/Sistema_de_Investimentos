//
// Criado por Henrique em 04/04/2025.
// Matricula: 241020840

#include "Data.h"


bool Data::validarData(const std::chrono::year_month_day &data) {
    // Verifica se o ano e negativo, o mes ou o dia sao zero (valores invalidos)
    if (static_cast<int>(data.year()) < 0 ||
       static_cast<unsigned>(data.month()) == 0 ||
       static_cast<unsigned>(data.day()) == 0) {
        throw std::invalid_argument("Numeros negativos ou zeros nao sao aceitos.");
    }

    // Verifica se a data nao e válida de acordo com a biblioteca <chrono>
    if (!data.ok()) {
        throw std::invalid_argument("Data invalida, verifique as informacoes digitadas ou"
                                    " veja se ela esta no formato AAAA/MM/DD.");
    }
    //Se passou por todas as verificacoes, a data e valida
        return true;
}

void Data::setData(const std::chrono::year_month_day &data) {
    if (validarData(data)) {} // Essa condicao nao faz nada, mas a validacao acontece

    this->data = data; // Atribui a data se for valida
}


