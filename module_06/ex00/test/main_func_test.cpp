#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>

// Incluye los archivos necesarios que contienen las funcionalidades que deseas probar
//#include "archivo1.h"
//#include "archivo2.h"
// ...

// Agrega tus pruebas aquí
TEST_CASE("Prueba del programa principal") {
    // Ejemplo de una prueba simple
    CHECK(2 + 2 == 4);
}

TEST_CASE("Pruebas de las funcionalidades") {
    // ...
}
