#include "JefeFinal.h"
#include <iostream>

JefeFinal::JefeFinal() : Enemigo("Señor Oscuro", 140, 10, 100), turnos(0), enfurecido(false) {}

void JefeFinal::atacar(Entidad& objetivo) {
    this->turnos++;

    // Habilidad 1: FURIA. Con la mitad de la vida su ataque aumenta (una sola vez).
    if (!this->enfurecido && this->vida <= this->vidaMaxima / 2) {
        this->enfurecido = true;
        this->aumentarAtaque(5);
        std::cout << this->nombre << " entra en FURIA. ¡Su ataque aumenta a " << this->ataque << "!\n";
    }

    if (this->turnos % 3 == 0) {
        // Habilidad 2: DRENAR VIDA. Hace daño y se cura lo mismo que causó.
        int danio = objetivo.recibirDanio(this->ataque + 4);
        this->curar(danio);
        std::cout << this->nombre << " DRENA LA VIDA de " << objetivo.getNombre()
                  << ": le hace " << danio << " de daño y se cura " << danio << ".\n";
    } else {
        int danio = objetivo.recibirDanio(this->ataque);
        std::cout << this->nombre << " lanza un golpe de sombras a " << objetivo.getNombre()
                  << " y le hace " << danio << " de daño.\n";
    }
}