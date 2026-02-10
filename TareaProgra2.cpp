#include <iostream>
using namespace std;

class Pelicula
{
private:
    string titulo;
    string genero;
    int duracion;

public:
    Pelicula(string t, string g, int d)
    {
        titulo = t;
        genero = g;
        duracion = d;
    }

    void setTitulo(string t)
    {
        titulo = t;
    }

    void setGenero(string g)
    {
        genero = g;
    }

    void setDuracion(int d)
    {
        duracion = d;
    }

    void mostrar()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << " minutos" << endl;
        cout << endl;
    }
};

int main()
{
    Pelicula p1("Pelicula 1", "", 0);
    Pelicula p2("Pelicula 2", "", 0);
    Pelicula p3("Pelicula 3", "", 0);

    string genero;
    int duracion;

    cout << "Ingrese genero y duracion de la pelicula 1: ";
    cin >> genero >> duracion;
    p1.setGenero(genero);
    p1.setDuracion(duracion);

    cout << "Ingrese genero y duracion de la pelicula 2: ";
    cin >> genero >> duracion;
    p2.setGenero(genero);
    p2.setDuracion(duracion);

    cout << "Ingrese genero y duracion de la pelicula 3: ";
    cin >> genero >> duracion;
    p3.setGenero(genero);
    p3.setDuracion(duracion);

    cout << endl;
    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    p2.setDuracion(150);

    cout << "Despues de modificar la duracion:" << endl << endl;

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    return 0;
}
