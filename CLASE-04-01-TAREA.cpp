#include <iostream>
#include <string>
using namespace std;

class Figura {
public:
    virtual float calcularArea() = 0;
};

class Circulo : public Figura {
private:
    float radio;
public:
    Circulo(float radio) {
        this->radio = radio;
    }
    float calcularArea() override {
        return 3.1416 * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    float base;
    float altura;
public:
    Rectangulo(float base, float altura) {
        this->base = base;
        this->altura = altura;
    }
    float calcularArea() override {
        return base * altura;
    }
};

class VectorFiguras {
protected:
    Figura** figuras;
    int tamanio;
    int indice;
public:
    VectorFiguras(int tamanio) {
        this->tamanio = tamanio;
        this->indice = 0;
        this->figuras = new Figura* [tamanio];
    }
    void agregarFigura(Figura* newFigura) {
        figuras[indice] = newFigura;
        indice++;
    }
    void calcularTodasLasAreas() {
        for (int i = 0; i < indice; i++) {
            cout << "Figura " << i + 1 << " - Area: " << figuras[i]->calcularArea() << " m cuadrados" << endl;
        }
    }
};

int main()
{
    VectorFiguras f(5);
    f.agregarFigura(new Circulo(5));
    f.agregarFigura(new Rectangulo(4, 6));
    f.calcularTodasLasAreas();
}

