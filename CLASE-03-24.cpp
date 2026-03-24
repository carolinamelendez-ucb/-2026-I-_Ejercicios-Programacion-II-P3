#include <iostream>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    int salarioBase;
    string departamento;
public:
    Empleado(const string& nombre, int salarioBase, const string& departamento)
        : nombre(nombre), salarioBase(salarioBase), departamento(departamento)
    {
    }
    int calcularSalario() {
        return salarioBase;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario Base: " << salarioBase << endl;
        cout << "Departamento: " << departamento << endl;
    }
};

class EmpleadoPlanta : public Empleado {
public:
    EmpleadoPlanta(string nombre, int salarioBase, string departamento) :
        Empleado(nombre, salarioBase, departamento){ }
    int calcularSalario() {
        return salarioBase + 1000;
    }
};

class Contratista : public Empleado {
private:
    int diasTrabajados;
public:
    Contratista(string nombre, int salarioBase, string departamento, int diasTrabajados) :
        Empleado(nombre, salarioBase, departamento) {
            this->diasTrabajados = diasTrabajados;
        }
    int calcularSalario() {
        return salarioBase * diasTrabajados;
    }
    void mostrar() {
        Empleado::mostrar();
        cout << "Dias Trabajados: " << diasTrabajados << endl;
    }
};

class Ejecutivo : public Empleado {
private:
    int comision;
public:
    Ejecutivo(string nombre, int salarioBase, string departamento, int comision) :
        Empleado(nombre, salarioBase, departamento) {
        this->comision = comision;
        }
    int calcularSalario() {
        return salarioBase + comision;
    }
    void mostrar() {
        Empleado::mostrar();
        cout << "Comision: " << comision << endl;
    }
};


int main()
{
    EmpleadoPlanta ep1("Juan", 2000, "Sistemas");
    Contratista c1("Ana", 100, "Marketing", 20);
    Ejecutivo e1("Luis", 3000, "Gerencia", 500);
    cout << "=== EMPLEADO PLANTA ===" << endl;
    ep1.mostrar();
    cout << "Salario: " << ep1.calcularSalario() << endl;
    cout << endl;
    cout << "=== CONTRATISTA ===" << endl;
    c1.mostrar();
    cout << "Salario: " << c1.calcularSalario() << endl;
    cout << endl;
    cout << "=== EJECUTIVO ===" << endl;
    e1.mostrar();
    cout << "Salario: " << e1.calcularSalario() << endl;
}
