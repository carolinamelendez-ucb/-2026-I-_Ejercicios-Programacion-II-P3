#include <iostream>
#include <string>
using namespace std;
//EJERCICIO 1
class Libro {
	private:
	string titulo;
	string autor;
	int paginas;
	public:
		Libro(string titulo, string autor, int paginas) {
			this->titulo = titulo;
			this->autor = autor;
			this->paginas = paginas;
	}
		void setTitulo(string nueTitulo) {
			this->titulo = nueTitulo;
		}
		void setAutor(string nueAutor) {
			this->autor = nueAutor;
		}
		void setPaginas(int nuePagina) {
			this->paginas = nuePagina;
		}
		void mostrarInfo() {
			cout << "Titulo: " << titulo << endl;
			cout << "Autor: " << autor << endl;
			cout << "Nro de Paginas: " << paginas << endl;
		}
};
///EJERCICIO 2
class Producto {
	private:
	string nombre;
	float precio;
	int stock;
	public:
		Producto(string nombre, float precio) {
			this->nombre = nombre;
			this->precio = precio;
			this->stock = 0;
		}
		void setNombre(string nueNombre) {
			this->nombre = nueNombre;
		}
		void setPrecio(float nuePrecio) {
			this->precio = nuePrecio;
		}
		void setStock(int nueStock) {
			this->stock = nueStock;
		}
		void mostrarInform() {
			cout << "Nombre: " << nombre << endl;
			cout << "Precio: Bs. " << precio << endl;
			cout << "Stock: " << stock << endl;
		}
};
///EJERCICIO 3
class Pelicula {
	private:
	string titulo;
	string genero;
	int duracion; //en minutos
	public:
		Pelicula(string titulo, string genero, int duracion) {
			this->titulo = titulo;
			this->genero = genero;
			this->duracion = duracion;
		}
		void setTitulo(string nueTitulo) {
			this->titulo = nueTitulo;

		}
		void setGenero(string nueGenero) {
			this->genero = nueGenero;
		}
		void setDuracion(int nueDuracion) {
			this->duracion = nueDuracion;
		}
		void mostrarInformacion() {
			cout << "Titulo de la Pelicula: " << titulo << endl;
			cout << "Genero: " << genero << endl;
			cout << "Duracion: " << duracion << " minutos" << endl;
		}
};
///EJERCICIO 4
class Mascota {
	private:
	string nombre;
	string tipo;
	int edad;
	public:
		Mascota(string nombre, string tipo, int edad) {
			this->nombre = nombre;
			this->tipo = tipo;
			this->edad = edad;
		}
		void setNombre(string nueNombre) {
			this->nombre = nueNombre;
		}
		void setTipo(string nueTipo) {
			this->tipo = nueTipo;
		}
		void setEdad(int nueEdad) {
			this->edad = nueEdad;
		}
		void mostrarInform() {
			cout<< "Nombre de la Mascota: " << nombre << endl;
			cout << "Tipo: " << tipo << endl;
			cout << "Edad: " << edad << " anios" << endl;
		}
};
///EJERCICIO 5
class Pedido {
	private:
	string codigo;
	string producto;
	int cantidad;
	int precioUnitario;
	public:
		Pedido(string codigo, string producto, int cantidad, int precioUnitario) {
			this->codigo = codigo;
			this->producto = producto;
			this->cantidad = cantidad;
			this->precioUnitario = precioUnitario;
		}
		void setCantidad(int nueCantidad) {
			this->cantidad = nueCantidad;
		}
		void setPrecioUnitario(int nuePrecio) {
			this->precioUnitario = nuePrecio;
		}
		double calcuTotal() {
			return cantidad * precioUnitario;
		}
		void mostrarInfo() {
			cout << "Codigo: " << codigo << endl;
			cout << "Producto: " << producto << endl;
			cout << "Cantidad: " << cantidad << endl;
			cout << "Precio Unitario: " << precioUnitario << endl;
			cout << "Total del pedido: " << calcuTotal() << endl;
		}
};
int main()
{
	Libro libro1 = Libro("Charlie y la Fabrica de Chocolate", "Roald Dahl", 170);
	libro1.mostrarInfo();
	cout << endl;
	cout << "Cambio Nro de paginas" <<endl;
	libro1.setPaginas(150);
	libro1.mostrarInfo();
	cout << "--------------------------------------------------" << endl;

	Producto producto1 = Producto("Samsung Galaxy S26+", 6500.50);
	producto1.mostrarInform();
	cout << endl;
	cout << "Cambio stock ..." << endl;
	producto1.setStock(20);
	cout << "Ajustando el precio ..." << endl;
	producto1.setPrecio(6200.75);
	cout << endl;
	cout << "Producto ajustado con Stock" << endl;
	producto1.mostrarInform();
	cout << "--------------------------------------------------" << endl;

	Pelicula pelicula1 = Pelicula("Shang Chi y la leyenda de los 10 anillos", "Ciencia Ficcion", 132);
	Pelicula pelicula2 = Pelicula("Rápidos y Furiosos 8", "Accion", 160);
	Pelicula pelicula3 = Pelicula("Guerra de Papas", "Comedia", 96);
	string nueGenero;
	int nueDuracion;
	cout << "INFORMACION DE PELICULAS" << endl;
	cout << "Pelicula: " << "Shang Chi y la leyenda de los 10 anillos" << endl;
	cout << "Ingrese genero: ";
	getline(cin >> ws, nueGenero);
	cout << "Ingrese la duracion (En Minutos): ";
	cin >> nueDuracion;
	pelicula1.setGenero(nueGenero);
	pelicula1.setDuracion(nueDuracion);
	cout << endl;
	cout << "Pelicula: " << "Rapidos y Furiosos 8" << endl;
	cout << "Ingrese genero: ";
	getline(cin >> ws, nueGenero);
	cout << "Ingrese la duracion (En Minutos): ";
	cin >> nueDuracion;
	pelicula2.setGenero(nueGenero);
	pelicula2.setDuracion(nueDuracion);
	cout << endl;
	cout << "Pelicula: " << "Guerra de Papas" << endl;
	cout << "Ingrese genero: ";
	getline(cin >> ws, nueGenero);
	cout << "Ingrese la duracion (En Minutos): ";
	cin >> nueDuracion;
	pelicula3.setGenero(nueGenero);
	pelicula3.setDuracion(nueDuracion);
	cout << "LISTA DE LAS PELICULAS" << endl;
	pelicula1.mostrarInformacion();
	pelicula2.mostrarInformacion();
	pelicula3.mostrarInformacion();
	cout << "Modificar duracion de Rapidos y Furiosos 8" << endl;
	cout << "Ingrese nuevamente la nueva duracion: ";
	cin >> nueDuracion;
	pelicula2.setDuracion(nueDuracion);
	cout << "Duracion actualizada de manera exitosa!" << endl;
	cout << "PELICULAS ACTUALIZADAS" << endl;
	pelicula1.mostrarInformacion();
	pelicula2.mostrarInformacion();
	pelicula3.mostrarInformacion();
	cout << "--------------------------------------------------" << endl;

	Mascota mascota1 = Mascota("Loky", "Perro", 6);
	Mascota mascota2 = Mascota("Chispita", "Perro", 6);
	Mascota mascota3 = Mascota("Nubecita", "Pajaro", 4);
	int nueEdad;
	cout << "ACTUALIZACION DE LA EDAD DE MASCOTAS" << endl;
	cout << "Mascota: " << "Loky (Perro)" << endl;
	cout << "Ingrese su nueva edad: ";
	cin >> nueEdad;
	mascota1.setEdad(nueEdad);
	cout << endl;
	cout << "Mascota: " << "Chispita (Perro)" << endl;
	cout << "Ingrese su nueva edad: ";
	cin >> nueEdad;
	mascota2.setEdad(nueEdad);
	cout << endl;
	cout << "Mascota: " << "Nubecita (Pajaro)" << endl;
	cout << "Ingrese su nueva edad: ";
	cin >> nueEdad;
	mascota3.setEdad(nueEdad);
	cout << endl;
	cout << "LISTA DE MASCOTAS" << endl;
	mascota1.mostrarInform();
	mascota2.mostrarInform();
	mascota3.mostrarInform();
	cout << "Cambiar edad de Nubecita" << endl;
	cout << "Ingrese nuevamente su nueva edad" << endl;
	cin >> nueEdad;
	mascota3.setEdad(nueEdad);
	cout << "Edad actualizada correctamente!" << endl;
	cout << endl;
	mascota1.mostrarInform();
	mascota2.mostrarInform();
	mascota3.mostrarInform();
	cout << "--------------------------------------------------" << endl;

	Pedido pedido1 = Pedido("A001", "Parlante", 1, 0.0);
	Pedido pedido2 = Pedido("A002", "CPU", 2, 0.0);
	int cantidad;
	int precio;
	cout << "INGRESE LOS DATOS DE LOS PEDIDOS" << endl;
	cout << "Pedido: Parlante (Codigo: A001)" << endl;
	cout << "Ingrese la cantidad: ";
	cin >> cantidad;
	cout << "Ingrese precio unitario: ";
	cin >> precio;
	pedido1.setCantidad(cantidad);
	pedido1.setPrecioUnitario(precio);
	cout << endl;
	cout << "Pedido: CPU (Codigo: A002)" << endl;
	cout << "Ingrese la cantidad: ";
	cin >> cantidad;
	cout << "Ingrese precio unitario: ";
	cin >> precio;
	pedido2.setCantidad(cantidad);
	pedido2.setPrecioUnitario(precio);
	cout << endl;
	cout << "LISTA DE PEDIDOS" << endl;
	pedido1.mostrarInfo();
	pedido2.mostrarInfo();
	cout << "Modificar cantidad del pedido A001 (Parlante):" << endl;
	cout << "Ingrese nueva cantidad:" << endl;
	cin >> cantidad;
	pedido1.setCantidad(cantidad);
	cout << "Cantidad actualizada correctamente!" << endl;
	cout << "PEDIDOS ACTUALIZADOS CORRECTAMENTE" << endl;
	pedido1.mostrarInfo();
	pedido2.mostrarInfo();
	return 0;
}
