#include <doctest.h>
#include <iostream>
#include <sstream>

// Creamos una función auxiliar para redireccionar la salida estándar a un stringstream
void redirect_stdout(std::stringstream& buffer) {
    std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    // La salida se redirecciona al stringstream 'buffer'
}

TEST_CASE("Test de ejecución del programa principal") {
    // Redirigimos la salida estándar a un stringstream para capturarla
    std::stringstream buffer;
    redirect_stdout(buffer);

    // Ejecutamos el programa principal 'ex00' (no llamamos a la función main())
    system("./ex00");

    // Obtenemos la salida redirigida del stringstream
    std::string output = buffer.str();

    // Comprobamos si el mensaje se imprime correctamente
    CHECK(output == "The project was created successfully.\n");
}

