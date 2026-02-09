#include <iostream>
#include <string>

using namespace std;

class Pelicula
{
private:
    string titulo;
    string genero;
    int duracion; // en minutos
public:

    Pelicula(string titulo, string genero, int duracion) {
        this->titulo = titulo;
        this->genero = genero;
        this->duracion = duracion;
    }

    void setTitulo(string nuevoTitulo) {
        this->titulo = nuevoTitulo;
    }

    void setGenero(string nuevoGenero) {
        this->genero = nuevoGenero;
    }

    void setDuracion(int nuevaDuracion) {
        this->duracion = nuevaDuracion;
    }

    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << " minutos" << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    Pelicula pelicula1("The Flash", "Ciencia Ficcion", 148);
    Pelicula pelicula2("Avengers End Game", "Ciencia Ficcion", 142);
    Pelicula pelicula3("Batman", "Accion", 152);

    string nuevoGenero;
    int nuevaDuracion;

    cout << " INFORMACION DE  PELICULAS " << endl;

    cout << "Pelicula: " << "The Flash" << endl;
    cout << "Ingrese genero: ";
    getline(cin >> ws, nuevoGenero);
    cout << "Ingrese duracion (minutos): ";
    cin >> nuevaDuracion;

    pelicula1.setGenero(nuevoGenero);
    pelicula1.setDuracion(nuevaDuracion);
    cout << endl;

    cout << "Pelicula: " << "Avengers Endgame" << endl;
    cout << "Ingrese genero: ";
    getline(cin >> ws, nuevoGenero);
    cout << "Ingrese duracion (minutos): ";
    cin >> nuevaDuracion;

    pelicula2.setGenero(nuevoGenero);
    pelicula2.setDuracion(nuevaDuracion);
    cout << endl;

    cout << "Pelicula: " << "Batman" << endl;
    cout << "Ingrese genero: ";
    getline(cin >> ws, nuevoGenero);
    cout << "Ingrese duracion (minutos): ";
    cin >> nuevaDuracion;

    pelicula3.setGenero(nuevoGenero);
    pelicula3.setDuracion(nuevaDuracion);
    cout << endl;

    cout << " LISTA DE PELICULAS " << endl;
    pelicula1.mostrar();
    pelicula2.mostrar();
    pelicula3.mostrar();

    cout << "Modificar duraciOn de The Flash:" << endl;
    cout << "Ingrese nueva duracion: ";
    cin >> nuevaDuracion;
    pelicula1.setDuracion(nuevaDuracion);
    cout << "¡Duracion actualizada!" << endl << endl;

    cout << " PELICULAS ACTUALIZADAS " << endl;
    pelicula1.mostrar();
    pelicula2.mostrar();
    pelicula3.mostrar();

    return 0;
}