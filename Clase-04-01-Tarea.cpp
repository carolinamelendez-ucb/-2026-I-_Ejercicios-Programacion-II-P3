#include <string>
#include <iostream>
using namespace std;

class Figura
{
public:
    virtual float calcularArea() = 0;
    virtual ~Figura() {}
};

class Circulo : public Figura
{
private:
    float radio;
public:
    Circulo(float radio)
    {
        this->radio = radio;
    }
    float calcularArea()
    {
        return 3.1416 * radio * radio;
    }
};

class Rectangulo : public Figura
{
private:
    float base;
    float altura;
public:
    Rectangulo(float base, float altura)
    {
        this->base = base;
        this->altura = altura;
    }
    float calcularArea()
    {
        return base * altura;
    }
};

class VectorFiguras
{
private:
    Figura** figuras;
    int tamanio;
    int indice;
public:
    VectorFiguras(int tamanio)
    {
        this->tamanio = tamanio;
        indice = 0;
        figuras = new Figura * [tamanio];
    }
    void agregar(Figura* f)
    {
        if (indice < tamanio)
        {
            figuras[indice] = f;
            indice++;
        }
    }
    void calcularTodasLasAreas()
    {
        for (int i = 0; i < indice; i++)
        {
            cout << "Figura " << i + 1
                << " - Area: "
                << figuras[i]->calcularArea()
                << " m2" << endl;
        }
    }
};

int main()
{
    VectorFiguras vf(5);

    vf.agregar(new Circulo(4));
    vf.agregar(new Rectangulo(5, 3));
    vf.agregar(new Circulo(2));

    vf.calcularTodasLasAreas();

    return 0;
}