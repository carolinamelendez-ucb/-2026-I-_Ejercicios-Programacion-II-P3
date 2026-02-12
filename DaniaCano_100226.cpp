// DaniaCano_100226.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Cuenta {
private:
    //atributos
    string titular;
    double cantidad;
public:
    //contructores
    Cuenta(string titular)
    {
        this->titular = titular;
        this->cantidad = 0;
    }
    Cuenta(string titular, double cantidad)
    {
        this->titular = titular;
        this->cantidad = cantidad;
    }
    //metodos get,set,mostar
    string gettitular(){
        return titular;
    }
    double getcantidad() {
        return cantidad;
    }
    void settitular(string titular) {
        this->titular = titular;
    }
    void setcantidad(double cantidad) {
        this->cantidad = cantidad;
    }
    void mostrar() {
        cout << endl;
        cout << "Titular: " << titular << endl;
        cout << "cantidad: " << cantidad << endl;
    }
    //metodos especiales
    void ingresar(double cantidad) {
        if (cantidad >= 0) {
            this->cantidad =this->cantidad + cantidad;
        }
    }
    void retirar(double cantidad) {
        this->cantidad = this->cantidad - cantidad;
        if (this->cantidad<=0)
        {
            this->cantidad = 0;
            cout << cantidad << endl;
        }
    }

};

class Persona {
private:
    string nombre;
    int edad;
    string DNI;
    char sexo;
    float peso;
    float altura;
    //constantes IMC
    // ponemos static xq pertenece a una clase (servira para todos los objetos)
    static const int bajopeso = -1;
    static const int pesoideal = 0;
    static const int sobrepeso = 1;
    //metodo privado
    void comprobarsexo(char sexo)
    {
        if(sexo=='H' || sexo == 'M')
        {
            this->sexo = sexo;
        }
        else {
            
            this->sexo = 'H';
        }
    }
    void generarDNI() {
        int numero;
        char letra ;
        
        numero = rand() % 90000000 + 10000000;
        char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        letra = letras[numero % 27];
        DNI = to_string(numero) + letra;
    }

public:
    //contructores
    Persona() {
        nombre="";
        edad=0;
        generarDNI();
        sexo='H';
        peso=0;
        altura=0;
    }
    Persona(string nombre, int edad, char sexo) {
        this->nombre = nombre;
        this->edad = edad;
        generarDNI();
        comprobarsexo(sexo);
        this->peso = 0;
        this->altura = 0;
    }
    Persona(string nombre, int edad, char sexo, float peso, float altura) {
        this->nombre = nombre;
        this->edad = edad;
        generarDNI();
        comprobarsexo(sexo);
        this->peso = peso;
        this->altura = altura;
    }
    //METODOS
    int calcularMCI() {

        float imc;
        if (altura == 0) {
            return bajopeso;
        }
        imc = peso / (altura * altura);
        if (imc < 20)
        { return bajopeso; }
        else {
            if (imc >= 20 && imc <= 25) 
                 { return pesoideal; }
            else {
                 return sobrepeso;
            }
        }
    }
    bool esMayorDeEdad()
    {
        return edad >= 18;
    }
    string toString() {
        return "Nombre: " + nombre + "\nEdad: " + to_string(edad) +
            "\nDNI: " + DNI + "\nSexo: "+ string(1,sexo) + "\nPeso: " + to_string(peso)+
            "\nAltura: "+ to_string(altura);

    }

    //SETS
    void setnombre(string nombre) {
        this->nombre = nombre;
    }
    void setedad(int edad) {
        this->edad = edad;
    }
    void setsexo(char sexo) {
        comprobarsexo(sexo);
    }
    void setpeso(float peso) {
        this->peso = peso;
    }
    void setaltura(float altura) {
        this->altura = altura;
    }
};

