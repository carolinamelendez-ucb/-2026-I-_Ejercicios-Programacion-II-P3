// tareaexception.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Biblioteca.h"

int main()
{
	Biblioteca  miBlioteca = Biblioteca("Rosales", 10, 10);
	miBlioteca.agregarLibros(new Libro ("A1", "Sueños sin Limites", "Anonimo"));
	miBlioteca.agregarLibros(new Libro("A2", "Libertad", "Lucas Lujan"));
	miBlioteca.agregarLibros(new Libro("A3", "Guitarra Latina", "William"));


}

