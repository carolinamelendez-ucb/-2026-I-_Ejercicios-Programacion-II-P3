// clase-24-02-2026.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
const int MAYOR_DE_EDAD = 18;
/*class Alumno {
private:
    string nombre;
    int ci;
public:
    Alumno(string nombre, int ci) {
        this->nombre = nombre;
        this->ci = ci;
    }
};*/
/*class Autor {
private:
    string nombre;
    string nacionalidad;
    int cantidadLibrosPublicados;
public:
    Autor(string nombre, string nacionalidad, int cantLibros) {
        this->nombre = nombre;
        this->nacionalidad = nacionalidad;
        this->cantidadLibrosPublicados = cantLibros;
    }
};
class Libro {
private:
    string titulo;
    int precio;
    Autor autor;
public:
    Libro(string titulo, int precio, Autor* autor) {
        this->titulo = titulo;
        this->precio = precio;
        this->autor = autor;
    }
};*/
class Propietario {
private:
    string nombre;
    int dni;
    int edad;
public:
    Propietario(string nombre, int dni, int edad) {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }
    int getedad() {
        return edad;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Dni: " << dni << endl;
        cout << "Edad: " << edad << endl;

    }
};
class Casa {
private:
    string direccion;
    int precio;
    Propietario propietario;
public:
    Casa(string direccion, int precio, Propietario propietario) : propietario(propietario) {
        this->direccion = direccion;
        this->precio = precio;
    }
    bool esPropietarioValido() {
        return propietario.getedad() >= MAYOR_DE_EDAD;
    }
    void mostrar()
    {
        cout << "direccion: " << direccion << endl;
        cout << "precio: " << precio<<" bs" << endl;
        cout << "---propietario---" << direccion << endl;
        propietario.mostrar();
    }
    void mostrarTitularidadValida() {
        if (esPropietarioValido()) {
            cout << "latitularidad es valida" << endl;
        }
        else {
            cout << "la titularidad es invalida" << endl;
        }
    }
};
void ejercicio() {
    Propietario propietario1 = Propietario("Miguel", 123456, 25);
    Casa casa1 = Casa("Av.Libertador", 250000, propietario1);

    casa1.mostrar();
    cout << "--------------" << endl;
    casa1.mostrarTitularidadValida();
}
int main()
{
   /* Alumno marco = Alumno("Marco", 123);
    Alumno* daniela = new Alumno("Daniela", 321);*/
    ejercicio();
    return 0;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
