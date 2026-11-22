#ifndef AVENTURATEXTUAL_JUGADOR_H
#define AVENTURATEXTUAL_JUGADOR_H

#include "Entidad.h"
#include "Objeto.h"
#include <memory>
#include <vector>

class Jugador : public Entidad {
private:
    std::vector<std::unique_ptr<Objeto>> inventario;
    int nivel;
    int experiencia;

public:
    Jugador(const std::string& nombre, int vida, int ataque);

    void atacar(Entidad& objetivo) override;

    void agregarObjeto(std::unique_ptr<Objeto> objeto);
    bool tieneObjetos() const;
    void mostrarInventario() const;
    bool usarObjeto(int indice);   // true si se uso el objeto

    void ganarExperiencia(int cantidad);
    int getNivel() const;
    int getExperiencia() const;
    int getExperienciaSiguienteNivel() const;
};

#endif