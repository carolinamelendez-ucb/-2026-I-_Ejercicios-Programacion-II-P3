#pragma once
#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
	int ci;
	string nombre;
	string apellido;
	int cantCursos; //PARA TEST 13: Se agrego el atributo cantCursos y los metodos get y aumentar y reducir en 1 dicho atributo
public:
	Estudiante(int ci, const string& nombre, const string& apellido)
		: ci(ci), nombre(nombre), apellido(apellido), cantCursos(0)
	{
	}
	int getCI() {
		return ci; //se retorna ci+1 en lugar de solamente ci
	}
	int getCantCursos() { 
		return cantCursos;
	}
	void aumentarCursoInscrito() {
		this->cantCursos++;
	}
	void reducirCursoInscrito() {
		this->cantCursos--;
	}
	static bool compararCI(int c, Estudiante* e) {
		return c == e->ci;
	}
	void mostrar() {
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Apellido: " << apellido << endl;
	}
};