#include <iostream>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    int salarioBase;
    string departamento;

public:

    Empleado(string n, int salario, string depto)
        : nombre(n), salarioBase(salario), departamento(depto) {
    }

    float calcularSalario() {
        return salarioBase;
    }

    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Salario Base: $" << salarioBase << endl;
        cout << "Salario Total: $" << calcularSalario() << endl;
    }
};

class EmpleadoPlanta : public Empleado {
private:
    float salarioExtra;
    static const int BONO_PLANTA;  // Bono fijo de planta

public:

    EmpleadoPlanta(string n, int salario, string depto, int extra = 0)
        : Empleado(n, salario, depto), salarioExtra(extra) {
    }


    float calcularSalario() {
        return salarioBase + BONO_PLANTA + salarioExtra;
    }

    void mostrarInfo() {
        cout << "\n=== EMPLEADO DE PLANTA ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Salario Base: $" << salarioBase << endl;
        cout << "Bono de Planta: $" << BONO_PLANTA << endl;
        if (salarioExtra > 0) {
            cout << "Salario Extra: $" << salarioExtra << endl;
        }
        cout << "Salario Total: $" << calcularSalario() << endl;
    }
};

const int EmpleadoPlanta::BONO_PLANTA = 1000;

class Contratista : public Empleado {
private:
    int diasTrabajados;
    static const int TARIFA_DIA;

public:
   
    Contratista(string n, int salario, string depto, int dias)
        : Empleado(n, salario, depto), diasTrabajados(dias) {
    }

    float calcularSalario() {
        return TARIFA_DIA * diasTrabajados;
    }

    void mostrarInfo() {
        cout << "\n=== CONTRATISTA ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Dias trabajados: " << diasTrabajados << endl;
        cout << "Tarifa por dia: $" << TARIFA_DIA << endl;
        cout << "Salario Total: $" << calcularSalario() << endl;
    }
};

const int Contratista::TARIFA_DIA = 150;

class Ejecutivo : public Empleado {
private:
    float comision;

public:

    Ejecutivo(string n, int salario, string depto, int com)
        : Empleado(n, salario, depto), comision(com) {
    }

    float calcularSalario() {
        return salarioBase + comision;
    }

    void mostrarInfo() {
        cout << "\n=== EJECUTIVO ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Salario Base: $" << salarioBase << endl;
        cout << "Comision: $" << comision << endl;
        cout << "Salario Total: $" << calcularSalario() << endl;
    }

    void setComision(int nuevaComision) {
        comision = nuevaComision;
    }
};

int main() {
    cout << "=== SISTEMA DE GESTION DE EMPLEADOS ===" << endl;
    cout << "========================================" << endl;

    EmpleadoPlanta empleado1("Ana Martinez", 2500, "Produccion", 500);
    Contratista empleado2("Luis Rodriguez", 0, "Mantenimiento", 20);
    Ejecutivo empleado3("Carlos Sanchez", 4000, "Ventas", 1500);

    empleado1.mostrarInfo();
    empleado2.mostrarInfo();
    empleado3.mostrarInfo();

    cout << "\n========================================" << endl;
    cout << "=== RESUMEN DE SALARIOS ===" << endl;

    cout << "\nSalario de " << empleado1.calcularSalario() << endl;
    cout << "Salario de " << empleado2.calcularSalario() << endl;
    cout << "Salario de " << empleado3.calcularSalario() << endl;

    cout << "\n=== ACTUALIZACION DE COMISION ===" << endl;
    cout << "Comision original del ejecutivo: $1500" << endl;
    empleado3.setComision(2500.0f);
    cout << "Nueva comision asignada: $2500" << endl;
    cout << "Salario actualizado del ejecutivo: $" << empleado3.calcularSalario() << endl;

    return 0;
}