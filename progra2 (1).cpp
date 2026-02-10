#include <iostream>
#include <string>
using namespace std;

class libro
{
private:
	string titulo;
	string autor;
	int paginas;
public:
	libro(string tituloa, string autora, int paginasa)
	{
		titulo = tituloa;
		autor = autora;
		paginas = paginasa;
	}
	void mostrarlibro()
	{
		cout << "titulo :" << titulo << endl;
		cout << "autor  :" << autor  << endl;
		cout << "paginas  :" << paginas << endl;
	}
	void setpaginas(int nuevo)
	{
		this->paginas = nuevo;
	}
};

class prod
{
private:
	string nombre;
	float precio;
	int stock=0;
public:
	prod(string nombrea, float precioa, int stocka)
	{
		nombre = nombrea;
		precio = precioa;
		stock = stocka;
	}
	void mostrarprod()
	{
		cout << "nombre :" << nombre << endl;
		cout << "precio  :" << precio << endl;
		cout << "stock  :" << stock << endl;
	}
	void setstock(int nuevo)
	{
		cout << "ingrese nuevo stock" << endl;
		cin >> nuevo;
		this->stock = nuevo;
	}
	void setprecio(float nuevoprecio)
	{
		cout << "ingrese nuevo precio" << endl;
		cin >> nuevoprecio;
		this->precio = nuevoprecio;
	}

};

class Pelicula 
{
private:
	string titulo, genero;
	int duracion;
public:
	Pelicula(string t, string g, int d) : titulo(t), genero(g), duracion(d) {}
	void setTitulo(string t) { titulo = t; }
	void setGenero(string g) { genero = g; }
	void setDuracion(int d) { duracion = d; }
	void mostrar() 
	{
		cout << "Peli: " << titulo << " | Genero: " << genero << " | Duracion: " << duracion << " min" << endl;
	}
};

class Mascota {
private:
	string nombre, tipo;
	int edad;
public:
	Mascota(string n, string t, int e) : nombre(n), tipo(t), edad(e) {}
	void setNombre(string n) { nombre = n; }
	void setTipo(string t) { tipo = t; }
	void setEdad(int e) { edad = e; }
	void mostrar() 
	{
		cout << "Nombre: " << nombre << " | Tipo: " << tipo << " | Edad: " << edad << endl;
	}
};

class Pedido {
private:
	string codigo, producto;
	int cantidad;
	float precioUnitario;
public:
	Pedido(string c, string p, int cant, float precio) {
		codigo = c; producto = p; cantidad = cant; precioUnitario = precio;
	}
	void setCantidad(int c) { cantidad = c; }
	void setPrecioUnitario(float p) { precioUnitario = p; }
	float calcularTotal() { return cantidad * precioUnitario; }
	void mostrar() 
	{
		cout << "Cod: " << codigo << " | Prod: " << producto << " | Cant: " << cantidad
			<< " | P.U: " << precioUnitario << " | TOTAL: " << calcularTotal() << endl;
	}
};

int main()
{
	int op=0;
	while (op != 6)
	{
		cout << "bienvenido al menu" << endl;
		cout << "elija las siguientes" << endl;
		cout << "1=libro" << endl;
		cout << "2=prod" << endl;
		cout << "3=pelicula" << endl;
		cout << "4=mascota" << endl;
		cout << "5=pedido" << endl;
		cout << "6=salir" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			libro l1 = libro("el principito", "Antoine", 100);
			l1.mostrarlibro();
			l1.setpaginas(150);
			l1.mostrarlibro();
			break;
		}
		case 2:
		{
			prod p1 = prod("pan", 12, 1);
			p1.mostrarprod();
			p1.setstock(00);
			p1.setprecio(00);
			p1.mostrarprod();
			break;
		}
		case 3: 
		{
			Pelicula p1("Inception", "Sci-Fi", 148), p2("Shrek", "Animada", 90);
			string g; int d;

			cout << "Ingrese genero y duracion para P1: "; cin >> g >> d;
			p1.setGenero(g); p1.setDuracion(d);
			cout << "Ingrese genero y duracion para P2: "; cin >> g >> d;
			p2.setGenero(g); p2.setDuracion(d);

			p1.mostrar(); p2.mostrar();
			cout << "Modificando duracion de P1 a 200..."<<endl;
			p1.setDuracion(200);
			p1.mostrar(); p2.mostrar();
			break;
		}
		case 4: 
		{
			Mascota m1("Firulais", "Perro", 3), m2("Michi", "Gato", 2);
			int e;
			cout << "Nueva edad para Firulais: "; cin >> e; m1.setEdad(e);
			cout << "Nueva edad para Michi: "; cin >> e; m2.setEdad(e);

			m1.mostrar(); m2.mostrar();
			cout << "Cambiando edad de Michi a 5..."<<endl;
			m2.setEdad(5);
			m1.mostrar(); m2.mostrar();
			break;
		}
		case 5: 
		{ 
			Pedido ped1("001", "Manzanas", 10, 0.5), ped2("002", "Pan", 5, 1.2);
			int c; float p;

			cout << "Cant. y Precio para Pedido 1: "; cin >> c >> p;
			ped1.setCantidad(c); ped1.setPrecioUnitario(p);

			ped1.mostrar(); ped2.mostrar();
			cout << "Modificando cantidad de Pedido 2..."<<endl;
			ped2.setCantidad(20);
			ped1.mostrar(); ped2.mostrar();
			break;
		}
		case 6: cout << "salio" << endl;
			break;
		}
	}
	return 0;
}