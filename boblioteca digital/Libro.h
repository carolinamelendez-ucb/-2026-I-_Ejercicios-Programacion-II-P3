#pragma once
#include <iostream>
#include <string>

using namespace std;

class Libro {
private:
    string codigo;
    string titulo;
    string autor;
    string estado;
    int vecesPrestado;

public:
    Libro() : codigo(""), titulo(""), autor(""), estado("Disponible"), vecesPrestado(0) {
    }

    Libro(string _codigo, string _titulo, string _autor)
        : codigo(_codigo), titulo(_titulo), autor(_autor),
        estado("Disponible"), vecesPrestado(0) {
    }

    string getCodigo() const { 
        return codigo; 
    }

    string getTitulo() const { 
        return titulo; 
    }

    string getAutor() const { 
        return autor; 
    }

    string getEstado() const { 
        return estado; 
    }

    int getVecesPrestado() const { 
        return vecesPrestado; 
    }

    void setEstado(string nuevoEstado) { 
        estado = nuevoEstado; 
    }

    void incrementarVecesPrestado() { 
        vecesPrestado++; 
    }

    bool estaDisponible() const { 
        return estado == "Disponible"; 
    }

    bool estaPrestado() const { 
        return estado == "Prestado"; 
    }

    bool estaEnReparacion() const { 
        return estado == "En reparacion"; 
    }

    void prestar() {
        if (estaDisponible()) {
            estado = "Prestado";
            vecesPrestado++;
        }
    }

    void devolver() {
        if (estaPrestado()) {
            estado = "Disponible";
        }
    }
};