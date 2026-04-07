#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;

int main()
{
    Sistema sistema(10);

    Cliente* c1 = new Cliente("Shamir Teran");
    c1->agregarPago(new PagoPorcentual(100));
    c1->agregarPago(new PagoFijo(200));

    Cliente* c2 = new Cliente("Pablo Ayaviri");
    c2->agregarPago(new PagoDescuento(150));
    c2->agregarPago(new PagoValidado(-50));

    sistema.agregarCliente(c1);
    sistema.agregarCliente(c2);

    sistema.mostrarTodo();

    cout << "----------------------------------" << endl;
    cout << "TOTAL GENERAL PROCESADO: " << sistema.totalGeneral() << endl;

    return 0;
}