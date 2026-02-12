// Ejercicios_tarea2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

class Persona
{
private:
	string nombre;
	int edad;
	int dni;
	char sexo;
	int peso;
	int altura;
	char comprobarSexo(char sexo)
	{
		if (sexo == 'H' || sexo == 'M')
		{
			return sexo;
		}
		else
		{
			return 'H';
		}

	}
public:
	Persona()
	{
		this->nombre = "";
		this->edad = 0;
		this->dni = 0;
		this->sexo = ' ';
		this->peso = 0;
		this->altura = 0;
		this->sexo = comprobarSexo(sexo);
	}
	Persona(string nombre, int edad, char sexo)
	{
		this->nombre = nombre;
		this->edad = edad;
		this->dni = 0;
		this->sexo = sexo;
		this->peso = 0;
		this->altura = 0;
		this->sexo = comprobarSexo(sexo);
	}
	Persona(string nombre, int edad, int dni, char sexo, int peso, int altura)
	{
		this->nombre = nombre;
		this->edad = edad;
		this->dni = dni;
		this->sexo = sexo;
		this->peso = peso;
		this->altura=altura;
		this->sexo = comprobarSexo(sexo);
	}
	int calcularIMC()
	{
		float alturam = altura / 100.0;
		float pesoIdeal = peso / (alturam *alturam);
		if (pesoIdeal < 20)
		{
			return -1;
		}
		if (pesoIdeal >= 20 && pesoIdeal <= 25)
		{
			return 0;
		}
		if (pesoIdeal > 25)
		{
			return 1;
		}
	}
	bool esMayorDeEdad()
	{
		return edad >= 18;
	}
	
	void mostrar()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "edad: " << edad << endl;
		cout << "DNI: " << dni << endl;
		cout << "sexo: " << sexo << endl;
		cout << "peso: " << peso << " en Kg" << endl;
		cout << "Alterua: " << altura << endl;
		cout << "IMC: " << calcularIMC() << endl;
		cout << "Mayor de edad: " << esMayorDeEdad() << endl;
	}
	void setNombre(string Nnombre)
	{
		this->nombre = Nnombre;
	}
	void setEdad(int Nedad)
	{
		this->edad = Nedad;
	}
	void setSexo(char Nsexo)
	{
		this->sexo = comprobarSexo(Nsexo);
	}
	void setPeso(int Npeso)
	{
		this->peso = Npeso;
	}
	void setAltura(int Naltura)
	{
		this->altura = Naltura;
	}
};
class Password
{
private:
	int longitud;
	string contrasenia;
public:
	Password( )
	{
		this->longitud = 8;
		this->contrasenia = "";
	}
	Password(int longitud)
	{
		this->longitud = 0;
		this->contrasenia = contrasenia;
	}
	int getLongitud()
	{
		return longitud;
	}
	string getContrasenia()
	{
		return contrasenia;
	}
	void setLongitud(int Nlongitud)
	{
		this->longitud = Nlongitud;
	}
	void mostrar()
	{
		cout << "Longitud: " << longitud<<endl;
		cout << "contrasenia: " << contrasenia << endl;
	}

	bool esFuerte()
	{
		int mayus = 0;
		int minus = 0;
		int numeros = 0;

		for (int i = 0; i < contrasenia.length(); i++)
		{
			if (contrasenia[i] >= 'A' && contrasenia[i] <= 'Z')
			{
				mayus++;
			}
				
			if (contrasenia[i] >= 'a' && contrasenia[i] <= 'z')
			{
				minus++;
			}
			
			if (contrasenia[i] >= '0' && contrasenia[i] <= '9')
			{
				numeros++;
			}
				
		}

		if (mayus > 2 && minus > 1 && numeros > 5)
		{
			return true;
		}
			
			
	}
};


int main()
{
	cout << "-----------Ejercico 1-----------" << endl;
	Persona p1 = Persona();
	Persona p2 = Persona("Josefa", 21, 'M');
	Persona p3 = Persona("Sam", 20, 1234, 'H', 80, 190);
	cout << "----------Persona 1 ----------" << endl;
	p1.setNombre("Mateo");
	p1.setEdad(15);
	p1.setSexo('H');
	p1.setPeso(120);
	p1.setAltura(185);
	p1.mostrar();
	cout << "-------------------" << endl;
	p1.setSexo('P');
	p1.mostrar();
	cout << "----------Persona 2 ----------" << endl;
	p2.setPeso(50);
	p2.setAltura(150);
	p2.mostrar();
	cout << "----------Persona 3 ----------" << endl;
	p3.mostrar();
	p3.setSexo('M');
	p3.mostrar();
	
	cout << "------------------------------------" << endl;
	cout << "---------------Ejercicio 2-------------" << endl;
	int longitud;
	Password pass1 = Password();
	Password pass2 = Password(0);
	pass1.getLongitud();
	pass1.getContrasenia();
	pass1.mostrar();
	cout << "Ingrese la longitud: " << endl;
	cin >> longitud;
	pass2.setLongitud(longitud);
	pass2.getContrasenia();
	pass2.esFuerte();
	pass2.mostrar();
}