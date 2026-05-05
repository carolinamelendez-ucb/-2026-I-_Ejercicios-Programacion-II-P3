#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Auto.h"

using namespace std;

int main()
{
    LinkedList<Auto> lista;
    lista.agregar(new Auto("2345EFN", "TOYOTA", "Corolla"));
    lista.agregar(new Auto("5393FGV", "FORD", "Mustang"));
    lista.mostrar();
}