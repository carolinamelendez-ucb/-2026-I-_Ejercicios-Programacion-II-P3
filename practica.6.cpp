// practica.6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

class Banco {
protected:
    string nombre;
    int num_cuenta;
    float balance;

    string historial[20];
    int contador;

public:
    Banco(string nombre, int num_cuenta, float balance) {
        this->nombre = nombre;
        this->num_cuenta = num_cuenta;
        this->balance = balance;
        contador = 0;
    }

    void depositar(float monto) {
        balance += monto;
        historial[contador] = "Deposito realizado";
        contador++;
    }

    void retirar(float monto) {
        if (monto <= balance) {
            balance -= monto;
            historial[contador] = "Retiro realizado";
            contador++;
        }
        else {
            cout << "Fondos insuficientes\n";
        }
    }

    void mostrar() {
        cout << "\nNombre: " << nombre << endl;
        cout << "Cuenta: " << num_cuenta << endl;
        cout << "Balance: " << balance << endl;

        cout << "Historial:\n";
        for (int i = 0; i < contador; i++) {
            cout << "- " << historial[i] << endl;
        }
    }
};

class Cuenta_corriente : public Banco {
public:
    Cuenta_corriente(string nombre, int num_cuenta, float balance)
        : Banco(nombre, num_cuenta, balance) {
    }
};

class Cuenta_transacional : public Banco {
public:
    Cuenta_transacional(string nombre, int num_cuenta, float balance)
        : Banco(nombre, num_cuenta, balance) {
    }

    void retirar(float monto) {
        float comision = monto * 0.003;
        float total = monto + comision;

        if (total <= balance) {
            balance -= total;

            historial[contador] = "Retiro con comision";
            contador++;
        }
        else {
            cout << "Fondos insuficientes\n";
        }
    }
};

class Cuenta_joven : public Banco {
public:
    Cuenta_joven(string nombre, int num_cuenta, float balance)
        : Banco(nombre, num_cuenta, balance) {
    }

    void retirar(float monto) {
        if (monto > 1000) {
            cout << "Maximo retiro 1000\n";
            return;
        }

        if (monto <= balance) {
            balance -= monto;

            historial[contador] = "Retiro permitido";
            contador++;
        }
        else {
            cout << "Fondos insuficientes\n";
        }
    }
};
int main() {

    Cuenta_corriente c1("Juan", 1, 3000);
    Cuenta_transacional c2("Maria", 2, 3000);
    Cuenta_joven c3("Luis", 3, 3000);

    // Operaciones
    c1.depositar(500);
    c1.retirar(200);
    c1.depositar(120);

    c2.depositar(1000);
    c2.retirar(500);

    c3.depositar(300);
    c3.retirar(200); 
    c3.retirar(500);
    

    // Mostrar
    c1.mostrar();
    c2.mostrar();
    c3.mostrar();

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
