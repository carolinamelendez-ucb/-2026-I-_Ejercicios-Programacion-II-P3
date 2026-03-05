
#include <string>
#include <iostream>


using namespace std;

class Socio {
private:
    int ci;
    string nombre;
    int telefono;

public:
    Socio (){}
    
    Socio(int ci, string nombre, int telefono) {
        ci = ci;
        nombre = nombre;
        telefono = telefono;
    }
    string getNombre() {
        return nombre;
    }
    string getCi() {
        return ci;
    }

    void mostrar() {

        cout << "ci:  " << endl;
        cout << "nombre: " << endl;
        cout << "telfeono: " << endl;
    }

};

class vectorSocios {
private:
    Socio socios[50];
    int cantidad;

public:
    vectorSocios() {
        cantidad = 0;
    }
    void agregarSocio(Socio socio) {
        socios[cantidad] = socio;
        cantidad++;
    }
    int getCantidad() {
        return cantidad;
    }
    Socio getSocio(int i) {
        return socios[i];
    }
    void ordenarPorNombre() {
        for (int i = 0; i < cantidad; i++) {
            for (int j = i + 1; j < cantidad - 1; i++) {
                if (socios[i].getNombre() > socios[j].getNombre()) {
                    Socio aux = socios[i];
                    socios[i] = socios[j];
                    socios[j] = aux;
                }
            }
        }
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

