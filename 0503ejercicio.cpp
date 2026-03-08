#include <iostream>
#include <string>
#include "Socio.h"
#include "VectorSocios.h"
#include "Equipo.h"
#include "VectorEquipos.h"
#include "Competencia.h"
using namespace std;

int main() {

    VectorSocios* listaSocios = new VectorSocios();
    VectorEquipos* listaEquipos = new VectorEquipos();

    int opcion;

    do {
        cout << "\n=== SISTEMA DE ASOCIACION AUTOMOVILISTICA ===" << endl;
        cout << "1. Registrar socio" << endl;
        cout << "2. Mostrar todos los socios (ordenados alfabeticamente)" << endl;
        cout << "3. Crear equipo" << endl;
        cout << "4. Mostrar todos los equipos" << endl;
        cout << "5. Crear competencia" << endl;
        cout << "6. Inscribir equipo en competencia" << endl;
        cout << "7. Buscar equipos de un socio" << endl;
        cout << "8. Mostrar competencia" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string nombre, telefono;
            int ci;

            cout << "Ingrese CI del socio: ";
            cin >> ci;
            cin.ignore();

            cout << "Ingrese nombre del socio: ";
            getline(cin, nombre);

            cout << "Ingrese telefono del socio: ";
            getline(cin, telefono);

            Socio* nuevoSocio = new Socio(nombre, ci, telefono);
            listaSocios->agregarSocio(nuevoSocio);

            cout << "Socio registrado exitosamente!" << endl;
            break;
        }

        case 2: {
            if (listaSocios->getCantidad() == 0) {
                cout << "No hay socios registrados" << endl;
            }
            else {
                listaSocios->ordenarAlfabeticamente();
                listaSocios->mostrarTodos();
            }
            break;
        }

        case 3: {
            if (listaSocios->getCantidad() < 2) {
                cout << "Se necesitan al menos 2 socios para crear un equipo" << endl;
                break;
            }

            string nombreEquipo, autoEquipo;
            int ciPiloto, ciCopiloto;

            cout << "Ingrese nombre del equipo: ";
            cin.ignore();
            getline(cin, nombreEquipo);

            cout << "Ingrese auto del equipo: ";
            getline(cin, autoEquipo);

            cout << "Ingrese CI del piloto: ";
            cin >> ciPiloto;

            Socio* piloto = listaSocios->buscarPorCI(ciPiloto);
            if (piloto == NULL) {
                cout << "Piloto no encontrado" << endl;
                break;
            }

            cout << "Ingrese CI del copiloto: ";
            cin >> ciCopiloto;

            // Ver que piloto y copiloto no sean la misma persona
            if (ciPiloto == ciCopiloto) {
                cout << "Error: El piloto y copiloto no pueden ser la misma persona" << endl;
                break;
            }

            Socio* copiloto = listaSocios->buscarPorCI(ciCopiloto);
            if (copiloto == NULL) {
                cout << "Copiloto no encontrado" << endl;
                break;
            }

            Equipo* nuevoEquipo = new Equipo(nombreEquipo, autoEquipo, piloto, copiloto);
            listaEquipos->agregarEquipo(nuevoEquipo);

            cout << "Equipo creado exitosamente!" << endl;
            break;
        }

        case 4: {
            if (listaEquipos->getCantidad() == 0) {
                cout << "No hay equipos registrados" << endl;
            }
            else {
                listaEquipos->mostrarTodos();
            }
            break;
        }

        case 5: {
            string nombreCompetencia;
            int maxEquipos;

            cout << "Ingrese nombre de la competencia: ";
            cin.ignore();
            getline(cin, nombreCompetencia);

            cout << "Ingrese maximo de equipos permitidos: ";
            cin >> maxEquipos;

            Competencia* nuevaCompetencia = new Competencia(nombreCompetencia, maxEquipos);

            cout << "Competencia creada exitosamente!" << endl;

            // Menú para inscribir equipos en esta competencia
            int subOpcion;
            do {
                cout << "\n--- Gestion de competencia: " << nombreCompetencia << " ---" << endl;
                cout << "1. Inscribir equipo" << endl;
                cout << "2. Mostrar inscritos" << endl;
                cout << "3. Volver al menu principal" << endl;
                cout << "Opcion: ";
                cin >> subOpcion;

                switch (subOpcion) {
                case 1: {
                    if (listaEquipos->getCantidad() == 0) {
                        cout << "No hay equipos registrados" << endl;
                        break;
                    }

                    listaEquipos->mostrarTodos();

                    int indice;
                    cout << "Seleccione el numero del equipo a inscribir: ";
                    cin >> indice;

                    Equipo* equipo = listaEquipos->getEquipo(indice - 1);
                    if (equipo != NULL) {
                        nuevaCompetencia->inscribirEquipo(equipo);
                    }
                    else {
                        cout << "Equipo no valido" << endl;
                    }
                    break;
                }

                case 2: {
                    nuevaCompetencia->mostrarInscritos();
                    break;
                }
                }
            } while (subOpcion != 3);

            delete nuevaCompetencia;
            break;
        }

        case 6: {
            if (listaEquipos->getCantidad() == 0) {
                cout << "No hay equipos registrados" << endl;
                break;
            }

            // Crear una competencia simple para pruebas
            string nombreComp;
            int maxEq;

            cout << "Ingrese nombre de la competencia: ";
            cin.ignore();
            getline(cin, nombreComp);

            cout << "Ingrese maximo de equipos: ";
            cin >> maxEq;

            Competencia* comp = new Competencia(nombreComp, maxEq);

            listaEquipos->mostrarTodos();

            int indice;
            cout << "Seleccione el numero del equipo a inscribir: ";
            cin >> indice;

            Equipo* equipo = listaEquipos->getEquipo(indice - 1);
            if (equipo != NULL) {
                comp->inscribirEquipo(equipo);
            }

            comp->mostrarInscritos();
            delete comp;
            break;
        }

        case 7: {
            if (listaSocios->getCantidad() == 0) {
                cout << "No hay socios registrados" << endl;
                break;
            }

            string nombreSocio;
            cout << "Ingrese nombre del socio a buscar: ";
            cin.ignore();
            getline(cin, nombreSocio);

            Socio* socio = listaSocios->buscarPorNombre(nombreSocio);
            if (socio != NULL) {
                listaEquipos->buscarEquiposDeSocio(socio);
            }
            else {
                cout << "Socio no encontrado" << endl;
            }
            break;
        }

        case 8: {

            Competencia* ejemplo = new Competencia("Gran Premio", 5);

            for (int i = 0; i < listaEquipos->getCantidad() && i < 3; i++) {
                ejemplo->inscribirEquipo(listaEquipos->getEquipo(i));
            }

            ejemplo->mostrarInscritos();
            delete ejemplo;
            break;
        }
        }

    } while (opcion != 0);

    delete listaEquipos;
    delete listaSocios;

    cout << "Programa terminado." << endl;

    return 0;
}