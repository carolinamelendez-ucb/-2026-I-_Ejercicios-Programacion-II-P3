#include <iostream>
#include <string>

#include "SistemaPagos.h"
#include "Cliente.h"
#include "PagoComisionPorcentual.h"
#include "PagoComisionFija.h"
#include "PagoSinComision.h"
#include "PagoConDescuento.h"

using namespace std;

int main()
{
    SistemaPagos sistema = SistemaPagos(10);

    Cliente* cliente1 = new Cliente("Juan Vargas", 10);
    Cliente* cliente2 = new Cliente("Alejandra Cabrera", 10);

    cliente1->agregarTransaccion(100, new PagoComisionPorcentual());
    cliente1->agregarTransaccion(200, new PagoComisionFija());

    cliente2->agregarTransaccion(150, new PagoConDescuento());
    cliente2->agregarTransaccion(0, new PagoSinComision());

    sistema.agregarCliente(cliente1);
    sistema.agregarCliente(cliente2);

    sistema.procesarTodasLasTransacciones();

    sistema.mostrarTodosLosClientes();
    sistema.mostrarTotalGeneral();

    return 0;
}