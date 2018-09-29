#include "jugador.h"

void Jugador::tomarCarta(Naipe naipe) {
    cartas.push_back(naipe);
}

std::vector<Naipe>& Jugador::verCartas() {
    return this->cartas;
}

void Jugador::descartarCartas() {
    cartas.clear();
}

void Jugador::aumentarEscalera() {
    escalera++;
}

void Jugador::aumentarEscaleraReal() {
    escaleraReal++;
}

int Jugador::obtenerEscalera() {
    return escalera;
}

int Jugador::obtenerEscaleraReal() {
    return escaleraReal;
}

int Jugador::obtenerPuntaje() {
    return 3 * obtenerEscalera() + 5 * obtenerEscaleraReal();
}

std::ostream& operator<<(std::ostream& os, const Jugador& jugador) {
    for (auto n: jugador.cartas) {
        os << n << "\n";
    }
    return os;
}