class Password {
private:
    int longitud;
    string contrasena;
public:
    void generarpass()
    {
        int indice;
        string todo = "ABCDEFGHIJKLMNOPQRSTUVWXYZbcdefghijklmnopqrstuvwxyz0123456789";
        contrasena = "";
        for (int i = 0; i < longitud; i++)
        {
            indice = rand() % todo.length();
            contrasena = contrasena + todo[indice];
        }

    }
    Password()
    {
        this->longitud = 8;
        generarpass();
    }
    Password(int longitud)
    {
        this->longitud = longitud;
        generarpass();
    }
    //METODOS
    bool esfuerte()
    {
        int contM = 0;
        int contm = 0;
        int contN = 0;
        for (int i = 0; i < contrasena.length(); i++)
        {
            if (isupper(contrasena[i]))
            {
                contM++;     //verificar si es mayuscula
            }
            else
            {
                if (islower(contrasena[i]))
                {
                    contm++; //verificar si es minuscula
                }
                else {
                    if (isdigit(contrasena[i])) contN++; //verificar si es numero
                }
                
            }
        }
        if (contM>2 && contm>1 && contN>5)
        {
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
        generarpass();
    }
};

void ejercicio1() {
    cout << "_____________EJERCICIO 1 ______________________________________________" << endl;
    Cuenta cuenta1 = Cuenta("JUAN");
    Cuenta cuenta2 = Cuenta("Martha", 1300);
    cuenta1.mostrar();
    cuenta2.mostrar();

    if (cuenta2.getcantidad() > 1000)
    {
        cout << "La cuenta2 tiene mas 1000" << endl;
    }
    cuenta1.settitular("Esteban");
    double cant;
    cout << "Ingrese la cantidad a sumar a la cuenta 1" << endl;
    cin >> cant;
    cuenta1.ingresar(cant);
    cout << "Ingrese la cantidad a retirar a la cuenta 2" << endl;
    cin >> cant;
    cuenta2.retirar(cant);
    cuenta1.mostrar();
    cuenta2.mostrar();
}

void ejercicio2()
{
    cout << "___________________________-EJERCICIO 2____________________" << endl;
    srand(time(NULL));
    Persona persona1 = Persona();
    Persona persona2 = Persona("Juliana", 15,'M');
    Persona persona3 = Persona("Juan", 20,'H',55.1,1.55);

    cout << "Persona 1 " << endl;
    cout << persona1.toString() << endl;
    cout << endl;
    cout << "Persona 2 " << endl;;
    cout << persona2.toString() << endl;
    cout << endl;
    cout << "Persona 3 " << endl;;
    cout << persona3.toString() << endl;
    cout << endl;

    persona2.setpeso(70);
    persona2.setaltura(1.52);

    cout << "Persona 2 " << endl;;
    cout << persona2.toString() << endl;
    cout << "En -1=(bajo de peso), 0=(peso ideal), 1=(sobrepeso)" << endl;
    cout << "MCI de persona 2 es: " << persona2.calcularMCI() << endl;

    if (persona2.esMayorDeEdad()) {
        cout << "Perosna 2 Es mayor de edad" << endl;
    }
    else {
        cout << "Persona 2 Es menor de edad" << endl;
    }
    

}
void ejercicio3()
{
    cout << "___________________--EJERCICIO 3________________________-" << endl;
    srand(time(NULL));

    Password password1=Password();
    Password password2=Password(12);
    cout << "Si sale 0 no es segura, si sale 1 la contraseña es fuerte" << endl;
    cout << "Password1: " << password1.getContrasena() << endl;
    cout << "La contrasena es fuerte? " << password1.esfuerte() << endl;
    cout << endl;
    cout << "Password2: " << password2.getContrasena() << endl;
    cout << "Es fuerte? " << password2.esfuerte() << endl;
    //cambiar longitud de contraseña 1
    password1.setLongitud(15);
    cout << endl;
    cout << "Modificamios contraseña 1" << endl;
    cout << "Nueva longitud: " << password1.getLongitud()<< endl;
    cout << "Nueva contrasena: " << password1.getContrasena() << endl;

    cout << "Password1: " << password1.getContrasena() << endl;
    cout << "La contrasena es fuerte? " << password1.esfuerte() << endl;
    
}

int main()
{
    ejercicio1();
    cout << endl;
    ejercicio2();
    cout << endl;
    ejercicio3();
}

