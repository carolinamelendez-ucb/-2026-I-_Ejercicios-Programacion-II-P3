#include <iostream>
#include <string>

#include "SistemaEntregas.h"

using namespace std;

int main() {
    SistemaEntregas sistema;

    cout << "=== Sistema De Gestion De Entregas ===\n" << endl;

    // Registramos repartidores
    cout << "--- Registro De Pepartidores ---" << endl;
    sistema.registrarRepartidor("Carlos Perez", 101);
    sistema.registrarRepartidor("Ana Camacho", 102);
    sistema.registrarRepartidor("Luis Polo", 103);
    sistema.registrarRepartidor("Maria Arandia", 104);

    // Intentar registrar repartidor con ID duplicado
    sistema.registrarRepartidor("Pedro Fernandez", 101);

    cout << endl;

    // Registramos las entregas
    cout << "--- Registro De Entregas ---" << endl;
    sistema.registrarEntrega(201, "Av. Circunvalacion 123");
    sistema.registrarEntrega(202, "Calle 25 de Mayo 456");
    sistema.registrarEntrega(203, "Plaza Quintanuilla 789");
    sistema.registrarEntrega(204, "Barrio Aranjuez 321");

    // Intentar registrar entrega sin repartidores libres
    sistema.registrarEntrega(205, "Zona Industrial 654");

    cout << endl;

    // Mostrar a los repartidores ordenados
    sistema.mostrarRepartidoresOrdenados();

    // Aumentar los paquetes
    cout << "--- Aumentar Paquetes ---" << endl;
    sistema.aumentarPaquetesEntrega(201, 5);
    sistema.aumentarPaquetesEntrega(201, 3);
    sistema.aumentarPaquetesEntrega(202, 10);

    // Intentar aumentar paquetes de entrega inexistente
    sistema.aumentarPaquetesEntrega(999, 2);

    cout << endl;

    // Finalizar las entregas
    cout << "--- Finalizar Entregas ---" << endl;
    sistema.finalizarEntrega(201);
    sistema.finalizarEntrega(202);

    // Intentar finalizar entrega ya finalizada
    sistema.finalizarEntrega(201);

    cout << endl;

    // Registrar una nueva entrega (ahora si hay repartidores libres)
    cout << "--- Nueva Entrega Con Reparidor Libre ---" << endl;
    sistema.registrarEntrega(205, "Zona Industrial 654");

    cout << endl;

    sistema.finalizarEntrega(203);

    cout << endl;

    // Mostrar al repartidor con menor entregas
    sistema.mostrarRepartidorMenorEntregas();

    // Mostrar a los repartidores ordenados nuevamente
    sistema.mostrarRepartidoresOrdenados();

    return 0;
}
