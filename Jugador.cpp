#include "Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string& nombre, int vida, int ataque)
    : Entidad(nombre, vida, ataque), nivel(1), experiencia(0) {}

void Jugador::atacar(Entidad& objetivo) {
    int danio = objetivo.recibirDanio(this->ataque);
    std::cout << this->nombre << " ataca a " << objetivo.getNombre()
              << " y le hace " << danio << " de daño.\n";
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

int Jugador::getNivel() const { return this->nivel; }
int Jugador::getExperiencia() const { return this->experiencia; }
int Jugador::getExperienciaSiguienteNivel() const { return 30 * this->nivel; }

void Jugador::ganarExperiencia(int cantidad) {
    this->experiencia += cantidad;
    std::cout << "Ganaste " << cantidad << " puntos de experiencia.\n";

    while (this->experiencia >= this->getExperienciaSiguienteNivel()) {
        this->experiencia -= this->getExperienciaSiguienteNivel();
        this->nivel++;
        this->vidaMaxima += 15;
        this->vida += 15;
        this->ataque += 3;
        std::cout << "*** ¡SUBISTE AL NIVEL " << this->nivel << "! ***\n"
                  << "Vida máxima: " << this->vidaMaxima
                  << " | Ataque: " << this->ataque << "\n";
    }
}