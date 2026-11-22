#include "Espada.h"
#include <iostream>

Espada::Espada(const std::string& nombre, int bonoAtaque)
    : Objeto(nombre, bonoAtaque) {}

void Espada::usar(Entidad& usuario) {
    usuario.aumentarAtaque(this->valor);
    std::cout << usuario.getNombre() << " equipa " << this->nombre
              << ". Ataque: " << usuario.getAtaque() << "\n";
}

std::string Espada::getDescripcion() const {
    return "+" + std::to_string(this->valor) + " de ataque";
}