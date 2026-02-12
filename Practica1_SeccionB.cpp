// Practica1_SeccionB.cpp 
// 11/02/26

/* Ejercicio 2. Crea una clase llamada Persona que siga las siguientes condiciones: 
● Sus atributos son: nombre, edad, DNI, sexo (H hombre, M mujer), peso y altura.  
● Implementar varios constructores: 
  ○ Un constructor por defecto. 
  ○ Un constructor con el nombre, edad y sexo, el resto por defecto. 
  ○ Un constructor con todos los atributos como parámetro. 
● Los métodos que se implementaran son: 
  ○ calcularIMC(): calculara si la persona esta en su peso ideal (peso en 
kg/(altura^2  en m)), si esta fórmula devuelve un valor menor que 20, la 
función devuelve un -1, si devuelve un número entre 20 y 25 (incluidos), 
significa que esta por debajo de su peso ideal la función devuelve un 0  y si 
devuelve un valor mayor que 25 significa que tiene sobrepeso, la función 
devuelve un 1. Te recomiendo que uses constantes para devolver estos 
valores. 
● esMayorDeEdad(): indica si es mayor de edad, devuelve un booleano. 
comprobarSexo(char sexo): comprueba que el sexo introducido es correcto. Si no es 
correcto, sera H. No sera visible al exterior. 
● toString(): devuelve toda la información del objeto en formato string 
● generaDNI(): genera un número aleatorio de 8 cifras, genera a partir de este su 
número su letra correspondiente. Este método sera invocado cuando se construya el 
objeto. Puedes dividir el método para que te sea más fácil. No será visible al exterior. 
● Métodos set de cada parámetro, excepto de DNI. 

Ejercicio 3. Crea una clase llamada Password que siga las siguientes condiciones: 
● Que tenga los atributos longitud y contraseña . Por defecto, la longitud sera de 8. 
● Los constructores serán los siguiente: 
  ○ Un constructor por defecto. 
  ○ Un constructor con la longitud que nosotros le pasemos. Generara una 
contraseña aleatoria con esa longitud. 
● Los métodos que implementa serán: 
  ○ esFuerte(): devuelve un booleano si es fuerte o no, para que sea fuerte debe 
tener mas de 2 mayúsculas, mas de 1 minúscula y mas de 5 números. 
  ○ generarPassword():  genera la contraseña del objeto con la longitud que 
tenga. 
  ○ Método get para contraseña y longitud. 
  ○ Método set para longitud. */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
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

    //CONSTANTES IMC
    static const int PESO_BAJO = -1;
    static const int PESO_IDEAL = 0;
    static const int SOBREPESO = 1;

    //NO VISIBLE AL EXTERIOR
    void comprobarSexo(char s)
    {
        if (s == 'M' || s == 'm' || s == 'H' || s == 'h')
        {
            sexo = s;
        }
        else
        {
            sexo = 'H';
        }
    }
    //NO VISIBLE AL EXTERIOR
    void generarDNI()
    {
        int numero = rand() % 90000000 + 10000000;
        char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        char letra = letras[numero % 23];

        DNI = to_string(numero) + letra;
    }

public:
    // 1.- CONSTRUCTOR POR DEFECTO
    Persona()
    {
        this->nombre = "";
        this->edad = 0;
        this->sexo = 'H';
        this->peso = 0;
        this->altura = 0;
        generarDNI();
    }
    // 2.- CONSTRUCTOR CON NOMBRE ,EDAD Y SEXO EL RESTO POR DEFECTO
    Persona(string nombre_a, int edad_a, char sexo_a)
    {
        this->nombre = nombre_a;
        this->edad = edad_a;
        this->peso = 0;
        this->altura = 0;
        comprobarSexo(sexo_a);
        generarDNI();
    }
    // 3.- CONSTRUCTOR CON TODOS LOS ATRIBUTOS COMO PARAMETRO
    Persona(string nombre_b,int edad_b,char sexo_b,float peso_b,float altura_b)
    {
        this->nombre = nombre_b;
        this->edad = edad_b;
        this->peso = peso_b;
        this->altura = altura_b;
        comprobarSexo(sexo_b);
        generarDNI();
    }
    //METODO calcularIMC()
    int calcularIMC()
    {
        if (altura == 0) { return PESO_BAJO; }

        float IMC = peso / (altura * altura);

        if (IMC < 20)
        {
            return PESO_BAJO;
        }
        else
        {
            if (IMC >= 20 && IMC <= 25)
            {
                return PESO_IDEAL;
            }
            else
            {
                return SOBREPESO;
            }
        }
    }
    //METODO esMayorDeEdad()
    bool esMayorDeEdad()
    {
        if (edad >= 18)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //METODO toString() EN FORMATO STRING
    string toString()
    {
        return
            "\nNombre: " + nombre +
            "\nEdad: " + to_string(edad) +
            "\nDNI: " + DNI +
            "\nSexo: " + sexo +
            "\nPeso: " + to_string(peso) +
            "\nAltura: " + to_string(altura);
    }
    //METODOS SET
    void setNombre(string nuevoNombre) { nombre = nuevoNombre; }
    void setEdad(int nuevaEdad) { edad = nuevaEdad; }
    void setSexo(char nuevoSexo) { comprobarSexo(nuevoSexo); }
    void setPeso(float nuevoPeso) { peso = nuevoPeso; }
    void setAltura(float nuevaAltura) { altura = nuevaAltura; }

};

