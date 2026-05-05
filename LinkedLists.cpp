#include <iostream>
#include "LinkedList.h"
#include "Auto.h"

using namespace std;

int main()
{
    LinkedList<string>* listaNombres = new LinkedList<string>();
    listaNombres->agregar("Marco");
    listaNombres->agregar("Mauricio");
    listaNombres->agregar("Diego");
    listaNombres->mostrar();

    /*LinkedList<Auto>* listaAutos = new LinkedList<Auto>();
    listaAutos->agregar(Auto("1A", "A", 4));
    listaAutos->agregar(Auto("1B", "B", 2));
    listaAutos->agregar(Auto("1C", "C", 4));
    listaAutos->mostrar();*/
}
