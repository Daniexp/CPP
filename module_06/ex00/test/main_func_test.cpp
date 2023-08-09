#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <ScalarConvert.hpp>

// Agrega tus pruebas aquí
    // Ejemplo de una prueba simple
TEST_CASE("Positive Integer Valid") {
	CHECK(ScalarConvert("5").getInt() == 5);
}
TEST_CASE("Negative Integer overflow")
{
	CHECK(ScalarConvert("-1111111111111111111111111111111111").getError(1) =="out of range");
}
TEST_CASE("Integer - Not possible convert")
{
	CHECK(ScalarConvert("holaMundo prueba de cadena").getError(1) == "impossible");
}
TEST_CASE("Alphabetical char")
{
	CHECK(ScalarConvert("A").getChar() == 'A');
	CHECK(ScalarConvert("*").getChar() == '*');
	CHECK(ScalarConvert(" ").getChar() == ' ');
}
TEST_CASE("Not possible char convert")
{
	CHECK(ScalarConvert("Hola mundo").getError(0) == "impossible");
}
TEST_CASE("Valid float")
{
	CHECK(ScalarConvert("15.0f").getFloat() == 15.0f);
	CHECK(ScalarConvert("-55.0").getFloat() == -55.0f);
	CHECK(ScalarConvert("5.0f").getError(2) == "clean");
}
/*
int main(int argc, char** argv) {
    // Inicializar doctest
    doctest::Context context;
    context.applyCommandLine(argc, argv);

    // Llamar a los casos de prueba con diferentes argumentos

    // Configurar el mensaje para el test
    context.setOption("no-breaks", true);

    // Ejecutar las pruebas y obtener el resultado
    int res = context.run();

    return res;
}
*/
