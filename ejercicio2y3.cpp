#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string DNI;
    char sexo;
    int peso;
    int altura;

    void comprobarSexo(char s) {
        if (s != 'H' && s != 'M') {
            sexo = 'H';
        }
        else {
            sexo = s;
        }
    }

    string generaDNI() {
        string dni = "";
        dni += char('0' + (rand() % 10));
        dni += char('0' + (rand() % 10));
        dni += char('0' + (rand() % 10));
        dni += char('0' + (rand() % 10));
        dni += char('0' + (rand() % 10));
        dni += char('0' + (rand() % 10));
        dni += char('0' + (rand() % 10));
        dni += char('0' + (rand() % 10));
        dni += char('A' + (rand() % 26));
        return dni;
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

    Persona(string nom, int ed, char sex) {
        nombre = nom;
        edad = ed;
        peso = 0;
        altura = 0;
        comprobarSexo(sex);
        DNI = generaDNI();
    }

    Persona(string nom, int ed, char sex, int pes, int alt) {
        nombre = nom;
        edad = ed;
        peso = pes;
        altura = alt;
        comprobarSexo(sex);
        DNI = generaDNI();
    }

    int calcularIMC() {
        if (altura == 0) return 0;
        int imc = peso / (altura * altura);
        if (imc < 20) return -1;
        if (imc <= 25) return 0;
        return 1;
    }

    bool esMayorDeEdad() {
        return edad >= 18;
    }

    string toString() {
        string resultado = "";
        resultado += "NOMBRE: " + nombre + "\n";
        resultado += "EDAD: " + to_string(edad) + "\n";
        resultado += "DNI: " + DNI + "\n";
        resultado += "SEXO: " + string(1, sexo) + "\n";
        resultado += "PESO: " + to_string(peso) + " kg\n";
        resultado += "ALTURA: " + to_string(altura) + " m\n";
        return resultado;
    }

    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    string getDNI() { return DNI; }
    char getSexo() { return sexo; }
    int getPeso() { return peso; }
    int getAltura() { return altura; }

    void setNombre(string nom) { nombre = nom; }
    void setEdad(int ed) { edad = ed; }
    void setSexo(char sex) { comprobarSexo(sex); }
    void setPeso(int pes) { peso = pes; }
    void setAltura(int alt) { altura = alt; }
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

    Password(int lon) {
        longitud = lon;
        generarPassword();
    }

    void generarPassword() {
        contrasena = "";
        for (int i = 0; i < longitud; i++) {
            int tipo = rand() % 3;
            if (tipo == 0) {
                contrasena += char('0' + (rand() % 10));
            }
            else if (tipo == 1) {
                contrasena += char('A' + (rand() % 26));
            }
            else {
                contrasena += char('a' + (rand() % 26));
            }
        }
    }

    bool esFuerte() {
        int mayusculas = 0;
        int minusculas = 0;
        int numeros = 0;
        for (int i = 0; i < longitud; i++) {
            char c = contrasena[i];
            if (c >= 'A' && c <= 'Z') mayusculas++;
            if (c >= 'a' && c <= 'z') minusculas++;
            if (c >= '0' && c <= '9') numeros++;
        }
        if (mayusculas > 2 && minusculas > 1 && numeros > 5) {
            return true;
        }
        return false;
    }

    string getContrasena() { return contrasena; }
    int getLongitud() { return longitud; }

    void setLongitud(int lon) { longitud = lon; }
};

void ejercicio2() {
    cout << "EJERCICIO 2" << endl;
    cout << "-----------" << endl;

    Persona p1;
    cout << "PERSONA 1 (CONSTRUCTOR 1):" << endl;
    cout << p1.toString() << endl;

    Persona p2("Juan", 25, 'H');
    p2.setPeso(70.5);
    p2.setAltura(1.75);
    cout << "PERSONA 2 (CONSTRUCTOR 2):" << endl;
    cout << p2.toString() << endl;

    //int imc = p2.calcularIMC();
    cout << "IMC: " << p2.calcularIMC() << endl;

    cout << endl;

    if (p2.esMayorDeEdad()) cout << "MAYOR DE EDAD: SI" << endl;
    else cout << "MAYOR DE EDAD: NO" << endl;
    cout << endl;

    Persona p3("Maria", 17, 'M', 60.0, 1.65);
    cout << "PERSONA 3 (CONSTRUCTOR 3):" << endl;
    cout << p3.toString() << endl;

    //imc = p3.calcularIMC();
    /*if (imc == -1) cout << "IMC: PESO IDEAL (-1)" << endl;
    if (imc == 0) cout << "IMC: DEBAJO PESO IDEAL (0)" << endl;
    if (imc == 1) cout << "IMC: SOBREPESO (1)" << endl;*/
    cout <<"IMC: "<< p3.calcularIMC() << endl;

    cout << endl;

    if (p3.esMayorDeEdad()) cout << "MAYOR DE EDAD: SI" << endl;
    else cout << "MAYOR DE EDAD: NO" << endl;
    cout << endl;

    Persona p4("Carlos", 30, 'X', 80.0, 1.80);
    cout << "PRUEBA COMPROBAR SEXO (X -> H):" << endl;
    cout << p4.toString() << endl;
    cout << endl;
}

void ejercicio3() {
    cout << "EJERCICIO 3" << endl;
    cout << "-----------" << endl;

    Password pass1;
    cout << "CONSTRUCTOR POR DEFECTO:" << endl;
    cout << "CONTRASENA: " << pass1.getContrasena() << endl;
    cout << "LONGITUD: " << pass1.getLongitud() << endl;
    if (pass1.esFuerte()) cout << "ES FUERTE: SI" << endl;
    else cout << "ES FUERTE: NO" << endl;
    cout << endl;

    Password pass2(12);
    cout << "CONSTRUCTOR LONGITUD 12:" << endl;
    cout << "CONTRASENA: " << pass2.getContrasena() << endl;
    cout << "LONGITUD: " << pass2.getLongitud() << endl;
    if (pass2.esFuerte()) cout << "ES FUERTE: SI" << endl;
    else cout << "ES FUERTE: NO" << endl;
    cout << endl;

    Password pass3(20);
    cout << "CONSTRUCTOR LONGITUD 20:" << endl;
    cout << "CONTRASENA: " << pass3.getContrasena() << endl;
    cout << "LONGITUD: " << pass3.getLongitud() << endl;
    if (pass3.esFuerte()) cout << "ES FUERTE: SI" << endl;
    else cout << "ES FUERTE: NO" << endl;
    cout << endl;

    cout << "PRUEBA SETLONGITUD Y GENERAR PASSWORD:" << endl;
    pass3.setLongitud(25);
    pass3.generarPassword();
    cout << "CONTRASENA: " << pass3.getContrasena() << endl;
    cout << "LONGITUD: " << pass3.getLongitud() << endl;
    if (pass3.esFuerte()) cout << "ES FUERTE: SI" << endl;
    else cout << "ES FUERTE: NO" << endl;
    cout << endl;
}

int main() {
  
    ejercicio2();
    ejercicio3();

    return 0;
}