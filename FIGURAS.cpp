#include "VectorFiguras.h"
#include "Circulo.h"
#include "Rectangulo.h"

int main() {

    VectorFiguras vectorFiguras(10);

    
    Figura* figura1 = new Circulo(4);
    Figura* figura2 = new Rectangulo(5, 10);
    Figura* figura3 = new Circulo(2.5);

    
    vectorFiguras.agregar(figura1);
    vectorFiguras.agregar(figura2);
    vectorFiguras.agregar(figura3);

    vectorFiguras.calcularTodasLasAreas();

    return 0;
}