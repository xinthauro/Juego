#include <iostream>
#include "jugador.h"
#include "baraja.h"
#include "naipe.h"

const int JUGADAS = 10000;
const int VALOR_MINIMO_BARAJA = 10;
const int VALOR_BARAJA_JUGADOR = 5;

int main() {
    // Inicia la semilla para numeros aleatorios
    Baraja::iniciarSemilla();
    // Nuevos jugadores
    Jugador jugador;
    Jugador casa;
    for (auto i = 0; i < JUGADAS; ++i) {
        // Nueva baraja
        Baraja *baraja = new Baraja();
        baraja->barajar();
        baraja->barajar();
        baraja->barajar();
        while (baraja->cantidadCartasDisponibles() >= VALOR_MINIMO_BARAJA) {
            // Reparte cartas
            for (auto i = 0; i < VALOR_BARAJA_JUGADOR; ++i) {
                jugador.tomarCarta(baraja->obtenerCarta());
                casa.tomarCarta(baraja->obtenerCarta());
            }
            // Valida puntos jugador
            if (baraja->validarEscaleraReal(jugador.verCartas()) == true) {
                jugador.aumentarEscaleraReal();
                std::cout << "Jugador obtuvo escalera real\n" << jugador << std::endl;
            } else if (baraja->validarEscalera(jugador.verCartas()) == true) {
                jugador.aumentarEscalera();
                std::cout << "Jugador obtuvo escalera\n" << jugador << std::endl;
            } else {
            }
            // Valida puntos casa
            if (baraja->validarEscaleraReal(casa.verCartas()) == true) {
                casa.aumentarEscaleraReal();
                std::cout << "Casa obtuvo escalera real\n" << casa << std::endl;
            } else if (baraja->validarEscalera(casa.verCartas()) == true) {
                casa.aumentarEscalera();
                std::cout << "Casa obtuvo escalera\n" << casa << std::endl;
            } else {
            }
            // Descarta cartas jugadores
            jugador.descartarCartas();
            casa.descartarCartas();
        }
        // Hay que obtener una nueva baraja
        delete baraja;
    }

    int entrada = 0;
    bool condicion = true;
    do {
        // Presenta las opciones
        std::cout << "\n";
        std::cout << "1. Ver puntaje Jugador\n";
        std::cout << "2. Ver puntaje Casa\n";
        std::cout << "3. Salir\n\n";
        std::cin >> entrada;
        if (std::cin.fail()) {
            throw std::runtime_error("La entrada no es un entero\n");
        }
        switch (entrada) {
            case 1:
                std::cout << "El jugador obtuvo:\n";
                std::cout << jugador.obtenerEscaleraReal() << " escalera(s) real(es)\n";
                std::cout << jugador.obtenerEscalera() << " escalera(s)\n";
                std::cout << "Para un total de " << jugador.obtenerPuntaje() << " punto(s).\n\n";
                break;
            case 2:
                std::cout << "La casa obtuvo:\n";
                std::cout << casa.obtenerEscaleraReal() << " escalera(s) real(es)\n";
                std::cout << casa.obtenerEscalera() << " escalera(s)\n";
                std::cout << "Para un total de " << casa.obtenerPuntaje() << " punto(s).\n\n";
                break;
            case 3:
                condicion = false;
                break;
            default:
                break;
        }
    } while (condicion);

    return 0;
}

