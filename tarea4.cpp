// tarea4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
using namespace std;

class Transporte {
protected:
    string placa;

public:
    Transporte(string p) : placa(p) {}

    string getPlaca() {
        return placa;
    }

    virtual double calcularCosto(double distancia) = 0;
    virtual void mostrar() = 0;

    virtual ~Transporte() {}
};

class Terrestre : public Transporte {
public:
    Terrestre(string p) : Transporte(p) {}

    double calcularCosto(double d) override {
        double costo = d * 0.5;
        if (d > 100) costo *= 1.10;
        return costo;
    }

    void mostrar() override {
        cout << "Transporte Terrestre , Placa: " << placa << endl;
    }
};

class Aereo : public Transporte {
public:
    Aereo(string p) : Transporte(p) {}

    double calcularCosto(double d) override {
        double costo = d * 2.0;
        if (d > 1000) costo *= 0.85;
        return costo;
    }

    void mostrar() override {
        cout << "Transporte Aereo , Placa: " << placa << endl;
    }
};

class Maritimo : public Transporte {
public:
    Maritimo(string p) : Transporte(p) {}

    double calcularCosto(double d) override {
        double costo = d * 1.2;
        if (d > 500) costo += 50;
        return costo;
    }

    void mostrar() override {
        cout << "Transporte Maritimo, Placa: " << placa << endl;
    }
};

class Operador {
private:
    string ci;
    string nombre;
    double distancia;
    Transporte* transporte;

public:
    Operador(string ci, string nombre, double distancia) {
        this->ci = ci;
        this->nombre = nombre;
        this->distancia = distancia;
        transporte = NULL;
    }

    string getCI() {
        return ci;
    }

    void asignarTransporte(Transporte* t) {
        transporte = t;
    }

    double calcularCosto() {
        if (transporte != NULL)
            return transporte->calcularCosto(distancia);
        return 0;
    }

    void mostrar() {
        cout << "Operador: " << nombre << "  CI: " << ci << endl;
        cout << "Distancia: " << distancia << endl;

        if (transporte != NULL) {
            transporte->mostrar();
            cout << "Costo: " << calcularCosto() << endl;
        }
        else {
            cout << "Sin transporte asignado "<<endl;
        }

    }

    Transporte* getTransporte() {
        return transporte;
    }
};

class VectorTransportes {
private:
    Transporte** arr;
    int n;

public:
    VectorTransportes() {
        arr = NULL;
        n = 0;
    }

    bool existePlaca(string placa) {
        for (int i = 0; i < n; i++) {
            if (arr[i]->getPlaca() == placa)
                return true;
        }
        return false;
    }

    void agregar(Transporte* t) {
        if (existePlaca(t->getPlaca())) {
            cout << "Error: placa duplicada "<<endl;
            return;
        }

        Transporte** nuevo = new Transporte * [n + 1];

        for (int i = 0; i < n; i++) {
            nuevo[i] = arr[i];
        }

        nuevo[n] = t;

        delete[] arr;
        arr = nuevo;
        n++;
    }

    Transporte* buscar(string placa) {
        for (int i = 0; i < n; i++) {
            if (arr[i]->getPlaca() == placa)
                return arr[i];
        }
        return NULL;
    }
};

class VectorOperadores {
private:
    Operador** arr;
    int n;

public:
    VectorOperadores() {
        arr = NULL;
        n = 0;
    }

    bool existeCI(string ci) {
        for (int i = 0; i < n; i++) {
            if (arr[i]->getCI() == ci)
                return true;
        }
        return false;
    }

    void agregar(Operador* o) {
        if (existeCI(o->getCI())) {
            cout << "Error: CI duplicado\n";
            return;
        }

        Operador** nuevo = new Operador * [n + 1];

        for (int i = 0; i < n; i++) {
            nuevo[i] = arr[i];
        }

        nuevo[n] = o;

        delete[] arr;
        arr = nuevo;
        n++;
    }

    Operador* buscar(string ci) {
        for (int i = 0; i < n; i++) {
            if (arr[i]->getCI() == ci)
                return arr[i];
        }
        return NULL;
    }

    double costoTotal() {
        double total = 0;
        for (int i = 0; i < n; i++) {
            total += arr[i]->calcularCosto();
        }
        return total;
    }

    Operador* menorCosto() {
        if (n == 0) return NULL;

        Operador* menor = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i]->calcularCosto() < menor->calcularCosto()) {
                menor = arr[i];
            }
        }

        return menor;
    }
};

class Sistema {
private:
    VectorTransportes vt;
    VectorOperadores vo;

public:
    void registrarTransporte(Transporte* t) {
        vt.agregar(t);
    }

    void registrarOperador(Operador* o) {
        vo.agregar(o);
    }

    void asociar(string ci, string placa) {
        Operador* o = vo.buscar(ci);
        Transporte* t = vt.buscar(placa);

        if (o != NULL && t != NULL) {
            o->asignarTransporte(t);
        }
        else {
            cout << "Error al asociar  "<<endl;
        }
    }

    void mostrarOperador(string ci) {
        Operador* o = vo.buscar(ci);
        if (o != NULL) {
            o->mostrar();
        }
        else {
            cout << "Operador no encontrado "<<endl;
        }
    }

    void mostrarCostoTotal() {
        cout << "Costo total del sistema: "
            << vo.costoTotal() << endl;
    }

    void mostrarMenorCosto() {
        Operador* o = vo.menorCosto();
        if (o != NULL) {
            cout << " Operador con menor costo: "<< endl;
            o->mostrar();
        }
    }
};

int main() {
    Sistema sistema;

    sistema.registrarTransporte(new Terrestre("T1"));
    sistema.registrarTransporte(new Aereo("A1"));
    sistema.registrarTransporte(new Maritimo("M1"));
    sistema.registrarTransporte(new Terrestre("T1")); 

    sistema.registrarOperador(new Operador("111", "Juan", 150));
    sistema.registrarOperador(new Operador("222", "Maria", 1200));
    sistema.registrarOperador(new Operador("333", "Luis", 600));
    sistema.registrarOperador(new Operador("111", "Repetido", 50)); 

    sistema.asociar("111", "T1");
    sistema.asociar("222", "A1");
    sistema.asociar("333", "M1");

    sistema.mostrarOperador("111");
    sistema.mostrarOperador("222");
    sistema.mostrarOperador("333");

    sistema.mostrarCostoTotal();

    sistema.mostrarMenorCosto();

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
