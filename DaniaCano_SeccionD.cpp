// DaniaCano_SeccionD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
//================================EJERCICIO 7 ==================================
class Cliente {
private:
	string nombre;
	string tipo;
	int antiguedad;
public:
	Cliente() {
		nombre = "";
		tipo = "";
		antiguedad = 0;
	}

	Cliente(string nombre, string tipo, int antiguedad) {
		this->nombre = nombre;
		this->tipo = tipo;
		this->antiguedad = antiguedad;
	}

	string getTipo() {
		return tipo;
	}

	int getAntiguedad() {
		return antiguedad;
	}
	bool frec() {
		return tipo== "frecuente";
	}

};

class Factura {
private: 
	int numero; //num de facturas
	int montoBase;
	bool pagada;
	Cliente cliente;
public:
	Factura(int numero, int montoBase, bool pagada, Cliente cliente)
	{
		this->numero = numero;
		this->montoBase = montoBase;
		this->cliente = cliente;
		this->pagada = pagada;
	}
	float getMonto() {
		return montoBase;
	}

	bool estaPagada() {
		return pagada;
	}

	Cliente getCliente() {
		return cliente;
	}

	float calcularTotal() {
		if (cliente.frec() && cliente.getAntiguedad() > 2) {
			return montoBase * 0.90;  // se le resta el 10%
		}
		else { return montoBase; }
	}
};
//metodos para el vector
float totalFrecuentes(Factura facturas[], int n) {
	float total = 0;
	for (int i = 0; i < n; i++) {
		if (facturas[i].getCliente().frec() && facturas[i].getCliente().getAntiguedad() > 2) {

			total=total+ facturas[i].getMonto();
		}
	}
	return total;
}
int contarFacturasNorm(Factura facturas[], int n) {

	int contador = 0;

	for (int i = 0; i < n; i++) {

		if (!facturas[i].getCliente().frec()) {
			contador++;
		}
	}

	return contador;
}
float mayorFrecuente(Factura facturas[], int n) {

	float mayor = 0;

	for (int i = 0; i < n; i++) {

		if (facturas[i].getCliente().frec() &&
			facturas[i].getMonto() > mayor) {

			mayor = facturas[i].getMonto();
		}
	}

	return mayor;
}
float promedioM5(Factura facturas[], int n) {

	float suma = 0;
	int contador = 0;

	for (int i = 0; i < n; i++) {

		if (facturas[i].getCliente().getAntiguedad() > 5) {
			suma = suma + facturas[i].getMonto();
			contador++; //contamos el numero de clinetes con ms de 5 años de ntiguedad
		}
	}

	if (contador > 0) {
		return suma / contador;
	}
	else {
		return 0;
	}
		
}
void mostrarIyD(Factura facturas[], int n) {

	int impagas = 0;
	float deudaF = 0;

	for (int i = 0; i < n; i++) {

		if (!facturas[i].estaPagada()) {
			impagas++;

			if (facturas[i].getCliente().frec()) {
				deudaF = deudaF+facturas[i].getMonto();
			}
		}
	}

	cout << "Tota l de facturas impagas: " << impagas << endl;
	cout << "Total deuda de clientes frecuentes: "<< deudaF << endl;
}

