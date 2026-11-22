#ifndef AVENTURATEXTUAL_HABITACION_H
#define AVENTURATEXTUAL_HABITACION_H

#include <memory>
#include <string>
#include <vector>
#include "Enemigo.h"
#include "Objeto.h"

class Habitacion {
private:
    std::string nombre;
    std::string descripcion;
    std::vector<std::unique_ptr<Enemigo>> enemigos;   // composicion: la habitacion es la duena
    std::vector<std::unique_ptr<Objeto>> objetos;     // objetos en el suelo
    std::vector<Habitacion*> salidas;                 // asociacion: apunta a otras habitaciones

public:
    Habitacion(const std::string& nombre, const std::string& descripcion);

    void agregarEnemigo(std::unique_ptr<Enemigo> enemigo);
    void agregarObjeto(std::unique_ptr<Objeto> objeto);
    void conectar(Habitacion* destino);

    int getCantidadSalidas() const;
    Habitacion* getSalida(int opcion) const;          // opcion empieza en 1; nullptr si no existe
    Enemigo* getEnemigoVivo() const;                  // nullptr si no hay
    std::vector<std::unique_ptr<Objeto>> recogerObjetos();

    std::string getNombre() const;
    void mostrar() const;
    void mostrarSalidas() const;
};

#endif