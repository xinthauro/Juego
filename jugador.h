#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include "baraja.h"
#include "naipe.h"

class Jugador {
public:
    Jugador() : escalera(0), escaleraReal(0) {}
    void tomarCarta(Naipe naipe);
    std::vector<Naipe>& verCartas();
    void descartarCartas(void);
    void aumentarEscalera();
    void aumentarEscaleraReal();
    int obtenerEscalera();
    int obtenerEscaleraReal();
    int obtenerPuntaje();
    friend std::ostream& operator<<(std::ostream& os, const Jugador& jugador);
private:
    std::vector<Naipe> cartas;
    int escalera;
    int escaleraReal;
};

#endif // JUGADOR_H

