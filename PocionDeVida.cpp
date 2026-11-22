#include "PocionDeVida.h"
#include <iostream>

PocionDeVida::PocionDeVida(const std::string& nombre, int curacion)
    : Objeto(nombre, curacion) {}

void PocionDeVida::usar(Entidad& usuario) {
    usuario.curar(this->valor);
    std::cout << usuario.getNombre() << " usa " << this->nombre
              << ". Vida: " << usuario.getVida() << "/" << usuario.getVidaMaxima() << "\n";
}

std::string PocionDeVida::getDescripcion() const {
    return "+" + std::to_string(this->valor) + " de vida";
}