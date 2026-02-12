// Ejercicio 12-02.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//EERCICIO 5

#include <iostream>
#include <string>

using namespace std;

const int LIBROS_PUBLICADOS = 6;

class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantidadDeLibrosPublicados;

public:

    Autor() {
        nombre = "";
        nacionalidad = "";
        cantidadDeLibrosPublicados = 0;
    }

    Autor(string nombre, string nacionalidad, int cantidadDeLibrosPublicados) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadDeLibrosPublicados = cantidadDeLibrosPublicados;
    }

    int getSeller() {
        return cantidadDeLibrosPublicados;
    }
};

class Libro {
private:
    string titulo;
    int precio;
    Autor autor;
public:
    Libro(string titulo, int precio, Autor autor) {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }
    bool esBestSeller() {
        int librosPublicados = autor.getSeller();
        return librosPublicados >= LIBROS_PUBLICADOS;
    }

    void mostrarTitularidad() {
        if (esBestSeller()) {
            cout << "TRUE" << endl;
        }
        else {
            cout << "FALSE" << endl;
        }
    }
};


void Ejercicio5() {
    Autor autor1 =  Autor("Jose", "Boliviano", 25);
    Libro libro1 = Libro("Rayito", 250, autor1);
    libro1.mostrarTitularidad();
}

int main()
{
    Ejercicio5();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
