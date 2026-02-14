// Tarea 10-02.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

//EJERCICIO 1

class Cuenta {
private:
    string titular;
    double cantidad;

public:
    Cuenta(string titular, double cantidad) {
        this->titular = titular;
        if (cantidad < 0) this->cantidad = 0;
        else this->cantidad = cantidad;
    }

    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0;
    }

    void setCantidad(double nuevaCantidad) {
        if (nuevaCantidad < 0) this->cantidad = 0;
        else this->cantidad = nuevaCantidad;
    }

    double getCantidad() {
        return cantidad;
    }

    void setTitular(string nuevoTitular) {
        this->titular = nuevoTitular;
    }

    string getTitular() {
        return titular;
    }

    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }

    void ingresar(double cantidadIngresada) {
        if (cantidadIngresada > 0) {
            cantidad = cantidad + cantidadIngresada;
        }
    }

    void retirar(double cantidadRetirada) {
        double restante = cantidad - cantidadRetirada;

        if (restante < 0) {
            cantidad = 0;
        }
        else {
            cantidad = restante;
        }
    }
};

//EJERCICIO 2

/*class Persona {
private:
    string nombre;
    int edad;
    string dni;
    string sexo;
    double peso;
    double altura;

    void comprobarSexo(string sexoIngresado) {
        if (sexoIngresado == "H" || sexoIngresado == "M") {
            sexo = sexoIngresado;
        }
        else {
            sexo = "H";
        }
    }

    char calcularLetraDNI(int numero) {
        string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
        int posicion = numero % 23;
        return letras[posicion];
    }

    void generarDNI() {
        int numeroBase = 12345678;
        char letra = calcularLetraDNI(numeroBase);
        dni = to_string(numeroBase) + letra;
    }

public:
    Persona() {
        nombre = "";
        edad = 0;
        peso = 0;
        altura = 0;
        comprobarSexo("H");
        generarDNI();
    }

    Persona(string nombrePersona, int edadPersona, string sexoPersona) {
        nombre = nombrePersona;
        edad = edadPersona;
        peso = 0;
        altura = 0;
        comprobarSexo(sexoPersona);
        generarDNI();
    }

    Persona(string nombrePersona, int edadPersona, string sexoPersona,
        double pesoPersona, double alturaPersona) {

        nombre = nombrePersona;
        edad = edadPersona;
        peso = pesoPersona;
        altura = alturaPersona;
        comprobarSexo(sexoPersona);
        generarDNI();
    }

    int calcularIMC() {
        if (altura <= 0) return -1;

        double imc = peso / (altura * altura);

        if (imc < 20) return -1;
        if (imc <= 25) return 0;
        return 1;
    }

    bool esMayorDeEdad() {
        return edad >= 18;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "DNI: " << dni << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Peso: " << peso << endl;
        cout << "Altura: " << altura << endl;
    }
};*/


int main() {
    double saldoInicial = 200.0;
    double ingreso = 45.5;
    double retiroGrande = 225.0;
    double nuevoSaldo = 150.0;

    Cuenta cuenta1("Juan", saldoInicial);
    Cuenta cuenta2("Pedro");

    cuenta1.mostrar();
    cout << "-----" << endl;
    cuenta2.mostrar();

    cout << "-----" << endl;
    cuenta2.setCantidad(nuevoSaldo);
    cuenta2.mostrar();

    cout << "-----" << endl;
    cuenta1.ingresar(ingreso);
    cuenta2.retirar(retiroGrande);

    cuenta1.mostrar();
    cout << "-----" << endl;
    cuenta2.mostrar();

    /* Persona p1;
     Persona p2("Maria", 20, "M");
    Persona p3("Juan", 17, "H", 72.5, 1.75);

     p1.mostrar();
    cout << "IMC: " << p1.calcularIMC()
     << " | Mayor edad: " << (p1.esMayorDeEdad() ? "SI" : "NO") << endl;

    cout << endl;

    p2.mostrar();
    cout << "IMC: " << p2.calcularIMC()
     << " | Mayor edad: " << (p2.esMayorDeEdad() ? "SI" : "NO") << endl;

     cout << endl;

     p3.mostrar();
    cout << "IMC: " << p3.calcularIMC()
     << " | Mayor edad: " << (p3.esMayorDeEdad() ? "SI" : "NO") << endl;*/

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
