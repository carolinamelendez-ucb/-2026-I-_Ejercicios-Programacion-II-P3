// TAREA_0401_FigurasGeometricas.cpp 
/* 2. Figuras geométricas (RAMA:  CLASE-04-01-TAREA)

Implemente una clase abstracta Figura con un método virtual puro calcularArea().
A partir de esta, desarrolle clases derivadas como Circulo y Rectangulo, las cuales deben implementar
dicho método según su fórmula correspondiente.

Segundo, cree una clase VectorFiguras que permita almacenar objetos de tipo Figura (mediante punteros)
y proporcione un método calcularTodasLasAreas() que recorra el vector y calcule el área de cada figura.

En la función main(), utilice la clase VectorFiguras para agregar diferentes figuras de las clases derivadas
y luego invoque el método calcularTodasLasAreas(), mostrando en pantalla el resultado de cada una en el siguiente formato:

Figura 1 - Área: 51 m²
Figura 2 - Área: ..      */

#include <iostream>
#include <string>

#include "VectorFiguras.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Rombo.h"
#include "Triangulo.h"
#include "Pentagono.h"
using namespace std;

int main()
{
    VectorFiguras MisFiguras = VectorFiguras(10);

    MisFiguras.agregar(new Circulo(4));
    MisFiguras.agregar(new Rectangulo(5, 3));
    MisFiguras.agregar(new Rombo(6, 4));
    MisFiguras.agregar(new Triangulo(5, 2));
    MisFiguras.agregar(new Pentagono(3, 2));

    MisFiguras.calcularTodasLasAreas();

    return 0;
        
}

