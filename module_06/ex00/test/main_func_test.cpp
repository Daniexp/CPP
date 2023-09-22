#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <ScalarConvert.hpp>

// Agrega tus pruebas aquí
    // Ejemplo de una prueba simple
TEST_CASE("Positive Integer Valid") {
	CHECK(ScalarConvert("5").getInt() == 5);
	CHECK(ScalarConvert("5").getType() == INT);
}
TEST_CASE("Negative Integer overflow")
{
	CHECK(ScalarConvert("-1111111111111111111111111111111111").getError(1) =="out of range");
}
TEST_CASE("Integer - Not possible convert")
{
	CHECK(ScalarConvert("holaMundo prueba de cadena").getError(1) == "clean");
	CHECK(ScalarConvert("15.0f").getError(1) == "clean");
	CHECK(ScalarConvert("15.0").getError(1) == "clean");
	CHECK(ScalarConvert("A").getError(1) == "clean");
	CHECK(ScalarConvert("11111111.111111111111111111111111111").getError(1) == "clean");
}
TEST_CASE("Alphabetical char")
{
	CHECK(ScalarConvert("A").getChar() == 'A');
	CHECK(ScalarConvert("*").getChar() == '*');
	CHECK(ScalarConvert(" ").getChar() == ' ');
}
TEST_CASE("Not possible char convert")
{
	CHECK(ScalarConvert("Hola mundo").getError(0) == "clean");
	CHECK(ScalarConvert("-15.0f").getError(0) == "clean");
	CHECK(ScalarConvert("15.0").getError(0) == "clean");
	CHECK(ScalarConvert("-150").getError(0) == "clean");
}
TEST_CASE("Valid float")
{
	CHECK(ScalarConvert("15.0f").getFloat() == 15.0f);
	CHECK(ScalarConvert("-55.0f").getFloat() == -55.0f);
	CHECK(ScalarConvert("5.0f").getError(2) == "clean");
}
TEST_CASE("Invalid float")
{
	CHECK(ScalarConvert("impossible").getError(2) == "clean");
	CHECK(ScalarConvert("5.0").getError(2) == "clean");
}
TEST_CASE("Valid double")
{
	CHECK(ScalarConvert("-55.0").getDouble() == -55.0);
	CHECK(ScalarConvert("15.0").getDouble() == 15.0);
	CHECK(ScalarConvert("111111211111111111111111111111111111111111111111.111111111111111111111111111").getError(3) == "clean");
	CHECK(ScalarConvert("111111211111111111111111111111111111111111111111.111111111111111111111111111").getDouble() == 111111211111111111111111111111111111111111111111.111111111111111111111111111);
}
TEST_CASE("Invalid double")
{
	CHECK(ScalarConvert("15.0f").getError(3) == "clean");
	CHECK(ScalarConvert("15.0f").getError(3) == "clean");
	CHECK(ScalarConvert("A").getError(3) == "clean");

}
TEST_CASE("Float pseudo literal")
{
	CHECK(ScalarConvert("nanf").isPseudoLiteral() == true);
	CHECK(ScalarConvert("-inff").isPseudoLiteral() == true);
	CHECK(ScalarConvert("+inff").isPseudoLiteral() == true);
}
TEST_CASE("Double pseudo literal")
{
	CHECK(ScalarConvert("nan").isPseudoLiteral() == true);
	CHECK(ScalarConvert("-inf").isPseudoLiteral() == true);
	CHECK(ScalarConvert("+inf").isPseudoLiteral() == true);
}
TEST_CASE("Valid explicit conversion, char scalar")
{
	CHECK(ScalarConvert("A").getInt() == 65);
	CHECK(ScalarConvert("B").getFloat() == 66.0f);
	CHECK(ScalarConvert("C").getDouble() == 67.0);
}
TEST_CASE("Valid explicit conversion, int scalar")
{
	CHECK(ScalarConvert("65").getChar() == 'A');
	CHECK(ScalarConvert("-66").getFloat() == -66.0f);
	CHECK(ScalarConvert("-67").getDouble() == -67.0);
}
TEST_CASE("Valid explicit conversion, float scalar")
{
	CHECK(ScalarConvert("65.0f").getChar() == 'A');
	CHECK(ScalarConvert("-66f").getInt() == -66.0f);
	CHECK(ScalarConvert("-67.0f").getDouble() == -67.0);
}
TEST_CASE("Valid explicit conversion, doublescalar")
{
	CHECK(ScalarConvert("65.0").getChar() == 'A');
	CHECK(ScalarConvert("-66.0").getFloat() == -66.0f);
	CHECK(ScalarConvert("-67.0").getInt() == -67.0);
}
TEST_CASE("Subject output examples")
{
	//CHECK(ScalarConvert("nan")
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