void ejer7() {
	cout << endl;
	cout << "==============EJERICICIO 7=====================" << endl;

	Cliente cliente[5];
	cliente[0] = Cliente("Ana", "frecuente", 3);
	cliente[1] = Cliente("Luis", "normal", 1);
	cliente[2] = Cliente("Maria", "frecuente", 6);
	cliente[3] = Cliente("Pedro", "normal", 4);
	cliente[4] = Cliente("Laura", "frecuente", 7);

	Factura factura[5] = {
	Factura(1, 500, true, cliente[0]),
	Factura(2, 800, false, cliente[1]),
	Factura(3, 1000, true, cliente[2]),
	Factura(4, 300, false, cliente[3]),
	Factura(5, 1200, true, cliente[4])}; 

	//cliente frecuente conmas de 2 años de antiguedad
	cout << "Total monto facturado de clientes frecuentes con mas d dos anos de antiguedad: "<< totalFrecuentes(factura, 5) << endl;
	//cantidad de facturas de clientes normales.
	cout << "Cantidad de facturas de clientes normales: " << contarFacturasNorm(factura, 5)<<endl;
	//La mayor factura frecuente
	cout << "Mayor factura frecuente: "<< mayorFrecuente(factura, 5)<< endl;
	//Promedio de monto de clientes con mas de 5 años de antiguedad
	cout << "Promedio clientes con mas de 5 anos de antiguedad: "<< promedioM5(factura, 5)<< endl;
	mostrarIyD(factura, 5);
}
//================================EJERCICIO 8 ==================================
class ClienteP {
private:
	string nombre;
	float saldoDis;
	bool habilitado;
public:
	ClienteP() {  
		nombre = "";
		saldoDis = 0;
		habilitado = false;
	}
	ClienteP(string nombre, float saldoDis, bool habilitado) {
		this->nombre=nombre;
		this->saldoDis = saldoDis;
		this->habilitado = habilitado;
	}
	float getSaldoDis() {
		return saldoDis;
	}

	bool Habilit() {
		return habilitado;
	}
	string getNombre() {
		return nombre;
	}
};
class Pedido {
private:
	string codigo;
	float importe;
	ClienteP clientep;
public:
	Pedido(string codigo, float importe, ClienteP clientep)
	{
		this->codigo = codigo;
		this->importe = importe;
		this->clientep = clientep;
	}
	float getImporte() {
		return importe;
	}

	ClienteP getCliente() {
		return clientep;
	}

	bool puedeConfirmarse() {
		if (clientep.Habilit() && clientep.getSaldoDis()>= importe) {
			return true;
		}	
		else { return false; }
	}

};
//metodos para arrive
int contarConfir(Pedido pedidos[], int n) {

	int contador = 0;

	for (int i = 0; i < n; i++) {
		if (pedidos[i].puedeConfirmarse()) {
			contador++;
		}
	}

	return contador;
}
float totalConfirmados(Pedido pedidos[], int n) {

	float total = 0;

	for (int i = 0; i < n; i++) {
		if (pedidos[i].puedeConfirmarse()) {
			total += pedidos[i].getImporte();
		}
	}

	return total;
}
int rechazadosPS(Pedido pedidos[], int n) {

	int contador = 0;

	for (int i = 0; i < n; i++) {

		if (pedidos[i].getCliente().Habilit() && pedidos[i].getCliente().getSaldoDis() < pedidos[i].getImporte()) {
			contador++;
		}
	}

	return contador;
}
int mayorPos(Pedido pedidos[], int n) { //devolveremos la psosicon del mayor tambien

	float mayor = 0;
	int pos = 0;

	for (int i = 0; i < n; i++) {

		if (pedidos[i].getImporte() > mayor) {
			mayor = pedidos[i].getImporte();
			pos = i;
		}
	}
	return pos;
}

void ejer8()
{
	cout << endl;
	cout << "==============EJERICICIO 8=====================" << endl;

	ClienteP clientep[4];

	clientep[0] = ClienteP("Ana", 1000, true);
	clientep[1] = ClienteP("Luis", 300, true);
	clientep[2] = ClienteP("Maria", 100, false);
	clientep[3] = ClienteP("Pedro", 1500, true);

	Pedido pedido[4] = {
		Pedido("P1", 500, clientep[0]),
		Pedido("P2", 800, clientep[1]),
		Pedido("P3", 200, clientep[2]),
		Pedido("P4", 1200, clientep[3]) 
	};

	cout << "Pedidos confirmados: "	<< contarConfir(pedido, 4) << endl;
	cout << "Total confirmados: " << totalConfirmados(pedido, 4) << endl;

	cout << "Rechazados por saldo: " << rechazadosPS(pedido, 4) << endl;
	int pos = mayorPos(pedido, 4);
	cout << "Mayor importe: "<< pedido[pos].getImporte() << endl;
	cout << "Cliente con pedido mas caro: " << pedido[pos].getCliente().getNombre() << endl;
}

