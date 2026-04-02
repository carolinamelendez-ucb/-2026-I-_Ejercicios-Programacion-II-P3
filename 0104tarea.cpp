#include <iostream>
#include <string>
#include "VectorFiguras.h"
#include "Circulo.h"
#include "Rectangulo.h"


int main()
{
    VectorFiguras misFiguras(5);
    misFiguras.agregar(new Circulo(5));
    misFiguras.agregar(new Rectangulo(4, 5));

    misFiguras.calcularTodasLasAreas();
   

}

