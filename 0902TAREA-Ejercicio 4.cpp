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
    Mascota(string nombreM,string tipoM,int edadM) { 
        nombre=nombreM;
        tipo=tipoM;
        edad=edadM;
    }

    void mostrar()
    {
        cout << "DATOS DE LA MASCOTA" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Edad: " << edad << endl;
        cout << endl;
    }

    void setNombre(string nNombre)
    {
        nombre = nNombre;
    }

    void setTipo(string nTipo)
    {
        tipo = nTipo;
    }

    void setEdad(int nEdad)
    {
        edad = nEdad;
    }
};


int main()
{
    string N[3];
    string T[3];
    int E[3];

    Mascota M1 = Mascota ("","",0);
    Mascota M2 = Mascota ("","",0);
    Mascota M3 = Mascota ("","",0);


    for (int i = 0; i < 3; i++)
    {
        cout << "MASCOTA " << i + 1 << endl;

        cout << "Ingrese el nombre: ";
        getline(cin, N[i]);

        cout << "Ingrese el tipo: ";
        getline(cin, T[i]);

        cout << "Ingrese la edad: ";
        cin >> E[i];
        cin.ignore();
    }

    M1.setNombre(N[0]);
    M1.setTipo(T[0]);
    M1.setEdad(E[0]);
    M2.setNombre(N[1]);
    M2.setTipo(T[1]);
    M2.setEdad(E[1]);
    M3.setNombre(N[2]);
    M3.setTipo(T[2]);
    M3.setEdad(E[2]);

    M1.mostrar();
    M2.mostrar();
    M3.mostrar();

    cout << "Ingrese la nueva edad de la primera mascota: ";
    cin >> E[1];
    M1.setEdad(E[1]);

    M1.mostrar();
    M2.mostrar();
    M3.mostrar();
}