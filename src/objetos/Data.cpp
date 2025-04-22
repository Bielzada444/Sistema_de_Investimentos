
//
// Criado por Henrique em 04/04/2025.
// Matricula: 241020840

#include "Data.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std::chrono;

bool Data::validarData(const year_month_day& data) {
    // Verifica se o ano é negativo
    if (static_cast<int>(data.year()) < 0) {
        throw DominioException("Ano negativo nao e aceito.");
    }

    // Verifica se a data não é válida de acordo com a biblioteca <chrono>
    if (!data.ok()) {
        throw DominioException("Data invalida, verifique as informacoes digitadas.");
    }
    
    return true;
}

year_month_day Data::stringParaData(const std::string& dataString) {
    // Verifica se a string tem exatamente 8 caracteres e são todos dígitos
    if (dataString.length() != 8 || dataString.find_first_not_of("0123456789") != std::string::npos) {
        throw DominioException("Data deve estar no formato AAAAMMDD com apenas digitos.");
    }

    int ano = std::stoi(dataString.substr(0, 4));
    unsigned mes = std::stoi(dataString.substr(4, 2));
    unsigned dia = std::stoi(dataString.substr(6, 2));

    return year_month_day{year{ano}, month{mes}, day{dia}};
}



void Data::setData(const std::string& dataString) {
    year_month_day novaData = stringParaData(dataString);
    if (validarData(novaData)) {
        valor = novaData;
    }
}

void Data::setData(const year_month_day& data) {
    if (validarData(data)) {
        valor = data;
    }
}

std::string Data::getData() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(4) << static_cast<int>(valor.year())
        << std::setw(2) << static_cast<unsigned>(valor.month())
        << std::setw(2) << static_cast<unsigned>(valor.day());
    return oss.str();
}

year_month_day Data::getDataPrimeiro() const {
    return valor;
}
