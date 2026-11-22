#ifndef AVENTURATEXTUAL_ESPADA_H
#define AVENTURATEXTUAL_ESPADA_H

#include "Objeto.h"

class Espada : public Objeto {
public:
    Espada(const std::string& nombre, int bonoAtaque);
    void usar(Entidad& usuario) override;
    std::string getDescripcion() const override;
};

#endif