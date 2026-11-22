#include "Dragon.h"
#include <iostream>

Dragon::Dragon() : Enemigo("Dragón", 100, 12, 50), turnos(0) {}

void Dragon::atacar(Entidad& objetivo) {
    this->turnos++;
    if (this->turnos % 3 == 0) {
        int danio = objetivo.recibirDanio(this->ataque * 2);
        std::cout << this->nombre << " lanza su ALIENTO DE FUEGO sobre " << objetivo.getNombre()
                  << " y le hace " << danio << " de daño.\n";
    } else {
        int danio = objetivo.recibirDanio(this->ataque);
        std::cout << this->nombre << " muerde a " << objetivo.getNombre()
                  << " y le hace " << danio << " de daño.\n";
    }
}