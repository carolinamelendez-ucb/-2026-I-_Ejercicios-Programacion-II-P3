#include <iostream>
#include <string>
#include "ListaTransporte.h"
#include "TransporteTerrestre.h"
#include "TransporteAereo.h"
#include "TransporteMaritimo.h"
using namespace std;


int main(){
   
	listaTransporte* flota = new listaTransporte(5);
	
	flota->agregar(new TrasnporteTerrestre("Bus", "Terrestre"));
	flota->agregar(new TransporteAereo("Avion", "Aereo"));
	flota->agregar(new TransporteMaritimo("Barco Carga", "Maritimo"));


	flota->calcularCostos(50.0);
	flota->calcularCostos(150.0);
	flota->calcularCostos(600.0);

}


