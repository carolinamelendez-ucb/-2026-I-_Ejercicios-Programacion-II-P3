#pragma once
#include <iostream>
#include <string>
#include "VectorCliente.h"
#include "VectorFuncion.h"
#include "VectorPelicula.h"
#include "VectorSala.h"
using namespace std;
class SistemaCine {
private:
	VectorCliente * listaCliente;
	VectorPelicula * listaPelicula;
	VectorSala * listaSala;
	VectorFuncion * listaFuncion;
public:
	SistemaCine(int espacioCliente, int espacioPelicula, int espacioSala, int espacioFuncion) {
		listaCliente = new VectorCliente(espacioCliente);
		listaPelicula = new VectorPelicula(espacioPelicula);
		listaSala = new VectorSala(espacioSala);
		listaFuncion = new VectorFuncion(espacioFuncion);
	}
	void registraClientes(int id, string nombre) {
		Cliente* clienteRegistrar = new Cliente(id, nombre);
		this->listaCliente->agregar(clienteRegistrar);
	}
	void mostrarClientes() {
		this->listaCliente->mostrar();
	}

	void registraSalas(int id, int numFilas, int numColumnas) {
		Sala* salaRegistrar = new Sala(id, numFilas, numColumnas);
		this->listaSala->agregar(salaRegistrar);
	}
	void mostrarSala() {
		this->listaSala->mostrar();
	}

	void registrPeliculas(int id, string nombre, string genero) {
		Pelicula* peliculaRegistrar = new Pelicula(id, nombre, genero);
		this->listaPelicula->agregar(peliculaRegistrar);
	}
	void mostrarPeliculas() {
		this->listaPelicula->mostrar();
	}

	void registraFuncion(int id, int idPelicula, int idSala, int precio) {
		Sala* salaFuncion = listaSala->buscarSala(idSala);
		Pelicula* peliculaFuncion = listaPelicula->buscarPelicula(idPelicula);

		if (salaFuncion != nullptr && peliculaFuncion != nullptr) {
			Funcion* funcionRegistrar = new Funcion(id, peliculaFuncion, salaFuncion, precio);
			this->listaFuncion->agregar(funcionRegistrar);
		}
		else {
			cout << "Sala o Plicula no encontrada, Error!!" << endl;
		}

	}
	void mostrarFuncion() {
		this->listaFuncion->mostrar();
	}

	// debe haber una cantidad de asientos eso sera igual a la cantidad
	// evitar vendr el mismo asiento, es como una matriz y cada siento tinen un lugar
	// de boletos disponibles para vender por funcion (se debe pasar parametro la funcion)
	// hay un contador de Boletos vendidos
	// RESTAR de boletos disponibles los boletos vendidos y verificar que
	// cunado ya no haya ya no se venda
	// SE DEBE SABER que CLIENTE compra el voleto
	//Debe haber un precio de boleto para luego clacular mosnto y actualizar ganacia si el boleto 
	//fue vendido con exito

	void venderBoletosC() {

		int idFuncion;
		cout << "Ingrese ID de la funcion: ";
		cin >> idFuncion;


		Funcion* funcionElegida = listaFuncion->buscarFuncion(idFuncion);

		if (funcionElegida == nullptr) {
			cout << "Funcion no encontrada, error" << endl;
			return;
		}
		int cantidad;
		cout << "Cuantos boletos desea? ";
		cin >> cantidad;
		for (int i = 0; i < cantidad; i++) {
			int fila, col;
			cout << "Boleto #" << (i + 1) << endl;
			funcionElegida->mostrarAsientos();

			cout << "Ingrese fila: ";
			cin >> fila; cout << endl;
			cout << "Ingrese columna: ";
			cin >> col; cout << endl;
			bool vendido = funcionElegida->venderBoleto(fila - 1, col - 1);
			if (!vendido) {
				cout << "No se pudo vender ese asiento. Intente otra vez" << endl;
				i--;
			}
			
		}
		cout << "Gracias por la compra!" << endl;
	}

	void mostrarReporteGananaciasFuncion() {
		listaFuncion->mostrarGananciaFun();
	}

	void mostrarReporteGananciasPelicula() {

		for (int i = 0; i < listaPelicula->getIndice(); i++) {
			Pelicula* peliAux = listaPelicula->getpos(i);

			int total = listaFuncion->ganaciaPeli(peliAux);
			cout << "Pelicula: " << peliAux->getNombre() << endl;
			cout << "Ganancia: " << total << " bs"<<endl;
		}
	}

};