// Objetos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//NOTACION: pascal CASE --> MiPrimeraPalabra
//NOTACION: cAMEL case --> mi

#include <iostream>
using namespace std;
class Mochila {
    //ATRIBBUTOS
private:
    
    string color;
    string marca;
    string capacidad;
    string tamano;
    string material;
    //METODOS
public:

    Mochila(string colorM, string marcaM,string capacidadM, string materialM, string tamanoM)
    {

    color = colorM;
    marca= marcaM;
    capacidad = capacidadM;
    tamano = tamanoM;
    material= materialM;
    
    }


    void mostrar() 
    {

        cout <<"color: "<<color << endl;
        cout << "marca: " << marca << endl;
        cout << "capacidad: " << capacidad << endl;
        cout << "tamano: " << tamano<< endl;
        cout << "material: " << material << endl;

    }

    void setColor(string nuevoColor)
    {
        color = nuevoColor;
    }
    void setmaterial(string nuevomaterial)
    {
        material = nuevomaterial;
    }
    /*
   
    void abrir() {
        cout << "mochila se abre...." << endl;   }
    void cerrar() {
        cout << "mochila se cierra...." << endl; }
    void guardarOjebeto() {
        cout << "mochila guarda objetos...." << endl;}
    void transportar() {
        cout << "mochila transporta...." << endl;}
    void sacarObjetos() {
        cout << "mochila saca objetos...." << endl; }*/

};

int main()
{
    cout << "MOCHILA 1" << endl;

    Mochila mochila1 = Mochila("rojo", "totto", "alta", "cuero", "carta");
    mochila1.mostrar();
    /*
    mochila1.abrir();
    mochila1.cerrar();
    mochila1.guardarOjebeto();
    mochila1.transportar();
    mochila1.sacarObjetos();*/

  // cout << "MOCHILA 2" << endl;
    Mochila mochila2 = Mochila("naranja", "totto", "alta", "cuero","carta");
  // cout << "MOCHILA 3" << endl;
    Mochila mochila3 = Mochila("verde", "otra", "baja", "cuerina","carta");
    cout << "MOCHILA 4" << endl;
    Mochila mochila4 = Mochila("negro", "totto", "media", "cuero","oficio");
 

   
    mochila4.mostrar();
    mochila4.setColor("azul");
    mochila4.setmaterial("impermeable");
    cout << "COLOR y material MODIFICADO. MOCHILA 4" << endl;
    mochila4.mostrar();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
