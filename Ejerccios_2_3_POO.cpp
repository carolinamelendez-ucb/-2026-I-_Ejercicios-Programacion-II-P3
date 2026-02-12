#include <iostream>
#include <string>

using namespace std;
//  --- Ejercicio 2 ---
class Persona {
private:
    string nombre;
    int edad;
    string DNI;
    char sexo;
    float peso;
    float altura;
    void generarDNI() {
        srand(time(NULL));
        int num = rand() % 99999999;
        DNI = to_string(num);
        int letra;
        letra = 97 + rand() % (122 - 97);
        DNI += letra;
    }
public:
    Persona() {
        this->altura = 0;
        this->edad = 0;
        this->nombre = "";
        this->peso = 0;
        this->sexo = 'H';
        void generarDNI();
    }
    Persona(string nombre, int edad, char sexo) {
        this->edad = edad;
        this->nombre = nombre;
        this->sexo = sexo;
        this->altura = 0;
        this->DNI = "";
        this->peso = 0;
    }
    Persona(string nombreP, int edadP, string DNIP, char sexoP, float pesoP, float alturaP) {
        this->altura = alturaP;
        this->DNI = DNIP;
        this->edad = edadP;
        this->nombre = nombreP;
        this->peso = pesoP;
        this->sexo = sexoP;
    }
    bool calcularIMC(float peso,float altura) {
        float imc = (peso / pow(altura , 2));
        if (imc <20)
        {
            return -1;
        }
        if (imc>=20 || imc<=25) {
            return 0;
        }
        if(imc >25){
            return 1;
        }
    }
    bool esMayorDeEdad(int edad) {
        if (edad>=18)
        {
            return true;
        }
        else {
            return false;
        }
    }
    void comprobarSexo(char sexo) {
        if (sexo !='H' && sexo !='M') {
            this->sexo = 'H';
        }
        else {
            this->sexo = sexo;
        }
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Peso: " << peso << endl;
        cout << "altura: " << altura << endl;
    }
 
    string setNombre(string nuevoNombre) {
        this->nombre = nuevoNombre;
    }
    void setEdad(int nuevaedad) {
        this->edad = nuevaedad;
    }
    void setSexo(char nuevosexo) {
        this->sexo = nuevosexo;
    }
    void setPeso(float nuevoPeso) {
        this->peso = nuevoPeso;
    }
    void setAltura(float nuevaAltura) {
        this->altura = nuevaAltura;
    }

};

//  --- Ejercico 3 ---
class Password {
private:
    int contraseña;
    int longitud;
public:
    Password(int contraseñaP, int longitudP) {
        this->contraseña = contraseñaP;
        this->longitud = 8;
    }
    Password(int longitudP) {
        this->longitud = 8;

    }
    bool esFuerta() {
    }
    void generarPassword() {

    }
    int getContraseña() {
        return contraseña;
     }
    int getLongitud() {
        return longitud;
    }
    void setLongitud(int longitudN) {
        this->longitud = longitudN;
    }
};
int main()
{
    srand(time(0));
    Persona persona1 = Persona("pepe",24,'M');
    persona1.calcularIMC(85, 1.75);
    persona1.comprobarSexo('M');
    persona1.esMayorDeEdad(24);
    persona1.mostrar();
}