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
	CHECK(ScalarConvert("holaMundo prueba de cadena").getError(1) == "notype");
	CHECK(ScalarConvert("15.0f").getError(1) == "notype");
	CHECK(ScalarConvert("15.0").getError(1) == "notype");
	CHECK(ScalarConvert("A").getError(1) == "notype");
	CHECK(ScalarConvert("11111111.111111111111111111111111111").getError(1) == "notype");
}
TEST_CASE("Alphabetical char")
{
	CHECK(ScalarConvert("A").getChar() == 'A');
	CHECK(ScalarConvert("*").getChar() == '*');
	CHECK(ScalarConvert(" ").getChar() == ' ');
}
TEST_CASE("Not possible char convert")
{
	CHECK(ScalarConvert("Hola mundo").getError(0) == "notype");
	CHECK(ScalarConvert("-15.0f").getError(0) == "notype");
	CHECK(ScalarConvert("15.0").getError(0) == "notype");
	CHECK(ScalarConvert("-150").getError(0) == "notype");
	CHECK(ScalarConvert("9").getError(0) == "notype");
	CHECK(ScalarConvert("3").getChar() == NULL);
}
TEST_CASE("Valid float")
{
	CHECK(ScalarConvert("15.0f").getFloat() == 15.0f);
	CHECK(ScalarConvert("-55.0").getFloat() == -55.0f);
	CHECK(ScalarConvert("5.0f").getError(2) == "clean");
}
TEST_CASE("Invalid float")
{
	CHECK(ScalarConvert("impossible").getError(2) == "notype");
	CHECK(ScalarConvert("-10").getError(2) == "notype");
	CHECK(ScalarConvert("5.0").getError(2) == "notype");
}
TEST_CASE("Valid double")
{
	CHECK(ScalarConvert("-55.0").getDouble() == -55.0);
	CHECK(ScalarConvert("15.0").getDouble() == 15.0);
	CHECK(ScalarConvert("99999999999999999999999999999999999999111111211111111111111111111111111111111111111111.111111111111111111111111111").getDouble() == 99999999999999999999999999999999999999111111211111111111111111111111111111111111111111.111111111111111111111111111);
}
TEST_CASE("Invalid double")
{
	CHECK(ScalarConvert("15").getError(3) == "notype");
	CHECK(ScalarConvert("15.0f").getError(3) == "notype");
	CHECK(ScalarConvert("A").getError(3) == "notype");
	CHECK(ScalarConvert("11211211211212122121212121121212121212121212121111111.11111111111199999999999999999999999999999999999999111111211111111111111111111111111111111111111111111111111111111111111111111").getError(3) == "out of range");
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
