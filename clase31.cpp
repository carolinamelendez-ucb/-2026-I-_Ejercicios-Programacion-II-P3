#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Animal {
private:
    string nombre;
    int edad;
    string raza;

public:
    Animal(const string& nombre, int edad, const string& raza)
        : nombre(nombre), edad(edad), raza(raza) {
    }

    virtual ~Animal() = default;

    const string& obtenerNombre() const { return nombre; }
    int obtenerEdad() const { return edad; }
    const string& obtenerRaza() const { return raza; }

    virtual void hacerSonido() const = 0;

    friend ostream& operator<<(ostream& os, const Animal& animal) {
        animal.mostrar(os);
        return os;
    }

protected:
    virtual void mostrar(ostream& os) const {
        os << "Nombre: " << nombre << "\n"
            << "Edad: " << edad << "\n"
            << "Raza: " << raza;
    }
};

class Perro : public Animal {
private:
    string tamanio;

public:
    Perro(const string& nombre, int edad, const string& raza, const string& tamanio)
        : Animal(nombre, edad, raza), tamanio(tamanio) {
    }

    void hacerSonido() const override {
        cout << "Guau guau\n";
    }

protected:
    void mostrar(ostream& os) const override {
        Animal::mostrar(os);
        os << "\nTamaño: " << tamanio;
    }
};

class Gato : public Animal {
public:
    Gato(const string& nombre, int edad, const string& raza)
        : Animal(nombre, edad, raza) {
    }

    void hacerSonido() const override {
        cout << "Miau miau\n";
    }
};

int main() {
    vector<unique_ptr<Animal>> listaAnimales;

    listaAnimales.push_back(make_unique<Perro>("Jefaso", 4, "Pastor aleman", "Grande"));
    listaAnimales.push_back(make_unique<Gato>("kiti", 3, "Siames"));
    listaAnimales.push_back(make_unique<Perro>("gema", 1, "Chihuahua", "Pequeño"));
    listaAnimales.push_back(make_unique<Gato>("shasha", 10, "Ragdoll"));

    for (const auto& animal : listaAnimales) {
        cout << *animal << "\n";
        animal->hacerSonido();
        cout << endl;
    }
    return 0;
}