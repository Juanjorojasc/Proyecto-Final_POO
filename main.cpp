#include <iostream>
#include <string>
#include "Juego.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);   // para que se vean la ñ y las tildes
#endif

    std::string nombre;
    std::cout << "¿Cómo se llama tu héroe? ";
    std::getline(std::cin, nombre);
    if (nombre.empty()) nombre = "Héroe";

    Juego juego(nombre);
    juego.iniciar();
    return 0;
}
