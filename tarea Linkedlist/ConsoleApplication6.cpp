#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

// Clase Auto para el punto 4
class Auto {
private:
    string marca;
    string modelo;
public:
    Auto(string m = "", string mod = "") : marca(m), modelo(mod) {}

    // Permite imprimir un Auto con cout
    friend ostream& operator<<(ostream& os, const Auto& a) {
        os << a.marca << " " << a.modelo;
        return os;
    }
};

int main() {
    // 1) Prueba con strings
    LinkedList<string> listaNombres;
    listaNombres.agregar("Marco");
    listaNombres.agregar("Isabel");
    listaNombres.agregar("Nelly");
    cout << "=== Lista de nombres ===" << endl;
    listaNombres.mostrar();

    // 4) Prueba con objetos Auto
    LinkedList<Auto> listaAutos;
    listaAutos.agregar(Auto("Toyota", "Corolla"));
    listaAutos.agregar(Auto("Honda", "Civic"));
    listaAutos.agregar(Auto("Ford", "Mustang"));
    cout << "\n=== Lista de autos ===" << endl;
    listaAutos.mostrar();

    return 0;
}
