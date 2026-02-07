// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

//notacion -> Pascal CASE ->MiPrimeraPalabra
//NOTACION -> Camel CASE -> miPrimeraPalabra
//NOTACION -> snake CASE -> mi_primera_palabra

class consola {
private:
    string nombre;
    string tipo;
    int capacidad;
    int precio;

public:
    consola(string nombre, string tipo, int capacidad, int precio)
    {
        this->nombre = nombre;
        this->tipo = tipo;
        this->capacidad = capacidad;
        this->precio = precio;
    
    }
    void mostrar()
    {
        cout << "nombre: " << nombre << endl;
        cout << "tipo: " << tipo << endl;
        cout << "capacidad: " << capacidad << " gb" << endl;
        cout << "precio: " << precio << " bs" << endl;
    }
    void setprecio(int nuevaprecio)
    {
        this->precio = nuevaprecio;
    }
};

/*class bicicleta {
private:
    //atributos
    int velocidad;
    string color;
    string tipo;
    string marca;

    //metodos
public:
    bicicleta(int velocidad, string color, string tipo, string marca)
    {
        this->velocidad = velocidad;
        this->color = color;
        this->tipo = tipo;
        this->marca = marca;
    }
    void mostrar()
    {
        cout << "Velocidad: "<< velocidad << endl;
        cout << "Color: "<< color << endl;
        cout << "Tipo: "<< tipo << endl;
        cout << "Marca: "<< marca << endl;
    }
    void avanzar()
    {
        cout << "Bicicleta avanza... " << endl;
    }
    void detener() 
    {
        cout << "Bicicleta se detiene... " << endl;
    }
    void desmantelar() {}
    void cambiarCaja() {}
    void ejercitar() {}
    void setVelocidad(int nuevaVelocidad)
    {
        this->velocidad = nuevaVelocidad;
    }
};
*/

int main()
{
    consola consola1 = consola("Xbox", "series S", 500, 2500);
    consola1.mostrar();
    consola consola2 = consola("nintendo", "wii", 10, 1000);
    consola2.mostrar();
    consola2.setprecio(50);
    cout << "------- " << endl;
    consola2.mostrar();
    /*bicicleta bicicleta1 = bicicleta(10, "rojo", "montañera", "trek");
    bicicleta1.mostrar();
    
    bicicleta bicicleta2 = bicicleta(20, "naranja", "rural", "trek");
    bicicleta bicicleta3 = bicicleta(40, "verde","ciudad", "trek");
    bicicleta bicicleta4 = bicicleta(5, "negro","competencia", "trek");
    bicicleta4.mostrar();
    bicicleta4.setVelocidad(50);
    cout << "------- " << endl;
    bicicleta4.mostrar();*/
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