class Password
{
private:
    int longitud;
    string contrasena;

public:

    //CONSTRUCTOR POR DEFECTO
    Password()
    {
        longitud = 8;
        generarPassword();
    }

    //COSTRUCTOR POR LONGITUD
    Password(int longi)
    {
        longitud = longi;
        generarPassword();
    }

    //METODO generarPassword()
    void generarPassword()
    {
        contrasena = "";

        for (int i = 0; i < longitud; i++)
        {
            int tipo = rand() % 3;

            if (tipo == 0) 
            {
                contrasena += char(rand() % 10 + 48);
            }
            else if (tipo == 1) 
            {
                contrasena += char(rand() % 26 + 65);
            }
            else 
            {
                contrasena += char(rand() % 26 + 97);
            }
        }
    }

    //METODO esFuerte()
    bool esFuerte()
    {
        int mayus = 0;
        int minus = 0;
        int numeros = 0;

        for (int i = 0; i < contrasena.length(); i++)
        {
            if (contrasena[i] >= 'A' && contrasena[i] <= 'Z')
                mayus++;
            else if (contrasena[i] >= 'a' && contrasena[i] <= 'z')
                minus++;
            else if (contrasena[i] >= '0' && contrasena[i] <= '9')
                numeros++;
        }

        return (mayus > 2 && minus > 1 && numeros > 5);
    }

    //METODO Getters
    string getContrasena()
    {
        return contrasena;
    }

    int getLongitud()
    {
        return longitud;
    }

    //METODO set
    void setLongitud(int nuevaLongitud)
    {
        longitud = nuevaLongitud;
        generarPassword();
    }
};

void ejercicio2()
{
    srand(time(0));

    cout << "-- PERSONA 1 --" << endl;
    Persona p1 = Persona();
    cout << p1.toString() << endl;
    cout << "\n-------------------------------\n" << endl;

    cout << "-- PERSONA 2 --" << endl;
    Persona p2 = Persona("Luis", 17, 'H');
    cout << p2.toString() << endl;
    cout << "IMC: " << p2.calcularIMC() << endl;
    cout << "Mayor de edad: " << (p2.esMayorDeEdad() ? "Si" : "No") << endl;
    cout << "\n-------------------------------\n" << endl;

    cout << "-- PERSONA 3 --" << endl;
    Persona p3 = Persona("Ana", 22, 'M', 60, 1.65);
    cout << p3.toString() << endl;
    cout << "IMC: " << p3.calcularIMC() << endl;
    cout << "Mayor de edad: " << (p3.esMayorDeEdad() ? "Si" : "No") << endl;
    cout << "\n-------------------------------\n" << endl;
        
}

void ejercicio3()
{
    srand(time(0));

    Password p1 = Password();
    Password p2 = Password(12);

    cout << "Password 1: " << p1.getContrasena() << endl;
    cout << "Es fuerte: " << (p1.esFuerte() ? "Si" : "No") << endl;

    cout << "\nPassword 2: " << p2.getContrasena() << endl;
    cout << "Es fuerte: " << (p2.esFuerte() ? "Si" : "No") << endl;
}

int main()
{

    ejercicio2();
    ejercicio3();

    return 0;
    
}

