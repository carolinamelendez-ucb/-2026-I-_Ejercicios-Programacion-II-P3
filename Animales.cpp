#include <iostream>
using namespace std;
class Animal {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
};
class Perro : public Animal {
public:
    void hacerSonido(){
        cout << "guau guau" << endl;
    }
};
class Gato : public Animal {
public:
    void hacerSonido() {
        cout << "miau miau" << endl;
    }
};

int main() {
    Animal* animales[3];
    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Perro();

    for (int i = 0; i < 3; i++) {
        animales[i]->hacerSonido();
    }
}