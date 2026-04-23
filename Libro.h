#pragma once
#include <string>
#include <iostream>
#include <exception>
using namespace std;

class Libro
{
private:
    string codigo;
    string titulo;
    string autor;
    string estado;
    int vecesPrestado;

public:

    Libro()
    {
      
    }

    Libro(string c, string t, string a)
    {
        codigo = c;
        titulo = t;
        autor = a;
        estado = "Disponible";
        vecesPrestado = 0;
    }

    string getCodigo() { return codigo; }
    string getTitulo() { return titulo; }
    string getEstado() { return estado; }
    int getVecesPrestado() { return vecesPrestado; }

    void setEstado(string e)
    {
        estado = e;
    }

    void aumentarPrestamo()
    {
        vecesPrestado++;
    }
};



