#include "Orco.h"
#include <iostream>

Orco::Orco() : Enemigo("Orco", 40, 8, 30) {}

void Orco::atacar(Entidad& objetivo) {
    int danio = objetivo.recibirDanio(this->ataque);
    std::cout << this->nombre << " golpea con su garrote a " << objetivo.getNombre()
              << " y le hace " << danio << " de daño.\n";
}