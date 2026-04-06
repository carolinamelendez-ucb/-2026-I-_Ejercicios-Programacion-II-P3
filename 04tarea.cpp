// 04tarea.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//  Hay un sistema, hay un pagom hay cliente cada uno con su vector

#include <iostream>
#include <string>
#include "Sistema.h"
#include "PagoComisionFija.h"
#include "PagoComisionPorcentual.h"
#include "PagoConDescuento.h"
#include "PagoSinComisionConValidacion.h"
using namespace std;


int main()
{
	Sistema misSistema(20);
	cout << "Registrando Clientes...." << endl;
	misSistema.registrarClientes(new Cliente(1, "Juan Perez",5));
	misSistema.registrarClientes(new Cliente(2, "Maria Lopez", 3));
	misSistema.registrarClientes(new Cliente(3, "Sarai Lujan", 5));
	cout << endl;
	cout << "Agregando Pagos....." << endl;
	misSistema.agregarPagoCliente(1, new PagoComisionPorcentual(100));
	misSistema.agregarPagoCliente(1, new PagoComisionFija(200));
	misSistema.agregarPagoCliente(1, new PagoConDescuento(150));
	misSistema.agregarPagoCliente(2, new PagoSinComisionConValidacion(-50));
	misSistema.agregarPagoCliente(2, new PagoComisionPorcentual(400));
	misSistema.agregarPagoCliente(3, new PagoConDescuento(500));
	cout << endl;
	cout << "Proecesando Transacciones..." << endl;
	cout << endl;
	misSistema.ProcesarTransacciones();
	cout << "Clientes Registrados: " << endl;
	misSistema.mostrarClientes();
	cout << endl;
	cout << "_______________________________________________ "<< endl;
	cout << "TOTAL GENERAL PROCESADO: "<< misSistema.totalProcesado();
}
