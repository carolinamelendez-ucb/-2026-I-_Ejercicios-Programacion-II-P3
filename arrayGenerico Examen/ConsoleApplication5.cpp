#include <iostream>
#include "SistemaParqueo.h"
#include "Espacio.h"
#include "Vehiculo.h"
#include "CapacidadMaximaException.h"
#include "CodigoEspacioDuplicadoException.h"

using namespace std;

int main() {
    try {
        SistemaParqueo::mostrarTotalSistemasCreados();
        SistemaParqueo::mostrarNombreEmpresaGlobal();
        Espacio::mostrarTotalEspaciosCreados();
        Vehiculo::mostrarTotalVehiculosCreados();
        cout << endl;

        SistemaParqueo sistema("Parqueo Central", "Av. Principal #123", 5);

        SistemaParqueo::mostrarTotalSistemasCreados();
        SistemaParqueo::mostrarNombreEmpresaGlobal();
        cout << endl;

        sistema.mostrarInformacion();
        cout << endl;

        Espacio* espacio1 = new Espacio("A01", 1);
        Espacio* espacio2 = new Espacio("A02", 1);
        Espacio* espacio3 = new Espacio("B01", 2);
        Espacio* espacio4 = new Espacio("B02", 2);
        Espacio* espacio5 = new Espacio("C01", 3);

        Espacio::mostrarTotalEspaciosCreados();
        cout << endl;

        espacio1->asignarSector("Norte");
        espacio2->asignarSector("Norte");
        espacio3->asignarSector("Sur");
        espacio4->asignarSector("Sur");
        espacio5->asignarSector("Este");

        espacio1->ocupar();
        espacio3->ocupar();

        cout << "=== Registrando espacios ===" << endl;
        sistema.registrarEspacio(espacio1);
        sistema.registrarEspacio(espacio2);
        sistema.registrarEspacio(espacio3);
        sistema.registrarEspacio(espacio4);
        sistema.registrarEspacio(espacio5);

        cout << endl;
        sistema.mostrarEspacios();
        cout << endl;

        Vehiculo* auto1 = new Vehiculo("ABC-123", "Toyota", "Corolla");
        Vehiculo* auto2 = new Vehiculo("DEF-456", "Honda", "Civic");
        Vehiculo* auto3 = new Vehiculo("GHI-789", "Mazda", "3");
        Vehiculo* auto4 = new Vehiculo("JKL-012", "Nissan", "Sentra");
        Vehiculo* auto5 = new Vehiculo("MNO-345", "Chevrolet", "Spark");

        Vehiculo::mostrarTotalVehiculosCreados();
        cout << endl;

        auto1->asignarTipo("Sedan");
        auto2->asignarTipo("Hatchback");
        auto3->asignarTipo("Sedan");
        auto4->asignarTipo("SUV");
        auto5->asignarTipo("Compacto");

        auto1->asignarEspacio(espacio1);
        auto2->asignarEspacio(espacio2);
        auto3->asignarEspacio(espacio3);
        auto4->asignarEspacio(espacio4);
        auto5->asignarEspacio(espacio5);

        cout << "=== Registrando vehiculos ===" << endl;
        sistema.registrarVehiculo(auto1);
        sistema.registrarVehiculo(auto2);
        sistema.registrarVehiculo(auto3);
        sistema.registrarVehiculo(auto4);
        sistema.registrarVehiculo(auto5);

        cout << endl;
        sistema.mostrarVehiculos();
        cout << endl;

        cout << "=== Detalle de Vehiculos ===" << endl;
        auto1->mostrarInformacion();
        cout << endl;
        auto2->mostrarInformacion();
        cout << endl;

        cout << "=== Detalle de Espacios ===" << endl;
        espacio1->mostrarInformacion();
        espacio2->mostrarInformacion();
        espacio3->mostrarInformacion();
        cout << endl;

        Espacio::mostrarTotalEspaciosCreados();
        Vehiculo::mostrarTotalVehiculosCreados();
        SistemaParqueo::mostrarTotalSistemasCreados();
    }
    catch (const exception& e) {
        cout << "Excepcion general capturada: " << e.what() << endl;
    }

    cout << "\n=== Fin del programa ===" << endl;

    return 0;
}