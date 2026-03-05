#include <iostream>
#include <string>

using namespace std;

class Socio
{
private:
    int ci;
    string nombre;
    int NumTelefono;

public:
    Socio(int _ci, string _nombre, int _numTelefono)
    {
        this->ci = _ci;
        this->nombre = _nombre;
        this->NumTelefono = _numTelefono;
    }

    void mostrarSocio()
    {
        cout << "Nombre del Socio : " << nombre << endl;
        cout << "Telefono del Socio : " << NumTelefono << endl;
        cout << "Ci del Socio : " << ci << endl;
    }
};

class SocioVector
{
private:
    Socio** socios;
    int tamanio;
    int indice;

public:
    SocioVector(int _tamanio)
    {
        this->socios = new Socio*[tamanio];
        this->tamanio = _tamanio;
        this->indice = 0;
    }

    void agregar(Socio* nuevoSocio)
    {
        if (indice < tamanio) {
            socios[indice] = nuevoSocio;
            indice++;
        }
    }

    void mostrar()
    {
        for (int i = 0; i < indice; i++)
        {
            socios[i]->mostrarSocio();
        }
    }
};

class Equipo
{
private:
    string copiloto;
    string piloto;
    string nombreEquipo;
    string nombreAuto;
    // los socios que componen el equipo
    SocioVector socios;

public:
    // se pide la capacidad máxima de socios al construir el equipo
    Equipo(string _copiloto, string _piloto, string _nombreEquipo,
           string _nombreAuto, int capacidadSocios)
        : socios(capacidadSocios)
    {
        this->copiloto = _copiloto;
        this->piloto = _piloto;
        this->nombreAuto = _nombreAuto;
        this->nombreEquipo = _nombreEquipo;
    }

    void mostrarEquip()
    {
        cout << " Nombre Piloto  : " << piloto << endl;
        cout << " Nombre Copiloto: " << copiloto << endl;
        cout << " Nombre Auto    : " << nombreAuto << endl;
        cout << " Nombre Equipo  : " << nombreEquipo << endl;
    }

    void agregarSocio(Socio* s)
    {
        socios.agregar(s);
    }

    void mostrarSocios()
    {
        cout << "-- Socios del equipo " << nombreEquipo << " --" << endl;
        socios.mostrar();
    }
};

int main()
{
    // vector principal de socios
    SocioVector socios(10);

    Socio* Juan = new Socio(4321, "Juan", 22222);
    Socio* Fer = new Socio(5678, "Fer", 33333);
    Socio* Luis = new Socio(8765, "Luis", 44444);
    socios.agregar(new Socio(1234, "Marco", 11111));
    
    socios.agregar(Fer);
    socios.agregar(Luis);
    socios.agregar(Fer);
    socios.agregar(Juan);

    cout << "Lista completa de socios:";
    socios.mostrar();

    cout << "Trabajando con equipos ";

    // crear un equipo con capacidad para 5 socios
    Equipo equipo1("Mariana", "Carlos", "Rayo1", "Ford", 5);

    // agregar algunos socios al equipo
    equipo1.agregarSocio(Juan);
    equipo1.agregarSocio(Fer);

    // crear y agregar un socio nuevo
    Socio* Ana = new Socio(9999, "Ana", 55555);
    equipo1.agregarSocio(Ana);

    // mostrar datos del equipo y sus miembros
    equipo1.mostrarEquip();
    equipo1.mostrarSocios();

    return 0;
}