#include <iostream>
#include <string>
using namespace std;

class Pelicula {
private:
    string titulo;
    string genero;
    int duracion;

public:

    Pelicula(string t, string g, int d) {
        titulo = t;
        genero = g;
        duracion = d;
    }

    void setGenero(string g) {
        genero = g;
    }

    void setDuracion(int d) {
        duracion = d;
    }

    void setTitulo(string t) {
        titulo = t;
    }
    void mostrar() {
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion: " << duracion << " minutos" << endl;

    }
};

int main() {
    Pelicula p1("Matrix", "", 0);
    Pelicula p2("Titanic", "", 0);

    string genero;
    int duracion,d;
    cout << "Genero de Matrix: ";
    cin >> genero;
    cout << "Duracion de Matrix: ";
    cin >> duracion;
    p1.setGenero(genero);
    p1.setDuracion(duracion);
    cout << "Genero de Titanic: ";
    cin >> genero;
    cout << "Duracion de Titanic: ";
    cin >> duracion;
    p2.setGenero(genero);
    p2.setDuracion(duracion);
    p1.mostrar();
    p2.mostrar();
    cout << "modifique la duracion de una peli: ";
    cin>>d;
    p1.setDuracion(d);
    p1.mostrar();
    p2.mostrar();
}