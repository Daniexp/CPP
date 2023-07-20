#include "doctest.h"
#include <iostream>
#include <sstream>

// Definimos una función que captura la salida estándar para realizar las pruebas
std::string captureOutput(std::ostream& stream, void (*func)()) {
    std::stringstream buffer;
    std::streambuf* oldBuffer = stream.rdbuf(buffer.rdbuf());
    func();
    stream.rdbuf(oldBuffer);
    return buffer.str();
}

// Definimos el test case usando el macro TEST_CASE de doctest
TEST_CASE("Test output without parameters") {
    // Capturamos la salida estándar usando la función captureOutput
    std::string output = captureOutput(std::cout, []() {
        // Aquí llamamos a la función que queremos probar (por ejemplo, tu programa principal)
        // Si el programa ya está implementado, reemplaza esta línea con la llamada correcta
        // a tu función principal que no recibe parámetros.
        std::cout << "The project was created successfully." << std::endl;
    });

    // Verificamos que la salida coincida con el mensaje esperado
    CHECK(output == "The project was created successfully.\n");
}

