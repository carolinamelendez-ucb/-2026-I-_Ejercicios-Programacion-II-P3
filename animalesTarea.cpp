#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string nombre;
    int edad;
    string color;
public:
    Animal(const string& nombre, int edad, const string& color)
        : nombre(nombre), edad(edad), color(color)
    {
    }
    
    virtual void hacerSonido() = 0;
    
    virtual ~Animal() {}
};

class Perro: public Animal {
private:
    string dueno;
public:
    Perro(const string& nombre, int edad, const string& color, const string& dueno)
        : Animal(nombre, edad, color), dueno(dueno)
    {
    }
    
    void hacerSonido() {
        cout << "Guau guau" << endl;
    }
};

class Gato: public Animal {
private:
    bool esIndependiente;
public:
    Gato(const string& nombre, int edad, const string& color, bool esIndependiente)
        : Animal(nombre, edad, color), esIndependiente(esIndependiente)
    {
    }
    
    void hacerSonido() {
        cout << "Miau miau" << endl;
    }
};

int main()
{
    Animal* misAnimales[4];
    
    misAnimales[0] = new Perro("Rex", 5, "Cafe", "Juan");
    misAnimales[1] = new Gato("Luna", 3, "Blanco", true);
    misAnimales[2] = new Perro("Max", 2, "Negro", "Maria");
    misAnimales[3] = new Gato("Simba", 4, "Naranja", false);
    
    for(int i = 0; i < 4; i++) {
        misAnimales[i]->hacerSonido();
    }
    
    for(int i = 0; i < 4; i++) {
        delete misAnimales[i];
    }
}