#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Persona
{
private:
    string nombre;
    int edad;
    int dni;
    char sexo;
    double peso;
    double altura;
    void comprobarSexo(char sexo)
    {
        if (sexo == 'H' || sexo == 'M')
        {
            this->sexo = sexo;
        }
        else
        {
            this->sexo = 'H';
        }
    }
    int generarDNI()
    {
        return rand() % 90000000 + 10000000;
    }
public:
    Persona()
    {
        nombre = "";
        edad = 0;
        dni = generarDNI();
        sexo = 'H';
        peso = 0;
        altura = 0;
    }
    Persona(string nombreP, int edadP, char sexoP)
    {
        this->nombre = nombreP;
        this->edad = edadP;
        dni = generarDNI();
        comprobarSexo(sexoP);
        peso = 0;
        altura = 0;
    }
    Persona(string nombreP, int edadP, char sexoP, double pesoP, double alturaP)
    {
        this->nombre = nombreP;
        this->edad = edadP;
        dni = generarDNI();
        this->sexo = sexoP;
        this->peso = pesoP;
        this->altura = alturaP;
    }

    int calcularIMC()
    {
        const int bajo_peso = -1;
        const int peso_ideal = 0;
        const int sobrepeso = 1;

        double imc = peso / (altura * altura);
        if (imc < 20)
        {
            return bajo_peso;
        }
        else
        {
            if (imc >= 20 && imc <= 25)
            {
                return peso_ideal;
            }
            else
            {
                return sobrepeso;
            }
        }
    }
    bool esMayorDeEdad()
    {
        return edad >= 18;
    }
    string toString()
    {
        return "Nombre: " + nombre + "\nEdad: " + to_string(edad) + "\nDNI: " + to_string(dni) +
            "\nSexo: " + string(1, sexo) + "\nPeso: " + to_string(peso) + "\nAltura: " + to_string(altura);
    }

    void setNombre(string nuevoNombre)
    {
        this->nombre = nuevoNombre;
    }
    void setEdad(int nuevaEdad)
    {
        this->edad = nuevaEdad;
    }
    void setSexo(char nuevoSexo)
    {
        this->sexo = nuevoSexo;
    }
    void setPeso(double nuevoPeso)
    {
        this->peso = nuevoPeso;
    }
    void setAltura(double nuevaAltura)
    {
        this->altura = nuevaAltura;
    }
    void mostrar()
    {
        cout << "NOMBRE: " << nombre << endl;
        cout << "EDAD: " << edad << endl;
        cout << "DNI: " << dni << endl;
        cout << "SEXO: " << sexo << endl;
        cout << "PESO: " << peso << endl;
        cout << "ALTURA: " << altura << endl;
    }
};
//EJERCICIO 3
class Password
{
private:
    int longitud;
    string contrasena;
public:
    Password()
    {
        longitud = 8;
        contrasena = "";
    }
    Password(int longitudP)
    {
        this->longitud = longitudP;
        generarPassword();
    }
    void generarPassword()
    {
        string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        contrasena = "";
        for (int i = 0; i < longitud; i++)
        {
            int indice = rand() % caracteres.length();
            contrasena = contrasena + caracteres[indice];
        }
    }
    bool esFuerte()
    {
        int mayus = 0;
        int minus = 0;
        int numeros = 0;
        for (int i = 0; i < contrasena.length(); i++)
        {
            if (contrasena[i] >= 'A' && contrasena[i] <= 'Z')
            {
                mayus++;
            }
            else
            {
                if (contrasena[i] >= 'a' && contrasena[i] <= 'z')
                {
                    minus++;
                }
                else
                {
                    if (contrasena[i] >= '0' && contrasena[i] <= '9')
                    {
                        numeros++;
                    }
                }
            }
        }
        if (mayus > 2 && minus > 1 && numeros > 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string getContrasena()
    {
        return contrasena;
    }
    int getLongitud()
    {
        return longitud;
    }
    void setLongitud(int nuevaLongitud)
    {
        longitud = nuevaLongitud;
        generarPassword();
    }
};

int main()
{
    //EJERCICIO 2
    srand(time(0));
    Persona persona1 = Persona("Mateo", 20, 'H', 64.1, 1.75);
    cout << persona1.toString() << endl;
    int imc = persona1.calcularIMC();
    cout << "Resultado IMC: " << imc << endl;
    if (persona1.esMayorDeEdad())
    {
        cout << "Es mayor de edad" << endl;
    }
    else
    {
        cout << "No es mayor de edad" << endl;
    }
    cout << "------------------------------------------" << endl;
    //EJERCICIO 3
    Password password1=Password(20);
    cout << "Password 1: " << password1.getContrasena() << endl;
    cout << "Es fuerte?: " << password1.esFuerte() << endl;
    return 0;
}
