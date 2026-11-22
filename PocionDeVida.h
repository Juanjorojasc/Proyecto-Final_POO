#ifndef AVENTURATEXTUAL_POCIONDEVIDA_H
#define AVENTURATEXTUAL_POCIONDEVIDA_H

#include "Objeto.h"

class PocionDeVida : public Objeto {
public:
    PocionDeVida(const std::string& nombre, int curacion);
    void usar(Entidad& usuario) override;
    std::string getDescripcion() const override;
};

#endif