#include "Orco.h"
#include <iostream>

Orco::Orco() : Enemigo("Orco", 40, 8, 30) {}

void Orco::atacar(Entidad& objetivo) {
    std::cout << this->nombre << " golpea con su garrote a " << objetivo.getNombre()
              << " y le hace " << this->ataque << " de daño.\n";
    objetivo.recibirDanio(this->ataque);
}