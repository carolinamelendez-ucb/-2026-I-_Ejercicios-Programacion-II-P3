#pragma once
#include <string>
#include<iostream>
using namespace std;

class Socios {
private:
	int CI;
	string Nombre;
	int telefono;
public:
	Socios() {
		CI = 0;
		Nombre = "";
		telefono = 0;
	}
	Socios(int dni,string nom,int telf) {
		this->CI = dni;
		this->Nombre = nom;
		this->telefono = telf;
	}
	void mostrarSocio() {
		cout << "CI:"<<CI << endl;
		cout << "Nombre"<<Nombre << endl;
		cout << "Telefono"<<telefono << endl;
	}
	int getCI() {
		return CI;
	}
	int getTelefono() {
		return telefono;
	}
	
};

class VectorSocios {
private:
	Socios** integrantes;
	int tamanio;
	int cantidad;
public:
	VectorSocios(int tamanio) {
		this->integrantes = new Socios*[tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void AgregarSocio(Socios* nuevoSocio) {
		integrantes[cantidad] = nuevoSocio;
		cantidad++;
	}
	void Mostrar_Vector_Socios() {
		for (int i = 0;i < cantidad;i++) {
			integrantes[i]->mostrarSocio();
		}
	}
};


class Equipo {
private:
	string Piloto;
	string Copiloto;
	string Nom_Auto;
	string NomEquipo;
public:
	Equipo() {
		Piloto = "";
		Copiloto = "";
		Nom_Auto = "";
		NomEquipo = "";
	}
	Equipo(string pi,string copi,string nomA,string nomE) {
		this->Piloto = pi;
		this->Copiloto = copi;
		this->NomEquipo = nomE;
		this->Nom_Auto = nomA;
	}
	void MostrarEquipo() {
		cout << "Nombre del Equipo:" << NomEquipo << endl;
		cout << "Piloto:" << Piloto << endl;
		cout << "Copiloto:" << Copiloto << endl;
		cout << "Nombre del Auto:" << Nom_Auto << endl;
	}
	string getPiloto() {
		return Piloto;
	}
	string getCopiloto() {
		return Copiloto;
	}

};

class VectorEquipo {
private:
	Equipo** Miembros;
	int tamanio;
	int cantidad;
public:
	VectorEquipo(int tamanio) {
		this->Miembros = new Equipo*[tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	
	void Mostrar_Vector_Equipo() {
		for (int i = 0;i < cantidad;i++) {
			Miembros[i]->MostrarEquipo();
		}
	}

	void Contro_de_Nombre() {
		for (int i = 0;i < cantidad;i++) {
			if (Miembros[i]->getPiloto() == Miembros[i]->getCopiloto()) {
				cout << "El equipo " << i << "hay integrantes con nombres similares" << endl;
			}
		}
	}


};