#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;




int main() {

    Sistema* Patomarking = new  Sistema("Patomarking");

    //1

    /*

    try {
        Patomarking->registrarVehiculo(new Vehiculo(1234, "Ford", 1000, 75));
        Patomarking->registrarVehiculo(new Vehiculo(5678, "Hyundai", 2000, 85));
        Patomarking->registrarVehiculo(new Vehiculo(9101, "BYD", 3900, 100));
        Patomarking->registrarVehiculo(new Vehiculo(3243, "Tesla", 4000, 80));

        Patomarking->mostrarVehiculo();
    }
    catch (VehiculoDuplicadoException& e) {
        cout << "Error:" << e.what() << endl;
    }
  */


  //2

/*
    try {
        Patomarking->registrarVehiculo(new Vehiculo(9876, "Toyota", 50, 3));
        cout << "=== ANTES ===" << endl;
        Patomarking->mostrarVehiculo();
        Patomarking->Disminuir(9876);
        cout << "=== DESPUES ===" << endl;
        Patomarking->mostrarVehiculo();
    }
    catch (VehiculoNoEncontradoException& e) {
        cout << "Error: " << e.what() << endl;
    }

*/
    //3

    /*

    try {
        Patomarking->registrarVehiculo(new Vehiculo(4321, "Audi", 0, 50));
    }
    catch(EnergiaMenorException& e){
        cout << "Error: " << e.what() << endl;
    }
  
   */

    //4

    /*

    try {
        Patomarking->registrarVehiculo(new Vehiculo(1234, "Ford", 100, 75));
        Patomarking->registrarVehiculo(new Vehiculo(5678, "Hyundai", 200, 85));
        Patomarking->registrarVehiculo(new Vehiculo(9101, "BYD", 80, 100));
        Patomarking->registrarVehiculo(new Vehiculo(3243, "Tesla", 120, 80));

        Patomarking->buscarPlaca(1111);
    }
    catch (VehiculoNoEncontradoException& e) {
        cout << "Error: " << e.what() << endl;
    }

    */

    //5

    /*
        Patomarking->registrarVehiculo(new Vehiculo(1234, "Ford", 60, 75));
        Patomarking->registrarVehiculo(new Vehiculo(5678, "Hyundai", 20, 85));
        Patomarking->registrarVehiculo(new Vehiculo(9101, "BYD", 39, 100));
        Patomarking->registrarVehiculo(new Vehiculo(3243, "Tesla", 70, 80));
   
        Patomarking->VehiculosMenorEnergia();
    */


}

