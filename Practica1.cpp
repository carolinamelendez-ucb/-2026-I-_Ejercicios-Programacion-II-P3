#include <iostream>
#include <string>
using namespace std;

class Cuenta {
private:
    string titular;
    double cantidad;

public:
    Cuenta(string titular, double cantidad) {
        this->titular = titular;
        this->cantidad = cantidad;
    }

    Cuenta(string titular) {
        this->titular = titular;
        this->cantidad = 0;
    }

    string getTitular() {
        return titular;
    }

    double getCantidad() {
        return cantidad;
    }

    void setTitular(string titular) {
        this->titular = titular;
    }

    void setCantidad(double cantidad) {
        this->cantidad = cantidad;
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
        if (cantidad - cantidadRetirada < 0) {
            cantidad = 0;
        }
        else {
            cantidad = cantidad - cantidadRetirada;
        }
    }
};

class Persona {
private:
    string nombre;
    int edad;
    string DNI;
    char sexo;
    double peso;
    double altura;

    void comprobarSexo(char sexo) {
        if (sexo == 'H' || sexo == 'M') {
            this->sexo = sexo;
        }
        else {
            this->sexo = 'H';
        }
    }

    void generaDNI() {
        DNI = "9395629CBBA";  
    }

public:
    Persona() {
        nombre = "";
        edad = 0;
        sexo = 'H';
        peso = 0;
        altura = 0;
        generaDNI();
    }

    Persona(string nombre, int edad, char sexo) {
        this->nombre = nombre;
        this->edad = edad;
        peso = 0;
        altura = 0;
        comprobarSexo(sexo);
        generaDNI();
    }

    Persona(string nombre, int edad, char sexo, double peso, double altura) {
        this->nombre = nombre;
        this->edad = edad;
        this->peso = peso;
        this->altura = altura;
        comprobarSexo(sexo);
        generaDNI();
    }

    double calcularIMC() {
        if (altura == 0) {return 0; }
        double imc = peso / (altura * altura);
        if (imc < 20) { return -1; }
        else if (imc <= 25) { return 0; }
        else { return 1; }
    }

    bool esMayorDeEdad() {
        if (edad >= 18) {
            return true;
        }
        else {
            return false;
        }
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "DNI: " << DNI << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Peso: " << peso << endl;
        cout << "Altura: " << altura << endl;
    }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    void setSexo(char sexo) { comprobarSexo(sexo); }
    void setPeso(double peso) { this->peso = peso; }
    void setAltura(double altura) { this->altura = altura; }
};

class Password {
private:
    int longitud;
    string contraseña;

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
        contraseña = "Contra123";  
    }

    bool esFuerte() {
        int mayus = 0;
        int minus = 0;
        int nums = 0;

        for (int i = 0; i < contraseña.length(); i++) {
            if (contraseña[i] >= 'A' && contraseña[i] <= 'Z')
                mayus++;
            else if (contraseña[i] >= 'a' && contraseña[i] <= 'z')
                minus++;
            else if (contraseña[i] >= '0' && contraseña[i] <= '9')
                nums++;
        }

        if (mayus > 2 && minus > 1 && nums > 5)
            return true;
        else
            return false;
    }

    string getContraseña() {
        return contraseña;
    }

    int getLongitud() {
        return longitud;
    }

    void setLongitud(int longitud) {
        this->longitud = longitud;
        generarPassword();
    }

    void mostrar() {
        cout << "Password: " << contraseña << endl;
        cout << "Longitud: " << longitud << endl;
    }
};

int main() {

    cout << "----- CUENTA -----" << endl;
    Cuenta c1("Juan", 100);
    c1.ingresar(50);
    c1.retirar(200);
    c1.mostrar();
    cout << endl;
    cout << "----- PERSONA -----" << endl;
    Persona p1("Ana", 25, 'M', 60, 2);
    p1.mostrar();
    cout << "IMC: " << p1.calcularIMC() << endl;
    cout << "Mayor de edad: " << p1.esMayorDeEdad() << endl;
    cout << endl;
    cout << "----- PASSWORD -----" << endl;
    Password pass(8);
    pass.mostrar();
    cout << "Es fuerte: " << pass.esFuerte() << endl;
}