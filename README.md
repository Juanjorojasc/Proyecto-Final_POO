# Operación Jaque

Juego de rol (RPG) de aventura textual para consola, hecho en **C++17** con **CLion**.
Proyecto final de **Programación Orientada a Objetos 2026-2** (Pontificia Universidad Javeriana Cali).

## Historia

El **Señor Oscuro** ha secuestrado al Rey y lo mantiene encadenado en su trono, al fondo de una montaña vigilada por orcos y por un dragón. La única esperanza es la **Operación Jaque**: una misión secreta de un solo soldado.

**Objetivo:** llegar a la Sala del Trono Oscuro, derrotar al Señor Oscuro y rescatar al Rey.

## Cómo jugar

- Al iniciar se cuenta la historia y se muestra el equipo inicial: una **Espada de hierro** y una **Poción pequeña**.
- En cada habitación eliges a dónde ir con un menú numerado (no hay norte/sur: eliges por nombre del lugar).
- Si hay un enemigo, comienza un **combate por turnos**: atacar o usar un objeto.
- Los objetos **solo se pueden usar durante un combate**. Fuera de combate solo puedes ver el inventario.
- Tu estado (vida, ataque, defensa, nivel y experiencia) se muestra de forma continua.
- Ganas al derrotar al Señor Oscuro. Pierdes si tu vida llega a 0.
- Explorar la Biblioteca y la Cripta antes de ir al trono te da equipo que hace posible ganar.

## Cómo compilar y ejecutar

Requisitos: CMake 3.20 o superior y un compilador compatible con C++17.

```bash
git clone https://github.com/Juanjorojasc/Proyecto-Final_POO.git
cd Proyecto-Final_POO
cmake -S . -B build
cmake --build build
./build/PROYECTO_FINAL
```

En CLion: abrir la carpeta del proyecto, *Reload CMake Project* y ejecutar `PROYECTO_FINAL`.

## Estructura del proyecto

| Clase | Descripción |
|-------|-------------|
| `Entidad` | Clase base **abstracta** (`atacar()` virtual pura). Vida, ataque y defensa. |
| `Jugador` | Hereda de `Entidad`. Inventario (`std::vector`), nivel y experiencia. |
| `Enemigo` | Hereda de `Entidad`. Clase intermedia abstracta con la experiencia que otorga. |
| `Orco`, `Dragon` | Hijos de `Enemigo`, cada uno con su propio ataque (el Dragón lanza su aliento de fuego cada tercer turno). |
| `JefeFinal` | Hijo de `Enemigo` (Señor Oscuro): entra en furia al 50 % de vida y drena vida cada tercer turno. |
| `Objeto` | Clase base **abstracta** (`usar()` y `getDescripcion()` virtuales puras). |
| `PocionDeVida`, `Espada`, `Armadura` | Hijos de `Objeto`: curan, suben el ataque o suben la defensa. |
| `Habitacion` | Descripción, enemigos, objetos en el suelo y salidas a otras habitaciones. |
| `Juego` | Controla el mapa, el bucle principal, el movimiento y el combate. |

## Los 4 pilares de la POO en el proyecto

- **Encapsulamiento:** los atributos son privados o protegidos y se acceden mediante métodos (por ejemplo, la vida solo cambia con `recibirDanio()` y `curar()`, que validan los límites).
- **Abstracción:** `Entidad` y `Objeto` son clases abstractas que definen un contrato (`atacar()`, `usar()`) sin implementarlo.
- **Herencia:** `Jugador` y `Enemigo` heredan de `Entidad`; `Orco`, `Dragon` y `JefeFinal` heredan de `Enemigo`; `PocionDeVida`, `Espada` y `Armadura` heredan de `Objeto`.
- **Polimorfismo:** el mismo llamado `enemigo.atacar()` o `objeto->usar()` produce un comportamiento distinto según el tipo real del objeto.

## Memoria y STL

- Contenedores: `std::vector` para el inventario, los enemigos, los objetos, las salidas y el mapa.
- Memoria dinámica con punteros inteligentes: `std::unique_ptr` y `std::make_unique`, sin `new` ni `delete` manuales.
- Clases base con destructor virtual.

## Relaciones entre clases

| Relación | Tipo |
|----------|------|
| `Juego` ◆ `Jugador`, `Juego` ◆ `Habitacion` | Composición |
| `Habitacion` ◆ `Enemigo` | Composición |
| `Jugador` ◇ `Objeto`, `Habitacion` ◇ `Objeto` | Agregación |
| `Habitacion` → `Habitacion` (salidas) | Asociación |

## Elementos adicionales (bonus)

- [x] **Niveles y experiencia:** cada enemigo da XP; al subir de nivel aumentan la vida máxima y el ataque.
- [x] **Tipos de objeto / armadura:** pociones, espadas y armaduras (la defensa reduce el daño recibido).
- [x] **Jefe final:** el Señor Oscuro, con furia y drenaje de vida.
- [ ] Guardar y cargar la partida (no implementado).

## Documentación

El informe del proyecto (UML final, guion literario, capturas de la simulación, distribución del trabajo y contenido de la presentación) está en la carpeta `docs/`.

## Equipo

| Integrante | Responsabilidades |
|------------|-------------------|
| Juan José Rojas Canencio | `Jugador`, `Juego`, programa principal y bonus (niveles, `Armadura`, `JefeFinal`) |
| Juan Esteban Marín Cardona | `Entidad`, `Enemigo`, `Orco`, `Dragon`, `Objeto`, `PocionDeVida`, `Espada`, `Habitacion`, y documentación (UML, guion e informe) |
