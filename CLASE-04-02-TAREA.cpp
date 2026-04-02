#include <iostream>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    string ci;

public:
    Empleado(string nombre, string ci) {
        this->nombre = nombre;
        this->ci = ci;
    }
    string getCI() { 
        return ci; 
    }
    virtual float calcularSalario() = 0;
    virtual void mostrarInformacion() = 0;
};

class EmpleadoTiempoCompleto : public Empleado {
private:
    float salarioBase;
    float bono;

public:
    EmpleadoTiempoCompleto(string nombre, string ci, float salarioBase, float bono)
        : Empleado(nombre, ci) {
        this->salarioBase = salarioBase;
        this->bono = bono;
    }
    float calcularSalario() override {
        return salarioBase + bono;
    }
    void mostrarInformacion() override {
        cout << "[Tiempo Completo] " << endl;
        cout << "Nombre:" << nombre << endl;
        cout << "CI: " << ci << endl;
        cout << "Salario: " << calcularSalario() << endl;
        cout << endl;
    }
};

class EmpleadoPorHoras : public Empleado {
private:
    float horas;
    float pagoHora;

public:
    EmpleadoPorHoras(string nombre, string ci, float horas, float pagoHora)
        : Empleado(nombre, ci) {
        this->horas = horas;
        this->pagoHora = pagoHora;
    }
    float calcularSalario() override {
        return horas * pagoHora;
    }
    void mostrarInformacion() override {
        cout << "[Por Horas] " << endl;
        cout << "Nombre:" << nombre << endl;
        cout << "CI: " << ci << endl;
        cout << "Salario: " << calcularSalario() << endl;
    }
};

class Proyecto {
protected:
    string codigo;
    string nombre;

public:
    Proyecto(string codigo, string nombre) {
        this->codigo = codigo;
        this->nombre = nombre;
    }
    string getCodigo() { 
        return codigo; 
    }
    virtual float calcularCosto() = 0;
    virtual void mostrar() = 0;
};

class ProyectoInterno : public Proyecto {
private:
    float presupuesto;

public:
    ProyectoInterno(string codigo, string nombre, float presupuesto)
        : Proyecto(codigo, nombre) {
        this->presupuesto = presupuesto;
    }
    float calcularCosto() override {
        return presupuesto;
    }
    void mostrar() override {
        cout << "[Interno] " << endl;
        cout << "Nombre:" << nombre << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Costo: " << calcularCosto() << endl;
        cout << endl;
    }
};

class ProyectoExterno : public Proyecto {
private:
    float costoBase;
    float impuesto;

public:
    ProyectoExterno(string codigo, string nombre, float costoBase, float impuesto)
        : Proyecto(codigo, nombre) {
        this->costoBase = costoBase;
        this->impuesto = impuesto;
    }
    float calcularCosto() override {
        return costoBase + impuesto;
    }
    void mostrar() override {
        cout << "[Externo] " << endl;
        cout << "Nombre:" << nombre << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Costo: " << calcularCosto() << endl;
        cout << endl;
    }
};

class VectorEmpleados {
private:
    Empleado** empleados;
    int tamanio;
    int indice;

public:
    VectorEmpleados(int tamanio) {
        this->tamanio = tamanio;
        this->indice = 0;
        empleados = new Empleado * [tamanio];
    }
    bool existeCI(string ci) {
        for (int i = 0; i < indice; i++) {
            if (empleados[i]->getCI() == ci)
                return true;
        }
        return false;
    }
    void agregar(Empleado* newEmpleado) {
        if (indice < tamanio && !existeCI(newEmpleado->getCI())) {
            empleados[indice++] = newEmpleado;
        }
        else {
            cout << "Empleado duplicado o vector lleno";
        }
    }
    void mostrar() {
        for (int i = 0; i < indice; i++)
            empleados[i]->mostrarInformacion();
    }
    float totalSalarios() {
        float total = 0;
        for (int i = 0; i < indice; i++)
            total = total + empleados[i]->calcularSalario();
        return total;
    }
};

class VectorProyectos {
private:
    Proyecto** proyectos;
    int tamanio;
    int indice;

public:
    VectorProyectos(int tamanio) {
        this->tamanio = tamanio;
        this->indice = 0;
        proyectos = new Proyecto * [tamanio];
    }
    bool existeCodigo(string cod) {
        for (int i = 0; i < indice; i++) {
            if (proyectos[i]->getCodigo() == cod)
                return true;
        }
        return false;
    }
    void agregar(Proyecto* p) {
        if (indice < tamanio && !existeCodigo(p->getCodigo())) {
            proyectos[indice++] = p;
        }
        else {
            cout << "Proyecto duplicado o vector lleno";
        }
    }
    void mostrar() {
        for (int i = 0; i < indice; i++)
            proyectos[i]->mostrar();
    }
    void proyectoMayorCosto() {
        if (indice == 0) return;
        int pos = 0;
        for (int i = 1; i < indice; i++) {
            if (proyectos[i]->calcularCosto() > proyectos[pos]->calcularCosto()) {
                pos = i;
            }
        }
        cout << "Proyecto con mayor costo: " << endl;
        proyectos[pos]->mostrar();
    }
};

class Empresa {
private:
    VectorEmpleados empleados;
    VectorProyectos proyectos;

public:
    Empresa(int tamanioE, int tamanioP)
        : empleados(tamanioE), proyectos(tamanioP) {
    }
    void agregarEmpleado(Empleado* newEmpleado) {
        empleados.agregar(newEmpleado);
    }
    void agregarProyecto(Proyecto* newProyecto) {
        proyectos.agregar(newProyecto);
    }
    void mostrarTodo() {
        cout << "--- EMPLEADOS ---" << endl;
        cout << endl;
        empleados.mostrar();
        cout << endl;
        cout << "--- PROYECTOS ---" << endl;
        cout << endl;
        proyectos.mostrar();
    }
    void totalSalarios() {
        cout << "Total salarios: " << endl;
        cout << empleados.totalSalarios() << endl;
    }
    void proyectoMasCaro() {
        proyectos.proyectoMayorCosto();
    }
};

int main() {
    Empresa emp(10, 10);
    emp.agregarEmpleado(new EmpleadoTiempoCompleto("Juan", "123", 3000, 500));
    emp.agregarEmpleado(new EmpleadoPorHoras("Ana", "456", 80, 20));
    emp.agregarProyecto(new ProyectoInterno("P1", "Sistema", 5000));
    emp.agregarProyecto(new ProyectoExterno("P2", "App Movil", 4000, 800));
    emp.mostrarTodo();
    emp.totalSalarios();
    emp.proyectoMasCaro();
}