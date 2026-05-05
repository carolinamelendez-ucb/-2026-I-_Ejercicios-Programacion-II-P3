
// class 0505.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main()
{
        LinkedList<string> autos;

        autos.agregar("TOYOTA");
        autos.agregar("MERCEDE");

        autos.mostrar();

}

