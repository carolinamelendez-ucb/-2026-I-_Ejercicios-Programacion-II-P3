#include <iostream>
#include "LinkedList.h"
#include "Auto.h"

using namespace std;

int main() {
    LinkedList<Auto> lista;
    lista.agregar(Auto("Toyota", "Corolla"));
    lista.agregar(Auto("Honda", "Civic"));
    lista.agregar(Auto("Ford", "Mustang"));

    cout << "Lista de autos:" << endl;
    lista.mostrar();
}
