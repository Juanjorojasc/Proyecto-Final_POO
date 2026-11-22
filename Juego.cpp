#include "Juego.h"
#include <iostream>
#include "Orco.h"
#include "Dragon.h"
#include "PocionDeVida.h"
#include "Espada.h"

Juego::Juego(const std::string& nombreJugador)
    : jugador(nombreJugador, 100, 10),
      habitacionActual(nullptr),
      habitacionFinal(nullptr),
      terminado(false) {
    this->crearMapa();
    this->entregarEquipo();
}

void Juego::crearMapa() {
    auto entrada = std::make_unique<Habitacion>("Entrada de la montaña",
        "Estás al pie de la montaña del Dragón. Frente a ti se abren tres caminos.");
    auto biblioteca = std::make_unique<Habitacion>("Biblioteca",
        "Una sala silenciosa llena de libros viejos y polvo.");
    auto cripta = std::make_unique<Habitacion>("Cripta",
        "Un lugar frío y húmedo. Hay tumbas rotas por todas partes.");
    auto pasillo = std::make_unique<Habitacion>("Pasillo oscuro",
        "Un pasillo estrecho. Escuchas respiraciones pesadas más adelante.");
    auto guarida = std::make_unique<Habitacion>("Guarida del Dragón",
        "Una enorme caverna llena de oro y huesos. El aire huele a azufre. Al fondo, el Rey espera encadenado.");

    biblioteca->agregarObjeto(std::make_unique<PocionDeVida>("Poción grande", 50));
    cripta->agregarEnemigo(std::make_unique<Orco>());
    cripta->agregarObjeto(std::make_unique<Espada>("Espada de plata", 8));
    pasillo->agregarEnemigo(std::make_unique<Orco>());
    pasillo->agregarObjeto(std::make_unique<PocionDeVida>("Poción media", 30));
    guarida->agregarEnemigo(std::make_unique<Dragon>());

    entrada->conectar(biblioteca.get());
    entrada->conectar(pasillo.get());
    entrada->conectar(cripta.get());
    biblioteca->conectar(entrada.get());
    cripta->conectar(entrada.get());
    pasillo->conectar(entrada.get());
    pasillo->conectar(guarida.get());
    guarida->conectar(pasillo.get());

    this->habitacionActual = entrada.get();
    this->habitacionFinal = guarida.get();

    this->habitaciones.push_back(std::move(entrada));
    this->habitaciones.push_back(std::move(biblioteca));
    this->habitaciones.push_back(std::move(cripta));
    this->habitaciones.push_back(std::move(pasillo));
    this->habitaciones.push_back(std::move(guarida));
}

void Juego::entregarEquipo() {
    this->jugador.agregarObjeto(std::make_unique<Espada>("Espada de hierro", 5));
    this->jugador.agregarObjeto(std::make_unique<PocionDeVida>("Poción pequeña", 30));
}

void Juego::contarHistoria() const {
    std::cout << "\n--- LA HISTORIA ---\n";
    std::cout << "El Dragón ha secuestrado al Rey y lo mantiene encadenado en su guarida,\n";
    std::cout << "al fondo de la montaña. Sus orcos vigilan cada rincón.\n";
    std::cout << "La única esperanza es la Operación Jaque: una misión secreta\n";
    std::cout << "de un solo soldado. Ese soldado eres tú, " << this->jugador.getNombre() << ".\n";
    std::cout << "\nOBJETIVO: llega a la Guarida, derrota al Dragón y rescata al Rey.\n";

    std::cout << "\nAntes de partir, el comandante te entrega este equipo:\n";
    this->jugador.mostrarInventario();
    std::cout << "Recuerda: solo podrás USAR tus objetos durante un combate.\n";
    std::cout << "Fuera de combate solo puedes revisar tu inventario.\n";
}

void Juego::mostrarEstado() const {
    std::cout << "[" << this->jugador.getNombre() << "] Vida: " << this->jugador.getVida()
              << "/" << this->jugador.getVidaMaxima()
              << " | Ataque: " << this->jugador.getAtaque() << "\n";
}

