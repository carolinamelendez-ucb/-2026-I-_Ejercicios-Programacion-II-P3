#include <iostream>
#include <string>
#include "Pregrado.h"
#include "Postgrado.h"
#include "MedioTiempo.h"
#include "TiempoCompleto.h"
#include "Sistema.h"
using namespace std;


int main(){
	Sistema* myUni = new Sistema(4, 10, 3);

	myUni->agregarEstudiante(new Pregrado("sergio", 1));
	myUni->agregarEstudiante(new Pregrado("maria", 2));
	myUni->agregarEstudiante(new Postgrado("cinthia", 2));
	myUni->agregarEstudiante(new Postgrado("alan", 5));


	myUni->agregarDocente(new MedioTiempo("Lucas", 4, true, 1000, 2));
	myUni->agregarDocente(new MedioTiempo("John", 2, true, 1200, 1));
	myUni->agregarDocente(new MedioTiempo("Karla", 3, true, 1000, 1));
	myUni->agregarDocente(new MedioTiempo("Martha", 4, true, 1000, 2));

	myUni->mostrarAlumnos();

}