//================================EJERCICIO 9 ==================================
const int MAYOR_DE_EDAD = 18;

class Propietario {
private:
	string nombre;
	int DNI;
	int edad;

public:
	Propietario() {
		this->nombre = "";
		this->DNI = 0;
		this->edad = 0;
	}
	Propietario(string nombre, int DNI, int edad) {
		this->nombre = nombre;
		this->DNI = DNI;
		this->edad = edad;
	}

	int getEdad() {
		return edad;
	}
	string getNombre() {
		return nombre;
	}
};

class Casa {
private:
	string direccion;
	float precio;
	Propietario propietario;

public:

	Casa(string direccion, float precio, Propietario propietario)
	{
		this->direccion = direccion;
		this->precio = precio;
		this->propietario = propietario;
	}
	float getPrecio() {
		return precio;
	}

	Propietario getPropietario() {
		return propietario;
	}
	bool PropietarioValido() {
		return propietario.getEdad() >= MAYOR_DE_EDAD;
	}
};
//metodos
float TMEdad(Casa casa[], int n) {

	float total = 0;
	for (int i = 0; i < n; i++) {
		if (casa[i].PropietarioValido()) {
			total = total + casa[i].getPrecio();
		}
	}
	return total;
}
int CMEdad(Casa casa[], int n) {

	int contador = 0;
	for (int i = 0; i < n; i++) {
		if (casa[i].PropietarioValido()) {
			contador++;
		}
	}
	return contador;
}
float TMayor60(Casa casa[], int n) {

	float total = 0;
	for (int i = 0; i < n; i++) {
		if (casa[i].getPropietario().getEdad() > 60) {
			total = total+ casa[i].getPrecio();
		}
	}
	return total;
}
float mayorCasaV(Casa casa[], int n) {

	float mayor = 0;
	for (int i = 0; i < n; i++) {

		if (casa[i].PropietarioValido() && casa[i].getPrecio() > mayor) {
			mayor = casa[i].getPrecio();
		}
	}
	return mayor;
}
float promedioEdades(Casa casa[], int n) { //de 30 a 50 años

	float suma = 0;
	int contador = 0;
	for (int i = 0; i < n; i++) {
		int edad = casa[i].getPropietario().getEdad();

		if (edad >= 30 && edad <= 50) {
			suma = suma + casa[i].getPrecio();
			contador++;
		}
	}
	if (contador > 0) {
		return suma / contador;
	}
	else { return 0; }	
}
int contarMenores(Casa casa[], int n) {

	int contador = 0;
	for (int i = 0; i < n; i++) {
		if (casa[i].getPropietario().getEdad() < 18) {
			contador++;
		}
	}

	return contador;
}
void ejer9() {
	cout << endl;
	cout << "==============EJERICICIO 9=====================" << endl;

	Propietario prop[5];

	prop[0] = Propietario("Juan", 111, 25);
	prop[1] = Propietario("Ana", 222, 17);
	prop[2] = Propietario("Luis", 333, 65);
	prop[3] = Propietario("Maria", 444, 40);
	prop[4] = Propietario("Pedro", 555, 70);

	Casa casa[5] = {
		Casa("Lanza", 50000, prop[0]),
		Casa("Junin", 30000, prop[1]),
		Casa("America", 80000, prop[2]),
		Casa("España", 45000, prop[3]),
		Casa("Oquendo", 90000, prop[4])
	};

	cout << "Total precio mayores de edad: " << TMEdad(casa, 5) << endl;
	cout << "Cantidad casas mayores de edad: " << CMEdad(casa, 5) << endl;
	cout << "Total precio propietarios con mas de 60 anos: " << TMayor60(casa, 5) << endl;
	cout << "Mayor casa con propietario valido: "<< mayorCasaV(casa, 5) << endl;
	cout << "Promedio casas propietarios 30 a 50 anos : "<< promedioEdades(casa, 5) << endl;

	cout << "Casas con propietarios menores: "<< contarMenores(casa, 5) << endl;
}
//================================EJERCICIO 10 ==================================
class Autor {
private:
	string nombre;
	string nacionalidad;
	int cantLibrosP;

public:
	Autor() {
		this->nombre = "";
		this->nacionalidad = "";
		this->cantLibrosP = 0;
	}
	Autor(string nombre, string nacionalidad, int cantidad) {
		this->nombre = nombre;
		this->nacionalidad = nacionalidad;
		this->cantLibrosP = cantidad;
	}

