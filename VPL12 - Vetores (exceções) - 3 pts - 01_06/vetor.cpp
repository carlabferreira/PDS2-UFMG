 #include "vetor.h"

#include <string>

Vetor::Vetor(int i, int f) {
    if(i > f) {
        IntervaloVazio x;
        x.inicio = i;
        x.fim = f;
        throw x;
    }
    elementos_ = new string[(f - i) + 1];
    inicializado = new bool[(f - i) + 1];
    inicio_ = i;
    fim_ = f;
}

void Vetor::atribuir(int i, string s) {
    if(i < inicio_ || i > fim_) {
        IndiceInvalido x;
        x.inicio = inicio_;
        x.fim = fim_;
        x.indice = i;
        throw x;
    }
    elementos_[i - inicio_] = s;
    inicializado[i - inicio_] = true;
}

string Vetor::valor(int i) const {
    if(i < inicio_ || i > fim_) {
        IndiceInvalido x;
        x.inicio = inicio_;
        x.fim = fim_;
        x.indice = i;
        throw x;
    }
    if (!inicializado[i - inicio_]) {
        IndiceNaoInicializado x;
        x.indice = i;
        throw(x);
    }
    return *(elementos_  + i-inicio_);
}

Vetor::~Vetor() {
    delete[] elementos_;
}