#ifndef AVENTURATEXTUAL_ORCO_H
#define AVENTURATEXTUAL_ORCO_H

#include "Enemigo.h"

class Orco : public Enemigo {
public:
    Orco();
    void atacar(Entidad& objetivo) override;
};

#endif