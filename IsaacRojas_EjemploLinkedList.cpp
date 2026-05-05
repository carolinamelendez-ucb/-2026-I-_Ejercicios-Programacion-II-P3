#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList<int> listaEnteros;
    listaEnteros.agregar(10);
    listaEnteros.agregar(20);
    listaEnteros.agregar(30);
    listaEnteros.mostrar();

    LinkedList<string> listaStrings;
    listaStrings.agregar("Gavriel");
    listaStrings.agregar("DesXa");
    listaStrings.agregar("Samus");
    listaStrings.mostrar();
}
