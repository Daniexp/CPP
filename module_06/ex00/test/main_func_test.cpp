#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <ScalarConvert.hpp>

// Incluye los archivos necesarios que contienen las funcionalidades que deseas probar
//#include "archivo1.h"
//#include "archivo2.h"
// ...

// Agrega tus pruebas aquí
    // Ejemplo de una prueba simple

#define ft_literal_valid_int(arg) \
TEST_CASE("ft: convertStirngToLiteral(), Int, valid", #arg) {
    // ...
	CHECK(ScalarConvert("").getInt() == arg.toInt();
}
    TEST_CASE("ft: convertStirngToLiteral(), Int, valid - " #arg) { \
        CHECK(ScalarConvert("5").getInt() == arg); \
    }

int main(int argc, char** argv) {
    // Inicializar doctest
    doctest::Context context;
    context.applyCommandLine(argc, argv);

    // Llamar a los casos de prueba con diferentes argumentos
    ft_literal_valid_int(5);
    ft_literal_valid_int(10);
    ft_literal_valid_int(-2);

    // Configurar el mensaje para el test
    context.setOption("no-breaks", true);

    // Ejecutar las pruebas y obtener el resultado
    int res = context.run();

    return res;
}
