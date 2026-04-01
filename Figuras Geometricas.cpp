// Figuras Geometricas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <string>
#include "SistemaFiguras.h"

using namespace std;

int main()
{
	SistemaFiguras sistema = SistemaFiguras(20);

	sistema.registrarFigura(new Circulo(5));
	sistema.registrarFigura(new Circulo(4));
	sistema.registrarFigura(new Circulo(3));
	sistema.registrarFigura(new Rectangulo(3, 8));
	sistema.registrarFigura(new Rectangulo(2, 4.5));
	sistema.registrarFigura(new Rectangulo(5.30, 2.25));
	sistema.mostrarAreas();
}

