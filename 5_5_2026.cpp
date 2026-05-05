#include <iostream>
#include <string>
#include "Linkedlist.h"
using namespace std;


/*

Linkedlist (lista enlazada)

Tarea: 
1)Insvestigar como agregar y mostrar en linkedlist
2)realizar prubea de ""  ""
3)Aplica Templates
4) agrega y mostra Autos.
*/



int main(){

	LinkedList* listaNombres = new LinkedList();  // no recibe nada
	
	/*
	listaNombres->agregar("Marco");
	listaNombres->agregar("Bicho");
	listaNombres->agregar("Favo");
	listaNombres->mostrar();
	*/
	// por ahora, solo SOBREESCRIBE Y NO NOS MUESTRA NADA.


	// como? hago un sig...

	listaNombres->agregar("Favo");
	listaNombres->aniadirMas("Paco");
	listaNombres->aniadirMas("Caballo");
	listaNombres->mostrar();

}


