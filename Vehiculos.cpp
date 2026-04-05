#include "Sistema.h"
#include "TransporteTerrestre.h"
#include "TransporteAereo.h"
#include "TransporteMaritimo.h"

int main() {

    Sistema sistema;

    // Transportes
    sistema.registrarTransporte(new TransporteTerrestre("Terreno 1"));
    sistema.registrarTransporte(new TransporteAereo("Aereo 1"));
    sistema.registrarTransporte(new TransporteMaritimo("Maritimo 1"));

    // Operadores
    sistema.registrarOperador(new Operador("123", "Juan"));
    sistema.registrarOperador(new Operador("456", "Maria"));

    // Asignaciones
    sistema.asignar("123", "Terreno 1", 150);
    sistema.asignar("456", "Aereo 1", 1200);

    
    sistema.mostrarTodo();
    cout << endl;
    cout << "TOTAL ////" << endl;
    sistema.mostrarTotal();
    cout << endl;
    cout << "MENOR ////" << endl;
    sistema.mostrarMenor();
    

    return 0;
}