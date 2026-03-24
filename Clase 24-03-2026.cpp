#include <iostream>
using namespace std;
class Empleado {
public:
    string nombre;
    float salario_base;
    string departamento;

    Empleado(string n, float s, string d) {
        nombre = n;
        salario_base = s;
        departamento = d;
    }

    float calcular_salario() {
        return salario_base;
    }
};
class EmpleadoPlanta : public Empleado {
public:
    float salario_extra;

    EmpleadoPlanta(string n, float s, string d, float extra)
        : Empleado(n, s, d) {
        salario_extra = extra;
    }

    float calcular_salario() {
        return salario_base + 1000 + salario_extra;
    }
};
class Contratista : public Empleado {
public:
    int dias_trabajados;
    float pago_por_dia;

    Contratista(string n, float pago_dia, string d, int dias)
        : Empleado(n, 0, d) {
        pago_por_dia = pago_dia;
        dias_trabajados = dias;
    }

    float calcular_salario() {
        return dias_trabajados * pago_por_dia;
    }
};
class Ejecutivo : public Empleado {
public:
    float comision;

    Ejecutivo(string n, float s, string d, float c)
        : Empleado(n, s, d) {
        comision = c;
    }

    float calcular_salario() {
        return salario_base + comision;
    }
};

int main() {
    EmpleadoPlanta e1("Juan", 3000, "RRHH", 200);
    Contratista e2("Ana", 100, "IT", 20);
    Ejecutivo e3("Carlos", 5000, "Ventas", 1500);

    cout << "Empleado Planta: " << e1.calcular_salario() << endl;
    cout << "Contratista: " << e2.calcular_salario() << endl;
    cout << "Ejecutivo: " << e3.calcular_salario() << endl;
}