#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Auto.h"

using namespace std;

int main()
{
    LinkedList<Auto> listaAutos;
    listaAutos.agregar(Auto("Toyota","123"));
    listaAutos.agregar(Auto("susuki","123"));
    listaAutos.mostrar();
}