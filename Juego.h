#ifndef AVENTURATEXTUAL_JUEGO_H
#define AVENTURATEXTUAL_JUEGO_H

#include <memory>
#include <string>
#include <vector>
#include "Habitacion.h"
#include "Jugador.h"

class Juego {
private:
    Jugador jugador;
    std::vector<std::unique_ptr<Habitacion>> habitaciones;   // composicion: el juego es el dueno del mapa
    Habitacion* habitacionActual;
    Habitacion* habitacionFinal;
    bool terminado;

    void crearMapa();
    void entregarEquipo();
    void contarHistoria() const;
    void mostrarEstado() const;
    std::string leerLinea();
    int leerNumero();
    void combatir(Enemigo& enemigo);
    void recogerObjetos();
    void elegirCamino();

public:
    Juego(const std::string& nombreJugador);
    void iniciar();
};

#endif