

#include <iostream>
#include <string>
using namespace std;

// EJERCICIO 1:

class Libro {
private:
	string titulo;
	string autor;
	int pagina;
public:

	Libro(string tituloS, string autorS, int paginaS){
		titulo = tituloS;
		autor = autorS;
		pagina = paginaS;
	}
		void mostrarLibro() {
		cout << "Titulo:"<<titulo << endl;
		cout<< "Autor/a:"<<autor <<endl;
		cout << "Num. Pgs:"<<pagina<<endl;
		}
		void setPagina(int nuevaPG) {
			pagina = nuevaPG;
		}

		//	 METODOS
	void CrearLibro(){
		cout << "Crear libro" << endl;
		}
	void MostrarDatos() {
		cout << "Mostrar Datos" << endl;
	}
	void CambiarPGS() {
		cout << "Cambiar Pg" << endl;
	}
	void VolverPG() {
		cout << "Volver Pg" << endl;
	}
};

// EJERCICIO 2 (PRODUCTO);

class Producto {
private: 
	string nombre;
	float precio;
	int stock;
public:
	 
	Producto(string nombreS,float precioS,int stockS) {
		nombre = nombreS;
		precio = precioS;
		stock = stockS;
	}
		void MostrarProducto() {
		cout<<"Nombre:"<<nombre<< endl;
		cout<<"Precio:"<<precio<< endl;
		cout<<"Stock:"<<stock << endl;
	}
		void setNuevoStock(int NuevoStock) {
			stock = NuevoStock;
		}
		void setNuevoPrecio(float NuevoPrecio) {
			precio = NuevoPrecio;
		}
// Metodo 2
	void Crear_Producto(){
		cout << "Crear Producto" << endl;
	}
	void MostrarP() {
		cout << "Mostrar Producto" << endl;
	}
	void Actualizar_stock(){
		cout << "Actualizar Stock" << endl;
	}
	void Actualizar_Precio() {
		cout << "Actualizar Precio" << endl;
	}
	void Mostrar_Nuevamente() {
		cout << "Mostrar Nuevamente" << endl;
	}
};

// EJERCICIO 3 (Pelicula)

class Pelicula {
private:
	string NombreP;
	string Genero;
	float Duracion;
public: 
	Pelicula(string nombrePs, string generoS, float duracionS) {
		NombreP = nombrePs;
		Genero = generoS;
		Duracion = duracionS;
	}
	void MostrarPeli() {
		cout << "Nombre Peli:" <<NombreP<< endl;
		cout << "Genero:" << Genero << endl;
		cout << "Duracion" << Duracion << endl;
		}
	void  setModificar_Duracion(int NuevaDuracion) {
		Duracion = NuevaDuracion;
	}

//Metodo 3
	void Crear_Pelicula() {
		cout << "Crear pelicula" << endl;
	}
	void Genero_Duracion() {
		cout << "Genero y duracion de la Peli" << endl;
	}
	void Mostrar_Info_PELIS() {
		cout << "Catalogo de pelis:" << endl;
		cout << "Nombre Peli:" << NombreP << endl;
		cout << "Genero:" << Genero << endl;
		cout << "Duracion" << Duracion << endl;
	}
	void Modificar_Duracion() {
		cout << "Modificar Duracion de Peli" << endl;
	}
	
};

// EJERCICIO 4 (Mascota)

class Mascota {
private:
	string NombreMas;
	string Raza;
	int Edad;
public:
	Mascota(string NombreMS, string razaS, int edadS) {
		NombreMas = NombreMS;
		Raza = razaS;
		Edad = edadS;
	}
	void MostrarMascota() {
		cout << "Nombre: " << NombreMas << endl;
		cout << "Raza:" << Raza << endl;
		cout << "Edad:" << Edad << endl;
	}
	void setCambio_Edad(int Nueva_Edad) {
		Edad = Nueva_Edad;
	}
	void setCambio_Nombre(string nombreNuevo) {
		NombreMas = nombreNuevo;
	}

};

