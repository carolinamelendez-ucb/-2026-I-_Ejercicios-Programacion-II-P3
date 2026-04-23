#include <iostream>
#include <string>
#include <exception>            // mira la nueva libreria
#include "Biblioteca.h"
using namespace std;

/*
Hoy VEREMOS EXCEPCIONES: 

 OJO CON ESTO todo throw debe tener su catch
 
 REVISA DISCORD
 
 
 int main(){
 //crear un objeto sin puntero
 Estudiante estudiante1=Estudiante(....);
 
 // crear Objeto con PUNTERO
 Estudiante* estudiante1=new Estudiante(...);
 
 SABADO VEREMOS TEMPLATES
 
 }

 en las pruebas vos haras 
 Custom exception


*/
/*

int dividir(int numerador, int denominador) {
    if (denominador == 0) { //control
        exception myExceotion = exception();    //objeto sin puntero. ESTO LO HIZO POR SEPARADO, de paso solo recibe un mensaje
        //throw exception();


        string mensaje = "Divison invalida sobre 0";
        throw mensaje;                                                // le pondremos throw (asocia esto con el baseball)
    }
    return numerador / denominador;
}
*/
int main(){
    /*
    int numerdor, denominador, resultado;
    std::cout << "Hello World!\n";
    for (int i = 0;i < 10;i++) {
        cin >> numerdor >> denominador;
        try {

            resultado = dividir(numerdor, denominador);     //Posibilidad q lanze throw

            // si se da una sentencia lanza throw, el resto de las lineas 
            cout << "El resultado es:" << resultado << endl;
        }
        catch (string  mensajeError) {  // si alla le puse exception .       Pone en catch un &, es de buena practica
            cout << "-  Mensaje de error : "<<mensajeError << endl;
        }   
    }
    cout << "FIn de las divisiones...." << endl;
    */


    Biblioteca* sistema = new Biblioteca("Choripan", 100, 50);

     sistema->AgregarLibro(new Libro (23,"La Iliada",true,11));
     sistema->AgregarLibro(new Libro(54, "El Pasajero", false, 32));

    




}
