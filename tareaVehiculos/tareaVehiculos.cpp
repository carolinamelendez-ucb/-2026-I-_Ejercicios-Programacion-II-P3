#include <iostream>
#include <string>

#include "SistemaTransporte.h"
#include "TransporteTerrestre.h"
#include "TransporteAereo.h"
#include "TransporteMaritimo.h"
#include "Operador.h"

using namespace std;

int main()
{
    SistemaTransporte sistema = SistemaTransporte(10, 10);

    cout << "=== 1. REGISTRO DE MEDIOS DE TRANSPORTE ===" << endl;
    sistema.registrarTransporte(new TransporteTerrestre("ABC-123", "Bus"));
    sistema.registrarTransporte(new TransporteAereo("AV-001", "Boeing 737"));
    sistema.registrarTransporte(new TransporteMaritimo("MAR-01", "Barco Carga"));
    sistema.registrarTransporte(new TransporteTerrestre("ABC-123", "Camion"));

    cout << "\n=== 2. REGISTRO DE OPERADORES ===" << endl;
    sistema.registrarOperador(new Operador(111, "Carlos Arandia"));
    sistema.registrarOperador(new Operador(222, "Ana Polo"));
    sistema.registrarOperador(new Operador(333, "Luis Fernandez"));
    sistema.registrarOperador(new Operador(111, "Sara Rojas"));

    cout << "\n=== 3. ASOCIACION OPERADOR - TRANSPORTE ===" << endl;
    sistema.asociarOperadorTransporte(111, "ABC-123", 80);
    sistema.asociarOperadorTransporte(222, "AVY-001", 1200);
    sistema.asociarOperadorTransporte(333, "MAR-01", 600);
    sistema.asociarOperadorTransporte(111, "XYZ-999", 100);

    cout << "\n=== 4. COSTO GENERADO POR OPERADOR ===" << endl;
    sistema.mostrarCostoPorOperador(111);
    sistema.mostrarCostoPorOperador(222);
    sistema.mostrarCostoPorOperador(333);

    cout << "\n=== 5. COSTO TOTAL GENERAL ===" << endl;
    sistema.mostrarCostoTotalGeneral();

    cout << "\n=== 6. OPERADOR Y TRANSPORTE CON MENOR COSTO ===" << endl;
    sistema.mostrarOperadorMenorCosto();

    cout << "\n=== INFORMACION ADICIONAL ===" << endl;
    sistema.mostrarTodosLosTransportes();
    sistema.mostrarTodosLosOperadores();

    return 0;
}