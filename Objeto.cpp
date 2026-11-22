#include "Objeto.h"

Objeto::Objeto(const std::string& nombre, int valor)
    : nombre(nombre), valor(valor) {}

std::string Objeto::getNombre() const { return this->nombre; }
int Objeto::getValor() const { return this->valor; }