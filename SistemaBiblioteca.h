#pragma once
#include "VectorEstudiantes.h"
#include "VectorLibros.h"
#include "VectorPrestamos.h"

class SistemaBiblioteca {

private:
    VectorEstudiantes* estudiantes;
    VectorLibros* libros;
    VectorPrestamos* prestamos;

public:

    SistemaBiblioteca(int e, int l, int p) {
        estudiantes = new VectorEstudiantes(e);
        libros = new VectorLibros(l);
        prestamos = new VectorPrestamos(p);
    }

    ~SistemaBiblioteca() {
        delete estudiantes;
        delete libros;
        delete prestamos;
    }

    void registrarEstudiante(int ci, string nombre) {
        estudiantes->agregar(new Estudiante(ci, nombre));
    }

    void registrarLibro(int codigo, string titulo) {
        libros->agregar(new Libro(codigo, titulo));
    }

    void prestarLibro(int ci, int codigo) {
        Estudiante* e = estudiantes->buscar(ci);
        Libro* l = libros->buscar(codigo);

        if (e == nullptr || l == nullptr) return;

        if (!l->estaDisponible()) {
            cout << "Libro no disponible" << endl;
            return;
        }

        if (!e->puedePrestar()) {
            cout << "Limite de prestamos alcanzado" << endl;
            return;
        }

        l->prestar();
        e->prestar();
        prestamos->agregar(new Prestamo(ci, codigo));
    }

    void devolverLibro(int ci, int codigo) {
        Prestamo* p = prestamos->buscarActivo(ci, codigo);
        Libro* l = libros->buscar(codigo);
        Estudiante* e = estudiantes->buscar(ci);

        if (p != nullptr && l != nullptr && e != nullptr) {
            p->finalizar();
            l->devolver();
            e->devolver();
        }
    }

    void mostrarTop() {
        estudiantes->mostrarTop();
    }

    void mostrarPrestamos() {
        prestamos->mostrar();
    }
};
