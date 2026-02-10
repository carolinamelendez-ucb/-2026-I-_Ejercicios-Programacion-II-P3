#include <iostream>
#include <string>
using namespace std;

class libro {
private:
	int pags;
	string titulo;
	string autor;
public:

	libro (int pags1, string autor1, string titulo1) {
		pags = pags1;
		titulo = titulo1;
		autor = autor1;
	}
	
	void mostrarlibro() {
		cout << "Titulo: " << titulo<<endl;
		cout << "Autor: " << autor << endl;
		cout << "Paginas: " << pags << endl;
	}
};

class producto {
private:
	string nombre;
	float precio;
	int stock;
public:
	producto(string n, float p) {
		nombre = n;
		precio = p;
		stock = 0;
	}
	
	void setPrecio(float p) { 
		precio = p;
	}
	void setStock(int s) {
		stock = s; 
	}

	void mostrarProduct() {
		cout << "Nombre: " << nombre << endl;
		cout << "Precio: " << precio << endl;
		cout << "Stock: " << stock << endl;
	}
};

class pelicula {
private:

	string titulo, genero;
	int duracion;

public:

	pelicula(string t, string g, int d) {
		titulo = t; genero = g; duracion = d;
	}
	void setGenero(string g) {
		genero = g;
	}
	void setDuracion(int d) {
		duracion = d;
	}

	void mostrarpeli() {
		cout << "PELICULA: " << titulo << endl;
		cout << "Genero:  " << genero << endl;
		cout << "Duracion: " << duracion <<" mins"<<endl;


	}
};

class Mascota {
private:
	string nombre, raza;
	int edad;
public:
	Mascota(string n, string t, int e) {
		nombre = n; raza = t; edad = e;
	}
	void setEdad(int e) {
		edad = e; 
	}
	void mostrarMasco() {
		cout << "Nombre: " << nombre << endl;
		cout << "Raza: " << raza << endl;
		cout << "Edad: " << edad << " anios"<<endl;
	}
};

class Pedido {
private:
	int codigo, canti;
	string producto;
	float precioUni;
public:
	Pedido(int c, string p,int cant,float pr) {
		codigo = c;
		producto = p;
		canti = cant;
		precioUni = pr;
	}
	void setCantidad(int c) {
		canti = c;
	}
	void setPrecio(float pr) {
		precioUni = pr;
	}
	double calcularTotal() {
		return canti* precioUni;
	}

	void mostrarPedi() {
		cout << "Codigo: " << codigo << endl;
		cout << "Producto: " << producto << endl;
		cout << "Cantidad: " << canti << endl;
		cout << "Precio: " << precioUni << endl;
		cout << "Total: " << calcularTotal() << endl;
	}
};

int main() {
	
	int op, c; 
	float pr;
	
	do {
		cout << "Ejercicio 1" << endl;
		cout << "Ejercicio 2" << endl;
		cout << "Ejercicio 3" << endl;
		cout << "Ejercicio 4" << endl;
		cout << "Ejercicio 5" << endl;
		cout << "SALIR 6" << endl;
		cout << "Ingrese ejercicio" << endl;
		cin >> op;
		cout << endl;
		switch (op) {

		case 1:
		{
			libro libro1 = libro(624, "Dan Brown", "El codigo Da Vinci");
			libro1.mostrarlibro();
			cout << endl;
			break;
		}
		case 2:
		{
			producto produc1 = producto("Tenis", 450);
			produc1.mostrarProduct();
			cout << "Nuevo stock y precio: " << endl;
			produc1.setStock(15);
			produc1.setPrecio(451);
			produc1.mostrarProduct();

			break;
		}
		case 3:
		{
			pelicula peli1 = pelicula("Batman", "Romantico", 110);
			peli1.mostrarpeli();
			cout << endl;
			cout << "Genero y duracion correcta: " << endl;
			peli1.setDuracion(152);
			peli1.setGenero("Accion");
			peli1.mostrarpeli();

				break;
		};
		case 4:
		{
			Mascota masco1 = Mascota("Pulga", "Rottweiler", 5);
			masco1.mostrarMasco();
			masco1.setEdad(2);
			masco1.mostrarMasco();

			break;
		};
		case 5:
		{
			
			cout << "Ingrese cantidad : ";
			cin >> c;
			cout << "Ingrese precio: ";
			cin>> pr;
			Pedido pedi1(1, "Hamburguesa",c,pr);
			pedi1.mostrarPedi();
			cout << "Ingrese nueva cantidad : ";
			cin >> c;
			cout << "Ingrese nuevo precio: ";
			cin >> pr;
			pedi1.setCantidad(c);
			pedi1.setPrecio(pr);
			pedi1.mostrarPedi();
			

			cout << endl;

			cout << "Ingrese cantidad : ";
			cin >> c;
			cout << "Ingrese precio: ";
			cin >> pr;
			Pedido pedi2(1, "Pizza", c, pr);
			pedi2.mostrarPedi();
			cout << "Ingrese nueva cantidad : ";
			cin >> c;
			cout << "Ingrese nuevo precio: ";
			cin >> pr;
			pedi2.setCantidad(c);
			pedi2.setPrecio(pr);
			pedi2.mostrarPedi();
			break;
		
		};

		default:
			cout << "No hay mas ejercicios";
			break;
		}
	
	} while (op != 6);
}