	int getCantidad() {
		return cantLibrosP;
	}
	string getNombre() {
		return nombre;
	}
};

class Libro {
private:
	string titulo;
	float precio;
	Autor autor;

public:
	Libro(string titulo, float precio, Autor autor)
	{
		this->titulo = titulo;
		this->precio = precio;
		this->autor = autor;
	}
	float getPrecio() {
		return precio;
	}

	Autor getAutor() {
		return autor;
	}
	bool esBestSeller() {
		return autor.getCantidad() > 5;
	}

};
//METODOS
float promedioPrecio(Libro libro[], int n, int N) { //N: cantidad de numero publicados 

	float suma = 0;
	int contador = 0;
	for (int i = 0; i < n; i++) {
		if (libro[i].getAutor().getCantidad() > N) {
			suma =suma + libro[i].getPrecio();
			contador++;
		}
	}

	if (contador > 0) {
		return suma / contador;
	} else { return 0; }
}
//Nos damos datos: Autor reconocido vendio mas de 5 libros
//Autor novatos vendio 2 o menos libros y Autor productivo vendio de 3 a 5 libros
float libroMasCaroR(Libro libro[], int n) {

	float mayor = 0;
	for (int i = 0; i < n; i++) {

		if (libro[i].getAutor().getCantidad() > 5 && libro[i].getPrecio() > mayor) {
			mayor = libro[i].getPrecio();
		}
	}
	return mayor;
}
float totalPr(Libro libro[], int n) {

	float total = 0;
	for (int i = 0; i < n; i++) {
		int cantidad = libro[i].getAutor().getCantidad();

		if (cantidad >= 3 && cantidad <= 5) {
			total = total + libro[i].getPrecio();
		}
	}
	return total;
}
int contarLNov(Libro libro[], int n) {

	int contador = 0;
	for (int i = 0; i < n; i++) {

		if (libro[i].getAutor().getCantidad() <= 2) {
			contador++;
		}
	}
	return contador;
}

void ejer10() {
	cout << endl;
	cout << "==============EJERICICIO 10=====================" << endl;

	Autor autor[5];
	autor[0] = Autor("Juan", "Boliviano", 7);   // reconocido
	autor[1] = Autor("Maria", "Peruana", 2);    // novato
	autor[2] = Autor("Luis", "Chileno", 4);     // productivo
	autor[3] = Autor("Ana", "Argentina", 1);    // novato
	autor[4] = Autor("Pedro", "Mexicano", 6);   // reconocido

	Libro libro[5] = {
		Libro("Libro1", 50, autor[0]),
		Libro("Libro2", 30, autor[1]),
		Libro("Libro3", 70, autor[2]),
		Libro("Libro4", 20, autor[3]),
		Libro("Libro5", 90, autor[4])
	};
	int cl;
	cout << "Para calcular promedio de precio de los libros cuyos autores" << endl;
	cout << "tengan mas de N libros publicados.Asignar un valor a N: ";
	cin >> cl;
	cout << endl;
	cout << "Promedio de precio de libros cuyos autores tengan mas de "<<cl<<" libros: " << promedioPrecio(libro, 5, cl) << endl;
	cout << "Promedio de precio de autores best seller: "<< promedioPrecio(libro, 5, 5) << endl;

	cout << "Libro mas caro de autor reconocido: " << libroMasCaroR(libro, 5) << endl;

	cout << "Cantidad libros de autores novatos: "<< contarLNov(libro, 5) << endl;

	cout << "Total recaudado por autores productivos: " << totalPr(libro, 5) << endl;
}
//================================EJERCICIO 11 ==================================
class Carrera {
private:
	string nombre;
	int duracion;
	int cupoDis;

public:
	Carrera() {
		this->nombre = "";
		this->duracion = 0;
		this->cupoDis = 0;
	}
	Carrera(string nombre, int duracion, int cupoDis) {
		this->nombre = nombre;
		this->duracion = duracion;
		this->cupoDis = cupoDis;
	}
	int getDuracion() {
		return duracion;
	}
	string getNombre() {
		return nombre;
	}
	int getCupoDis() {
		return cupoDis;
	}
};

