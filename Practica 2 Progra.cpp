// Practica 2 Programacion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Cuenta {
private:
    string titular;
    int cantidad;
public:
    Cuenta(string titular, int cantidad) {
        this->titular = titular;
        this->cantidad = cantidad;
    }
    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0;
    }
    void setCantidad(int nuevaC) {
        this->cantidad = nuevaC;
    }
    int getCantidad() {
        return cantidad;
    }
    void setTitular(string nuevoT) {
        this->titular = nuevoT;
    }
    string getTitular() {
        return titular;
    }
    void mostrar() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
    void ingresar(int cantidadIngresada) {
        if (cantidadIngresada >= 0) {
            cantidad = cantidad + cantidadIngresada;
        }

    }
    void retirar(int cantidadRetirada) {
        int restante = cantidad - cantidadRetirada;
        if (restante < 0) {
            this->cantidad = 0;
        }
        else {
            this->cantidad = restante;
        }
    }
};

void Ejercicio1() {
    Cuenta cuenta1 = Cuenta("alan", 200);
    Cuenta cuenta2 = Cuenta("fabian");
    cuenta1.mostrar();
    cuenta2.mostrar();
    cuenta2.setCantidad(200);
    cuenta2.mostrar();
    cuenta1.ingresar(100);
    cuenta2.retirar(210);
    cuenta1.mostrar();
    cuenta2.mostrar();
}

class Persona {
private:
    string nombre;
    int edad;
    string dni;
    char sexo;
    int peso;
    int altura;

    void comprobarSexo(char sexo) {
        if (sexo != 'H' && sexo != 'M') {
            this->sexo = 'H';
        }
        else {
            this->sexo = sexo;
        }
    }

    void generaDNI() {
        int numero = generarNumero();
        char letra = calcularLetra(numero);
        this->dni = to_string(numero) + letra;
    }

    int generarNumero() {
        return 10000000 + rand() % 90000000;
    }

    char calcularLetra(int numero) {
        string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
        return letras[numero % 23];
    }

public:
    Persona() {
        this->nombre = "";
        this->edad = 0;
        this->dni = "";
        this->sexo = 'H';
        this->peso = 0;
        this->altura = 0;
        generaDNI();
    }

    Persona(string nombre, int edad, char sexo) {
        this->nombre = nombre;
        this->edad = edad;
        this->dni = "";
        comprobarSexo(sexo);
        this->peso = 0;
        this->altura = 0;
        generaDNI();
    }

    Persona(string nombre, int edad, char sexo, int peso, int altura) {
        this->nombre = nombre;
        this->edad = edad;
        this->dni = "";
        comprobarSexo(sexo);
        this->peso = peso;
        this->altura = altura;
        generaDNI();
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "DNI: " << dni << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Peso: " << peso << endl;
        cout << "Altura: " << altura << endl;
    }

    void setNombre(string nuevoN) {
        this->nombre = nuevoN;
    }

    void setEdad(int nuevaE) {
        this->edad = nuevaE;
    }

    void setSexo(char nuevoS) {
        comprobarSexo(nuevoS);
    }

    void setPeso(int nuevoP) {
        this->peso = nuevoP;
    }

    void setAltura(int nuevoA) {
        this->altura = nuevoA;
    }

    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    string getDNI() { return dni; }
    char getSexo() { return sexo; }
    int getPeso() { return peso; }
    int getAltura() { return altura; }

    int calcularIMC() {
        if (altura <= 0) {
            return -1;
        }

        double alturaM = altura / 100.0;
        double imc = peso / (alturaM * alturaM);

        if (imc < 20) {
            return -1;
        }
        else if (imc >= 20 && imc <= 25) {
            return 0;
        }
        else {
            return 1;
        }
    }

    bool esMayorDeEdad() {
        if (edad >= 18) {
            return true;
        }
        else {
            return false;
        }
    }

    string toString() {
        string texto = "";
        texto += "Nombre: " + nombre + "\n";
        texto += "Edad: " + to_string(edad) + "\n";
        texto += "DNI: " + dni + "\n";
        texto += "Sexo: ";
        texto += sexo;
        texto += "\n";
        texto += "Peso: " + to_string(peso) + "\n";
        texto += "Altura: " + to_string(altura) + "\n";
        return texto;
    }
};

void Ejercicio2() {

        Persona persona1;

        string nom;
        int ed;
        char sex;
        int pe;
        int al;

        cout << "----- DATOS PERSONA 1 (con setters) -----" << endl;
        cout << "Ingrese nombre: ";
        cin >> nom;
        cout << "Ingrese edad: ";
        cin >> ed;
        cout << "Ingrese sexo (H/M): ";
        cin >> sex;
        cout << "Ingrese peso (kg): ";
        cin >> pe;
        cout << "Ingrese altura (cm): ";
        cin >> al;

        persona1.setNombre(nom);
        persona1.setEdad(ed);
        persona1.setSexo(sex);
        persona1.setPeso(pe);
        persona1.setAltura(al);

        cout << "\n----- DATOS PERSONA 2 (constructor nombre, edad, sexo) -----" << endl;
        cout << "Ingrese nombre: ";
        cin >> nom;
        cout << "Ingrese edad: ";
        cin >> ed;
        cout << "Ingrese sexo (H/M): ";
        cin >> sex;

        Persona persona2(nom, ed, sex);

        cout << "Ingrese peso (kg): ";
        cin >> pe;
        cout << "Ingrese altura (cm): ";
        cin >> al;

        persona2.setPeso(pe);
        persona2.setAltura(al);

        cout << "\n----- DATOS PERSONA 3 (constructor completo) -----" << endl;
        cout << "Ingrese nombre: ";
        cin >> nom;
        cout << "Ingrese edad: ";
        cin >> ed;
        cout << "Ingrese sexo (H/M): ";
        cin >> sex;
        cout << "Ingrese peso (kg): ";
        cin >> pe;
        cout << "Ingrese altura (cm): ";
        cin >> al;

        Persona persona3(nom, ed, sex, pe, al);

        cout << "\n================= MOSTRAR PERSONAS =================" << endl;

        cout << "\n--- Persona 1 ---" << endl;
        persona1.mostrar();
        cout << "IMC: " << persona1.calcularIMC() << endl;
        cout << "Mayor de edad: " << persona1.esMayorDeEdad() << endl;

        cout << "\n--- Persona 2 ---" << endl;
        persona2.mostrar();
        cout << "IMC: " << persona2.calcularIMC() << endl;
        cout << "Mayor de edad: " << persona2.esMayorDeEdad() << endl;

        cout << "\n--- Persona 3 ---" << endl;
        persona3.mostrar();
        cout << "IMC: " << persona3.calcularIMC() << endl;
        cout << "Mayor de edad: " << persona3.esMayorDeEdad() << endl;

        cout << "\n================= TOSTRING =================" << endl;
        cout << "\nPersona 1:\n" << persona1.toString() << endl;
        cout << "\nPersona 2:\n" << persona2.toString() << endl;
        cout << "\nPersona 3:\n" << persona3.toString() << endl;
    }

 

int main()
{
    //   Ejercicio1();
    Ejercicio2();

}