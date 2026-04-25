#include <iostream>
#include <string>
#include "Pelicula.h"
#include "ArrayGenerico.h"
using namespace std;

int main()
{
	ArrayGenerico<Pelicula>* listaPeliculas = new ArrayGenerico<Pelicula>(10);
	try {
		listaPeliculas->agregar(new Pelicula("Wall-e", 243));
		listaPeliculas->agregar(new Pelicula("Drama", 300));
	}
	catch (exception& err) {
		cout << err.what() << endl;
	}
	listaPeliculas->mostrar();
}