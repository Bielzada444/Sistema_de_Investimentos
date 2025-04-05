//
// Criado por Henrique em 04/04/2025.
// Matricula: 241020840
#ifndef DATA_H
#define DATA_H

#include <chrono>

class Data {
private:
    std::chrono::year_month_day data; // Armazena a data no formato AAAA/MM/DD
    bool validarData(const std::chrono::year_month_day &data);
    public:
    // Metodo privado para validar a data antes de definir o valor
        void setData(const std::chrono::year_month_day &data);
        //talvez seja necessario utlizar o [[nodiscard]] no futuro
       inline std::chrono::year_month_day getData() {
           return data;
       };

};

#endif //DATA_H