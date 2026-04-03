#pragma once
#include <iostream>
#include <string>
using namespace std;

class Empleado
{
protected:
    string nombre;
    int ci;
public:
    Empleado(string nombre, int ci)
    {
        this->nombre = nombre;
        this->ci = ci;
    }

    int getCi()
    {
        return ci;
    }

    virtual float calcularSalario() = 0;
    virtual void mostrarInformacion() = 0;

    virtual ~Empleado() {}
};

class EmpleadoTiempoCompleto : public Empleado
{
private:
    float salarioMensual;

public:
    EmpleadoTiempoCompleto(string nombre, int ci, float salarioMensual)
        : Empleado(nombre, ci)
    {
        this->salarioMensual = salarioMensual;
    }

    float calcularSalario()
    {
        return salarioMensual;
    }

    void mostrarInformacion()
    {
        cout << "Empleado : " << nombre << " CI: " << ci
            << " Salario: " << calcularSalario() << endl;
    }
};

class EmpleadoPorHoras : public Empleado
{
private:
    int horas;
    float pagoPorHora;

public:
    EmpleadoPorHoras(string nombre, int ci, int horas, float pagoPorHora)
        : Empleado(nombre, ci)
    {
        this->horas = horas;
        this->pagoPorHora = pagoPorHora;
    }

    float calcularSalario()
    {
        return horas * pagoPorHora;
    }

    void mostrarInformacion()
    {
        cout << "Empleado : " << nombre << " CI: " << ci << " Salario: " << calcularSalario() << endl;
    }
};