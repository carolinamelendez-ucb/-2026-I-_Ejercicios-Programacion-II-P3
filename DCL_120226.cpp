// DCL_120226.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
const int MAYOR_DE_EDAD=18;
/*
class Propietario {
    private:
    string nombre;
    int DNI;
    int edad;
public:

    Propietario(string nombre, int DNI, int edad) {
        this->nombre = nombre;
        this->DNI = DNI;
        this->edad = edad;
    }
    int getEdad()
    { return edad; }
};
class Casa {
private:
    string direccion;
    int valor;
    Propietario propietario; //Un almuno tiene un Profe -  A esta compuesto B por, coche esta compuesto por un motor

public:

    Casa(string direccion, int valor, Propietario propietario) {
        this->direccion = direccion;
        this->valor = valor;
        this->propietario = propietario;
    }
    bool esPropietarioValido()
    {
        int edadPropietario = propietario.getEdad();
        return edadPropietario >= MAYOR_DE_EDAD;
    }
    void mostrarTitularValida() {
        if (esPropietarioValido()) {
            cout << "La titularidad es validad" << endl;
        }
        else { cout << "La titularidad no es Valida" << endl; }
    }
};

void ejer4()
{

}
*/
class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantlibrosvendidos;
public:
    Autor(string nombre, string naionalidad, int cantlibrosvendidos) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantlibrosvendidos = cantlibrosvendidos;

    }
    void mostrarAutor() {
        cout << "Nombre: " << nombre << endl;
        cout << "Nacionalidad: " << nacionalidad << endl;
        cout << "Cantidad de libros vendidos: " << cantlibrosvendidos << endl;
    }

};
class Libro {
private:
    string titulo;
    float precio;
    Autor autor;
public:
    Libro(string titulo, float precio, Autor autor)
    {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }
    bool esBestSeller(int cantlibrosvendidos) {
        if (cantlibrosvendidos > 5) {
            return true;
        }
    }
    void mostrarLibro() {
        cout << "Titulo: " << titulo << endl;
        cout << "Precio: " << precio << endl;
        Autor mostrarAutor();
    }

};

void ejer5()
{
    Autor autor1 = Autor("Juan", "Cubana", 7);
    Libro libro1 = Libro("Maravillas", 300, autor1);

    if (libro1.esBestSeller(7)) {
        cout << "El autor venidomas de 5 libros" << endl;
    }
    else {
        cout << "El autor NO venido mas de 5 libros" << endl;
    }
}


int main()
{
    ejer5();
}

