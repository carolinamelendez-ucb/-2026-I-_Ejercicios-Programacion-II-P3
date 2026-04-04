
#include <iostream>
#include "vecsistema.h"
#include "vecvehiculos.h"

using namespace std;

int main() {

    VectorTransportes* T;
    VectorSistemas* S;

    Transporte* t1 = new TransporteTerrestre("BYT666");
    Transporte* t2 = new TransporteAereo("JPK888");
    Transporte* t3 = new TransporteMaritimo("PYT777");

    T->agregar(t1);
    T->agregar(t2);
    T->agregar(t3);

    S->agregar(new Sistema("Pedro", "654", 100, t1));
   S->agregar(new Sistema("Lurdes", "468", 1050, t2));
    S->agregar(new Sistema("Alejandro", "555", 340, t3));

    S->mostrar();

    return 0;
