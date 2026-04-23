#include <iostream>
#include "Biblioteca.h"

using namespace std;

int main() {
    try {
        Biblioteca lumen("Biblioteca Digital LUMEN");

        lumen.agregarLibro("LIB001", "Cien anios de soledad", "Gabriel Garcia Marquez");
        lumen.agregarLibro("LIB002", "El principito", "Antoine de Saint-Exupéry");
        lumen.agregarLibro("LIB003", "Don Quijote de la Mancha", "Miguel de Cervantes");
        lumen.agregarLibro("LIB004", "1984", "George Orwell");

        lumen.agregarEstudiante("1234567", "Juan Perez");
        lumen.agregarEstudiante("7654321", "Maria Gonzalez");
        lumen.agregarEstudiante("9876543", "Carlos Rodriguez");

        lumen.mostrarCatalogo();

        cout << "\n=== REGISTRANDO PRESTAMOS ===" << endl;
        lumen.registrarPrestamo("1234567", "LIB001");
        lumen.registrarPrestamo("7654321", "LIB002");

        try {
            lumen.registrarPrestamo("1234567", "LIB003");
        }
        catch (exception& err) {
            cout << "Mensaje de error: " << err.what() << endl;
        }

        try {
            lumen.registrarPrestamo("9876543", "LIB001");
        }
        catch (exception& err) {
            cout << "Mensaje de error: " << err.what() << endl;
        }

        lumen.listarEstudiantesConLibros();

        lumen.mostrarLibroMasSolicitado();

        cout << "\n=== REALIZANDO MAS PRESTAMOS ===" << endl;
        lumen.devolverLibro("1234567");
        lumen.registrarPrestamo("1234567", "LIB001");
        lumen.registrarPrestamo("9876543", "LIB003");

        lumen.mostrarLibroMasSolicitado();

    }
    catch (exception& err) {
        cout << "Error en el sistema: " << err.what() << endl;
    }

    return 0;
}