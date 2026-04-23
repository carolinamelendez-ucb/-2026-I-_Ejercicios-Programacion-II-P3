#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Libro.h"
#include "Estudiantes.h"
#include "ErrorBiblioteca.h"
using namespace std;
class Biblioteca
{
private:

    string nombre;

    Libro listaLibro[100];
    Estudiante listaEstudiante[100];

public:

    int nLibros;
    int nEstudiantes;


    Biblioteca(string n)
    {
        nombre = n;
        nLibros = 0;
        nEstudiantes = 0;
    }


    void agregarLibro(Libro l)
    {
        listaLibro[nLibros] = l;
        nLibros++;
    }


    void agregarEstudiante(Estudiante e)
    {
        listaEstudiante[nEstudiantes] = e;
        nEstudiantes++;
    }


    Libro* buscarLibro(string codigo)
    {
        for (int i = 0; i < nLibros; i++)
        {
            if (listaLibro[i].getCodigo() == codigo)
                return &listaLibro[i];
        }

        return NULL;
    }


    Estudiante* buscarEstudiante(string ci)
    {
        for (int i = 0; i < nEstudiantes; i++)
        {
            if (listaEstudiante[i].getCI() == ci)
                return &listaEstudiante[i];
        }

        return NULL;
    }


    void prestarLibro(string ci, string codigo)
    {
        Libro* libro = buscarLibro(codigo);

        if (libro == NULL)
            throw ErrorBiblioteca("No existe el libro");


        Estudiante* estudiante = buscarEstudiante(ci);

        if (estudiante == NULL)
            throw ErrorBiblioteca("No existe el estudiante");


        if (libro->getEstado() == "Prestado")
            throw ErrorBiblioteca("El libro ya esta prestado");


        if (libro->getEstado() == "En reparación")
            throw ErrorBiblioteca("El libro esta en reparacion");


        if (estudiante->getLibroAsignado() != "")
            throw ErrorBiblioteca("El estudiante ya tiene un libro");


        libro->setEstado("Prestado");

        libro->aumentarPrestamo();

        estudiante->setLibroAsignado(codigo);
    }


    void listarPrestamos()
    {
        for (int i = 0; i < nEstudiantes; i++)
        {
            if (listaEstudiante[i].getLibroAsignado() != "")
            {
                Libro* libro =
                    buscarLibro(listaEstudiante[i].getLibroAsignado());

                cout << listaEstudiante[i].getNombre()
                    << " tiene el libro "
                    << libro->getTitulo() << endl;
            }
        }
    }


    void libroMasSolicitado()
    {
        if (nLibros == 0)
            throw ErrorBiblioteca("No hay libros registrados");

        int mayor = 0;

        for (int i = 1; i < nLibros; i++)
        {
            if (listaLibro[i].getVecesPrestado() >
                listaLibro[mayor].getVecesPrestado())
                mayor = i;
        }

        cout << "Libro mas solicitado: "
            << listaLibro[mayor].getTitulo() << endl;
    }

};

