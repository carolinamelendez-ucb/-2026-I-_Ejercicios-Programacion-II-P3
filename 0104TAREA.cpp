#include <iostream>
#include <string>

using namespace std;

class Figura {
protected:
    string nombre;
    int cantLados;

public:
    Figura(const string& nombre, int cantLados)
        : nombre(nombre), cantLados(cantLados)
    {
    }

    virtual void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Numero de lados: " << cantLados << endl;
    }

    virtual void calcularArea() = 0;
};

class Circulo : public Figura {
private:
    int radio;
public:
    Circulo(const string& nombre, int cantLados, int radio)
        : Figura(nombre, cantLados)
    {
        this->radio = radio;
    }

    void mostrar() {
        Figura::mostrar();
        cout << "Radio: " << radio << endl;
        cout << endl;
    }

    void calcularArea() {
        float area = radio * radio * 3.14;
        cout << "Area: " << area << endl;
    }
};

class Rectangulo : public Figura {
private:
    int largo;
    int ancho;
public:
    Rectangulo(const string& nombre, int cantLados, int largo, int ancho)
        : Figura(nombre, cantLados)
    {
        this->largo = largo;
        this->ancho = ancho;
    }

    void mostrar() {
        Figura::mostrar();
        cout << "Ancho: " << ancho << endl;
        cout << "Largo: " << largo << endl;
        cout << endl;
    }

    void calcularArea() {
        float area = largo * ancho;
        cout << "Area: " << area << endl;
    }
};

class VectorFiguras {
private:
    Figura** figuras;
    int tamanio;
    int indice;
public:
    VectorFiguras(int tamanio)
        : tamanio(tamanio)
    {
        indice = 0;
        figuras = new Figura * [tamanio];
    }

    void agregar(Figura* nuevaFigura) {
        if (indice < tamanio) {
            figuras[indice] = nuevaFigura;
            indice++;
        }
        else {
            cout << "No se pueden agregar mas figuras, limite alcanzado" << endl;
        }
    }

    void calcularTodasLasAreas() {
        for (int i = 0; i != indice; i++) {
            cout << "Figura " << i + 1 << " - ";
            figuras[i]->calcularArea();
            cout << endl;
        }
    }

    void mostrarVector() {
        for (int i = 0; i != indice; i++) {
            figuras[i]->mostrar();
        }
    }
};


int main()
{
    VectorFiguras* listaFiguras = new VectorFiguras(10);
    listaFiguras->agregar(new Circulo("Circulo 1", 0, 5));
    listaFiguras->agregar(new Rectangulo("Rectangulo 1", 4, 5, 4));
    listaFiguras->agregar(new Circulo("Circulo 2", 0, 3));
    listaFiguras->agregar(new Rectangulo("Rectangulo 2", 4, 1, 2));
    listaFiguras->agregar(new Rectangulo("Rectangulo 3", 4, 2, 3));
    listaFiguras->mostrarVector();
    listaFiguras->calcularTodasLasAreas();
}
