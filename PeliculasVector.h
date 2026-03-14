#pragma once
#include "Pelicula.h"

class PeliculasVector {

private:
    Pelicula** peliculas;
    int indice;
    int tamanio;

public:

    PeliculasVector(int tamanio)
        : tamanio(tamanio), indice(0)
    {
        peliculas = new Pelicula * [tamanio];
    }

    ~PeliculasVector() {
        for (int i = 0; i < indice; i++) {
            delete peliculas[i];
        }
        delete[] peliculas;
    }

    void agregar(Pelicula* pelicula) {
        if (indice < tamanio) {
            peliculas[indice] = pelicula;
            indice++;
        }
    }

    Pelicula* getPelicula(int pos) {
        return peliculas[pos];
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            peliculas[i]->mostrar();
            cout << endl;
        }
    }
};
