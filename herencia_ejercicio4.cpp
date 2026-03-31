// herencia_ejercicio4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string.h>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "Sonido de animal" << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() {
        cout << "Guau guau" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() {
        cout << "Miau miau" << endl;
    }
};

int main() {
    Animal* animales[2];

    animales[0] = new Perro();
    animales[1] = new Gato();

    for (int i = 0; i < 2; i++) {
        animales[i]->hacerSonido();
    }


}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
