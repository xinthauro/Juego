#ifndef NAIPE_H
#define NAIPE_H

#include <iostream>

enum class Palo {
    ORO, TREBOL, CORAZON, ESPADA, MAX
};

enum class Valor {
    UNO,
    DOS,
    TRES,
    CUATRO,
    CINCO,
    SEIS,
    SIETE,
    OCHO,
    NUEVE,
    DIEZ,
    SOTA,
    CABALLERO,
    REY,
    MAX
};

Palo& operator++(Palo& palo);
Valor& operator++(Valor& valor);
std::ostream& operator<<(std::ostream& os, const Palo& palo);
std::ostream& operator<<(std::ostream& os, const Valor& valor);

class Naipe {
public:
    Naipe() : palo(Palo::ORO), valor(Valor::UNO) {}
    Naipe(Palo palo, Valor valor) : palo(palo), valor(valor) {}
    Naipe(const Naipe& other);
    Palo obtenerPalo();
    Valor obtenerValor();
    bool operator<(const Naipe& other);
    friend std::ostream& operator<<(std::ostream& os, const Naipe& naipe);
private:
    Palo palo;
    Valor valor;
};

#endif // NAIPE_H

