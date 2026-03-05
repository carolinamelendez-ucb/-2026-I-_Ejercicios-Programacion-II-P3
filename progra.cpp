#include <iostream>
#include <string>
using namespace std;

class Socio
{
    int ci;
    string nombre;
    int tel;
public:
    Socio(int ci, string nombre, int tel)
    {
        this->ci = ci;
        this->nombre = nombre;
        this->tel = tel;
    }

    void mostrars()
    {
        cout << "el nombre es " << nombre;
        cout << "el ci es " << ci;
        cout << "el tel es " << tel;

    }
};

class VectorSocios
{
private:
    Socio** socio;
    int i;
    int indice;
public:
    VectorSocios(int i)
    {
        this->socio = new Socio * [i];
        this->i = i;
        this->indice = 0;
    }

    void sumar(Socio* nuevosocio)
    {
        socio[indice] = nuevosocio;
        indice++;
    }

    void mostrarS()
    {
        for (int i = 0; i < indice; i++)
        {
            socio[i]->mostrars();
        }
    }
};

class Equipo
{
private:
    Socio piloto;
    Socio copiloto;
    string nombrequip;
public:
    Equipo(Socio piloto, Socio copiloto, string nombrequip)
    {
        this->piloto = piloto;
        this->copiloto = copiloto;
        this->nombrequip = nombrequip;
    }

    void mostrar()
    {
        cout << "el piloto es " << piloto.mostrars();
        cout << "el copilto es " << copiloto.mostrars();
    }
};

class VectorEquipos
{
private:
    Equipo** equipo;
    int i;
    int indice;
public:
    VectorEquipos(int i)
    {
        this->equipo = new Equipo * [i];
        this->i = i;
        this->indice = 0;
    }

    void sumar(Equipo* nuevoequipo)
    {
        equipo[indice] = nuevoequipo;
        indice++;
    }

    void mostrarS()
    {
        for (int i = 0; i < indice; i++)
        {
            equipo[i]->mostrar();
        }
    }
};




int main()
{
    
}
