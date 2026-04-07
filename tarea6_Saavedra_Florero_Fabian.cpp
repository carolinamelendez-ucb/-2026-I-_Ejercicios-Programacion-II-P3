#include <iostream>
#include <string>
#include "Sistema.h"
#include "Cliente.h"
#include "PagoComisionPorcentual.h"
#include "PagoConComisionFija.h"
#include "PagoConDescuento.h"
#include "PagoConDescuento.h"
using namespace std;

int main(){
	Sistema* sis = new Sistema(3);


	Cliente* c1 = new Cliente(10);
	c1->agregarPago(new PagoComisionFija("Maria",240,10));
	c1->agregarPago(new PagoConDescuento("Maria",24));


}

