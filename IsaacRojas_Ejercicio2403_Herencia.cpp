#include <iostream>
#include <string>
using namespace std;
class Empleado {
protected:
    string nombre;
    float salario_base;
    string departamento;
public:
    Empleado(const string& nombre, float salario_base, const string& departamento)
        : nombre(nombre), salario_base(salario_base), departamento(departamento)
    {
    }
    float calcular_salario() {
        return salario_base;
    }
    void mostrarEmpleado() {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario_base << endl;
        cout << "Departamento: " << departamento << endl;
    }
};

class EmpleadoPlanta : public Empleado {
private:
    float salario_extra;
public:
    EmpleadoPlanta(const string& nombre, float salario_base, const string& departamento, float salario_extra = 0.0)
        : Empleado(nombre, salario_base, departamento), salario_extra(salario_extra) {
    }
    float calcular_salario() {
        return salario_base + 1000 + salario_extra;
    }
    void mostrarEmpleadoPlanta() {
    Empleado: mostrarEmpleado();
        cout << "Salario extra: " << endl;
    }
};
class Contratista : public Empleado {
private:
    int dias_trabajados;
};
class Ejecutivo : public Empleado {
private:
    float comision;
};
int main()
{
    
}
