#pragma once
#include <iostream>
using namespace std;

class Repartidor {
private:
	string nombre;
	int ci;
	string zonaAsignada;
	int cantidadPedidosEntregados;
	bool estado; //true = libre, false=ocupado
public:
	Repartidor() = default;

	Repartidor(const string& nombre, int ci, const string& zonaAsignada)
		: nombre(nombre), ci(ci), zonaAsignada(zonaAsignada), cantidadPedidosEntregados(0), estado(true)
	{
	}

	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Ci: " << ci << endl;
		cout << "Zona Asignada: " << zonaAsignada << endl;
		cout << "Cantidad de pedidos entregados: " << cantidadPedidosEntregados << endl;
		cout << "Esta libre: " << estado << endl;
	}

	void cambiarEstado() {
		if (estado) {
			estado = false;
		}
		else {
			estado = true;
		}
	}

	void aumentarNumeroPedidos() {
		cantidadPedidosEntregados++;
	}

	int getCi() { return ci; }
	string getZonaAsignada() { return zonaAsignada; }
	bool getEstado() { return estado; }
	int getCantidadPedidosEntregados() { return cantidadPedidosEntregados; }

};