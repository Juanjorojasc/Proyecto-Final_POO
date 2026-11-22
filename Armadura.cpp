#include "Armadura.h"
#include <iostream>

Armadura::Armadura(const std::string& nombre, int defensa)
    : Objeto(nombre, defensa) {}

void Armadura::usar(Entidad& usuario) {
    usuario.aumentarDefensa(this->valor);
    std::cout << usuario.getNombre() << " se pone " << this->nombre
              << ". Defensa: " << usuario.getDefensa() << "\n";
}

std::string Armadura::getDescripcion() const {
    return "+" + std::to_string(this->valor) + " de defensa";
}