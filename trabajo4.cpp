#include <iostream>
#include <string>
using namespace std;

class Mascota {
private:
    string nombre;
    string tipo;
    int edad;

public:
    Mascota(string n, string t, int e) {
        nombre = n;
        tipo = t;
        edad = e;
    }
    void setEdad(int e) {
        edad = e;
    }

    void setNombre(string n) {
        nombre = n;
    }

    void setTipo(string t) {
        tipo = t;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << endl;
    }
};

int main() {
    int edad;
    Mascota m1("toni", "Perro", 0);
    Mascota m2("gaturro", "Gato", 0);
    cout << "Edad de toni: ";
    cin >> edad;
    m1.setEdad(edad);
    cout << "Edad de gaturro: ";
    cin >> edad;
    m2.setEdad(edad);
    m1.mostrar();
    m2.mostrar();
    cout<<"cambie la edad del perrito: ";
    cin>>edad;
    m1.setEdad(edad);
    m1.mostrar();
    m2.mostrar();
}
