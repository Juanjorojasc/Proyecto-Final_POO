#ifndef AVENTURATEXTUAL_ENEMIGO_H
#define AVENTURATEXTUAL_ENEMIGO_H

#include "Entidad.h"

class Enemigo : public Entidad {
protected:
    int experiencia;

public:
    Enemigo(const std::string& nombre, int vida, int ataque, int experiencia);
    int getExperiencia() const;
};

#endif