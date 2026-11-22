#ifndef AVENTURATEXTUAL_ARMADURA_H
#define AVENTURATEXTUAL_ARMADURA_H

#include "Objeto.h"

class Armadura : public Objeto {
public:
    Armadura(const std::string& nombre, int defensa);
    void usar(Entidad& usuario) override;
    std::string getDescripcion() const override;
};

#endif