#include <iostream>
#include <string>

using namespace std;

class Mascota
{
private:
    string nombre;
    string tipo;
    int edad;
public:
    Mascota(string nombre, string tipo, int edad) {
        this->nombre = nombre;
        this->tipo = tipo;
        this->edad = edad;
    }

    void setNombre(string nuevoNombre) {
        this->nombre = nuevoNombre;
    }

    void setTipo(string nuevoTipo) {
        this->tipo = nuevoTipo;
    }

    void setEdad(int nuevaEdad) {
        this->edad = nuevaEdad;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << " anos" << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    Mascota mascota1("Copito", "Perro", 3);
    Mascota mascota2("Cleo", "Gato", 2);
    Mascota mascota3("Loro", "Pajaro", 1);

    int nuevaEdad;

    cout << " ACTUALIZAR EDADES DE MASCOTAS " << endl;

    cout << "Mascota: " << "Copito (Perro)" << endl;
    cout << "Ingrese nueva edad: ";
    cin >> nuevaEdad;

    mascota1.setEdad(nuevaEdad);
    cout << endl;

    cout << "Mascota: " << "Cleo (Gato)" << endl;
    cout << "Ingrese nueva edad: ";
    cin >> nuevaEdad;

    mascota2.setEdad(nuevaEdad);
    cout << endl;

    cout << "Mascota: " << "Loro (Pajaro)" << endl;
    cout << "Ingrese nueva edad: ";
    cin >> nuevaEdad;

    mascota3.setEdad(nuevaEdad);
    cout << endl;

    cout << " LISTA DE MASCOTAS " << endl;
    mascota1.mostrar();
    mascota2.mostrar();
    mascota3.mostrar();

    cout << "Cambiar edad de Cleo:" << endl;
    cout << "Ingrese nueva edad: ";
    cin >> nuevaEdad;
    mascota2.setEdad(nuevaEdad);
    cout << "Edad actualizada!" << endl << endl;

    cout << " MASCOTAS ACTUALIZADAS " << endl;
    cout << endl;
    mascota1.mostrar();
    mascota2.mostrar();
    mascota3.mostrar();

    return 0;
}