#include <iostream>

using namespace std;

class Animal {
protected:
    string raza;
    int tamanio;
    string sexo;
public:
    Animal(const string& raza, int tamanio, const string& sexo)
        : raza(raza), tamanio(tamanio), sexo(sexo)
    {
    }
    virtual void hacerSonido() = 0;
};

class Perro: public Animal{
public:
    Perro(const string& raza, int tamanio, const string& sexo)
        : Animal(raza,tamanio,sexo)
    {
    }
    void hacerSonido() {
        cout << "Guau Guau" << endl;
    }
};

class Gato : public Animal {
public:
    Gato(const string& raza, int tamanio, const string& sexo)
        : Animal(raza, tamanio, sexo)
    {
    }
    void hacerSonido() {
        cout << "Miau Miau" << endl;
    }
};

int main()
{
    Animal** misAnimales = new Animal * [10];
    misAnimales[0] = new Perro("Pastor Aleman", 10, "Hembra");
    misAnimales[1] = new Gato("Siames", 3, "Macho");
    misAnimales[0]->hacerSonido();
    misAnimales[1]->hacerSonido();
}
