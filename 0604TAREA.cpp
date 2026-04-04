#include <iostream>
#include "SistemaPagos.h"
#include "PagoPorcentual.h"
#include "PagoFijo.h"
#include "PagoDescuento.h"
#include "PagoValidado.h"

using namespace std;

int main() {

    SistemaPagos sistema(5);

    Cliente* cliente1 = new Cliente("Juan Perez");
    cliente1->agregarPago(new PagoPorcentual(100));
    cliente1->agregarPago(new PagoFijo(200));

    Cliente* cliente2 = new Cliente("Maria Lopez");
    cliente2->agregarPago(new PagoDescuento(150));
    cliente2->agregarPago(new PagoValidado(-50));

    sistema.registrarCliente(cliente1);
    sistema.registrarCliente(cliente2);

    sistema.mostrarTodo();
}