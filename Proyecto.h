#pragma once
#include <iostream>
#include <string>
using namespace std;

class Proyecto
{
protected:
    int codigo;
    string nombre;
public:
    Proyecto(int codigo, string nombre)
    {
        this->codigo = codigo;
        this->nombre = nombre;
    }

    int getCodigo()
    {
        return codigo;
    }

    virtual float calcularCosto() = 0;

    virtual void mostrar()
    {
        cout << "Proyecto: " << nombre << " Codigo: " << codigo << endl;
    }

    virtual ~Proyecto() {}
};

class ProyectoInterno : public Proyecto
{
private:
    float costoBase;

public:
    ProyectoInterno(int codigo, string nombre, float costoBase)
        : Proyecto(codigo, nombre)
    {
        this->costoBase = costoBase;
    }

    float calcularCosto()
    {
        return costoBase;
    }
};

class ProyectoExterno : public Proyecto
{
private:
    float costoBase;
    float impuesto;
public:
    ProyectoExterno(int codigo, string nombre, float costoBase, float impuesto)
        : Proyecto(codigo, nombre)
    {
        this->costoBase = costoBase;
        this->impuesto = impuesto;
    }

    float calcularCosto()
    {
        return costoBase + impuesto;
    }
};