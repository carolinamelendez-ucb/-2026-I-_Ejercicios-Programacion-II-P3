// Ejercicio3_objetos.cpp
// 08/02/26
/* Ejercicio 3. Crea una clase llamada Película. 
● Atributos: titulo, genero, duración 
● Crea un constructor con todos los atributos. 
● Métodos set para cada atributo. 
● Método mostrar() que muestre la información de la película. 
En el main: 
1. Crear 2 o 3 objetos Pelicula. 
2. Pedir por consola el género y duración de cada una. 
3. Asignar los valores usando setters. 
4. Mostrar la información de todas las películas. 
5. Modificar la duración de una película. 
6. Volver a mostrar todas para comprobar el cambio. */

#include <iostream>
#include<string>
using namespace std;


class Pelicula
{
    //ATRIBUTOS
private:
    string titulo;
    string genero;
    float duracion;

public:
    //CONSTRUCTOR
    Pelicula(string T, string G, float D)
    {
        titulo = T;
        genero = G;
        duracion = D;
    }
    //METODO MOSTRAR()
    void mostrar()
    {
        cout << "\nTitulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << endl;
    }
    //METODO SET
    void setTitulo(string nuevoTitulo)
    {
        this->titulo = nuevoTitulo;
    }
    void setGenero(string nuevoGenero)
    {
        this->genero = nuevoGenero;
    }
    void setDuracion(float nuevaDuracion)
    {
        this->duracion = nuevaDuracion;
    }

};

int main()
{
    string genero;
    float duracion;

    cout << "-- PELICULA 1 --\n" << endl;
    cout << "Ingrese el genero de la pelicula: ";
    getline(cin, genero);
    cout << "Ingrese la duracion de la pelicula: ";
    cin >> duracion;
    cin.ignore();

    Pelicula p1 = Pelicula("Yo antes de ti", genero, duracion);
    p1.mostrar();
  
    cout << "\n---------------------\n" << endl;

    cout << "-- PELICULA 2 --\n" << endl;
    cout << "Ingrese el genero de la pelicula: ";
    getline(cin, genero);
    cout << "Ingrese la duracion de la pelicula: ";
    cin >> duracion;
    cin.ignore();

    Pelicula p2 = Pelicula("Rapidos y furiosos", genero, duracion);
    p2.mostrar();

    cout << "\n---------------------" << endl;
    cout << "\nMODIFICANDO DURACION DE LA PELICULA 1...\n" << endl;
    cout << "Nueva Duracion: ";
    cin >> duracion;
    p1.setDuracion(duracion);
    cout << "\n---------------------\n" << endl;

    cout << "-- PELICULA 1 --" << endl;
    p1.mostrar();
    cout << "\n-- PELICULA 2 --" << endl;
    p2.mostrar();

    return 0;

}


