// 1202EJERCICIO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class Carrera {
private:
    string nombre;
    int duracion;
    int cupoDisponible;
public:

    Carrera()
    {
        nombre = "";
        duracion = 0;
        cupoDisponible = 0;
    }

    Carrera(string nombre, int duracion, int cupo)
    {
        this->nombre = nombre;
        this->duracion = duracion;
        this->cupoDisponible = cupo;
    }

    void mostrar()
    {
        cout << "CARRERA: " << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Duracion: " << duracion << endl;
        cout << "Cupo: " << cupoDisponible << endl;
    }

    int getCupo()
    {
        return cupoDisponible;
    }
};

class Estudiante {
private:
    string nombre;
    int edad;
    Carrera carrera=Carrera(); //Ahora se esta poniendo una clase como atributo
public:
    Estudiante(string nombre, int edad, Carrera carrera)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->carrera = carrera;
    }

    void mostrar()
    {
        cout << "NOMBRE: " << nombre << endl;
        cout << "EDAD: " << edad << endl;
        carrera.mostrar();
    }

    int getEdad()
    {
        return edad;
    }

    bool puedeInscribirse()
    {
        return (edad >= 18 && carrera.getCupo() > 0);
    }

    void mostrarInscripcion()
    {
        if (puedeInscribirse())
        {
            cout << "Puede Inscribirse" << endl;
        }
        else
        {
            cout << "No puede Inscribirse" << endl;
        }
    }
};

void ejercicio6()
{
    Carrera carr = Carrera("Ing. de Sistemas", 5, 10);
    Estudiante est = Estudiante("Alejandro Reyes Diaz", 17, carr);
    est.mostrar();
    est.mostrarInscripcion();
}

int main()
{
    ejercicio6();
}