// EJERCICIO 5 (Pedido)

class Pedido {
private:
	string Codigo;
	string Producto5;
	int Cantidad;
	float PrecioUnitario;
public:
	Pedido(string codigoS, string productoS, int cantidadS, float puS) {
		Codigo = codigoS;
		Producto5 = productoS;
		Cantidad = cantidadS;
		PrecioUnitario = puS;
	}
	void MostrarPedido() {
		cout << "Codigo:" << Codigo << endl;
		cout << "Producto:" << Producto5 << endl;
		cout << "Cantidad:" << Cantidad << endl;
		cout << "Precio Unitario:" << PrecioUnitario << endl;
	}
	void setModificar_Cantidad(int Nueva_cant) {
		Cantidad = Nueva_cant;
	}
	///METODOS 5
	int total;
	void Precio_Total() {
		total=Cantidad* PrecioUnitario;
		cout << "Total:" << total<<" Bs" << endl;
	}
};


int main(){
   
   ///EJR 1 (Libros)
	/*
	string Titulo;
	string Autor;
	int pgs;
	Libro libro1("Cien anios de soledad","Gabriel Garcia Marquez",400);
	libro1.mostrarLibro();
	libro1.setPagina(235);
	libro1.mostrarLibro();
	*/

   ///EJR 2 (Producto)

	/*
	string NombreP;
	float Precio;
	int stockp;
	Producto Produc1("Celular",500,0);
	Produc1.MostrarProducto();
	cout << "Nuevo stock:";
	cin >> stockp;
	cout << "Nuevo Precio:";
	cin >> Precio;
	Produc1.setNuevoStock(stockp);
	Produc1.setNuevoPrecio(Precio);
	Produc1.MostrarProducto();
	*/

   ///EJR 3 (Pelicula)

	/*
	string nombrePl;
	string GeneroPl1,GeneroPl2;
	int duracionpl;
	Pelicula Peli1("Harry Potter","fantasia",1.20);
	Peli1.MostrarPeli();
	cout << endl;
	Pelicula Peli2("Avengers","Accion-CF",2.30);
	Peli2.MostrarPeli();
	cout << endl;
	Peli1.Modificar_Duracion(2.00);
	Peli2.Modificar_Duracion(2.50);
	Peli1.MostrarPeli();
	cout << endl;
	Peli2.MostrarPeli();
	*/

   ///EJR 4	(Mascota)

	/*
	string nombreMs;
	string razaMs;
	int EdadMs;
	Mascota Masco1("Pintudango","golden",6);
	Mascota Masco2("Perengue","Shitzu",3);
	Mascota Masco3("Zoey", "Chihuhua", 1);
	Masco1.MostrarMascota();
	cout << endl;
	Masco2.MostrarMascota();
	cout << endl;
	Masco3.MostrarMascota();
	cout << endl;
	cout << "Cambio de Nombre:";
	cin >> nombreMs;
	cout << "Modificar de Edad:";
	cin >> EdadMs;
	Masco1.setCambio_Nombre(nombreMs);
	Masco1.setCambio_Edad(EdadMs);
	cout << endl;
	Masco1.MostrarMascota();
	Masco2.MostrarMascota();
	Masco3.MostrarMascota();
	*/


   ///EJR 5 (Pedido);


	int codigo;
	string Producto;
	string PreUNI;
	int cantidadPd;
	int precioTotal;
	Pedido pedido1("A113", "chompa", 50, 60);
	Pedido pedido2("F42Y", "Zapatillas", 30, 45);
	pedido1.MostrarPedido();
	pedido1.Precio_Total();
	cout << endl;
	pedido2.MostrarPedido();
	pedido2.Precio_Total();
	cout << endl;
	cout << "Modifica la cantidad:";
	cin >> cantidadPd;
	pedido1.setModificar_Cantidad(cantidadPd);
	pedido1.MostrarPedido();
	pedido1.Precio_Total();
	cout << endl;
	pedido2.MostrarPedido();
	pedido2.Precio_Total();


}
