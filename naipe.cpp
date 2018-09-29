#include "naipe.h"

Palo& operator++(Palo& palo) {
    palo = static_cast<Palo>(static_cast<int>(palo) + 1);
    return palo;
}

Valor& operator++(Valor& valor) {
    valor = static_cast<Valor>(static_cast<int>(valor) + 1);
    return valor;
}

std::ostream& operator<<(std::ostream& os, const Palo& palo) {
    switch (palo) {
        case Palo::ORO:
            os << "ORO";
            break;
        case Palo::TREBOL:
            os << "TREBOL";
            break;
        case Palo::CORAZON:
            os << "CORAZON";
            break;
        case Palo::ESPADA:
            os << "ESPADA";
            break;
        default:
            os << "";
            break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Valor& valor) {
    switch (valor) {
        case Valor::UNO:
            os<< "UNO";
            break;
        case Valor::DOS:
            os << "DOS";
            break;
        case Valor::TRES:
            os << "TRES";
            break;
        case Valor::CUATRO:
            os << "CUATRO";
            break;
        case Valor::CINCO:
            os << "CINCO";
            break;
        case Valor::SEIS:
            os << "SEIS";
            break;
        case Valor::SIETE:
            os << "SIETE";
            break;
        case Valor::OCHO:
            os << "OCHO";
            break;
        case Valor::NUEVE:
            os << "NUEVE";
            break;
        case Valor::DIEZ:
            os << "DIEZ";
            break;
        case Valor::SOTA:
            os << "SOTA";
            break;
        case Valor::CABALLERO:
            os << "CABALLERO";
            break;
        case Valor::REY:
            os << "REY";
            break;
        default:
            os << "";
            break;
    }
    return os;
}

Naipe::Naipe(const Naipe& other) {
    palo = other.palo;
    valor = other.valor;
}

Palo Naipe::obtenerPalo() {
    return palo;
}

Valor Naipe::obtenerValor() {
    return valor;
}

bool Naipe::operator<(const Naipe& other) {
    return static_cast<int>(this->valor) < static_cast<int>(other.valor);
}

std::ostream& operator<<(std::ostream& os, const Naipe& naipe) {
    return os << naipe.palo << " " << naipe.valor;
}

