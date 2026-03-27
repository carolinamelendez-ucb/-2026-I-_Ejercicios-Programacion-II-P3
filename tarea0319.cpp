// tarea0319.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "AdminitracioLibros.h"

using namespace std;

int main()
{
    AdminitracionLibros sistema(10, 10, 50);
    cout << "Registramos Estudiantes: " << endl;
    sistema.registrarEstudiantes(1, "Juan");
    sistema.registrarEstudiantes(2, "Esteban");
    sistema.registrarEstudiantes(3, "Lupe");
    sistema.registrarEstudiantes(1, "Luis");
    sistema.registrarEstudiantes(4, "Maria");
    sistema.registrarEstudiantes(5, "Ariana");
    sistema.mostrarEstudiantes();
    cout << endl;
    cout << "Registramos Libros: " << endl;

    sistema.registrarLibros(111, "Anne with e");
    sistema.registrarLibros(222, "100 anios de soledad");
    sistema.registrarLibros(333, "Gambito de Dama");
    sistema.registrarLibros(444, "Sere Reina cueste lo que cueste");
    sistema.registrarLibros(111, "Pedro Paramo");
    sistema.registrarLibros(666, "Los miserables");
    sistema.registrarLibros(777, "Edipo Rey");
    sistema.registrarLibros(888, "Odisea");
    sistema.registrarLibros(999, "La cartas de ....");

    //sistema.mostrarLibros();

    cout << endl;
    cout << "Prestano libros... " << endl;
    
    sistema.prestarLibro(1, 111);
    sistema.prestarLibro(1, 222);
    sistema.prestarLibro(1, 333);
    sistema.prestarLibro(1, 444);
    sistema.prestarLibro(1, 555);
    sistema.prestarLibro(1, 666);

    sistema.prestarLibro(2, 111);
    sistema.prestarLibro(2, 777);
    sistema.prestarLibro(3, 888);
    sistema.prestarLibro(5, 999);
    sistema.prestarLibro(4, 666);

    
    cout << "Estudinates devolvieron libros.. " << endl;
    sistema.devolverLibro(2, 777);
    sistema.devolverLibro(3, 888);
    sistema.devolverLibro(5, 999);
    sistema.devolverLibro(4, 666);

    cout << "Estudinates con 5 prestamos activos " << endl;
    sistema.mostrarEstudiantes5Prestamos();
    cout << endl;

    cout << "Informacion de prestamos" << endl; 
    sistema.mostrarPrestamos();




}

