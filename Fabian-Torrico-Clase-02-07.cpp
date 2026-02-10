// PrimerObjeto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

//Ejercicio 1

class Libro {
    private:
        string titulo;
        string autor;
        int paginas;
    public:
        Libro(string titulo, string autor, int paginas) {
            this->titulo = titulo;
            this->autor = autor;
            this->paginas = paginas;
        }
        void mostrar() {
            cout << "Titulo: " << titulo << endl;
            cout << "Autor: " << autor << endl;
            cout << "Paginas: " << paginas << endl;
        }
        void setTitulo(string nuevoTitulo) {
            titulo = nuevoTitulo;
        }
        void setAutor(string nuevoAutor) {
            autor = nuevoAutor;
        }
        void setPaginas(int nuevaPagina) {
            paginas = nuevaPagina;
        }
};

/*
//Ejercicio 2

class Producto {
private:
    string nombre;
    int precio;
    int stock;
public:
    Producto(string nombre, int precio) {
        this->nombre = nombre;
        this->precio = precio;
        stock = 0;
    }
    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }
    void setPrecio(int nuevoPrecio) {
        precio = nuevoPrecio;
    }
    void setStock(int nuevoStock) {
        stock = nuevoStock;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    }
};*/


/*
//Ejercicio 3

class Pelicula {
private:
    string titulo;
    string genero;;
    int duracion;
public:
    Pelicula(string titulo, string genero, int duracion) {
        this->titulo = titulo;
        this->genero = genero;
        this->duracion = duracion;
    }
    void mostrar() {
        cout << "Pelicula: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "duracion: " << duracion << endl;
    }
    void setTitulo(string nuevoTitulo) {
        titulo = nuevoTitulo;
    }
    void setGenero(string nuevoGenero) {
        genero = nuevoGenero;
    }
    void setDuracion(int nuevoDuracion) {
        duracion = nuevoDuracion;
    }
};*/

int main()
{
    Libro libro1 = Libro("Rayo", "Luis Valencia", 155);
    libro1.mostrar();
    libro1.setPaginas(155);
    libro1.mostrar();

    /*Producto producto1 = Producto("juguete", 500);
    producto1.mostrar();
    producto1.setStock(3);
    producto1.setPrecio(500);
    producto1.mostrar();
    
    string genero;
    int duracion;
    Pelicula pelicula = Pelicula("the grefg", "", 0);
    cout << "Ingrese el genero de las pelicula: " << endl;
    cin >> genero;
    cout << "Ingrese la duracion de la peliucula: " << endl;
    cin >> duracion;
    pelicula1.setGenero(gen);
    pelicula1.setDuracion(dur);
    
    
    */

}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
