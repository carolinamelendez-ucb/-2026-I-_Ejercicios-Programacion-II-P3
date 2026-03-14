#include <iostream>
#include <string>
#include "Cliente.h"
#include "FuncionVector.h"
using namespace std;

int main()
{
    Sala* s1 = new Sala(1, 13, 12);
    Sala* s2 = new Sala(2, 15, 14);
    Sala* s3 = new Sala(3, 10, 10);
    Cliente* c1 = new Cliente(123, "Ana");
    Cliente* c2 = new Cliente(456, "Mario");
    Cliente* c3 = new Cliente(789, "Juan");
    Cliente* c4 = new Cliente(101, "Marta");
    Pelicula* p1 = new Pelicula("SpiderMan", 156);
    Pelicula* p2 = new Pelicula("LaLaLand", 212);
    Pelicula* p3 = new Pelicula("HarryPotter", 156);
    FuncionVector f(10);
    f.agregarFuncion(new Funcion(s1, p1, 35));
    f.agregarFuncion(new Funcion(s2, p2, 40));
    f.agregarFuncion(new Funcion(s2, p2, 40));
    f.agregarFuncion(new Funcion(s3, p3, 30));
    cout << "=== FUNCIONES ===" << endl;
    f.getFuncion(0)->venderBoleto();
    f.getFuncion(0)->venderBoleto();
    f.getFuncion(1)->venderBoleto();
    f.getFuncion(2)->venderBoleto();
    f.getFuncion(2)->venderBoleto();
    f.getFuncion(2)->venderBoleto();
    f.getFuncion(3)->venderBoleto();
    f.mostrarFunciones();
    cout << "=== GANANCIA POR FUNCION ===" << endl;
    f.TotalPorFuncion();
    cout << "=== GANANCIA POR PELICULA ===" << endl;
    f.TotalPorPelicula("LaLaLand");
    f.TotalPorPelicula("SpiderMan");
    f.TotalPorPelicula("HarryPotter");
}

