// Ejercicio 5
#include <iostream>
#include <string>
using namespace std;

const int CANTIDAD_MINIMA_BESTSELLER = 5;

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

    int getCantidadDeLibrosPublicados() {
        return cantidadDeLibrosPublicados;
    }

    void mostrar() {
        cout << "Autor: " << nombre << endl;
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Libros publicados: " << cantidadDeLibrosPublicados << endl;
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
        int cantidadLibros = autor.getCantidadDeLibrosPublicados();
        return cantidadLibros > CANTIDAD_MINIMA_BESTSELLER;
    }

    void mostrarTitularidadValida() {
        if (esBestSeller()) {
            cout << "El libro ES best seller" << endl;
        }
        else {
            cout << "El libro NO es best seller" << endl;
        }
    }

    void mostrar() {
        cout << "Libro: " << titulo << endl;
        cout << "Precio: $" << precio << endl;
        autor.mostrar();
    }
};

void ejercicio5() {
    Autor autor1 = Autor("Gabriel Garcia Marquez", "Colombiana", 25);
    Libro libro1 = Libro("Cien anios de soledad", 450, autor1);

    libro1.mostrar();
    libro1.mostrarTitularidadValida();
}

int main() {
    ejercicio5();
    return 0;
}