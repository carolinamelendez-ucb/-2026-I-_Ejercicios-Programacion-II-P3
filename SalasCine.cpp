// SalasCine.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "SistemaCine.h"
using namespace std;


int main()
{
    SistemaCine cine(50,10,7,20);
    cout << "Clientes registrados" << endl;
    cine.registraClientes(1, "Juan");
    cine.registraClientes(2, "Maria");
    cine.registraClientes(3, "Sara");
    cine.registraClientes(4, "Esteban");
    cine.registraClientes(5, "Lucas");

    cine.mostrarClientes();

    cout << endl;
    cout << "Salas registradas" << endl;
    cine.registraSalas(11, 4,5);
    cine.registraSalas(22, 3, 3);
    cine.registraSalas(33, 4, 5);
    cine.registraSalas(44, 5, 5);
    cine.registraSalas(55, 6, 6);
    cine.registraSalas(66, 5, 5);
    cine.registraSalas(77, 6, 6);
    cine.mostrarSala();

    cout << endl;
    cout << "Peliculas registradas" << endl;
    cine.registrPeliculas(111,"Harry Potter","Fantasia");
    cine.registrPeliculas(222, "Sirenita", "Infantil");
    cine.registrPeliculas(333, "Rapidos y Furiosos", "Accion");
    cine.registrPeliculas(444, "Cenicienta", "Infantil");
    cine.registrPeliculas(555, "Amar es primavera", "Romance");

    cine.mostrarPeliculas();

    cout << endl;
    cout << "Funciones registradas" << endl;
    cine.registraFuncion(1111, 111,11,30);
    cine.registraFuncion(2222, 111, 22, 35);
    cine.registraFuncion(3333, 111, 33, 30);
    cine.registraFuncion(4444, 222, 44, 45);
    cine.registraFuncion(5555, 222, 44, 30);
    cine.registraFuncion(6666, 333, 55, 20);
    cine.registraFuncion(7777, 444, 66, 30);
    cine.registraFuncion(8888, 555, 77, 35);

    cine.mostrarFuncion();
    cout << endl;
    cout << "Venta de Boletos" << endl;
        cout << endl;
    cine.venderBoletosC();
    cine.venderBoletosC();
    cout << endl;
    cout << "Ganancias por Funcion" << endl;
    cout << endl;
    cine.mostrarReporteGananaciasFuncion();
    cout << endl;
    cout << "Ganancias por peliula" << endl;
    cout << endl;
    cine.mostrarReporteGananciasPelicula();
    cout << endl;

}

