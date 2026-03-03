// Clase 03-03-EJERCICIO
#include <iostream>
#include <string>

using namespace std;

class Pasajero {
private:
    string nombre;
    int ci;
    int numeroAsiento;

public:
    Pasajero(string nombre, int ci) {
        this->ci = ci;
        this->nombre = nombre;
        this->numeroAsiento = 0;
    }

    void asignarAsiento(int numero) {
        this->numeroAsiento = numero;
    }

    string getNombre() {
        return nombre;
    }

    int getCi() {
        return ci;
    }

    int getNumeroAsiento() {
        return numeroAsiento;
    }
};

class PasajerosVector {
private:
    Pasajero** pasajeros;
    int capacidad;
    int cantidad;

public:
    PasajerosVector(int capacidad) {
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->pasajeros = new Pasajero * [capacidad];
    }

    ~PasajerosVector() {
        for (int i = 0; i < cantidad; i++) {
            delete pasajeros[i];
        }
        delete[] pasajeros;
    }

    void agregarPasajero(string nombre, int ci) {
        if (cantidad < capacidad) {
            pasajeros[cantidad] = new Pasajero(nombre, ci);
            cantidad++;
        }
        else {
            cout << "No hay espacio para más pasajeros." << endl;
        }
    }

    void asignarAsientoAPasajero(int indice, int numeroAsiento) {
        if (indice >= 0 && indice < cantidad) {
            pasajeros[indice]->asignarAsiento(numeroAsiento);
        }
    }

    // 1. Mostrar todos los pasajeros que no tienen asiento
    void mostrarPasajerosSinAsiento() {
        cout << "Pasajeros sin asiento:" << endl;
        bool encontrado = false;

        for (int i = 0; i < cantidad; i++) {
            if (pasajeros[i]->getNumeroAsiento() == 0) {
                cout << "Nombre: " << pasajeros[i]->getNombre()
                    << ", CI: " << pasajeros[i]->getCi() << endl;
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No hay pasajeros sin asiento." << endl;
        }
        cout << endl;
    }

    // 2. Mostrar pasajeros que tienen asiento impar
    void mostrarPasajerosAsientoImpar() {
        cout << "Pasajeros con asiento impar:" << endl;
        bool encontrado = false;

        for (int i = 0; i < cantidad; i++) {
            int asiento = pasajeros[i]->getNumeroAsiento();
            if (asiento != 0 && asiento % 2 != 0) {
                cout << "Nombre: " << pasajeros[i]->getNombre()
                    << ", CI: " << pasajeros[i]->getCi()
                    << ", Asiento: " << asiento << endl;
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No hay pasajeros con asiento impar." << endl;
        }
        cout << endl;
    }

    // 3. Mostrar un pasajero dado un nombre
    void mostrarPasajeroPorNombre(string nombreBuscado) {
        cout << "Buscando pasajero con nombre '" << nombreBuscado << "':" << endl;
        bool encontrado = false;

        for (int i = 0; i < cantidad; i++) {
            if (pasajeros[i]->getNombre() == nombreBuscado) {
                cout << "Nombre: " << pasajeros[i]->getNombre()
                    << ", CI: " << pasajeros[i]->getCi()
                    << ", Asiento: " << pasajeros[i]->getNumeroAsiento() << endl;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "No se encontro un pasajero con ese nombre." << endl;
        }
        cout << endl;
    }

    // 4. Mostrar un pasajero dado un CI
    void mostrarPasajeroPorCI(int ciBuscado) {
        cout << "Buscando pasajero con CI " << ciBuscado << ":" << endl;
        bool encontrado = false;

        for (int i = 0; i < cantidad; i++) {
            if (pasajeros[i]->getCi() == ciBuscado) {
                cout << "Nombre: " << pasajeros[i]->getNombre()
                    << ", CI: " << pasajeros[i]->getCi()
                    << ", Asiento: " << pasajeros[i]->getNumeroAsiento() << endl;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "No se encontro un pasajero con ese CI." << endl;
        }
        cout << endl;
    }

    // Mostrar a todos los pasajeros
    void mostrarTodosLosPasajeros() {
        cout << "Todos los pasajeros:" << endl;
        for (int i = 0; i < cantidad; i++) {
            cout << "Nombre: " << pasajeros[i]->getNombre()
                << ", CI: " << pasajeros[i]->getCi()
                << ", Asiento: " << pasajeros[i]->getNumeroAsiento() << endl;
        }
        cout << endl;
    }
};

int main() {
    // Crear un vector de pasajeros para 10 personas
    PasajerosVector listaPasajeros(10);

    // Agregamos pasajeros de ejemplo
    listaPasajeros.agregarPasajero("Juan Perez", 1234567);
    listaPasajeros.agregarPasajero("Maria Gomez", 2345678);
    listaPasajeros.agregarPasajero("Carlos Lopez", 3456789);
    listaPasajeros.agregarPasajero("Ana Martinez", 4567890);
    listaPasajeros.agregarPasajero("Pedro Rodriguez", 5678901);

    // Asignar algunos asientos
    listaPasajeros.asignarAsientoAPasajero(0, 5);  
    listaPasajeros.asignarAsientoAPasajero(1, 8);  
    listaPasajeros.asignarAsientoAPasajero(2, 3);  
    listaPasajeros.asignarAsientoAPasajero(3, 10); 
    // Pedro queda sin asiento (0)

    cout << "=== Demostracion de las funciones ===" << endl << endl;

    // Mostrar todos los pasajeros
    listaPasajeros.mostrarTodosLosPasajeros();

    // 1. Pasajeros sin asiento
    listaPasajeros.mostrarPasajerosSinAsiento();

    // 2. Pasajeros con asiento impar
    listaPasajeros.mostrarPasajerosAsientoImpar();

    // 3. Pasajeros por nombre
    listaPasajeros.mostrarPasajeroPorNombre("Maria Gomez");
    listaPasajeros.mostrarPasajeroPorNombre("Jose Fernandez"); 

    // 4. Pasajeros por CI
    listaPasajeros.mostrarPasajeroPorCI(3456789);
    listaPasajeros.mostrarPasajeroPorCI(9999999); 

    return 0;
}