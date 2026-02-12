#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;
    string DNI;
    char sexo;
    float peso;
    float altura;

    void comprobarSexo(char s)
    {
        if (s == 'H' || s == 'M')
            sexo = s;
        else
            sexo = 'H';
    }

    string generaDNI()
    {
        int numero = 12345678 + edad;
        char letra = 'A' + (numero % 26);
        return to_string(numero) + letra;
    }

public:
    Persona()
    {
        nombre = "";
        edad = 0;
        sexo = 'H';
        peso = 0;
        altura = 1;
        DNI = generaDNI();
    }

    Persona(string nombre, int edad, char sexo)
    {
        this->nombre = nombre;
        this->edad = edad;
        comprobarSexo(sexo);
        peso = 0;
        altura = 1;
        DNI = generaDNI();
    }

    Persona(string nombre, int edad, char sexo, float peso, float altura)
    {
        this->nombre = nombre;
        this->edad = edad;
        comprobarSexo(sexo);
        this->peso = peso;
        this->altura = altura;
        DNI = generaDNI();
    }

    int calcularIMC()
    {
        float imc = peso / (altura * altura);

        if (imc < 20)
            return -1;
        else if (imc <= 25)
            return 0;
        else
            return 1;
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
            "\nSexo: " + sexo +
            "\nPeso: " + to_string(peso) +
            "\nAltura: " + to_string(altura) + "\n";
    }

    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    void setSexo(char s) { comprobarSexo(s); }
    void setPeso(float p) { peso = p; }
    void setAltura(float a) { altura = a; }
};
class Password
{
private:
    int longitud;
    string contrasena;

    string generarPassword()
    {
        string base = "Aa1Bb2Cc3Dd4Ee5Ff6Gg7Hh8Ii9Jj0";
        string pass = "";

        for (int i = 0; i < longitud; i++)
        {
            pass += base[i % base.length()];
        }

        return pass;
    }

public:
    Password()
    {
        longitud = 8;
        contrasena = generarPassword();
    }

    Password(int longitud)
    {
        this->longitud = longitud;
        contrasena = generarPassword();
    }

    bool esFuerte()
    {
        int may = 0, min = 0, num = 0;

        for (int i = 0; i < contrasena.length(); i++)
        {
            if (contrasena[i] >= 'A' && contrasena[i] <= 'Z')
                may++;
            else if (contrasena[i] >= 'a' && contrasena[i] <= 'z')
                min++;
            else if (contrasena[i] >= '0' && contrasena[i] <= '9')
                num++;
        }

        return (may > 2 && min > 1 && num > 5);
    }

    string getContrasena() { return contrasena; }
    int getLongitud() { return longitud; }

    void setLongitud(int l)
    {
        longitud = l;
        contrasena = generarPassword();
    }
};
void ejercicio2()
{
    cout << "EJERCICIO 2" << endl;

    Persona p("Joel", 20, 'H', 70, 1.75);

    cout << p.toString();
    cout << "IMC: " << p.calcularIMC() << endl;
    cout << "Mayor de edad: " << p.esMayorDeEdad() << endl;
    cout << endl;
}

void ejercicio3()
{
    cout << "EJERCICIO 3" << endl;

    Password p1;
    Password p2(12);

    cout << "Password 1: " << p1.getContrasena() << endl;
    cout << "Es fuerte: " << p1.esFuerte() << endl;

    cout << "Password 2: " << p2.getContrasena() << endl;
    cout << "Es fuerte: " << p2.esFuerte() << endl;
}

int main()
{
    ejercicio2();
    ejercicio3();
    return 0;
}
