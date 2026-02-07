// Clase_02-07.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string.h>
// Notacion -> Pascal CASE -> MiPrimeraPalabra
// Notacion -> Camel CASE -> miPrimeraPalabra
// Notacion -> snake CASE -> mi_primera_palabra
using namespace std;

class Perro
{
private:
    // Atributos
    string nombre;
    int edad;
    string raza;
    int peso;
    string color;

public:
    //Construtor no olvidar
    Perro(string nombrep,int edadp,string razap,int pesop,string colorp) {
        nombre = nombrep;
        edad = edadp;
        raza = razap;
        peso = pesop;
        color = colorp;
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Raza: " << raza << endl;
        cout << "Peso: " << peso << endl;
        cout << "Color: " << color << endl;
    }
    void setPeso(int pesoNuevo)
    {
        this->peso = pesoNuevo;
    }
    // METODOS
    void ladrar()
    {
        cout << "El perro ladra" << endl;
    }
    void comer() {
        cout << "El perro come" << endl;
    }
    void dormir() {}
    void correr() {}
};
class Alumno
{
private:
    string nombre;
    int edad;
    int ci;
public:
  Alumno(string nombreA,int edadA,int ciA)
  { 
      this->nombre= nombreA;
      this->edad = edadA;
      this->ci = ciA;
  }

  void mostrar()
  {
      cout << "Nombre: " << nombre << endl;
      cout << "Edad: " << edad << endl;
      cout << "CI: " << ci << endl;

  }
  void setEdad(int nuevaEdad) {
      this->edad = nuevaEdad;

  }
};


int main()
{
   
    cout << "-------------------" << endl;
    cout << "Primer perro" << endl;
    Perro perro1 = Perro("Luck",3,"pastor aleman",30,"naranja");
    perro1.mostrar();
    cout << "-------------------" << endl;
    cout << "Segundo perro" << endl;
    Perro perro2 = Perro("Chacho",11,"buldog frances",20,"blanco");
    perro2.mostrar();
    perro2.setPeso(25);
    cout << "-----Nuevo peso----" << endl;
    perro2.mostrar();
   
    /*
    cout << "Primer alumno" << endl;
    Alumno alumno1 = Alumno("Jeremy", 20, 123);
    alumno1.mostrar();
    cout << "Segundo alumno" << endl;
    Alumno alumno2 = Alumno("Harold", 23, 456);
    alumno2.mostrar();
    alumno2.setEdad(21);
    cout << "Nueva edad: " << endl;
    alumno2.mostrar();
    */
  
    
}

