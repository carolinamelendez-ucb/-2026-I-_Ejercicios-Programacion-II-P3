#pragma once
#include <iostream>
#include <string>
#include "Libro.h"
#include "Estudiante.h"
#include "Excepciones.h"

using namespace std;

const int MAX_LIBROS = 100;
const int MAX_ESTUDIANTES = 100;

class Biblioteca {
private:
    string nombre;
    Libro* listaLibros[MAX_LIBROS];
    Estudiante* listaEstudiantes[MAX_ESTUDIANTES];
    int totalLibros;
    int totalEstudiantes;

public:
    Biblioteca(string _nombre) : nombre(_nombre), totalLibros(0), totalEstudiantes(0) {
        for (int i = 0; i < MAX_LIBROS; i++) {
            listaLibros[i] = nullptr;
        }
        for (int i = 0; i < MAX_ESTUDIANTES; i++) {
            listaEstudiantes[i] = nullptr;
        }
    }

    ~Biblioteca() {
        for (int i = 0; i < totalLibros; i++) {
            delete listaLibros[i];
        }
        for (int i = 0; i < totalEstudiantes; i++) {
            delete listaEstudiantes[i];
        }
    }

    void agregarLibro(string codigo, string titulo, string autor) {
        if (totalLibros < MAX_LIBROS) {
            Libro* nuevoLibro = new Libro(codigo, titulo, autor);
            listaLibros[totalLibros] = nuevoLibro;
            totalLibros++;
        }
        else {
            cout << "No se pueden agregar más libros. Límite alcanzado." << endl;
        }
    }

    void agregarEstudiante(string ci, string nombre) {
        if (totalEstudiantes < MAX_ESTUDIANTES) {
            Estudiante* nuevoEstudiante = new Estudiante(ci, nombre);
            listaEstudiantes[totalEstudiantes] = nuevoEstudiante;
            totalEstudiantes++;
        }
        else {
            cout << "No se pueden agregar mas estudiantes. Limite alcanzado." << endl;
        }
    }

    Libro* buscarLibroPorCodigo(string codigo) {
        for (int i = 0; i < totalLibros; i++) {
            if (listaLibros[i]->getCodigo() == codigo) {
                return listaLibros[i];
            }
        }
        return nullptr;
    }

    Estudiante* buscarEstudiantePorCI(string ci) {
        for (int i = 0; i < totalEstudiantes; i++) {
            if (listaEstudiantes[i]->getCi() == ci) {
                return listaEstudiantes[i];
            }
        }
        return nullptr;
    }

    void registrarPrestamo(string ciEstudiante, string codigoLibro) {
        Estudiante* estudiante = buscarEstudiantePorCI(ciEstudiante);
        if (estudiante == nullptr) {
            throw EstudianteNoEncontradoException();
        }

        Libro* libro = buscarLibroPorCodigo(codigoLibro);
        if (libro == nullptr) {
            throw LibroNoEncontradoException();
        }

        if (estudiante->tieneLibroPrestado()) {
            throw EstudianteYaTieneLibroException();
        }

        if (libro->estaPrestado()) {
            throw LibroYaPrestadoException();
        }

        if (libro->estaEnReparacion()) {
            throw LibroEnReparacionException();
        }

        libro->prestar();
        estudiante->asignarLibro(libro);

        cout << "Prestamo exitoso: " << estudiante->getNombre()
            << " ha tomado prestado '" << libro->getTitulo() << "'" << endl;
    }

    void listarEstudiantesConLibros() {
        cout << "\n=== LISTA DE ESTUDIANTES CON LIBROS PRESTADOS ===" << endl;

        if (totalEstudiantes == 0) {
            cout << "No hay estudiantes registrados." << endl;
            return;
        }

        bool hayPrestamos = false;

        for (int i = 0; i < totalEstudiantes; i++) {
            Estudiante* estudiante = listaEstudiantes[i];
            cout << "Estudiante: " << estudiante->getNombre()
                << " (CI: " << estudiante->getCi() << ")" << endl;

            if (estudiante->tieneLibroPrestado()) {
                cout << "Libro prestado: " << estudiante->getLibroAsignado()->getTitulo() << endl;
                hayPrestamos = true;
            }
            else {
                cout << "Libro prestado: Ninguno" << endl;
            }
        }

        if (!hayPrestamos) {
            cout << "\nNo hay prestamos activos en este momento." << endl;
        }
    }

    void mostrarLibroMasSolicitado() {
        cout << "\n=== LIBRO MAS SOLICITADO ===" << endl;

        if (totalLibros == 0) {
            cout << "No hay libros en la biblioteca." << endl;
            return;
        }

        Libro* libroMasSolicitado = nullptr;
        int maxVecesPrestado = -1;

        for (int i = 0; i < totalLibros; i++) {
            if (listaLibros[i]->getVecesPrestado() > maxVecesPrestado) {
                maxVecesPrestado = listaLibros[i]->getVecesPrestado();
                libroMasSolicitado = listaLibros[i];
            }
        }

        if (libroMasSolicitado != nullptr && maxVecesPrestado > 0) {
            cout << "Título: " << libroMasSolicitado->getTitulo() << endl;
            cout << "Autor: " << libroMasSolicitado->getAutor() << endl;
            cout << "Código: " << libroMasSolicitado->getCodigo() << endl;
            cout << "Veces prestado: " << libroMasSolicitado->getVecesPrestado() << endl;
        }
        else {
            cout << "No hay prestamos registrados aun." << endl;
        }
    }

    void mostrarCatalogo() {
        cout << "\n=== CATALOGO DE LIBROS ===" << endl;
        for (int i = 0; i < totalLibros; i++) {
            cout << "Codigo: " << listaLibros[i]->getCodigo()
                << " Titulo: " << listaLibros[i]->getTitulo()
                << " Autor: " << listaLibros[i]->getAutor()
                << " Estado: " << listaLibros[i]->getEstado()
                << " Veces prestado: " << listaLibros[i]->getVecesPrestado() << endl;
        }
    }

    void devolverLibro(string ciEstudiante) {
        Estudiante* estudiante = buscarEstudiantePorCI(ciEstudiante);
        if (estudiante != nullptr && estudiante->tieneLibroPrestado()) {
            Libro* libro = estudiante->getLibroAsignado();
            libro->devolver();
            estudiante->devolverLibro();
            cout << "Libro devuelto exitosamente por " << estudiante->getNombre() << endl;
        }
        else {
            cout << "El estudiante no tiene ningun libro prestado." << endl;
        }
    }

    int getTotalLibros() { 
        return totalLibros; 
    }

    int getTotalEstudiantes() { 
        return totalEstudiantes; 
    }
};