std::string Juego::leerLinea() {
    std::string linea;
    if (!std::getline(std::cin, linea)) {   // fin de la entrada
        this->terminado = true;
        return "";
    }
    return linea;
}

int Juego::leerNumero() {
    std::string texto = this->leerLinea();
    try {
        return std::stoi(texto);
    } catch (...) {
        return -1;
    }
}

void Juego::recogerObjetos() {
    auto objetos = this->habitacionActual->recogerObjetos();
    for (auto& objeto : objetos) {
        std::cout << "Recogiste: " << objeto->getNombre()
                  << " (" << objeto->getDescripcion() << ")\n";
        this->jugador.agregarObjeto(std::move(objeto));
    }
}

void Juego::combatir(Enemigo& enemigo) {
    std::cout << "\n!!! COMBATE contra " << enemigo.getNombre() << " !!!\n";

    while (enemigo.estaVivo() && this->jugador.estaVivo() && !this->terminado) {
        std::cout << "\n";
        this->mostrarEstado();
        std::cout << "Enemigo " << enemigo.getNombre() << ": vida " << enemigo.getVida()
                  << "/" << enemigo.getVidaMaxima() << "\n";
        std::cout << "1. Atacar\n2. Usar objeto\n> ";

        int opcion = this->leerNumero();
        if (this->terminado) break;

        if (opcion == 1) {
            this->jugador.atacar(enemigo);
        } else if (opcion == 2) {
            if (!this->jugador.tieneObjetos()) {
                std::cout << "No tienes objetos.\n";
                continue;
            }
            this->jugador.mostrarInventario();
            std::cout << "Número del objeto (0 para cancelar): ";
            int numero = this->leerNumero();
            if (this->terminado) break;
            if (numero == 0) continue;
            if (!this->jugador.usarObjeto(numero - 1)) continue;   // no gasta turno si falla
        } else {
            std::cout << "Opción inválida.\n";
            continue;
        }

        if (enemigo.estaVivo()) {
            enemigo.atacar(this->jugador);   // turno del enemigo (polimorfismo)
        }
    }

    if (this->terminado) return;

    if (!this->jugador.estaVivo()) {
        std::cout << "\nHas caído en combate... El Rey sigue prisionero. GAME OVER.\n";
        this->terminado = true;
    } else {
        std::cout << "\n¡Derrotaste a " << enemigo.getNombre() << "!\n";
    }
}

void Juego::elegirCamino() {
    bool seMovio = false;
    while (!seMovio && !this->terminado) {
        std::cout << "\n";
        this->mostrarEstado();
        std::cout << "¿Hacia dónde vas?\n";
        this->habitacionActual->mostrarSalidas();

        int cantidad = this->habitacionActual->getCantidadSalidas();
        std::cout << (cantidad + 1) << ". Ver inventario\n";
        std::cout << (cantidad + 2) << ". Salir del juego\n> ";

        int opcion = this->leerNumero();
        if (this->terminado) break;

        if (opcion >= 1 && opcion <= cantidad) {
            this->habitacionActual = this->habitacionActual->getSalida(opcion);
            seMovio = true;
        } else if (opcion == cantidad + 1) {
            this->jugador.mostrarInventario();
        } else if (opcion == cantidad + 2) {
            this->terminado = true;
        } else {
            std::cout << "Opción inválida.\n";
        }
    }
}

void Juego::iniciar() {
    std::cout << "=== OPERACIÓN JAQUE ===\n";
    this->contarHistoria();

    while (!this->terminado) {
        this->habitacionActual->mostrar();

        Enemigo* enemigo = this->habitacionActual->getEnemigoVivo();
        if (enemigo != nullptr) {
            this->combatir(*enemigo);
            if (this->terminado) break;
        }

        this->recogerObjetos();

        if (this->habitacionActual == this->habitacionFinal) {
            std::cout << "\n*** ¡JAQUE MATE! Derrotaste al Dragón y rescataste al Rey. ***\n";
            break;
        }

        this->elegirCamino();
    }
    std::cout << "\nFin del juego.\n";
}