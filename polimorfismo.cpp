// polimorfismo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;


class Empleado {
protected:
    string ci;
    string nombre;

public:
    Empleado(string ci, string nombre) : ci(ci), nombre(nombre) {}

    string getCI() {
        return ci;
    }

    virtual double calcularSalario() = 0;
    virtual void mostrarInformacion() = 0;

    virtual ~Empleado() {}
};


class EmpleadoTiempoCompleto : public Empleado {
private:
    double salarioMensual;
    double bono;

public:
    EmpleadoTiempoCompleto(string ci, string nombre, double salario, double bono)
        : Empleado(ci, nombre), salarioMensual(salario), bono(bono) {
    }

    double calcularSalario() override {
        return salarioMensual + bono;
    }

    void mostrarInformacion() override {
        cout << "Empleado Tiempo Completo "<<endl;
        cout << "CI: " << ci << " Nombre: " << nombre << endl;
        cout << "Salario: " << calcularSalario() << endl;
    }
};


class EmpleadoPorHoras : public Empleado {
private:
    int horas;
    double pagoHora;

public:
    EmpleadoPorHoras(string ci, string nombre, int horas, double pago)
        : Empleado(ci, nombre), horas(horas), pagoHora(pago) {
    }

    double calcularSalario() override {
        return horas * pagoHora;
    }

    void mostrarInformacion() override {
        cout << "Empleado Por Horas "<<endl;
        cout << "CI: " << ci << "  Nombre: " << nombre << endl;
        cout << "Salario: " << calcularSalario() << endl;
    }
};


class Proyecto {
protected:
    string codigo;
    string nombre;

public:
    Proyecto(string codigo, string nombre) : codigo(codigo), nombre(nombre) {}

    string getCodigo() {
        return codigo;
    }

    virtual double calcularCosto() = 0;
    virtual void mostrarInformacion() = 0;

    virtual ~Proyecto() {}
};

class ProyectoInterno : public Proyecto {
private:
    double costoBase;

public:
    ProyectoInterno(string codigo, string nombre, double costo)
        : Proyecto(codigo, nombre), costoBase(costo) {
    }

    double calcularCosto() override {
        return costoBase * 1.10;
    }

    void mostrarInformacion() override {
        cout << "Proyecto Interno "<<endl;
        cout << "Codigo: " << codigo << " Nombre: " << nombre << endl;
        cout << "Costo: " << calcularCosto() << endl;
    }
};


class ProyectoExterno : public Proyecto {
private:
    double costoBase;
    double impuesto;

public:
    ProyectoExterno(string codigo, string nombre, double costo, double impuesto)
        : Proyecto(codigo, nombre), costoBase(costo), impuesto(impuesto) {
    }

    double calcularCosto() override {
        return costoBase + impuesto;
    }

    void mostrarInformacion() override {
        cout << "Proyecto Externo ";
        cout << "Codigo: " << codigo << " Nombre: " << nombre << endl;
        cout << "Costo: " << calcularCosto() << endl;
    }
};


class VectorEmpleados {
private:
    Empleado** arr;
    int n;

public:
    VectorEmpleados() {
        arr = NULL;
        n = 0;
    }

    bool existeCI(string ci) {
        for (int i = 0; i < n; i++) {
            if (arr[i]->getCI() == ci) return true;
        }
        return false;
    }

    void agregarEmpleado(Empleado* e) {
        if (existeCI(e->getCI())) {
            cout << "CI repetido "<< endl;
            return;
        }

        Empleado** nuevo = new Empleado * [n + 1];

        for (int i = 0; i < n; i++) {
            nuevo[i] = arr[i];
        }

        nuevo[n] = e;

        delete[] arr;
        arr = nuevo;
        n++;
    }

    void mostrar() {
        for (int i = 0; i < n; i++) {
            arr[i]->mostrarInformacion();
          
        }
    }

    double totalSalarios() {
        double total = 0;
        for (int i = 0; i < n; i++) {
            total += arr[i]->calcularSalario();
        }
        return total;
    }
};


class VectorProyectos {
private:
    Proyecto** arr;
    int n;

public:
    VectorProyectos() {
        arr = NULL;
        n = 0;
    }

    bool existeCodigo(string cod) {
        for (int i = 0; i < n; i++) {
            if (arr[i]->getCodigo() == cod) return true;
        }
        return false;
    }

    void agregarProyecto(Proyecto* p) {
        if (existeCodigo(p->getCodigo())) {
            cout << "Codigo repetido "<< endl;
            return;
        }

        Proyecto** nuevo = new Proyecto * [n + 1];

        for (int i = 0; i < n; i++) {
            nuevo[i] = arr[i];
        }

        nuevo[n] = p;

        delete[] arr;
        arr = nuevo;
        n++;
    }

    void mostrar() {
        for (int i = 0; i < n; i++) {
            arr[i]->mostrarInformacion();
            
        }
    }

    Proyecto* mayorCosto() {
        if (n == 0) return NULL;

        Proyecto* mayor = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i]->calcularCosto() > mayor->calcularCosto()) {
                mayor = arr[i];
            }
        }
        return mayor;
    }
};


class Empresa {
private:
    VectorEmpleados empleados;
    VectorProyectos proyectos;

public:
    void agregarEmpleado(Empleado* e) {
        empleados.agregarEmpleado(e);
    }

    void agregarProyecto(Proyecto* p) {
        proyectos.agregarProyecto(p);
    }

    void mostrarTodo() {
        cout << "Empleados"<<endl;
        empleados.mostrar();

        cout << "Proyectos "<< endl;
        proyectos.mostrar();
    }

    void totalSalarios() {
        cout << "Total salarios: " << empleados.totalSalarios() << endl;
    }

    void proyectoMasCostoso() {
        Proyecto* p = proyectos.mayorCosto();
        if (p != NULL) {
            cout << "Proyecto mas costoso : ";
            p->mostrarInformacion();
        }
    }
};

int main() {
    Empresa emp;

    
    emp.agregarEmpleado(new EmpleadoTiempoCompleto("111", "Juan", 3000, 500));
    emp.agregarEmpleado(new EmpleadoPorHoras("222", "Maria", 100, 20));
    emp.agregarEmpleado(new EmpleadoPorHoras("111", "Repetido", 50, 10));

    
    emp.agregarProyecto(new ProyectoInterno("P1", "Sistema", 10000));
    emp.agregarProyecto(new ProyectoExterno("P2", "App", 8000, 2000));
    emp.agregarProyecto(new ProyectoInterno("P1", "Duplicado", 5000));

    emp.mostrarTodo();
    emp.totalSalarios();
    emp.proyectoMasCostoso();

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
