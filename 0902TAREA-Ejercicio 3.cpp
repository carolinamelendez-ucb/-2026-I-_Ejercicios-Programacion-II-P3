#include <iostream>
#include <string>

using namespace std;

class Pelicula
{
private:
    string titulo;
    string genero;
    int duracion;

public:
    Pelicula(string tituloP,string generoP,int durP) { 
        titulo=tituloP;
        genero=generoP;
        duracion=durP;
    }

    void mostrar()
    {
        cout << "DATOS DE LA PELICULA" << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Genero: " << genero << endl;
        cout << "Duracion (minutos): " << duracion << endl;
        cout << endl;
    }

    void setTitulo(string nTitulo)
    {
        titulo = nTitulo;
    }

    void setGenero(string nGen)
    {
        genero = nGen;
    }

    void setDur(int nDur)
    {
        duracion = nDur;
    }
};


int main()
{
    string T[3];
    string G[3];
    int D[3];

    Pelicula P1 = Pelicula ("","",0);
    Pelicula P2 = Pelicula ("","",0);
    Pelicula P3 = Pelicula ("","",0);


    for (int i = 0; i < 3; i++)
    {
        cout << "PELICULA " << i + 1 << endl;

        cout << "Ingrese el titulo: ";
        getline(cin, T[i]);

        cout << "Ingrese el genero: ";
        getline(cin, G[i]);

        cout << "Ingrese la duracion: ";
        cin >> D[i];
        cin.ignore();
    }

    P1.setTitulo(T[0]);
    P1.setGenero(G[0]);
    P1.setDur(D[0]);

    P2.setTitulo(T[1]);
    P2.setGenero(G[1]);
    P2.setDur(D[1]);

    P3.setTitulo(T[2]);
    P3.setGenero(G[2]);
    P3.setDur(D[2]);

    P1.mostrar();
    P2.mostrar();
    P3.mostrar();

    cout << "Ingrese la nueva duracion de la segunda pelicula: ";
    cin >> D[1];
    P2.setDur(D[1]);

    P1.mostrar();
    P2.mostrar();
    P3.mostrar();
}
