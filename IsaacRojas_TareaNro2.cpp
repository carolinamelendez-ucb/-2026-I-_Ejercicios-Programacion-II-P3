#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
///EJERCICIO 2
using namespace std;
class Persona {
private:
	string nombre;
	int edad;
	string DNI;
	char sexo;
	float peso;
	float altura;
	const int pesoIdealBajo = -1;
	const int pesoIdealNormal = 0;
	const int sobrepeso = 1;
	void comprobarSexo(char sexo) {
		if (sexo != 'H' && sexo != 'M') {
			this->sexo = 'H';
		}
		else {
			this->sexo = sexo;
		}
	}
	void generarDNI() {
		string numeros = "0123456789";
		string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
		string dni = "";
		for (int i = 0; i < 8; i++) {
			dni += numeros[rand() % numeros.size()];
		}
		dni += letras[stoi(dni) % 23];
		this->DNI = dni;
	}
public:
	Persona() {
		this->nombre = "";
		this->edad = 0;
		this->sexo = 'H';
		this->peso = 0;
		this->altura = 0;
		generarDNI();
	}
	Persona(string nombre, int edad, char sexo) {
		this->nombre = nombre;
		this->edad = edad;
		comprobarSexo(sexo);
		this->peso = 0;
		this->altura = 0;
		generarDNI();
	}
	Persona(string nombre, int edad, char sexo, float peso, float altura) { 
		this->nombre = nombre;
		this->edad = edad;
		comprobarSexo(sexo);
		this->peso = peso;
		this->altura = altura;
		generarDNI();
	}
	int calcularIMC() {
		if (altura <= 0) {
			return 0;
		}
		float imc = peso / (altura * altura);
		if (imc < 20) {
			return pesoIdealBajo;
		}
		else if (imc >= 20 && imc <= 25) {
			return pesoIdealNormal;
		}
		else {
			return sobrepeso;
		}
	}
	bool esMayorDeEdad() {
		return edad >= 18;
	}
	string toString() {
		string resul = "";
		resul += "Nombre: " + nombre + "\n";
		resul += "Edad: " + to_string(edad) + " anios\n";
		resul += "Sexo: " + string(1, sexo) + "\n";
		resul += "Peso: " + to_string(peso) + " kg\n";
		resul += "Altura: " + to_string(altura) + " mts\n";
		int imc = calcularIMC();
		resul += "IMC: ";
		if (imc == -1) {
			resul += "Peso ideal bajo\n";
		}
		else if (imc == 0) {
			resul += "Peso ideal normal\n";
		}
		else {
			resul += "Sobrepeso\n";
		}
		resul += "Mayor de edad: ";
		if (esMayorDeEdad()) {
			resul += "Si";
		} else {
			resul += "No";
		}
		resul += "\n";
		return resul;
	}
	void setNombre(string nueNombre) {
		this->nombre = nueNombre;
	}
	void setEdad(int nueEdad) {
		this->edad = nueEdad;
	}
	void setSexo(char nueSexo) {
		comprobarSexo(nueSexo);
	}
	void setPeso(float nuePeso) {
		this->peso = nuePeso;
	}
	void setAltura(float nueAltura) {
		this->altura = nueAltura;
	}
	string getDNI() {
		return DNI;
	}
};
///EJERCICIO 3
class Password {
private:
	int longitud;
	string contrasenia;
	void generarContrasenia() {
		string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
		string contrasenia = "";
		for (int i = 0; i < longitud; i++) {
			contrasenia += caracteres[rand() % caracteres.size()];
		}
		this->contrasenia = contrasenia;
	}
public:
	Password() {
		this->longitud = 8;
		generarContrasenia();
	}
	Password(int longitud) {
		this->longitud = longitud;
		generarContrasenia();
	}
	bool esFuerte() {
		int mayusculas = 0;
		int minusculas = 0;
		int numeros = 0;
		int especiales = 0;
		for (int i = 0; i < contrasenia.length(); i++) {
			char c = contrasenia[i];
			if (c >= 'A' && c <= 'Z') {
				mayusculas++;

			}
			else if (c >= 'a' && c <= 'z') {
				minusculas++;
			}
			else if (c >= '0' && c <= '9') {
				numeros++;
			}
			else {
				especiales++;
			}
		}
		return (mayusculas > 2 && minusculas > 1 && numeros > 5);
	}
	string getContrasenia() {
		return contrasenia;
	}
	int getLongitud() {
		return longitud;
	}
	void setLongitud(int nueLongitud) {
		this->longitud = nueLongitud;
		generarContrasenia();
	}
	void mostrarInfo() {
		cout << "Longitud: " << longitud << endl;
		cout << "Contrasenia: " << contrasenia << endl;
		cout << "Es fuerte: ";
		if (esFuerte()) {
			cout << "Si" << endl;
		}
		else {
			cout << "No" << endl;
		}
		cout << endl;
	}
};
void ejercicio2() {
	Persona persona1;
	cout << persona1.toString() << endl;
	Persona persona2("Juan", 25, 'H');
	persona2.setPeso(70.6);
	persona2.setAltura(1.78);
	cout << persona2.toString() << endl;
	Persona persona3("Maria", 30, 'M', 60.2, 1.65);
	cout << persona3.toString() << endl;
	cout << "Modificando datos de la persona 3..." << endl;
	persona3.setEdad(28);
	persona3.setPeso(58.4);
	cout << "Datos Actualizados" << endl;
	cout << persona3.toString() << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
}
void ejercicio3() {
	Password pass1;
	pass1.mostrarInfo();
	cout << endl;
	Password pass2(12);
	pass2.mostrarInfo();
	cout << endl;
	Password pass3(16);
	pass3.mostrarInfo();
	cout << endl;
	cout << "Modificando longitud de Password 1... " << endl;
	pass1.setLongitud(10);
	cout << "Password 1 actualizada:" << endl;
	pass1.mostrarInfo();
}
int main()
{
	srand(time(0));
	ejercicio2();
	ejercicio3();
}
