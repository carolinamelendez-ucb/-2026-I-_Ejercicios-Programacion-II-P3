#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pelicula {
private:
	int id;
	string nombre;
	string genero;
public:
	Pelicula() = default;

	Pelicula(int id, const string& nombre, const string& genero)
		: id(id), nombre(nombre), genero(genero)
	{
	}
	void mostrar() {
		cout << "Id de Pelicula: " << id << endl;
		cout << "Nombre de la Pleicula: " << nombre << endl;
		cout << "Genero de la Pelicula: " << genero << endl;
	}

	string getNombre() {
		return nombre;
	}
	int getId(){
		return id;
}
};
