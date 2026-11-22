#include "Habitacion.h"
#include <iostream>

Habitacion::Habitacion(const std::string& nombre, const std::string& descripcion)
    : nombre(nombre), descripcion(descripcion) {}

void Habitacion::agregarEnemigo(std::unique_ptr<Enemigo> enemigo) {
    this->enemigos.push_back(std::move(enemigo));
}

void Habitacion::agregarObjeto(std::unique_ptr<Objeto> objeto) {
    this->objetos.push_back(std::move(objeto));
}

void Habitacion::conectar(Habitacion* destino) {
    this->salidas.push_back(destino);
}

int Habitacion::getCantidadSalidas() const {
    return static_cast<int>(this->salidas.size());
}

Habitacion* Habitacion::getSalida(int opcion) const {
    if (opcion < 1 || opcion > this->getCantidadSalidas()) return nullptr;
    return this->salidas[opcion - 1];
}

Enemigo* Habitacion::getEnemigoVivo() const {
    for (const auto& e : this->enemigos) {
        if (e->estaVivo()) return e.get();
    }
    return nullptr;
}

std::vector<std::unique_ptr<Objeto>> Habitacion::recogerObjetos() {
    return std::move(this->objetos);   // el vector queda vacio
}

std::string Habitacion::getNombre() const { return this->nombre; }

void Habitacion::mostrar() const {
    std::cout << "\n=== " << this->nombre << " ===\n" << this->descripcion << "\n";
    Enemigo* enemigo = this->getEnemigoVivo();
    if (enemigo != nullptr) {
        std::cout << "¡Aquí hay un enemigo: " << enemigo->getNombre() << "!\n";
    }
}

void Habitacion::mostrarSalidas() const {
    for (size_t i = 0; i < this->salidas.size(); i++) {
        std::cout << (i + 1) << ". Ir a: " << this->salidas[i]->getNombre() << "\n";
    }
}