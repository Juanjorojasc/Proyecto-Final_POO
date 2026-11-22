#include "Entidad.h"

Entidad::Entidad(const std::string& nombre, int vida, int ataque)
    : nombre(nombre), vida(vida), vidaMaxima(vida), ataque(ataque) {}

void Entidad::recibirDanio(int danio) {
    this->vida -= danio;
    if (this->vida < 0) this->vida = 0;
}

void Entidad::curar(int cantidad) {
    this->vida += cantidad;
    if (this->vida > this->vidaMaxima) this->vida = this->vidaMaxima;
}

void Entidad::aumentarAtaque(int cantidad) {
    this->ataque += cantidad;
}

bool Entidad::estaVivo() const { return this->vida > 0; }

std::string Entidad::getNombre() const { return this->nombre; }
int Entidad::getVida() const { return this->vida; }
int Entidad::getVidaMaxima() const { return this->vidaMaxima; }
int Entidad::getAtaque() const { return this->ataque; }