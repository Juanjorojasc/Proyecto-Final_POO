#include "Enemigo.h"

Enemigo::Enemigo(const std::string& nombre, int vida, int ataque, int experiencia)
    : Entidad(nombre, vida, ataque), experiencia(experiencia) {}

int Enemigo::getExperiencia() const { return this->experiencia; }