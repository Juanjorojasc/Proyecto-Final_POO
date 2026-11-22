#ifndef AVENTURATEXTUAL_ENTIDAD_H
#define AVENTURATEXTUAL_ENTIDAD_H

#include <string>

class Entidad {
protected:
    std::string nombre;
    int vida;
    int vidaMaxima;
    int ataque;

public:
    Entidad(const std::string& nombre, int vida, int ataque);
    virtual ~Entidad() = default;

    virtual void atacar(Entidad& objetivo) = 0;   // virtual pura -> clase abstracta

    void recibirDanio(int danio);
    void curar(int cantidad);
    void aumentarAtaque(int cantidad);
    bool estaVivo() const;

    std::string getNombre() const;
    int getVida() const;
    int getVidaMaxima() const;
    int getAtaque() const;
};

#endif