class Estudiante {
private:
	string nombre;
	int edad;
	Carrera carrera;

public:
	Estudiante(string nombre, int edad, Carrera carrera)
	{
		this->nombre = nombre;
		this->edad = edad;
		this->carrera = carrera;
	}
	int getEdad() {
		return edad;
	}
	string getNombre() {
		return nombre;
	}
	Carrera getCarrera() {
		return carrera;
	}
	bool puedeInscribirse() {
		return edad >= MAYOR_DE_EDAD && carrera.getCupoDis() > 0;
	}
};
int contarIns(Estudiante est[], int n) {

	int contador = 0;
	for (int i = 0; i < n; i++) {
		if (est[i].puedeInscribirse()) {
			contador++;
		}
	}
	return contador;
}
string ECarreralarga(Estudiante est[], int n) {

	int mayor = 0;
	string nombre = "";
	for (int i = 0; i < n; i++) {

		if (est[i].getCarrera().getDuracion() > mayor) {
			mayor = est[i].getCarrera().getDuracion();
			nombre = est[i].getNombre();
		}
	}
	return nombre;
}
float promEdadCD(Estudiante est[], int n) {

	float suma = 0;
	int contador = 0;
	for (int i = 0; i < n; i++) {

		if (est[i].getCarrera().getCupoDis() > 0) {
			suma =suma + est[i].getEdad();
			contador++;
		}
	}
	if (contador > 0) {
		return suma / contador;
	}
	else { return 0; }
}
int sinCupo(Estudiante est[], int n) {

	int contador = 0;
	for (int i = 0; i < n; i++) {

		if (est[i].getCarrera().getCupoDis() == 0) {
			contador++;
		}
	}
	return contador;
}
int cantidadPorCarrera(Estudiante est[], int n, string nomC) {

	int contador = 0;
	for (int i = 0; i < n; i++) {

		if (est[i].getCarrera().getNombre() == nomC) {
			contador++;
		}
	}
	return contador;
}
void ejer11() {
	cout << endl;
	cout << "==============EJERICICIO 11=====================" << endl;

	Carrera carrera[3];

	carrera[0] = Carrera("Ingenieria", 5, 30);
	carrera[1] = Carrera("Medicina", 7, 0);
	carrera[2] = Carrera("Derecho", 4, 20);

	Estudiante est[5] = {
		Estudiante("Ana", 19, carrera[0]),
		Estudiante("Luis", 17, carrera[1]),
		Estudiante("Maria", 22, carrera[2]),
		Estudiante("Pedro", 20, carrera[1]),
		Estudiante("Laura", 18, carrera[0])
	};

	cout << "Estudiantes que pueden inscribirse (mayores de edad y cupo dis en carrera): " << contarIns(est, 5) << endl;
	cout << "Estudiante con carrera mas larga: " << ECarreralarga(est, 5) << endl;
	cout << "Promedio de la edad de Estudiantes con cupo: " << promEdadCD(est, 5) << endl;
	cout << "Cantidad de estudiantes sin cupo: " << sinCupo(est, 5) << endl;
	cout << "Cantidad de estudiantes en Ingenieria: " << cantidadPorCarrera(est, 5, "Ingenieria") << endl;
	cout << "Cantidad de estudiantes en Medicina " << cantidadPorCarrera(est, 5, "Medicina") << endl;
	cout << "Cantidad de estudiantes en Derecho: " << cantidadPorCarrera(est, 5, "Derecho") << endl;
}


int main()
{
	ejer7();
	ejer8();
	ejer9();
	ejer10();
	ejer11();
}

