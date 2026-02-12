#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    string DNI;
    char sexo;
    float peso;
    float altura;

    void comprobarSexo(char s) {
        if (s == 'H' || s == 'M')
            sexo = s;
        else
            sexo = 'H';
    }

public:
    Persona() {
        nombre = "";
        edad = 0;
        DNI = "00000000A";
        sexo = 'H';
        peso = 0;
        altura = 0;
    }
    Persona(string n, int e, char s) {
        nombre = n;
        edad = e;
        DNI = "00000000A";
        comprobarSexo(s);
        peso = 0;
        altura = 0;
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

        if (imc < 20)
            return -1;
        else if (imc >= 20 && imc <= 25)
            return 0;
        else
            return 1;
    }

    bool esMayorDeEdad() {
        return edad >= 18;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "DNI: " << DNI << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Peso: " << peso << endl;
        cout << "Altura: " << altura << endl;
    }

    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    void setSexo(char s) { comprobarSexo(s); }
    void setPeso(float p) { peso = p; }
    void setAltura(float a) { altura = a; }
};

int main() {

    Persona p1("joselito", 20, "3453678B", 'H', 70, 1.75);

    p1.mostrar();

    cout << "IMC: " << p1.calcularIMC() << endl;

    if (p1.esMayorDeEdad())
        cout << "Es mayor de edad" << endl;
    else
        cout << "No es mayor de edad" << endl;
}