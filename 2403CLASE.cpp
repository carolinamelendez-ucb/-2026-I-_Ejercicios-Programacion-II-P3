#include <iostream>
#include <string>

using namespace std;

class Empleado {
protected:
    string nombre;
    float salarioBase;
    string departamento;
public:
    Empleado(const string& nombre, float salarioBase, const string& departamento)
        : nombre(nombre), salarioBase(salarioBase), departamento(departamento)
    {
    }

    int calcularSalario() {
        return salarioBase / 30;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario Base Mensual: " << salarioBase << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Salario total: " << calcularSalario() << endl;
    }
};

class EmpleadoPlanta : public Empleado {
private:
    float salarioExtra;
public:
    EmpleadoPlanta(string nombre, float salarioBase, float salarioExtra) :
        Empleado(nombre, salarioBase, "Planta")
    {
        this->salarioExtra = salarioExtra;
    }

    int calcularSalario() {
        return (salarioBase / 30) + 1000;
    }

    void mostrar() {
        Empleado::mostrar();
        cout << "Salario total: " << calcularSalario() << endl;
    }
};

class Contratista : public Empleado {
private:
    int diasTrabajados;
public:
    Contratista(string nombre, float salarioBase, int diasTrabajados) :
        Empleado(nombre, salarioBase, "Constratista")
    {
        this->diasTrabajados = diasTrabajados;
    }

    int calcularSalario() {
        return salarioBase * diasTrabajados;
    }

    void mostrar() {
        Empleado::mostrar();
        cout << "Salario total: " << calcularSalario() << endl;
    }
};

class Ejecutivo : public Empleado {
private:
    float comision;
public:
    Ejecutivo(string nombre, float salarioBase, float comision) :
        Empleado(nombre, salarioBase, "Ejecutivo")
    {
        this->comision = comision;
    }

    int calcularSalario() {
        return (salarioBase / 30) + comision;
    }

    void mostrar() {
        Empleado::mostrar();
        cout << "Salario total: " << calcularSalario() << endl;
    }
};

int main()
{
    Empleado empleado1 = Empleado("Alejandro", 3000, "Internacional");
    empleado1.mostrar();
    cout << endl;

    EmpleadoPlanta planta1 = EmpleadoPlanta("Santiago", 6000, 1000);
    planta1.mostrar();
    cout << endl;

    Contratista contratista1 = Contratista("Edy", 300, 30);
    contratista1.mostrar();
    cout << endl;

    Ejecutivo ejecutivo1 = Ejecutivo("Lenny", 3000, 1500);
    ejecutivo1.mostrar();
    cout << endl;
}

