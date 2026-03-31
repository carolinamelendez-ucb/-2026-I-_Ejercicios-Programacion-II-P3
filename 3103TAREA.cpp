#include <iostream>
#include <string>

using namespace std;

class Animal { 
protected:
    string nombre;
    int edad;
    string raza;

public:
    Animal(const string& nombre, int edad, const string& raza)
        : nombre(nombre), edad(edad), raza(raza)
    {
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Raza: " << raza << endl;
    }

    virtual void hacerSonido() = 0;
};

class Perro : public Animal {
private:
    string tamanio;
public:
    Perro(const string& nombre, int edad, const string& raza, const string& tamanio)
        : Animal(nombre,edad,raza)
    {
        this->tamanio = tamanio;
    }

    void hacerSonido() {
        cout << "Guau guau" << endl;
    }
};

class Gato : public Animal {
public:
    Gato(const string& nombre, int edad, const string& raza)
        : Animal(nombre, edad, raza)
    {
    }

    void hacerSonido() {
        cout << "Miau miau" << endl;
    }
};


int main()
{
    Animal** listaAnimales = new Animal * [100]; //Tambien sirve para vectores

    listaAnimales[0] = new Perro("Rex", 4, "Pastor aleman", "Grande");
    listaAnimales[1] = new Gato("Luna", 3, "Siames");
    listaAnimales[2] = new Perro("Cloe", 1, "Chihuahua", "Pequeño");
    listaAnimales[3] = new Gato("Pelusa", 10, "Ragdoll");

    for (int i = 0;i != 4;i++) {
        listaAnimales[i]->mostrar();
        listaAnimales[i]->hacerSonido();
        cout << endl;
    }
}
