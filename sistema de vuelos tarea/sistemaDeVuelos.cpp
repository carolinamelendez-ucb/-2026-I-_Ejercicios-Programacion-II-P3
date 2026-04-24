#include <iostream>
#include <string>
#include "SistemaAsignacion.h"

using namespace std;

int main() {
    try {
        SistemaAsignacion sistema("BOA - Boliviana de Aviacion");

        cout << "=== SISTEMA DE ASIGNACION DE VUELOS - AEROPUERTO VIRU VIRU ===" << endl;

        // 1. Registrar vuelos
        cout << "\n--- REGISTRANDO VUELOS ---" << endl;
        sistema.registrarVuelo("VB101", "08:00", "10:30", 5, 4);
        sistema.registrarVuelo("VB202", "12:00", "14:15", 4, 3);
        sistema.registrarVuelo("VB303", "15:30", "17:45", 6, 4);

        // 2. Registrar pasajeros
        cout << "\n--- REGISTRANDO PASAJEROS ---" << endl;
        sistema.registrarPasajero("1234567", "Juan", "Perez");
        sistema.registrarPasajero("7654321", "Maria", "Gonzales");
        sistema.registrarPasajero("9876543", "Carlos", "Rodriguez");
        sistema.registrarPasajero("5555555", "Ana", "Martinez");
        sistema.registrarPasajero("4444444", "Luis", "Fernandez");

        // Intentar registrar pasajero duplicado
        try {
            sistema.registrarPasajero("1234567", "Pedro", "Lopez");
        }
        catch (exception& err) {
            cout << "Mensaje de error: " << err.what() << endl;
        }

        // 3. Asignar pasajeros a vuelos
        cout << "\n--- ASIGNANDO PASAJEROS A VUELOS ---" << endl;
        sistema.asignarPasajeroAVuelo("1234567", "VB101", "A1");
        sistema.asignarPasajeroAVuelo("7654321", "VB101", "A2");
        sistema.asignarPasajeroAVuelo("9876543", "VB202", "B1");
        sistema.asignarPasajeroAVuelo("5555555", "VB101", "A3");
        sistema.asignarPasajeroAVuelo("4444444", "VB303", "C1");

        // Intentar asignaciones invalidas
        try {
            sistema.asignarPasajeroAVuelo("9999999", "VB101", "A4");  // Pasajero no existe
        }
        catch (exception& err) {
            cout << "\nMensaje de error: " << err.what() << endl;
        }

        try {
            sistema.asignarPasajeroAVuelo("1234567", "VB999", "A5");  // Vuelo no existe
        }
        catch (exception& err) {
            cout << "Mensaje de error: " << err.what() << endl;
        }

        try {
            sistema.asignarPasajeroAVuelo("1234567", "VB101", "Z99");  // Asiento no existe
        }
        catch (exception& err) {
            cout << "Mensaje de error: " << err.what() << endl;
        }

        try {
            sistema.asignarPasajeroAVuelo("7654321", "VB101", "A1");  // Asiento no disponible
        }
        catch (exception& err) {
            cout << "Mensaje de error: " << err.what() << endl;
        }

        // 4. Mostrar lista de pasajeros de un vuelo
        sistema.mostrarPasajerosDeVuelo("VB101");

        // 5. Mostrar estadisticas de asientos
        sistema.mostrarEstadisticasVuelo("VB101");

        // 6. Actualizar horas de llegada para pruebas
        cout << "\n--- ACTUALIZANDO HORAS DE LLEGADA ---" << endl;
        Vuelo* vuelo1 = sistema.buscarVuelo("VB101");
        if (vuelo1 != nullptr) vuelo1->actualizarHoraLlegada("10:15");  // Llegó antes (a tiempo)

        Vuelo* vuelo2 = sistema.buscarVuelo("VB202");
        if (vuelo2 != nullptr) vuelo2->actualizarHoraLlegada("15:00");  // Llegó tarde (45 min retraso)

        Vuelo* vuelo3 = sistema.buscarVuelo("VB303");
        if (vuelo3 != nullptr) vuelo3->actualizarHoraLlegada("18:30");  // Llegó tarde (45 min retraso)

        // 7. Mostrar vuelos a tiempo y con retraso
        sistema.mostrarVuelosATiempo();
        sistema.mostrarVuelosConRetraso();
        sistema.mostrarVueloMayorRetraso();

        // 8. Cambiar asiento a un pasajero
        cout << "\n--- CAMBIANDO ASIENTO ---" << endl;
        sistema.cambiarAsientoPasajero("1234567", "VB101", "B2");

        // 9. Buscar pasajero por CI
        sistema.buscarPasajeroPorCI("1234567");

        // 10. Ordenar pasajeros por apellido
        sistema.ordenarPasajerosPorApellido("VB101");

        // 11. Mostrar vuelos de un pasajero
        sistema.mostrarVuelosDePasajero("1234567");

        // 12. Mostrar pasajero con mas vuelos
        sistema.mostrarPasajeroConMasVuelos();

        // 13. Mostrar estadísticas actualizadas despues del cambio de asiento
        sistema.mostrarEstadisticasVuelo("VB101");

        cout << "\n=== FIN DEL PROGRAMA ===" << endl;

    }
    catch (exception& err) {
        cout << "Error en el sistema: " << err.what() << endl;
    }

    return 0;
}