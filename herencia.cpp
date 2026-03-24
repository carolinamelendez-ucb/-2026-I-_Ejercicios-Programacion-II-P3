#include <iostream>
using namespace std;

class Empleado {
private:
    string nombre;
    float salario_base;
    string departamento;
public:
    Empleado(const string& nombre, float salario_base, const string& departamento)
        : nombre(nombre), salario_base(salario_base), departamento(departamento)
    {
    }

    Empleado() = default;

    float calcularSalario() {
        return salario_base;
    }

    void mostrar() {
        cout << endl << "Nombre:" << nombre << endl;
        cout << "Salario Base: " << salario_base << endl;
        cout << "Departamento:" << departamento << endl;
    }
};

class EmpleadoPlanta: public Empleado {
private:
    float salario_extra;
public:
    EmpleadoPlanta(string nombre, float salario_base, string departamento) :
        Empleado(nombre, salario_base, departamento), salario_extra(0)
    {
    }

    float calcularSalario() {
        return Empleado::calcularSalario() + salario_extra + 1000;
    }

    void mostrar() {
        Empleado::mostrar();
        cout << "Salario Extra: " << salario_extra << endl;
    }
};

class Contratista : public Empleado {
private:
   int diasTrabajados;
public:
    Contratista(string nombre, float salario_base, string departamento, int diasTrabajados) :
        Empleado(nombre, salario_base, departamento), diasTrabajados(diasTrabajados)
    {
    }

    float calcularSalario() {
        return Empleado::calcularSalario()*diasTrabajados;
    }

    void mostrar() {
        Empleado::mostrar();
        cout << "Dias Trabajados: " << diasTrabajados << endl;
    }
};

class Ejecutivo : public Empleado {
private:
    float comision;
public:
    Ejecutivo(string nombre, float salario_base, string departamento, float comision) :
        Empleado(nombre, salario_base, departamento), comision(comision)
    {
    }

    float calcularSalario() {
        return Empleado::calcularSalario() + comision;
    }

    void mostrar() {
        Empleado::mostrar();
        cout << "Comision: " << comision << endl;
    }
};

int main()
{
    Empleado miEmpleado("Juan", 1000, "Humanidades");
    EmpleadoPlanta miEmpleadoPlanta("Pedro", 2000, "Economia");
    Contratista miContratista("Pablo", 2500, "Relaciones",20);
    Ejecutivo miEjecutivo("Jannet", 5000.5, "Administracion",250.6);

    miEmpleado.mostrar();
    cout << "Su salario total es :" << miEmpleado.calcularSalario() << endl;
    miEmpleadoPlanta.mostrar();
    cout << "Su salario total es :" << miEmpleadoPlanta.calcularSalario() << endl;
    miContratista.mostrar();
    cout << "Su salario total es :" << miContratista.calcularSalario() << endl;
    miEjecutivo.mostrar();
    cout << "Su salario total es :" << miEjecutivo.calcularSalario() << endl;
}
