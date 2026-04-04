#include <iostream>
#include<string>
#include"Super.h"
using namespace std;

int main() {

 Supermercado* s1;
 Supermercado* s2;
 s1->agregarProducto(new ProductoEnvasado(20,"locoto",10));
 s1->agregarProducto(new ProductoFresco("lechuga",30,20));
 s2->agregarProducto(new ProductoPromocional(0.6,30,"tomate",20));
 s2->agregarProducto(new ProductoPremium(20,20,"papaya",50));
    cout << "Supermercado con mayor precio promedio: ";

    if (s1->tieneMayorPrecioPromedioQue(s2)) {
        s1->mostrarDatos();
    }
    else {
        s2->mostrarDatos();
    }

    return 0;
}
