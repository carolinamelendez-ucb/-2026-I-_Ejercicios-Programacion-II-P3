#pragma once
#include <iostream>
#include <string>
using namespace std;

class Libro{
	private:
	string titulo;
	int codigo;
	bool estado; //true = disponible
	public:

	Libro (const string& titulo, int codigo)
		: titulo (titulo), codigo (codigo), estado (true)
	{
	}

	void mostrar (){
		cout << "Titulo: " << titulo << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Estado: " << endl;
		if(estado == true){
			cout << "Disponible" << endl;
		}
		else{
			cout << "No disponible" << endl;
		}
	}

	string getTitulo (){
		return titulo;
	}

	int getCodigo (){
		return codigo;
	}

	bool getEstado (){
		return estado;
	}

	void actualizarEstado (){
		if(estado == true){
			estado = false;
		}
		else{
			estado = true;
		}
	}
};