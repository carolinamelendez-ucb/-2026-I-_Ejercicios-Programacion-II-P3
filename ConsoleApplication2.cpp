// ConsoleApplication2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>
using namespace std;

class Empleado {
protected:
    string nombre;
    float salarioBase;
    string departamentos;
public:
    Empleado(const string& nombre, float salarioBase, const string& departamentos)
        : nombre(nombre), departamentos(departamentos)
    {
        this->salarioBase = salarioBase;
    }

    float calcularSalario(float bono) {
        return salarioBase+bono;
    }
};
class EmpleadoPlanta: Empleado {
private:
    float salarioExtra;
public:
    EmpleadoPlanta(string nombre, float salarioBase, string departamentos) :
        Empleado(nombre, salarioBase, departamentos) {
        this->salarioExtra = 0;
    }
    EmpleadoPlanta(string nombre, float salarioBase, string departamentos, float salarioExtra) :
        Empleado(nombre, salarioBase, departamentos) {
        this->salarioExtra = salarioExtra;
    }

};

class Contratista : Empleado {
private:
    int diasTrabajados;
public:
    Contratista(string nombre, float salarioBase, string departamentos, int diasTrabajados) :
        Empleado(nombre, salarioBase, departamentos) {
        this->diasTrabajados = diasTrabajados;
    }
    float calcularSalario(float diasTrabajados) {
        return this->salarioBase * diasTrabajados;
    }
};

class Ejecutivo : Empleado {
private:
    float comision;
public:
    Ejecutivo(string nombre, float salarioBase, string departamentos, float comision) :
        Empleado(nombre, salarioBase, departamentos) {
        this->comision = comision;
    }
};

int main()
{
    EmpleadoPlanta empleadoPlanta1 = EmpleadoPlanta("Juan", 120, "Dep1");
    empleadoPlanta1.calcularSalario();

}

