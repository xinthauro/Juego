#ifndef BARAJA_H
#define BARAJA_H

#include <iostream>
#include <vector>

#include "naipe.h"

class Baraja : public Naipe {
public:
    Baraja();
    void barajar();
    int cantidadCartasDisponibles();
    Naipe obtenerCarta();
    bool validarEscalera(std::vector<Naipe>& cartas);
    bool validarEscaleraReal(std::vector<Naipe>& cartas);
    friend std::ostream& operator<<(std::ostream& os, const Baraja& baraja);
    static void iniciarSemilla();
    static int obtenerNumeroAleatorio(int n);
private:
    std::vector<Naipe> baraja;
};

#endif // BARAJA_H

