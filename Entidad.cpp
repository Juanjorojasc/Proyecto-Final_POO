#include "Entidad.h"

Entidad::Entidad(const std::string& nombre, int vida, int ataque)
    : nombre(nombre), vida(vida), vidaMaxima(vida), ataque(ataque), defensa(0) {}

int Entidad::recibirDanio(int danio) {
    int danioReal = danio - this->defensa;   // la defensa reduce el daño
    if (danioReal < 1) danioReal = 1;        // siempre se recibe al menos 1
    this->vida -= danioReal;
    if (this->vida < 0) this->vida = 0;
    return danioReal;
}

void Entidad::curar(int cantidad) {
    this->vida += cantidad;
    if (this->vida > this->vidaMaxima) this->vida = this->vidaMaxima;
}

void Entidad::aumentarAtaque(int cantidad) {
    this->ataque += cantidad;
}

void Entidad::aumentarDefensa(int cantidad) {
    this->defensa += cantidad;
}

bool Entidad::estaVivo() const { return this->vida > 0; }

std::string Entidad::getNombre() const { return this->nombre; }
int Entidad::getVida() const { return this->vida; }
int Entidad::getVidaMaxima() const { return this->vidaMaxima; }
int Entidad::getAtaque() const { return this->ataque; }
int Entidad::getDefensa() const { return this->defensa; }