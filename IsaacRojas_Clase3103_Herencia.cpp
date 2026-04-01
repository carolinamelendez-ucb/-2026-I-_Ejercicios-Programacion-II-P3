#include <iostream>
#include <string>
using namespace std;
class Animal {
protected:
    string especie;
public:
    virtual void haceElSonido() {
        cout << "El animal hace un sonido" << endl;
    }

    virtual ~Animal() {}
};

class Perro : public Animal {
public:
    void haceElSonido() override {
        cout << "Guau, guau" << endl;
	}
};
class Gato : public Animal {
public:
    void haceElSonido() override {
        cout << "Miau, miau" << endl;
	}
};
int main()
{
    Animal* animales[2];
    animales[0] = new Perro();
    animales[1] = new Gato();
    for (int i = 0; i < 2; i++) {
        animales[i]->haceElSonido();
    }
    for (int i = 0; i < 2; i++) {
        delete animales[i];
    }

    return 0;
}