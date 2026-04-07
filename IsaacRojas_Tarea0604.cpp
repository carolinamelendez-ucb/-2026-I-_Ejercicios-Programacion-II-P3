#include <iostream>
#include <string>
#include "SistemaDePago.h"
#include "PagoComisionFija.h"
#include "PagoComisionPorcentual.h"
#include "PagoConDescuento.h"
#include "PagoSinComisionConValidacion.h"
using namespace std;
int main()
{
    SistemaDePago miSistema(30);
    cout << "REGISTRANDO LOS CLIENTES..." << endl;
    miSistema.registrarClientes(new Cliente("Sofia Yucra", 1, 4));
    miSistema.registrarClientes(new Cliente("Jose Munioz", 2, 3));
    miSistema.registrarClientes(new Cliente("Urzula Oscares", 3, 5));
    cout << endl;
    cout << "AGREGANDO LOS PAGOS..." << endl;
    miSistema.agregarPagoCliente(1, new PagoComisionPorcentual(170));
    miSistema.agregarPagoCliente(1, new PagoComisionFija(300));
	miSistema.agregarPagoCliente(1, new PagoConDescuento(500));
	miSistema.agregarPagoCliente(2, new PagoSinComisionConValidacion(-70));
	miSistema.agregarPagoCliente(2, new PagoComisionPorcentual(250));
	miSistema.agregarPagoCliente(3, new PagoConDescuento(1000));
    cout << endl;
    cout << "PROCESANDO TRANSACCIONES..." << endl;
    cout << endl;
	miSistema.procesarTransacciones();
    cout << endl;
    cout << "Clientes Registrados" << endl;
    miSistema.mostrarClientes();
    cout << endl;
    cout << "____________________________" << endl;
    cout << "TOTAL GENERAL PROCESADO: " << miSistema.totalProcesado();
}