#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string DNI;
    char sexo;
    float peso;
    float altura;

    const int PB = -1;
    const int PI = 0;
    const int SP = 1;

    void comprobarSexo(char s) {
        if (s == 'H' || s == 'M') {
            sexo = s;
        } else {
            sexo = 'H';
        }
    }

    void generaDNI() {
        int numero = 10000000 + rand() % 90000000;
        char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        char letra = letras[numero % 23];

        DNI = to_string(numero) + letra;
    }

public:
    Persona()
    {
        nombre = "";
        edad = 0;
        sexo = 'H';
        peso = 0;
        altura = 0;
        generaDNI();
    }

    Persona(string nombre, int edad, char sexo)
    {
        this->nombre = nombre;
        this->edad = edad;
        peso = 0;
        altura = 0;
        comprobarSexo(sexo);
        generaDNI();
    }

    Persona(string nombre, int edad, char sexo, float peso, float altura)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->peso = peso;
        this->altura = altura;
        comprobarSexo(sexo);
        generaDNI();
    }

    int calcularIMC()
    {
        float imc = peso / (altura * altura);

        if (imc < 20) return PB;
        else if (imc <= 25) return PI;
        else return SP;
    }

    bool esMayorDeEdad()
    {
        return edad >= 18;
    }

    string toString()
    {
        return "Nombre: " + nombre +
               "\nEdad: " + to_string(edad) +
               "\nDNI: " + DNI +
               "\nSexo: " + string(1, sexo) +
               "\nPeso: " + to_string(peso) +
               "\nAltura: " + to_string(altura);
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setEdad(int edad) {
        this->edad = edad;
    }

    void setSexo(char sexo) {
        comprobarSexo(sexo);
    }

    void setPeso(float peso) {
        this->peso = peso;
    }

    void setAltura(float altura) {
        this->altura = altura;
    }
};

class Password {
private:
    int longitud;
    string contrasena;

public:
    Password() {
        longitud = 8;
        generarPassword();
    }

    Password(int longitud) {
        this->longitud = longitud;
        generarPassword();
    }

    void generarPassword() {
        contrasena = "";
        char M,m,num;

        for (int i = 0; i < longitud; i++) {

            int tipo = rand() % 3;

            if (tipo == 0) {
                char M = 'A' + rand() % 26;
                contrasena += M;
            }
            else if (tipo == 1) {
                char m = 'a' + rand() % 26;
                contrasena += m;
            }
            else {
                char num = '0' + rand() % 10;
                contrasena += num;
            }
        }
    }

    bool esFuerte() {
        int M = 0;
        int m = 0;
        int num = 0;

        for (int i = 0; i < contrasena.length(); i++) {

            if (contrasena[i] >= 'A' && contrasena[i] <= 'Z') {
                M++;
            }
            else if (contrasena[i] >= 'a' && contrasena[i] <= 'z') {
                m++;
            }
            else if (contrasena[i] >= '0' && contrasena[i] <= '9') {
                num++;
            }
        }

        if (M > 2 && m > 1 && num > 5) {
            return true;
        }
        else {
            return false;
        }
    }

    string getContrasena() {
        return contrasena;
    }

    int getLongitud() {
        return longitud;
    }

    void setLongitud(int longitud) {
        this->longitud = longitud;
        generarPassword();
    }
};

void ejercicio2()
{
    cout << "EJERCICIO 2" << endl;
    cout << endl;
    srand(time(0));

    Persona p1=Persona();
    p1.setNombre("Carlos");
    p1.setEdad(17);
    p1.setSexo('M');
    p1.setPeso(60);
    p1.setAltura(1.70);

    cout << "PERSONA 1" << endl;
    cout << p1.toString() << endl;
    cout << "IMC: " << p1.calcularIMC() << endl;
    cout << "Mayor de edad: " << p1.esMayorDeEdad() << endl;

    cout << endl;

    Persona p2 = Persona("Ana", 22, 'M');
    p2.setPeso(55);
    p2.setAltura(1.60);

    cout << "PERSONA 2" << endl;
    cout << p2.toString() << endl;
    cout << "IMC: " << p2.calcularIMC() << endl;
    cout << "Mayor de edad: " << p2.esMayorDeEdad() << endl;

    cout << endl;

    Persona p3 = Persona("Luis", 30, 'H', 90, 1.75);

    cout << "PERSONA 3" << endl;
    cout << p3.toString() << endl;
    cout << "IMC: " << p3.calcularIMC() << endl;
    cout << "Mayor de edad: " << p3.esMayorDeEdad() << endl;
}

void ejercicio3()
{
    cout << "EJERCICIO 3" << endl;
    cout << endl;

    srand(time(0));

    Password p1 = Password ();

    cout << "Password 1: " << endl;
    cout << "Longitud: " << p1.getLongitud() << endl;
    cout << "Contrasena: " << p1.getContrasena() << endl;
    cout << "Es fuerte?: " << p1.esFuerte() << endl;

    cout << endl;

    Password p2 = Password(15);

    cout << "Password 2: " << endl;
    cout << "Longitud: " << p2.getLongitud() << endl;
    cout << "Contrasena: " << p2.getContrasena() << endl;
    cout << "Es fuerte?: " << p2.esFuerte() << endl;

    cout << endl;

    p2.setLongitud(20);

    cout << "Password 2 modificada:\n";
    cout << "Nueva Longitud: " << p2.getLongitud() << endl;
    cout << "Nueva Contrasena: " << p2.getContrasena() << endl;
    cout << "Es fuerte?: " << p2.esFuerte() << endl;
}

int main()
{
    ejercicio2();
    ejercicio3();
}