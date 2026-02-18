#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
///EJERCICIO 7 (Ref. Ejer 2)
class ClienteFactura {
private:
	string nombre;
	string tipo;
	int antiguedad;
public:
	ClienteFactura() {
		this->nombre = "";
		this->tipo = "";
		this->antiguedad = 0;
	}
	ClienteFactura(string nombre, string tipo, int antiguedad) {
		this->nombre = nombre;
		this->tipo = tipo;
		this->antiguedad = antiguedad;
	}
	string getNombre() {
		return this->nombre;
	}
	string getTipo() {
		return this->tipo;
	}
	int getAntiguedad() {
		return this->antiguedad;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setTipo(string tipo) {
		this->tipo = tipo;
	}
	void setAntiguedad(int antiguedad) {
		this->antiguedad = antiguedad;
	}
};
class Factura {
private:
	int numero;
	float montoBase;
	ClienteFactura cliente;
	bool pagada;
public:
	Factura() {
		this->numero = 0;
		this->montoBase = 0.0;
		this->pagada = false;
	}
	Factura(int numero, float montoBase, ClienteFactura cliente, bool pagada) {
		this->numero = numero;
		this->montoBase = montoBase;
		this->cliente = cliente;
		this->pagada = pagada;
	}
	double calcularTotal() {
		double total = montoBase;
		if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 2) {
			total = montoBase * 0.9;
		}
		return total;
	}
	int getNumero() {
		return numero;
	}
	float getMontoBase() {
		return montoBase;
	}
	ClienteFactura getCliente() {
		return cliente;
	}
	bool getPagada() {
		return pagada;
	}
	void setNumero(int numero) {
		this->numero = numero;
	}
	void setMontoBase(float montoBase) {
		this->montoBase = montoBase;
	}
	void setCliente(ClienteFactura cliente) {
		this->cliente = cliente;
	}
	void setPagada(bool pagada) {
		this->pagada = pagada;
	}
};
///EJERCICIO 8 (Ref. Ejer 3)
class ClientePedido {
private:
	string nombre;
	float saldoDisponible;
	bool habilitado;
public:
	ClientePedido() {
		this->nombre = "";
		this->saldoDisponible = 0;
		this->habilitado = false;
	}
	ClientePedido(string nombre, float saldoDisponible, bool habilitado) {
		this->nombre = nombre;
		this->saldoDisponible = saldoDisponible;
		this->habilitado = habilitado;
	}
	string getNombre() {
		return this->nombre;
	}
	float getSaldoDisponible() {
		return this->saldoDisponible;
	}
	bool getHabilitado() {
		return this->habilitado;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setSaldoDisponible(float saldoDisponible) {
		this->saldoDisponible = saldoDisponible;
	}
	void setHabilitado(bool habilitado) {
		this->habilitado = habilitado;
	}
};
class Pedido {
private:
	string codigo;
	float importe;
	ClientePedido cliente;
public:
	Pedido() {
		this->codigo = "";
		this->importe = 0;
	}
	Pedido(string pedido, float importe, ClientePedido cliente) {
		this->codigo = codigo;
		this->importe = importe;
		this->cliente = cliente;
	}
	bool puedeConfirmarse() {
		if (cliente.getHabilitado() && cliente.getSaldoDisponible() >= importe) {
			return true;
		}
		return false;
	}
	string getCodigo() {
		return codigo;
	}
	float getImporte() {
		return importe;
	}
	ClientePedido getCliente() {
		return cliente;
	}
	void setCodigo(string codigo) {
		this->codigo = codigo;
	}
	void setImporte(float importe) {
		this->importe = importe;
	}
	void setCliente(ClientePedido cliente) {
		this->cliente = cliente;
	}
};
///EJERCICIO 9 (Ref. Ejer 4)
class Propietario {
private:
	string nombre;
	string DNI;
	int edad;
public:
	Propietario() {
		this->nombre = "";
		this->DNI = "";
		this->edad = 0;
	}
	Propietario(string nombre, string DNI, int edad) {
		this->nombre = nombre;
		this->DNI = DNI;
		this->edad = edad;
	}
	string getNombre() {
		return this->nombre;
	}
	string getDNI() {
		return this->DNI;
	}
	int getEdad() {
		return this->edad;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setDNI(string DNI) {
		this->DNI = DNI;
	}
	void setEdad(int edad) {
		this->edad = edad;
	}
};
class Casa {
private:
	string direccion;
	float precio;
	Propietario propietario;
public:
	Casa() {
		this->direccion = "";
		this->precio = 0;
	}
	Casa(string direccion, float precio, Propietario propietario) {
		this->direccion = direccion;
		this->precio = precio;
		this->propietario = propietario;
	}
	bool esPropietarioValido() {
		if (propietario.getEdad() >= 18) {
			return true;
		}
		return false;
	}
	string getDireccion() {
		return direccion;
	}
	float getPrecio() {
		return precio;
	}
	Propietario getPropietario() {
		return propietario;
	}
	void setDireccion(string direccion) {
		this->direccion = direccion;
	}
	void setPrecio(float precio) {
		this->precio = precio;
	}
	void setPropietario(Propietario propietario) {
		this->propietario = propietario;
	}
};
///EJERCICIO 10 (Ref. Ejer 5)
class Autor {
private:
	string nombre;
	string nacionalidad;
	int cantLibrosPublicados;
public:
	Autor() {
		this->nombre = "";
		this->nacionalidad = "";
		this->cantLibrosPublicados = 0;
	}
	Autor(string nombre, string nacionalidad, int cantLibrosPublicados) {
		this->nombre = nombre;
		this->nacionalidad = nacionalidad;
		this->cantLibrosPublicados = cantLibrosPublicados;
	}
	string getNombre() {
		return this->nombre;
	}
	string getNacionalidad() {
		return this->nacionalidad;
	}
	int getCantLibrosPublicados() {
		return this->cantLibrosPublicados;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setNacionalidad(string nacionalidad) {
		this->nacionalidad = nacionalidad;
	}
	void setCantLibrosPublicados(int cantLibrosPublicados) {
		this->cantLibrosPublicados = cantLibrosPublicados;
	}
};
class Libro {
private:
	string titulo;
	float precio;
	Autor autor;
public:
	Libro() {
		this->titulo = "";
		this->precio = 0;
	}
	Libro(string titulo, float precio, Autor autor) {
		this->titulo = titulo;
		this->precio = precio;
		this->autor = autor;
	}
	bool esBestSeller() {
		if (autor.getCantLibrosPublicados() > 5) {
			return true;
		}
		return false;
	}
	string getTitulo() {
		return titulo;
	}
	float getPrecio() {
		return precio;
	}
	Autor getAutor() {
		return autor;
	}
	void setTitulo(string titulo) {
		this->titulo = titulo;
	}
	void setPrecio(float precio) {
		this->precio = precio;
	}
	void setAutor(Autor autor) {
		this->autor = autor;
	}
};
///EJERCICIO 11 (Ref. Ejer 6)
class Carrera {
private:
	string nombre;
	int duracion;
	int cupoDisponible;
public:
	Carrera() {
		this->nombre = "";
		this->duracion = 0;
		this->cupoDisponible = 0;
	}
	Carrera(string nombre, int duracion, int cupoDisponible) {
		this->nombre = nombre;
		this->duracion = duracion;
		this->cupoDisponible = cupoDisponible;
	}
	string getNombre() {
		return this->nombre;
	}
	int getDuracion() {
		return this->duracion;
	}
	int getCupoDisponible() {
		return this->cupoDisponible;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setDuracion(int duracion) {
		this->duracion = duracion;
	}
	void setCupoDisponible(int cupoDisponible) {
		this->cupoDisponible = cupoDisponible;
	}
};
class Estudiante {
private:
	string nombre;
	int edad;
	Carrera carrera;
public:
	Estudiante() {
		this->nombre = "";
		this->edad = 0;
	}
	Estudiante(string nombre, int edad, Carrera carrera) {
		this->nombre = nombre;
		this->edad = edad;
		this->carrera = carrera;
	}
	bool puedeInscribirse() {
		if (carrera.getCupoDisponible() > 0) {
			return true;
		}
		return false;
	}
	string getNombre() {
		return nombre;
	}
	int getEdad() {
		return edad;
	}
	Carrera getCarrera() {
		return carrera;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setEdad(int edad) {
		this->edad = edad;
	}
	void setCarrera(Carrera carrera) {
		this->carrera = carrera;
	}
};
///EJERCICIO 7
double montoTotalClienteFrecuente(Factura facturas[], int cant) {
	float total = 0;
	for (int i = 0; i < cant; i++) {
		ClienteFactura cliente = facturas[i].getCliente();
		if (cliente.getTipo() == "frecuente" && cliente.getAntiguedad() > 5) {
			total = total + facturas[i].calcularTotal();
		}
	}
	return total;
}
int contarFacturasClientesNormales(Factura facturas[], int cant) {
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (facturas[i].getCliente().getTipo() == "normal") {
			contador++;
		}
	}
	return contador;
}
void mostrarFacturaMayorMontoFrecuente(Factura facturas[], int cant) {
	float mayorMonto = 0;
	int indiceMayor = -1;
	for (int i = 0; i < cant; i++) {
		if (facturas[i].getCliente().getTipo() == "frecuente") {
			float monto = facturas[i].calcularTotal();
			if (monto > mayorMonto) {
				mayorMonto = monto;
				indiceMayor = i;
			}
		}
	}
	if (indiceMayor != -1) {
		cout << "Factura de mayor monto para cliente frecuente: " << endl;
		cout << "Numero: " << facturas[indiceMayor].getNumero() << endl;
		cout << "Monto Total: Bs. " << mayorMonto << endl;
		cout << "Cliente: " << facturas[indiceMayor].getCliente().getNombre() << endl;
	} else {
		cout << "No hay facturas de clientes frecuentes" << endl;
	}
}
float promedioMontoClientesMas5Anios(Factura facturas[], int cant) {
	float suma = 0;
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (facturas[i].getCliente().getAntiguedad() > 5) {
			suma = suma + facturas[i].calcularTotal();
			contador++;
		}
	}
	if (contador > 0) {
		return suma / contador;
	} else {
		return 0;
	}
}
void mostrarImpagasClientesFrecuentes(Factura facturas[], int cant) {
	int contadorImpagas = 0;
	float totalAdeudado = 0;
	for (int i = 0; i < cant; i++) {
		ClienteFactura cliente = facturas[i].getCliente();
		if (cliente.getTipo() == "frecuente" && !facturas[i].getPagada()) {
			contadorImpagas++;
			totalAdeudado = totalAdeudado + facturas[i].calcularTotal();
		}
	}
	cout << "Facturas impagas de clientes frecuentes: " << contadorImpagas << endl;
	cout << "Total adeudado por clientes frecuentes: Bs. " << totalAdeudado << endl;
}
void ejercicio7() {
	cout << "EJERCICIO 7" << endl;
	cout << "-----------------------------------------------------" << endl;
	ClienteFactura cliente1("Diana Mejia", "frecuente", 7);
	ClienteFactura cliente2("Carlos Perez", "normal", 3);
	ClienteFactura cliente3("Ana Gomez", "frecuente", 10);
	ClienteFactura cliente4("Zara Ramirez", "frecuente", 1);
	ClienteFactura cliente5("Luis Torres", "normal", 4);
	Factura facturas[10];
	facturas[0] = Factura(10, 1124, cliente1, true);
	facturas[1] = Factura(11, 235.65, cliente2, true);
	facturas[2] = Factura(12, 1251.14, cliente3, false);
	facturas[3] = Factura(13, 142.1, cliente4, true);
	facturas[4] = Factura(14, 1352.23, cliente5, true);
	facturas[5] = Factura(15, 574, cliente1, true);
	facturas[6] = Factura(16, 1046.39, cliente2, false);
	facturas[7] = Factura(17, 346.2, cliente3, true);
	facturas[8] = Factura(18, 754, cliente4, false);
	facturas[9] = Factura(19, 1643.34, cliente5, false);
	int cantFacturas = 10;
	cout << "Monto total (clientes frecuentes +2 anios): Bs. " << montoTotalClienteFrecuente(facturas, cantFacturas) << endl;
	cout << "Facturas de clientes normales: " << contarFacturasClientesNormales(facturas, cantFacturas) << endl;
	mostrarFacturaMayorMontoFrecuente(facturas, cantFacturas);
	cout << "Promedio monto (clientes +5 anios): Bs. " << promedioMontoClientesMas5Anios(facturas, cantFacturas) << endl;
	mostrarImpagasClientesFrecuentes(facturas, cantFacturas);
	cout << "-----------------------------------------------------------" << endl;
}
///EJERCICIO 8
int contarPedidosConfirmados(Pedido pedidos[], int cant) {
	int contador = 0;
	for (int i=0;i<cant;i++) {
		if (pedidos[i].puedeConfirmarse()) {
			contador++;
		}
	}
	return contador;
}
double importeTotalPedidosConfirmados(Pedido pedidos[], int cant) {
	float total = 0;
	for (int i = 0; i < cant; i++) {
		if (pedidos[i].puedeConfirmarse()) {
			total = total + pedidos[i].getImporte();
		}
	}
	return total;
}
int contarPedidosRechazadosPorSaldo(Pedido pedidos[], int cant) {
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		ClientePedido cliente = pedidos[i].getCliente();
		if (cliente.getHabilitado() && cliente.getSaldoDisponible() < pedidos[i].getImporte()) {
			contador++;
		}
	}
	return contador;
}
void mostrarPedidoMayorImporte(Pedido pedidos[], int cant) {
	float mayorImporte = -1;
	int indiceMayor = -1;
	for (int i = 0; i < cant; i++) {
		if(pedidos[i].getImporte() > mayorImporte) {
		mayorImporte = pedidos[i].getImporte();
		indiceMayor = i;
		}
	}
	if (indiceMayor != -1) {
		cout << "Pedido de mayor importe: " << endl;
		cout << "Codigo: " << pedidos[indiceMayor].getCodigo() << endl;
		cout << "Importe: Bs. " << mayorImporte << endl;
		cout << "Cliente: " << pedidos[indiceMayor].getCliente().getNombre() << endl;
	}
}
string nombreClientePedidoMasCaro(Pedido pedidos[], int cant) {
	float mayorImporte = -1;
	string nombreCliente = "";
	for (int i = 0; i < cant; i++) {
		if (pedidos[i].getImporte() > mayorImporte) {
			mayorImporte = pedidos[i].getImporte();
			nombreCliente = pedidos[i].getCliente().getNombre();
		}
	}
	return nombreCliente;
}
void ejercicio8() {
	cout << "EJERCICIO 8" << endl;
	cout << "-----------------------------------------------------" << endl;
	ClientePedido cliente1("Rosa Illanez", 3300, true);
	ClientePedido cliente2("Kimberly Yave", 1400, true);
	ClientePedido cliente3("Gabriel Estrada", 560, false);
	ClientePedido cliente4("Bernardo Galas", 1500, false);
	ClientePedido cliente5("Julia Flores", 2800, true);
	Pedido pedidos[8];
	pedidos[0] = Pedido("P01", 1600, cliente1);
	pedidos[1] = Pedido("P02", 235, cliente1);
	pedidos[2] = Pedido("P03", 2362, cliente1);
	pedidos[3] = Pedido("P04", 462, cliente1);
	pedidos[4] = Pedido("P05", 670, cliente1);
	pedidos[5] = Pedido("P06", 1112, cliente1);
	pedidos[6] = Pedido("P07", 754, cliente1);
	pedidos[7] = Pedido("P08", 834, cliente1);
	int cantPedidos = 8;
	cout << "Pedidos que pueden confirmarse: " << contarPedidosConfirmados(pedidos, cantPedidos) << endl;
	cout << "Importe total de pedidos confirmados: Bs. " << importeTotalPedidosConfirmados(pedidos, cantPedidos) << endl;
	cout << "Pedidos rechazados por falta de saldo: " << contarPedidosRechazadosPorSaldo(pedidos, cantPedidos) << endl;
	mostrarPedidoMayorImporte(pedidos, cantPedidos);
	cout << "Cliente con el pedido mas caro: " << nombreClientePedidoMasCaro(pedidos, cantPedidos) << endl;
	cout << "----------------------------------------------------------" << endl;
}
///EJERCICIO 9
float precioTotalPropietarioMayoreEdad(Casa casas[], int cant) {
	float total = 0;
	for (int i = 0; i < cant; i++) {
		if (casas[i].getPropietario().getEdad() >= 18) {
			total = total + casas[i].getPrecio();
		}
	}
	return total;
}
int contarCasasPropietariosMayoresEdad(Casa casas[], int cant) {
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (casas[i].getPropietario().getEdad() >= 18) {
			contador++;
		}
	}
	return contador;
}
float precioTotalPropietariosMas60(Casa casas[], int cant) {
	float total = 0;
	for (int i = 0; i < cant; i++) {
		if (casas[i].getPropietario().getEdad() > 60) {
			total = total + casas[i].getPrecio();
		}
	}
	return total;
}
void mostrarCasaMayorValorPropietarioValido(Casa casas[], int cant) {
	float mayorValor = -1;
	int indiceMayor = -1;
	for (int i = 0; i < cant; i++) {
		if (casas[i].esPropietarioValido() && casas[i].getPrecio() > mayorValor) {
			mayorValor = casas[i].getPrecio();
			indiceMayor = i;
		}
	}
	if (indiceMayor != -1) {
		cout << "Casa de mayor valor con propietario valido: " << endl;
		cout << "Direccion: " << casas[indiceMayor].getDireccion() << endl;
		cout << "Precio: Bs. " << mayorValor << endl;
		cout << "Propietario: " << casas[indiceMayor].getPropietario().getNombre() << endl;
	} else {
		cout << "No hay casas con propietario valido" << endl;
	}
}
float promedioValorPropietarios30a50(Casa casas[], int cant) {
	float suma = 0;
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		int edad = casas[i].getPropietario().getEdad();
		if (edad >= 30 && edad <= 50) {
			suma = suma + casas[i].getPrecio();
			contador++;
		}
	}
	if (contador > 0) {
		return suma / contador;
	} else {
		return 0;
	}
}
int contarCasasPropietariosMenoresEdad(Casa casas[], int cant) {
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (casas[i].getPropietario().getEdad() < 18) {
			contador++;
		}
	}
	return contador;
}
void ejercicio9() {
	cout << "EJERCICIO 9" << endl;
	cout << "----------------------------------------------" << endl;
	Propietario propietario1("Cristian Loza", "521251A", 30);
	Propietario propietario2("Mariel Santos", "840636B", 16);
	Propietario propietario3("Julieta Martinez", "390236C", 22);
	Propietario propietario4("Nicolas Gales", "275545D", 67);
	Propietario propietario5("Oscar Pinto", "183523E", 14);
	Propietario propietario6("Esmeralda Yucra", "634623F", 27);
	Casa casas[10];
	casas[0] = Casa("Av. Circunvalacion", 453000, propietario1);
	casas[1] = Casa("Av. Beijing", 143500, propietario2);
	casas[2] = Casa("Av. Heroinas", 310000, propietario3);
	casas[3] = Casa("Av. Aroma", 526000, propietario4);
	casas[4] = Casa("Av. Ecologica", 290000, propietario5);
	casas[5] = Casa("Av. Ballivian", 578000, propietario6);
	casas[6] = Casa("Av. Ayacucho", 110000, propietario3);
	casas[7] = Casa("Av. 2da Circunvalacion", 680000, propietario2);
	casas[8] = Casa("Av. America", 477000, propietario6);
	casas[9] = Casa("Av. Oquendo", 321000, propietario4);
	int cantCasas = 10;
	cout << "Precio total (propietarios mayores de edad): Bs. " << precioTotalPropietarioMayoreEdad(casas, cantCasas) << endl;
	cout << "Casas con propietarios mayores de edad: " << contarCasasPropietariosMayoresEdad(casas, cantCasas) << endl;
	cout << "Precio total (propietarios > 60 anios): Bs. " << precioTotalPropietariosMas60(casas, cantCasas) << endl;
	mostrarCasaMayorValorPropietarioValido(casas, cantCasas);
	cout << "Promedio valor (propietarios 30-50 anios): Bs. " << promedioValorPropietarios30a50(casas, cantCasas) << endl;
	cout << "Casas con propietarios menores de edad: " << contarCasasPropietariosMenoresEdad(casas, cantCasas) << endl;
	cout << "-------------------------------------------------------------------" << endl;
}
///EJERCICIO 10
float promPrecioAutoresMasNLibros(Libro libro[], int cant, int n) {
	float suma = 0;
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (libro[i].getAutor().getCantLibrosPublicados() > n) {
			suma = suma + libro[i].getPrecio();
			contador++;
		}
	}
	if (contador > 0) {
		return suma / contador;
	} else {
		return 0;
	}
}
float precioPromedioBestSeller(Libro libro[], int cant) {
	float suma = 0;
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (libro[i].esBestSeller()) {
			suma = suma + libro[i].getPrecio();
			contador++;
		}
	}
	if (contador > 0) {
		return suma / contador;
	} else {
		return 0;
	}
}
void mostrarLibroMasCaroAutorReconocido(Libro libro[], int cant) {
	float mayorPrecio = -1;
	int indiceMayor = -1;
	for (int i = 0 ; i < cant; i++) {
		if (libro[i].getAutor().getCantLibrosPublicados() > 8) {
			if (libro[i].getPrecio() > mayorPrecio) {
				mayorPrecio = libro[i].getPrecio();
				indiceMayor = i;
			}
		}
	}
	if (indiceMayor != -1) {
		cout << "Libro mas caro de autor receonocido: " << endl;
		cout << "Titulo: " << libro[indiceMayor].getTitulo() << endl;
		cout << "Precio: Bs. " << mayorPrecio << endl;
		cout << "Autor: " << libro[indiceMayor].getAutor().getNombre() << endl;
	} else {
		cout << "No hay libros de autores reconocidos" << endl;
	}
}
int contarLibrosAutoresNovatos(Libro libro[], int cant) {
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (libro[i].getAutor().getCantLibrosPublicados() < 3) {
			contador++;
		}
	}
	return contador;
}
float totalRecaudadoAutoresProductivos(Libro libro[], int cant) {
	float total = 0;
	for (int i = 0; i < cant; i++) {
		if (libro[i].getAutor().getCantLibrosPublicados() > 10) {
			total = total + libro[i].getPrecio();
		}
	}
	return total;
}
void ejercicio10() {
	cout << "EJERCICIO 10" << endl;
	cout << "------------------------------------------------------" << endl;
	Autor autor1("Augusto Flores", "Argentina", 20);
	Autor autor2("Valeria Olmos", "Canadiense", 14);
	Autor autor3("Ricardo Rocabado", "Venezolana", 35);
	Autor autor4("Hugo Barrionuevo", "Ecuatoriana", 8);
	Autor autor5("Willy Valdez", "Peruana", 27);
	Autor autor6("Maite Robles", "Boliviana", 9);
	Libro libro[10];
	libro[0] = Libro("En tu soledad eterna", 140, autor1);
	libro[1] = Libro("El sentir de tu alma", 175, autor2);
	libro[2] = Libro("Los perros en la eternidad", 250, autor3);
	libro[3] = Libro("Olvidame", 115, autor4);
	libro[4] = Libro("Como olvidar tu deseo", 95, autor5);
	libro[5] = Libro("La historia de un pajaro", 220, autor6);
	libro[6] = Libro("Sin ser tu mismo", 160, autor3);
	libro[7] = Libro("Sin libertad no hay vida", 275, autor5);
	libro[8] = Libro("Corazon oxidado", 180, autor2);
	libro[9] = Libro("Frio, no se ha partido", 140, autor4);
	int cantLibros = 10;
	int n = 10;
	cout << "Precio promedio (autores > " << n << " libros): Bs. " << promPrecioAutoresMasNLibros(libro, cantLibros, n) << endl;
	cout << "Precio promedio de best sellers: Bs. " << precioPromedioBestSeller(libro, cantLibros) << endl;
	mostrarLibroMasCaroAutorReconocido(libro, cantLibros);
	cout << "Libros de autores novatos (< 3 libros): " << contarLibrosAutoresNovatos(libro, cantLibros) << endl;
	cout << "Total recaudado (autores > 10 libros): Bs. " << totalRecaudadoAutoresProductivos(libro, cantLibros) << endl;
	cout << "------------------------------------------------------------------------" << endl;
}
///EJERCICIO 11
int contarEstudiantesPuedenInscribirse(Estudiante estudiantes[], int cant) {
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (estudiantes[i].puedeInscribirse()) {
			contador++;
		}
	}
	return contador;
}
string nombreEstudianteCarreraMayorDuracion(Estudiante estudiantes[], int cant) {
	int mayorDuracion = -1;
	string nombreEstudiante = "";
	for (int i = 0; i < cant; i++) {
		int duracion = estudiantes[i].getCarrera().getDuracion();
		if (duracion > mayorDuracion) {
			mayorDuracion = duracion;
			nombreEstudiante = estudiantes[i].getNombre();
		}
	}
	return nombreEstudiante;
}
float edadPromedioEstudiantesCarreraConCupo(Estudiante estudiantes[], int cant) {
	float sumaEdades = 0;
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (estudiantes[i].getCarrera().getCupoDisponible() > 0) {
			sumaEdades = sumaEdades + estudiantes[i].getEdad();
			contador++;
		}
	}
	if (contador > 0) {
		return sumaEdades / contador;
	} else {
		return 0;
	}
}
int contarEstudiantesNoInscritosConCupos(Estudiante estudiantes[], int cant) {
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (estudiantes[i].getEdad() >= 18 && estudiantes[i].getCarrera().getCupoDisponible() == 0) {
			contador++;
		}
	}
	return contador;
}
int contadorEstudiantesPorCarrera(Estudiante estudiantes[], int cant, string nombreCarrera) {
	int contador = 0;
	for (int i = 0; i < cant; i++) {
		if (estudiantes[i].getCarrera().getNombre() == nombreCarrera) {
			contador++;
		}
	}
	return contador;
}
void ejercicio11() {
	cout << "EJERCICIO 11" << endl;
	Carrera carrera1("Administracon de Empresas", 4, 20);
	Carrera carrera2("Ingenieria Comercial", 5, 15);
	Carrera carrera3("Medicina", 6, 8);
	Carrera carrera4("Ingenieria de Sistemas", 4, 8);
	Carrera carrera5("Filosofia y Letras", 4, 10);
	Estudiante estudiantes[10];
	estudiantes[0] = Estudiante("Diana Rojas", 19, carrera3);
	estudiantes[1] = Estudiante("Alexander Torrico", 18, carrera1);
	estudiantes[2] = Estudiante("Ester Julianez", 21, carrera2);
	estudiantes[3] = Estudiante("Henrique Naoli", 17, carrera4);
	estudiantes[4] = Estudiante("NIcolas Espejo", 22, carrera5);
	estudiantes[5] = Estudiante("Camila Llanos", 19, carrera1);
	estudiantes[6] = Estudiante("Valentina Reyes", 23, carrera2);
	estudiantes[7] = Estudiante("Roberto Unzueta", 18, carrera3);
	estudiantes[8] = Estudiante("Melissa Hermosillo", 20, carrera4);
	estudiantes[9] = Estudiante("Brenda Corazon", 21, carrera5);
	int cantEstudiantes = 10;
	cout << "Estudiantes que pueden inscribrise: " << contarEstudiantesPuedenInscribirse(estudiantes, cantEstudiantes) << endl;
	cout << "Estudiantes con carrera de mayor duracion: " << nombreEstudianteCarreraMayorDuracion(estudiantes, cantEstudiantes) << endl;
	cout << "Edad Promedio (carreras por cupo): " << edadPromedioEstudiantesCarreraConCupo(estudiantes, cantEstudiantes) << endl;
	cout << "Estudiantes no inscritos por falta de cupos: " << contarEstudiantesNoInscritosConCupos(estudiantes, cantEstudiantes) << endl;
	cout << "Cantidad de estudiantes por carrera: " << endl;
	cout << "- Administracion de empresas: " << contadorEstudiantesPorCarrera(estudiantes, cantEstudiantes, "Administracion de Empresas") << endl;
	cout << "- Ingenieria Comercial: " << contadorEstudiantesPorCarrera(estudiantes, cantEstudiantes, "Ingenieria Comercial") << endl;
	cout << "- Medicina: " << contadorEstudiantesPorCarrera(estudiantes, cantEstudiantes, "Medicina") << endl;
	cout << "- Ingenieria de Sistemas: " << contadorEstudiantesPorCarrera(estudiantes, cantEstudiantes, "Ingenieria de Sistemas") << endl;
	cout << "- Filosofia y Letras: " << contadorEstudiantesPorCarrera(estudiantes, cantEstudiantes, "Filosofia y Letras") << endl;
}
int main() 
{
	srand(time(0));
	ejercicio7();
	ejercicio8();
	ejercicio9();
	ejercicio10();
	ejercicio11();
}
