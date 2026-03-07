#include <iostream>
#include "Socio.h"
#include "Equipo.h"
#include "VectorSocios.h"
#include "VectorEquipos.h"
#include "Competencia.h"
#include "VectorCompetencias.h"

using namespace std;

int main() {
    SociosVector socios(10);
    socios.agregar(new Socio("Alejandro", 1111, 7771));
    socios.agregar(new Socio("Carlos", 2222, 7772));
    socios.agregar(new Socio("Beatriz", 3333, 7773));
    socios.agregar(new Socio("Daniel", 4444, 7774));
    socios.agregar(new Socio("Elena", 5555, 7775));

    // Mostrar todos los socios
    cout << "SOCIOS REGISTRADOS" << endl;
    cout << endl;
    socios.mostrarSocios();
    cout << endl;

    // Ordenar socios alfabéticamente
    cout << "SOCIOS ORDENADOS ALFABETICAMENTE" << endl;
    cout << endl;
    socios.ordenarAlfabetico();
    socios.mostrarSocios();
    cout << endl;

    EquiposVector equipos(10);
    equipos.agregar(new Equipo("Rayo", "Toyota"));
    equipos.agregar(new Equipo("Trueno", "Subaru"));
    equipos.agregar(new Equipo("Relampago", "Ford"));
    equipos.registrarSociosEquipo(0, socios.getSocio(0), socios.getSocio(1));
    equipos.registrarSociosEquipo(1, socios.getSocio(2), socios.getSocio(3));
    equipos.registrarSociosEquipo(2, socios.getSocio(1), socios.getSocio(4));

    // Mostrar todos los equipos
    cout << "EQUIPOS REGISTRADOS" << endl;
    cout << endl;
    equipos.mostrarEquipos();
    cout << endl;

    CompetenciasVector competencias(5);
    Competencia* rally = new Competencia("Rally Nacional", 3);
    rally->agregarEquipo(equipos.getEquipo(0));
    rally->agregarEquipo(equipos.getEquipo(1));
    rally->agregarEquipo(equipos.getEquipo(2)); // Carlos ya participa en otro equipo, se espera fallo
    competencias.agregar(rally);
    cout << endl;

    // Mostrar todas las competencias
    cout << "COMPETENCIAS REGISTRADAS" << endl;
    cout << endl;
    competencias.mostrar();
    cout << endl;

    // Buscar equipos de un socio
    cout << "BUSCAR EQUIPOS DE UN SOCIO" << endl;
    cout << endl;
    Socio* buscado = socios.getSocio(1);
    cout << "Socio buscado: " << buscado->getNombre() << endl;
    equipos.buscarEquiposDeSocio(buscado);
}