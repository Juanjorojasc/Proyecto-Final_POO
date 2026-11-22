#include "Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string& nombre, int vida, int ataque)
    : Entidad(nombre, vida, ataque) {}

void Jugador::atacar(Entidad& objetivo) {
    std::cout << this->nombre << " ataca a " << objetivo.getNombre()
              << " y le hace " << this->ataque << " de daño.\n";
    objetivo.recibirDanio(this->ataque);
}

void Jugador::agregarObjeto(std::unique_ptr<Objeto> objeto) {
    this->inventario.push_back(std::move(objeto));
}

bool Jugador::tieneObjetos() const {
    return !this->inventario.empty();
}

void Jugador::mostrarInventario() const {
    if (this->inventario.empty()) {
        std::cout << "Inventario vacío.\n";
        return;
    }
    std::cout << "Inventario:\n";
    for (size_t i = 0; i < this->inventario.size(); i++) {
        std::cout << "  " << (i + 1) << ". " << this->inventario[i]->getNombre()
                  << " (" << this->inventario[i]->getDescripcion() << ")\n";
    }
}

bool Jugador::usarObjeto(int indice) {
    if (indice < 0 || indice >= static_cast<int>(this->inventario.size())) {
        std::cout << "Ese objeto no existe.\n";
        return false;
    }
    this->inventario[indice]->usar(*this);                       // polimorfismo
    this->inventario.erase(this->inventario.begin() + indice);   // se consume
    return true;
}