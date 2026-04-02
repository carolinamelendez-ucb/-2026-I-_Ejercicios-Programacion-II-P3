#include <iostream>
#include <string>
#include "GestorFiguras.h"
using namespace std;


int main() {

    GestorFiguras ListaDeFiguras = GestorFiguras(10);

    ListaDeFiguras.registrarFigura(new Circulo(5.3));
    ListaDeFiguras.registrarFigura(new Rectangulo(5.3,12));
    ListaDeFiguras.registrarFigura(new Circulo(5.3));
    ListaDeFiguras.registrarFigura(new Rectangulo(10,8.9));

    ListaDeFiguras.mostrarTodasLasAreas();


}


