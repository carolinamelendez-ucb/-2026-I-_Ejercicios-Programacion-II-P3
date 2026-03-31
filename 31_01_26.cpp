#include <iostream>
#include <string>
using namespace std;


class Animal {
protected:
	string sonido;
public:
	Animal(string son) {
		this->sonido = son;
	}
	void hacerSonido() {
		cout << sonido << endl;
	}
};



class Gato : public Animal {

public:
	Gato(const string& sonido)
	:Animal(sonido)
	{
	}
	void mostrarGato() {
		Animal::hacerSonido();
	}
};


class Perro : public Animal {
public:
	Perro(const string& sonido)
	:Animal(sonido)
	{
	}

	void mostrarPerro() {
		Animal::hacerSonido();
	}
};




int main(){
	Gato* g1 = new Gato("Miau miau");
	g1->mostrarGato();

	Perro* p1 = new Perro("Guau guau");
	p1->mostrarPerro();
}
