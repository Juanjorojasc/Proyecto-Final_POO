#ifndef AVENTURATEXTUAL_JEFEFINAL_H
#define AVENTURATEXTUAL_JEFEFINAL_H

#include "Enemigo.h"

class JefeFinal : public Enemigo {
private:
    int turnos;
    bool enfurecido;   // la furia se activa una sola vez, con la mitad de la vida

public:
    JefeFinal();
    void atacar(Entidad& objetivo) override;
};

#endif