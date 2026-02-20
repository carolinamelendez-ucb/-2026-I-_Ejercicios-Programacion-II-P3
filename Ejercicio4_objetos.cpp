// Ejercicio4_objetos.cpp
// 09/02/26

/* Ejercicio 4. Crea una clase llamada Mascota. 
1. Atributos: nombre, tipo, edad 
2. Crea un constructor con todos los atributos. 
3. Métodos set para cada atributo. 
4. Método mostrar(). 
En el main: 
1. Crear 2 o 3 objetos Mascota. 
2. Pedir por consola la edad de cada mascota. 
3. Asignar las edades con setters. 
4. Mostrar todas las mascotas. 
5. Cambiar la edad de una mascota. 
6. Volver a mostrar todas para verificar que solo una cambió. */

#include <iostream>
#include <string>
using namespace std;

class Mascota
{
    //ATRIBUTOS
    private:
        string nombre;
        string tipo;
        int edad;
    public:
        //CONSTRUCTOR
        Mascota(string nombre_a, string tipo_a, int edad_a)
        {
            nombre = nombre_a;
            tipo = tipo_a;
            edad = edad_a;
        }
        //METODO MOSTRAR()
        void mostrar()
        {
            cout << "\nNombre: " << nombre << endl;
            cout << "Tipo: " << tipo << endl;
            cout << "Edad: "<<edad << endl;
        }
        //METODO SET
        void setNombre(string nuevoNombre)
        {
            this->nombre = nuevoNombre;
        }
        void setTipo(string nuevoTipo)
        {
            this->tipo = nuevoTipo;
        }
        void setEdad(int nuevaEdad)
        {
            this->edad = nuevaEdad;
        }

};
int main()
{
    int edad;

    cout << "-- MASCOTA 1 --\n" << endl;
    cout << "Ingrese la edad: ";
    cin >> edad;
    Mascota m1 = Mascota("Toby", "Bulldog", edad);
    m1.mostrar();

    cout << "\n---------------------\n" << endl;

    cout << "-- MASCOTA 2 --\n" << endl;
    cout << "Ingrese la edad: ";
    cin >> edad;
    Mascota m2 = Mascota("Max", "Pastor aleman", edad);
    m2.mostrar();

    cout << "\n---------------------\n" << endl;
    cout << "MODIFICANDO LA EDAD DE LA MASCOTA 1..." << endl;
    m1.setEdad(5);
    cout << "\n---------------------" << endl;

    m1.mostrar();
    m2.mostrar();

    return 0;
    
}


