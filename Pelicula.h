#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pelicula {
private:
    string titulo;
    string director;
    int duracion; // en minutos
    string genero;

public:
    Pelicula() : titulo(""), director(""), duracion(0), genero("") {}

    Pelicula(string tit, string dir, int dur, string gen)
        : titulo(tit), director(dir), duracion(dur), genero(gen) {
    }

    void registrar() {
        cout << "Titulo: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Director: ";
        getline(cin, director);
        cout << "Duracion (minutos): ";
        cin >> duracion;
        cout << "Genero: ";
        cin.ignore();
        getline(cin, genero);
    }

    void mostrar() const {
        cout << "Pelicula: " << titulo << " | Director: " << director
            << " | Duracion: " << duracion << " min | Genero: " << genero;
    }

    string getTitulo() const { return titulo; }
    string getDirector() const { return director; }
    int getDuracion() const { return duracion; }
    string getGenero() const { return genero; }
};