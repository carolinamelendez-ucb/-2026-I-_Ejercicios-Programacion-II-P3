#include <iostream>
using namespace std;

class Mascota
{
private:
    string nombre;
    string tipo;
    int edad;

public:
    Mascota(string n, string t, int e)
    {
        nombre = n;
        tipo = t;
        edad = e;
    }

    void setNombre(string n)
    {
        nombre = n;
    }

    void setTipo(string t)
    {
        tipo = t;
    }

    void setEdad(int e)
    {
        edad = e;
    }

    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << endl;
        cout << endl;
    }
};

int main()
{
    Mascota m1("Max", "Perro", 0);
    Mascota m2("Michi", "Gato", 0);
    Mascota m3("Loro", "Ave", 0);

    int edad;

    cout << "Ingrese la edad de la mascota 1: ";
    cin >> edad;
    m1.setEdad(edad);

    cout << "Ingrese la edad de la mascota 2: ";
    cin >> edad;
    m2.setEdad(edad);

    cout << "Ingrese la edad de la mascota 3: ";
    cin >> edad;
    m3.setEdad(edad);

    cout << endl;
    m1.mostrar();
    m2.mostrar();
    m3.mostrar();

    m2.setEdad(5);

    cout << "Despues de cambiar la edad de una mascota:" << endl << endl;

    m1.mostrar();
    m2.mostrar();
    m3.mostrar();

    return 0;
}
