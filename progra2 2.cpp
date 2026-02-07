// progra2 2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
using namespace std;
#include <string>

//Notacion --> Pascal CASE -->MiPrimeraPalabra
//Notacion --> Camel CASE --> miPrimeraPalabra
//Notacion --> Snake CASE  --> mi_primera_palabra


/*class Bicicleta {
    //Atributos
private:
    int velocidad;
    string color;
    string tipo;
    string marca;
public:
    Bicicleta(int velocidadb, string colorb, string tipob, string marcab)
    {
        velocidad = velocidadb;
        color = colorb;
        tipo = tipob;
        marca = marcab;
    }
    void mostrar()
    {
        cout << "velocidad:" << velocidad << endl;
        cout << "color" << color << endl;
        cout << "tipo:" << tipo << endl;
        cout << "marca:" << marca << endl;

    }
    //Metodos
    void avanzar() {
        cout << "Bicicleta Avanza 1 espacio " << endl;
    }
    void detener() {
        cout << "Bicicleta empieza a detenerse" << endl;
    }
    void desmantelar() {

    }
    void cambiarCaja() {

    }
    void ejercitar() {

    }


};

int main()
{
    Bicicleta bicicleta1 = Bicicleta();
    bicicleta1.avanzar();
    bicicleta1.avanzar();
    bicicleta1.avanzar();
    bicicleta1.detener();
    cout << "bici1" << endl;
    Bicicleta bicicleta1 = Bicicleta(10, "rojo", "montañera", "trek");
}


class alumno
{
private:
    string nombre;
    int edad;
    int ci;
public:
    alumno(string nombrea, int edada, int cia)
    {
        nombre = nombrea;
        edad = edada;
        ci = cia;
    }
    void mostrar()
    {
        cout << "nombre: " << nombre << endl;
        cout << "edad: " << edad << endl;
        cout << "ci: " << ci << endl;
    }

    void setedad(int nueva)
    {
        this->edad = nueva;
    }

    void setci(int nuevac)
    {
        this->ci = cia;
    }
};

int main()
{
    alumno alumno1 = alumno("marco", 18, 1414141);
    alumno alumno2 = alumno("isaac", 19, 121323);
    //alumno1.mostrar();
    alumno2.mostrar();
    alumno2.setedad(21);
    alumno2.mostrar();
    alumno2.setci
}*/


class cel 
{
private:
    string marca;
    int anio;
public:
    cel(string marcaa, int anioa)
    {
        marca = marcaa;
            anio = anioa;
    }
    void mostrar()
    {
        cout << "marca: " << marca << endl;
        cout << "anio: " << anio << endl;
    }

    void setmarca(string nueva)
    {
        this->marca = nueva;
    }
        
};



int main()
{
    cel celu1 = cel("samsung", 2025);
    cel celu2 = cel("apple", 2024);
    celu1.mostrar();
    celu1.setmarca("nokia");
    celu1.mostrar();
}







// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
