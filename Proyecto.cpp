// Proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<string>

using namespace std;
class Bicicleta {
    //Atributos
private:
    int Vel;
    string Color;
    string tipo;
    //Acciones
public:
    Bicicleta(int Velo, string Col, string tip) {
        Vel = Velo;
        Color = Col;
        tipo = tip;
    }
    void mostrar() {
        cout << "Velocidad: " << Vel << endl;
        cout << "Color: " << Color << endl;
        cout << "Tipo: " << tipo << endl;
    }
    void setVel(int NVel)
    {
        Vel = NVel;
    }
    /*void Avanzar() {
        cout << "Bicicleta Avanza....." << endl;
    }
    void Detener();
    void Desmanterlar();
    void CambiarCaja();
    void Ejecutar();*/
};
int main()
{
    /* Bicicleta bici=Bicicleta();
     bici.Avanzar();
     bici.Avanzar();
     bici.Avanzar();
     bici.Avanzar();
     bici.Avanzar();*/
    Bicicleta bici = Bicicleta(123, "Marron", "Monaco");
    bici.mostrar();
    bici.setVel(23);
    bici.mostrar();
    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
