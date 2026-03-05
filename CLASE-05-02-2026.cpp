#include<string>
#include <iostream>
#include"socios.h"
#include"equipo.h"
using namespace std;
int main() {
	Socios s(7939943,"Mateo", 61617247);
	s.mostrarSocios();
	Equipo e("Mateo", "Liam", "LosBorrachos", "ToyotaSupra2005");
	e.mostrarEquipos();
	return 0;
}
