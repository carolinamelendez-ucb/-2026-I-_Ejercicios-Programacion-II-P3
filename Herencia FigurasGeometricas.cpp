// Herencia FigurasGeometricas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

class FiguraGeometrica {
public:
    virtual float calcularArea() = 0;
    virtual ~FiguraGeometrica() {}
};

class Circulo : public FiguraGeometrica {
private:
    float radio;

public:
    Circulo(float r) {
        radio = r;
    }

    float calcularArea() {
        return 3.1416 * radio * radio;
    }
};

class Rectangulo : public FiguraGeometrica {
private:
    float base, altura;

public:
    Rectangulo(float b, float a) {
        base = b;
        altura = a;
    }

    float calcularArea() {
        return base * altura;
    }
};

class VectorFigurasGeometricas {
private:
    FiguraGeometrica* figuras[10];
    int cantidad;

public:
    VectorFigurasGeometricas() {
        cantidad = 0;
    }

    void agregarFigura(FiguraGeometrica* figura) {
        figuras[cantidad] = figura;
        cantidad++;
    }

    void mostrar() {
        for (int i = 0; i < cantidad; i++) {
            cout << "Figura " << i + 1
                << " Area: "
                << figuras[i]->calcularArea()
                << " m2" << endl;
        }
    }

    ~VectorFigurasGeometricas() {
        for (int i = 0; i < cantidad; i++) {
            delete figuras[i];
        }
    }
};

int main() {

    VectorFigurasGeometricas vectorFiguras;

    vectorFiguras.agregarFigura(new Circulo(4));
    vectorFiguras.agregarFigura(new Rectangulo(5, 10));
    vectorFiguras.agregarFigura(new Circulo(3));

    vectorFiguras.mostrar();

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
