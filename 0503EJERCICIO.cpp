#include <iostream>
#include <string>
#include "Equipo.h"
#include "Socio.h"
#include "VectorEquipos.h"
#include "VectorSocios.h"

using namespace std;

int main()
{
	SociosVector socios = SociosVector(20);

	socios.agregar(new Socio("Alejandro", 12345, 12345));
	socios.agregar(new Socio("Santiago", 67890, 67890));
	socios.agregar(new Socio("Juana", 45678, 45678));
	socios.agregar(new Socio("Jose", 78901, 78901));

	socios.mostrarSocios();
}