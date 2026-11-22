#ifndef AVENTURATEXTUAL_DRAGON_H
#define AVENTURATEXTUAL_DRAGON_H

#include "Enemigo.h"

class Dragon : public Enemigo {
private:
    int turnos;

public:
    Dragon();
    void atacar(Entidad& objetivo) override;
};

#endif