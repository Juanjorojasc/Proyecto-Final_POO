#ifndef AVENTURATEXTUAL_OBJETO_H
#define AVENTURATEXTUAL_OBJETO_H

#include <string>
#include "Entidad.h"

class Objeto {
protected:
    std::string nombre;
    int valor;

public:
    Objeto(const std::string& nombre, int valor);
    virtual ~Objeto() = default;

    virtual void usar(Entidad& usuario) = 0;          // cada objeto se usa a su manera
    virtual std::string getDescripcion() const = 0;   // cada objeto se describe a su manera

    std::string getNombre() const;
    int getValor() const;
};

#endif