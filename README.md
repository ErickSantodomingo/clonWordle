# Clon de Wordle

## Descripción
Proyecto personal desarrollado en C++ como ejercicio de práctica, fuera de la currícula de la facultad. Recreación de la lógica del popular juego de palabras Wordle.

## Tecnologías
- **Lenguaje:** C++

## Cómo funciona
- El juego corre íntegramente por **terminal** (entrada/salida con `cin`/`cout`), sin interfaz gráfica.
- Se permiten **6 intentos** para adivinar la palabra, igual que en el Wordle original.
- La palabra secreta se elige al azar de un listado externo (`listado.txt`), cargado al iniciar la partida. Solo se aceptan intentos que además de tener la longitud correcta pertenezcan a ese mismo listado (`intento_valido`).
- El feedback no usa colores, sino una representación simbólica por consola: por cada letra del intento se imprime `+` si está en la posición correcta, `-` si la letra existe en la palabra pero en otra posición, y `X` si no está presente.

## Estado del proyecto
Proyecto de práctica personal para reforzar habilidades de programación en C++, con tests unitarios (Google Test) sobre las funciones principales del juego.

## Cómo ejecutar
El proyecto se compila con CMake (C++20, descarga Google Test automáticamente vía `FetchContent`):

```bash
mkdir build && cd build
cmake ..
make
./wordle    # ejecuta el juego
./tests     # corre los tests unitarios
```

## Autoría
Proyecto personal. **Erick David Santodomingo Polo**.
