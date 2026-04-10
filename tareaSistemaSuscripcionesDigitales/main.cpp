#include <iostream>
#include <string>

#include "SistemaSuscripciones.h"
#include "Usuario.h"
#include "PlanBasico.h"
#include "PlanPremium.h"
#include "PlanFamiliar.h"
#include "PlanDescuento.h"

using namespace std;

int main()
{
    SistemaSuscripciones sistema = SistemaSuscripciones(10);

    Usuario* usuario1 = new Usuario("Luis F. Hernandez", "luis@email.com", 10);
    Usuario* usuario2 = new Usuario("Sofia Rojas", "sofia@email.com", 10);

    usuario1->agregarSuscripcion(new PlanBasico());
    usuario1->agregarSuscripcion(new PlanPremium());

    usuario2->agregarSuscripcion(new PlanFamiliar(7));
    usuario2->agregarSuscripcion(new PlanDescuento(20));

    sistema.agregarUsuario(usuario1);
    sistema.agregarUsuario(usuario2);

    Usuario* usuario3 = new Usuario("Pedro Lopez", "luis@email.com", 10);
    sistema.agregarUsuario(usuario3);

    sistema.procesarTodasLasSuscripciones();

    sistema.mostrarTodosLosUsuarios();
    sistema.mostrarTotalGeneral();

    return 0;
}