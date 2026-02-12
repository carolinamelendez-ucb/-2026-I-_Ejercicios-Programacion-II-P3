#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


class persona
{
private: 
	string nombre;
	int edad;
	int ci;
	char genero;
	int peso;
	float altura;
public:
	//contructores
	persona(string nombre, int edad, int ci, char genero, int peso, float altura)
	{
		this->nombre = nombre;
		this->edad = edad;
		this->ci = ci;
		this->genero = genero;
		this->peso = peso;
		this->altura = altura;
	}
	persona(string nombre, int edad, char genero)
	{
		this->nombre = nombre;
		this->edad = edad;
		this->genero = genero;
	}
	//gets
	int getpeso()
	{
		return peso;
	}

	float getaltura()
	{
		return altura;
	}

	int getedad()
	{
		return edad;
	}

	char getgenero()
	{
		return genero;
	}
	//sets
	void setgenero(char nuevae)
	{
		this->genero = nuevae;
	}

	void mostrar()
	{
		  
	}
};

class Password 
{
private:
	int longitud;
	string contrasena;
	void generarPassword() 
	{
		string caracteres = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string nuevaContra = "";

		for (int i = 0; i < longitud; i++) 
		{
			int indice = rand() % caracteres.length();
			nuevaContra += caracteres[indice];
		}
		this->contrasena = nuevaContra;
	}

public:
	Password() 
	{
		this->longitud = 8;
		generarPassword();
	}
	Password(int longitud) 
	{
		this->longitud = longitud;
		generarPassword();
	}
	bool esFuerte() 
	{
		int cuentaMayus = 0;
		int cuentaMinus = 0;
		int cuentaNum = 0;

		for (char c : contrasena) 
		{
			if (c >= 'A' && c <= 'Z') cuentaMayus++;
			else if (c >= 'a' && c <= 'z') cuentaMinus++;
			else if (c >= '0' && c <= '9') cuentaNum++;
		}

		return (cuentaMayus > 2 && cuentaMinus > 1 && cuentaNum > 5);
	}

	string getContrasena() 
	{ 
		return contrasena; 
	}
	int getLongitud() 
	{ 
		return longitud; 
	}
	void setLongitud(int nuevaLon) 
	{
		this->longitud = nuevaLon;
		generarPassword();
	}
};


int main()
{
	persona p1 = persona("mauricio", 18, 121212, 'g', 80, 1.91);
	cout << "peso " << p1.getpeso() << endl;
	cout << "altura" << p1.getaltura() << " en metros"<<endl;
	if (p1.getpeso() / (p1.getaltura() * p1.getaltura()) < 20)
	{
		cout << "-1" << endl;
	}
	else
	{
		if (p1.getpeso() / (p1.getaltura() * p1.getaltura()) >= 20 && (p1.getpeso() / (p1.getaltura() * p1.getaltura()) <= 25))
		{
			cout << "0" << endl;
		}
		else
		{
			if (p1.getpeso() / (p1.getaltura() * p1.getaltura()) > 25)
			{
				cout << "1" << endl;
			}
		}
	}
	cout << "edad" << p1.getedad() << endl;
	bool mayor = false;
	if (p1.getedad() >= 18)
	{
		mayor = true;
		cout << mayor << endl;
	}
	else
	{
		cout << mayor << endl;
	}
	cout << "genero " << p1.getgenero() << endl;
	if ((p1.getgenero() != 'm') && (p1.getgenero() != 'f'))
	{
		p1.setgenero('H');
		cout << "genero cambiado " << p1.getgenero() << endl;
	}

	srand(time(0));
	Password ps;
	cout << "Password 1 (8 chars): " << ps.getContrasena() << endl;
	cout << "Es fuerte? " << (ps.esFuerte() ? "Si" : "No") << endl;

	cout << "-----------------------------------" << endl;
	Password p2(15);
	cout << "Password 2 (15 chars): " << p2.getContrasena() << endl;
	if (p2.esFuerte()) 
	{
		cout << "Nivel de seguridad: ALTO" << endl;
	}
	else 
	{
		cout << "Nivel de seguridad: DEBIL (generando otra...)" << endl;
		p2.setLongitud(20);
		cout << "Nueva Password 2: " << p2.getContrasena() << endl;
	}
}
