#include <iostream>
#include <string>

#include "VectorFiguras.h"
#include "Circulo.h"
#include "Rectangulo.h"

using namespace std;

int main()
{
    VectorFiguras miVector = VectorFiguras(10);

    miVector.agregar(new Circulo("Circulo1", 5.0));
    miVector.agregar(new Rectangulo("Rectangulo1", 4.0, 6.0));
    miVector.agregar(new Circulo("Circulo2", 3.0));
    miVector.agregar(new Rectangulo("Rectangulo2", 2.5, 8.0));

    miVector.calcularTodasLasAreas();

    return 0;
}