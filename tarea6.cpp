#include "Sistema.h"

int main() {

    Sistema s;

    Cliente* c1 = new Cliente("Mauricio");
    Cliente* c2 = new Cliente("Sebas");

    c1->agregarPago(new PagoPorcentual(100));
    c1->agregarPago(new PagoFijo(50));
    c1->agregarPago(new PagoValidado(-10));

    c2->agregarPago(new PagoDescuento(200));
    c2->agregarPago(new PagoPorcentual(300));

    s.agregarCliente(c1);
    s.agregarCliente(c2);

    s.mostrarSistema();

    return 0;
}
