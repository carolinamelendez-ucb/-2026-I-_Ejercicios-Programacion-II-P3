#include <iostream>
#include <string>
#include <cstdlib> #include <ctime>
using namespace std;

class Cuenta {
private:
    string titular;
    float cantidad;
public:
   
    Cuenta(string t) {
        titular = t;
        cantidad = 0;
    }
    
    Cuenta(string t, float c) {
        titular = t;
        cantidad = c;
    }

    string getTitular() {
        return titular; 
    }
    float getCantidad() {
        return cantidad;
    }

    void setTitular(string t) {
        titular = t; 
    }
    void setCantidad(float c) {
        cantidad = c; 
    }

    void ingresar(float c) {
        if (c > 0) 
            cantidad += c;
    }

    void retirar(float c) {
        cantidad -= c;
        if (cantidad < 0) 
            cantidad = 0;
    }

    void mostrarC() {
        cout << "Titular: " << titular << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
};


class Persona {
private:
    string nombre, DNI;
    int edad;
    char sexo;
    float peso, altura;

    void comprobarSexo(char s) {
        if (s != 'H' && s != 'M') sexo = 'H';
        else sexo = s;
    }

    string generaDNI() {
        int num = rand() % 90000000 + 10000000;
        return to_string(num);
    }

public:
    Persona() {
        nombre = "";
        edad = 0;
        sexo = 'H';
        peso = 0;
        altura = 0;
        DNI = generaDNI();
    }

    Persona(string n, int e, char s) {
        nombre = n;
        edad = e;
        comprobarSexo(s);
        peso = 0;
        altura = 0;
        DNI = generaDNI();
    }

    Persona(string n, int e, string d, char s, float p, float a) {
        nombre = n;
        edad = e;
        DNI = d;
        comprobarSexo(s);
        peso = p;
        altura = a;
    }

    int calcularIMC() {
        float imc = peso / (altura * altura);
        if (imc < 20) return -1;
        if (imc <= 25) return 0;
        return 1;
    }

    float esMayorDeEdad() {
        return edad >= 18;
    }

    void setNombre(string n) { 
        nombre = n;
    }

    void setEdad(int e) { 
        edad = e;
    }

    void setSexo(char s) {
        comprobarSexo(s); 
    }

    void setPeso(float p) {
        peso = p; 
    }

    void setAltura(float a) {
        altura = a; 
    }

    void mostrar() {
        cout << "Nombre: " << nombre << " Edad: " << edad << " DNI: " << DNI << endl;
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

    Password(int l) {
        longitud = l;
        generarPassword();
    }

    void generarPassword() {
        contrasena = " ";
        string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        for (int i = 0; i < longitud; i++) {
            contrasena += chars[rand() % chars.size()];
        }
    }

   float esFuerte() {
        int may = 0, min = 0, num = 0;
        for (char c : contrasena) {
            if (isupper(c)) may++;
            else if (islower(c)) min++;
            else if (isdigit(c)) num++;
        }
        return (may > 2 && min > 1 && num > 5);
    }

    string getContrasena() {
        return contrasena;
    }

    int getLongitud() {
        return longitud; 
    }

    void setLongitud(int l) {
        longitud = l;
    }
};



int main() {

    srand(time(0));
    int op;
    do {
        cout << "Ejercicio 1"<<endl;
        cout << "Ejercicio 2" << endl;
        cout << "Ejercicio 3" << endl;
        cout << "SALIR 4" << endl;

        cout << "Ingrese op: " << endl;
        cin >> op;
        cin.ignore();

        switch (op) {
        case 1: {
            Cuenta c("Juan", 100);
            c.ingresar(50);
            c.retirar(1);
            c.mostrarC();
            break;
        }
        case 2: {
            Persona p("Ana", 20, 'M');
            p.mostrar();
            cout << "Mayor edad: " << p.esMayorDeEdad() << endl;
            break;
        }
        case 3: {
            Password p(10);
            cout << "Password: " << p.getContrasena() << endl;
            cout << "Fuerte: " << p.esFuerte() << endl;
            break;
        }
        }
    } while (op != 4);
}