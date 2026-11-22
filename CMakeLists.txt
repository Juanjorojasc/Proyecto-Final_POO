cmake_minimum_required(VERSION 3.20)
project(PROYECTO_FINAL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PROYECTO_FINAL
        main.cpp
        Entidad.cpp Entidad.h
        Enemigo.cpp Enemigo.h
        Orco.cpp Orco.h
        Dragon.cpp Dragon.h
        JefeFinal.cpp JefeFinal.h
        Objeto.cpp Objeto.h
        PocionDeVida.cpp PocionDeVida.h
        Espada.cpp Espada.h
        Armadura.cpp Armadura.h
        Jugador.cpp Jugador.h
        Habitacion.cpp Habitacion.h
        Juego.cpp Juego.h)