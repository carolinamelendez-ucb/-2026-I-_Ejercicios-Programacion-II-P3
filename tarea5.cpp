// tarea5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

class Pago {
protected:
    double monto;

public:
    Pago(double m) : monto(m) {}

    virtual double procesarPago() = 0;
    virtual void mostrar() = 0;

    virtual ~Pago() {}
};

class PagoPorcentaje : public Pago {
public:
    PagoPorcentaje(double m) : Pago(m) {}

    double procesarPago() override {
        return monto * 1.03;
    }

    void mostrar() override {
        double comision = monto * 0.03;
        cout << "Monto original: " << monto << endl;
        cout << "Comision: " << comision << endl;
        cout << "Total pagado: " << monto + comision << endl;
    }
};

class PagoFijo : public Pago {
public:
    PagoFijo(double m) : Pago(m) {}

    double procesarPago() override {
        return monto + 5;
    }

    void mostrar() override {
        cout << "Monto original: " << monto << endl;
        cout << "Comision fija: 5" << endl;
        cout << "Total pagado: " << monto + 5 << endl;
    }
};

class PagoValidado : public Pago {
public:
    PagoValidado(double m) : Pago(m) {}

    double procesarPago() override {
        if (monto <= 0) return 0;
        return monto;
    }

    void mostrar() override {
        if (monto <= 0) {
            cout << "Error" << endl;
        }
        else {
            cout << "Monto original: " << monto << endl;
            cout << "Sin comision" << endl;
            cout << "Total pagado: " << monto << endl;
        }
    }
};

class PagoDescuento : public Pago {
public:
    PagoDescuento(double m) : Pago(m) {}

    double procesarPago() override {
        return monto * 0.90;
    }

    void mostrar() override {
        double desc = monto * 0.10;
        cout << "Monto original: " << monto << endl;
        cout << "Descuento: " << desc << endl;
        cout << "Total pagado: " << monto - desc << endl;
    }
};

class VectorPagos {
private:
    Pago** arr;
    int n;

public:
    VectorPagos() {
        arr = NULL;
        n = 0;
    }

    void agregar(Pago* p) {
        Pago** nuevo = new Pago * [n + 1];

        for (int i = 0; i < n; i++) {
            nuevo[i] = arr[i];
        }

        nuevo[n] = p;

        delete[] arr;
        arr = nuevo;
        n++;
    }

    double procesarTodos() {
        double total = 0;

        for (int i = 0; i < n; i++) {
            total += arr[i]->procesarPago();
        }

        return total;
    }

    void mostrar() {
        for (int i = 0; i < n; i++) {
            cout << "Pago " << i + 1 << ": ";
            arr[i]->mostrar();
            cout << endl;
        }
    }
};

class Cliente {
private:
    string nombre;
    VectorPagos pagos;

public:
    Cliente(string n) {
        nombre = n;
    }

    void agregarPago(Pago* p) {
        pagos.agregar(p);
    }

    double procesarPagos() {
        return pagos.procesarTodos();
    }

    void mostrar() {
        cout << "Cliente: " << nombre << endl;
        pagos.mostrar();
    }
};


class VectorClientes {
private:
    Cliente** arr;
    int n;

public:
    VectorClientes() {
        arr = NULL;
        n = 0;
    }

    void agregar(Cliente* c) {
        Cliente** nuevo = new Cliente * [n + 1];

        for (int i = 0; i < n; i++) {
            nuevo[i] = arr[i];
        }

        nuevo[n] = c;

        delete[] arr;
        arr = nuevo;
        n++;
    }

    double totalGeneral() {
        double total = 0;

        for (int i = 0; i < n; i++) {
            total += arr[i]->procesarPagos();
        }

        return total;
    }

    void mostrar() {
        for (int i = 0; i < n; i++) {
            arr[i]->mostrar();
            cout << endl;
        }
    }
};

int main() {

    VectorClientes sistema;

   
    Cliente* c1 = new Cliente("Juan Perez");
    c1->agregarPago(new PagoPorcentaje(100));
    c1->agregarPago(new PagoFijo(200));

    
    Cliente* c2 = new Cliente("Maria Lopez");
    c2->agregarPago(new PagoDescuento(150));
    c2->agregarPago(new PagoValidado(-50));

    sistema.agregar(c1);
    sistema.agregar(c2);

  
    sistema.mostrar();

   
    cout << "proceso total: "
        << sistema.totalGeneral() << endl;

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
