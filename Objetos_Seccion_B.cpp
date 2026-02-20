#include <iostream>
#include <string>
#include <random>
using namespace std;


//Ejercicio 1
class Cuenta {
private:
	string titular;
	double	cantidad;
public:
	Cuenta(string titular, double cantidad)
	{
		this->titular = titular;
		this->cantidad = cantidad;
	}
	Cuenta(string titular)
	{
		this->titular = titular;
		this->cantidad = 10.5;
	}
	string getTitular()
	{
		return titular;
	}
	double getCantidad()
	{
		return cantidad;
	}
	void setTitular(string titular)
	{
		this->titular = titular;
	}
	void setCantidad(double cantidad)
	{
		this->cantidad = cantidad;
	}
	void mostrar()
	{
		cout << "Titular: " << titular << endl;
		cout << "Cantidad: " << cantidad << endl;
	}
	void ingresar(double cantidad)
	{
		if (cantidad >= 0)
		{
			this->cantidad += cantidad;
		}
	}
	void retirar(double cantidad)
	{
		this->cantidad -= cantidad;
		if (this->cantidad < 0)
		{
			this->cantidad = 0;
		}
	}
};
//Ejercicio 2
int generarDNI()
{
	srand(time(0));
	return rand() % 99999999 + 10000000;
}
class Persona {
private:
	string nombre;
	int edad;
	int DNI;
	char sexo;
	float peso;
	float altura;
public:
	Persona()
	{
		nombre = "Benjamin";
		edad = 19;
		DNI = generarDNI();
		sexo = 'H';
		peso = 75.2;
		altura = 1.75;
	}
	Persona(string nombre, int edad, char sexo)
	{
		this->nombre = nombre;
		this->edad = edad;
		DNI = generarDNI();
		this->sexo = sexo;
		peso = 85;
		altura = 1.60;
	}
	Persona(string nombre, int edad, int DNI, char sexo, float peso, float altura)
	{
		this->nombre = nombre;
		this->edad = edad;
		this->DNI = DNI;
		this->sexo = sexo;
		this->peso = peso;
		this->altura = altura;
	}
	float calcularIMC()
	{
		float imc = peso / (altura * altura);
		if (imc < 20)
		{
			return -1;
		}
		else if (imc >= 20 && imc <= 25)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	bool esMayorDeEdad()
	{
		if (edad >= 18)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void comprobarSexo()
	{
		if (sexo == 'H' || sexo == 'M')
		{
			sexo = sexo;
		}
		else
		{
			sexo = 'H';
		}
	}
	string toString()
	{
		return "Nombre: " + nombre + "\tEdad: " + to_string(edad) + "\tDNI: " + to_string(DNI) + "\tSexo: " + sexo + "\tPeso: " + to_string(peso) + "\tAltura: " + to_string(altura);
	}
	void setNombre(string nombre)
	{
		this->nombre = nombre;
	}
	void setEdad(int edad)
	{
		this->edad = edad;
	}
	void setSexo(char sexo)
	{
		this->sexo = sexo;
	}
	void setPeso(float peso)
	{
		this->peso = peso;
	}
	void setAltura(float altura)
	{
		this->altura = altura;
	}
	void mostrar()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
		cout << "DNI: " << DNI << endl;
		cout << "Sexo: " << sexo << endl;
		cout << "Peso: " << peso << endl;
		cout << "Altura: " << altura << endl;
	}
};

//Ejercicio 3

class Password {
private:
	int longitud;
	string contra;
public:
	string generarContra(int longitud)
	{
		string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
		string cont = "";
		for (int i = 0; i < longitud; i++)
		{
			cont += caracteres[rand() % caracteres.length()];
		}
		return cont;
	}
	Password()
	{
		longitud = 8;
		contra = "SAMPORTB";
	}
	Password(int longitud)
	{
		this->longitud = longitud;
		contra = generarContra(longitud);
	}
	bool esFuerte() {
		int mayusculas = 0;
		int minusculas = 0;
		int numeros = 0;
		for (int i = 0; i < contra.length(); i++)
		{
			if (contra[i] >= 'A' && contra[i] <= 'Z')
			{
				mayusculas++;
			}
			else if (contra[i] >= 'a' && contra[i] <= 'z')
			{
				minusculas++;
			}
			else if (contra[i] >= '0' && contra[i] <= '9')
			{
				numeros++;
			}
		}
		if (mayusculas >= 2 && minusculas >= 1 && numeros >= 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string getContra()
	{
		return contra;
	}
	int getLongitud()
	{
		return longitud;
	}
	void setLongitud(int longitud)
	{
		this->longitud = longitud;
	}
};

int main()
{
	Cuenta miCuenta = Cuenta("Benjamin", 1000);
	miCuenta.mostrar();
	cout << endl;
	miCuenta.ingresar(500);
	miCuenta.mostrar();
	cout << endl;
	miCuenta.retirar(2000);
	miCuenta.mostrar();
	cout << endl;
	Persona miPersona = Persona("Gabo",19,'X');
	miPersona.mostrar();
	miPersona.comprobarSexo();
	cout << endl;
	miPersona.mostrar();
	cout << endl;
	cout << "IMC: " << miPersona.calcularIMC() << endl;
	cout << "Mayor de edad: " << miPersona.esMayorDeEdad() << endl;
	cout << endl;
	Password miContra(10);
	cout << "Contrasena: " << miContra.getContra() << endl;
	cout << "Es fuerte: " << miContra.esFuerte() << endl;
}
