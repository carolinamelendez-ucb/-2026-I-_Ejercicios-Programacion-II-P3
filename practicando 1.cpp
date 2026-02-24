// practicando 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//crtl + d es para duplicar lineas

#include <iostream>
#include <string>
using namespace std;
/// paso por valor --> copia la variable en una nueva pos de men
/// paso por referencia --> se envia la pos de mem para editar su valor directo
/**Modele una clase Propietario con los atributos : nombre, dni y edad.
Modele una clase Casa con los atributos : dirección, precio y un objeto Propietario.
La clase Casa debe implementar el método esPropietarioValido(), que retorne true si el propietario es mayor de edad.
En el main(), cree una casa con su propietario y muestre si la titularidad es válida**/

class Propietario {
private:
    string nombre;
    int dni;
    int edad;
public:
    Propietario(string nombre, int dni, int edad) {
        this->nombre = nombre;
        this->dni = dni;
        this->edad = edad;
    }
    int setEdad() {
        return edad;
   }
};
class Casa {
private:
    int direccion;
    int precio;
    Propietario* propietario;
public:
    Casa(int direccion, int precio, Propietario *propietario) {
        this->direccion = direccion;
        this->precio = precio;
        this->propietario = propietario;
    }
    bool setEsvalido() {
        int verdad = true;
        if (propietario->setEdad() > 45) {
            verdad = true;
        }
        else {
            verdad = false;
        }
        return verdad;
    }
};

int main()
{
   
    cout << "----------------------------------------------" << endl;
    
    //con puntero se usa flecha pera definir.
    Propietario *pedroJuan = new Propietario("pedroJuan", 123, 43);
    Casa* casa1 = new Casa(14, 13000, pedroJuan);
    if (casa1->setEsvalido() == true) {
        cout << "el propietario es valido" << endl;
    }
    else {
        cout << "el propietario no es valido" << endl;
    }
    ///cual es el criterio podemos usar el criterio de los punteros;
    cout << "----------------------------------------------" << endl;
    int y = 10;
    cout << "Dirreccion de meoria " << &y << endl;////direccion de memoria
    cout << "valor de y: " << y << endl;
    cout << "----------------------------------------------"<< endl;



    int *yPr = &y; /// * es para que guarde la direccion de memoria en una variable y usar esa variable activamente
    cout << "valor de yPr: " << yPr << endl;///direccion de memoria de y
    cout << "valor de *yPr: " << *yPr << endl;// valor =20 extraer lo que contiene esa direccion de memoria
    cout << "valor de &yPr: " << &yPr << endl;///direccion de memoria nueva
}


