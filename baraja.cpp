#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "baraja.h"

Baraja::Baraja() {
    for (Palo p = Palo::ORO; p < Palo::MAX; ++p) {
        for (Valor v = Valor::UNO; v < Valor::MAX; ++v) {
            baraja.push_back(Naipe(p, v));
        }
    }
}

void Baraja::barajar() {
    unsigned s = baraja.size();
    for (unsigned i = 0; i < s; ++i) {
        int r = Baraja::obtenerNumeroAleatorio(s);
        Naipe t = Naipe(baraja[r]);
        baraja.erase(baraja.begin() + r);
        baraja.push_back(t);
    }
}

int Baraja::cantidadCartasDisponibles() {
    return baraja.size();
}

Naipe Baraja::obtenerCarta() {
    Naipe naipe(baraja.back());
    baraja.pop_back();
    return naipe;
}

bool Baraja::validarEscalera(std::vector<Naipe>& cartas) {
    bool test = false;
    if (cartas.size() != 5) {
        return test;
    }
    std::sort(cartas.begin(), cartas.end());
    for (unsigned i = 0; i < cartas.size() - 1; ++i) {
        if ((static_cast<int>(cartas[i + 1].obtenerValor()) - static_cast<int>(cartas[i].obtenerValor())) == 1) {
            test = true;
        } else {
            test = false;
            break;
        }
    }
    return test;
}

bool Baraja::validarEscaleraReal(std::vector<Naipe>& cartas) {
    bool test = false;
    if (cartas.size() != 5) {
        return test;
    }
    if (validarEscalera(cartas) != true) {
        return test;
    }
    for (unsigned i = 0; i < cartas.size() - 1; ++i) {
        if (static_cast<int>(cartas[i + 1].obtenerPalo()) == static_cast<int>(cartas[i].obtenerPalo())) {
            test = true;
        } else {
            test = false;
            break;
        }
    }
    return test;
}

std::ostream& operator<<(std::ostream& os, const Baraja& baraja) {
    for (auto n: baraja.baraja) {
        os << n << "\n";
    }
    return os;
}

void Baraja::iniciarSemilla() {
    std::srand(std::time(0));
}

int Baraja::obtenerNumeroAleatorio(int n) {
    return std::rand() % n;
}

