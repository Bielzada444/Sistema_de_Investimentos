#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
inline void limparTela() {
    system(CLEAR);
}

#endif // UTILS_HPP_INCLUDED
