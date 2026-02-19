
#include <iostream>
#define TAM 50
#include <string>
using namespace std;

// EJR 1 

class Cliente {
private:
    string NombreCLI;
    string NIT;
    string Telefono;
    int Edad;
public:
    Cliente(){
        NombreCLI = "";
        NIT = "";
        Telefono = "";
        Edad = 0;
    }
    Cliente(string nombreCli,string nitCli,string telefonoCli,int edadCli) {
        this->NombreCLI = nombreCli;
        this->NIT = nitCli;
        this->Telefono = telefonoCli;
        this->Edad = edadCli;
    }
    void MostrarCliente() const {
        cout << "Nombre:" << NombreCLI << endl;
        cout << "Edad:"<<Edad << endl;
        cout << "NIT: " << NIT << endl;
        cout << "Telefono: " << Telefono << endl;
    }
    ///SETTERS
    void setNombreCli(string NuevoNomCli) {
        NombreCLI = NuevoNomCli;
    }
    void setNIT(string NuevoNIT) {
        NIT = NuevoNIT;
    }
    void setTelefono(string NuevoTelefono){
        Telefono = NuevoTelefono;
    }
    void setEdad(int nuvEdad) {
        Edad = nuvEdad;
    }
    ///GETTERS
    string getNombreCli() const {
        return NombreCLI;
    }
    string getNIT() const {
        return NIT;
    }
    string getTelefono() const {
        return Telefono;
    }
    int getEdad() const{
        return Edad;
    }
};

class Factura {
private:
    int CantProductos;
    int Monto;
    Cliente cliente;
public:
    Factura() {
        CantProductos = 0;
        Monto = 0;
    }
    Factura(int cantProd, int montoP, Cliente clienteS,int cantidad){
        this->CantProductos = cantProd;
        this->Monto = montoP;
        this->cliente = clienteS;
    }
    void MostrarFactura(){
        cout << "Cantidad De Productos:" << CantProductos << endl;
        cout << "Monto Total:" << Monto << endl;
        cliente.MostrarCliente();
    }
    ///Setter
    void setMonto(int NuvMonto) {
        Monto = NuvMonto;
    }
    //Getter
    int getMonto() const {
        return Monto;
    }
    
};


// EJR 2


class Cliente2 {
private:
    string NomCliente;
    string Direccion;
    string Celular;
public:
    Cliente2() {
        NomCliente = "";
        Direccion = "";
        Celular = "";
    }
    Cliente2(string nomCli, string direc, string celu) {
        this->NomCliente = nomCli;
        this->Direccion = direc;
        this->Celular = celu;
    }
    void MostrarCliente2() {
        cout << "Nombre: " << NomCliente << endl;
        cout << "Direccion: " << Direccion << endl;
        cout << "Celular" << Celular << endl;
    }
    //Setter 
    void setNombre(string nvuNOM) {
        NomCliente = nvuNOM;
    }
    void setDireccion(string nvuDir) {
        Direccion = nvuDir;
    }
    void setCelular(string nvuCelu) {
        Celular = nvuCelu;
    }
    //Getter
    string getNombre() const{
        return NomCliente;
    }
    string getDireccion() const{
        return Direccion;
    }
    string getCelular() const{
        return Celular;
    }
};


class Pedido {
private:
    int NumPedido;
    int cantPedidos;
    double Monto_Total;
    Cliente2 Clin2;
public:
    Pedido(){
    NumPedido = 0;
    cantPedidos = 0;
    Monto_Total = 0;
    }
    Pedido(int numP, int cantP, double mntP,Cliente2 clinP) {
        this->NumPedido = numP;
        this->cantPedidos = cantP;
        this->Monto_Total = mntP;
        Clin2.MostrarCliente2();
    }
    //SETTER
    void stenumP(int NvunumP) {
        NumPedido = NvunumP;
    }
    void setMontoP(int Nvumonto) {
        Monto_Total = Nvumonto;
    }
    void setCantP(int NvuCant) {
        cantPedidos = NvuCant;
    }
    //GETTER
    int getNumPed() const{
        return NumPedido;
    }
    int getCantP() const{
        return cantPedidos;
    }
    int MontoT() const{
        return Monto_Total;
    }
};


// EJR 3 

class Autor {
private:
    string NomArt;
    string Nacionalidad;
    int CantidadDeLibrosPublicados;
public:
    Autor() {
        NomArt = "";
        Nacionalidad = "";
        CantidadDeLibrosPublicados = 0;
    }
    Autor(string nomA, string Nld, int cantL) {
        this->NomArt = nomA;
        this->Nacionalidad = Nld;
        this->CantidadDeLibrosPublicados = cantL;
    }
    void MostrarAutor() {
        cout << "Nombre: " << NomArt << endl;
        cout << "Nacionalidad: " << Nacionalidad << endl;
        cout << "Cantidad De libros publicado: " << CantidadDeLibrosPublicados << endl;
    }
    //Setter
    void setNomArt(string NvuNomArt){
        NomArt = NvuNomArt;
    }
    void setNacionalidad(string NvuNacionalidad) {
        Nacionalidad = NvuNacionalidad;
    }
    void setCantidadLibros(int NvoCant) {
        CantidadDeLibrosPublicados = NvoCant;
    }
    //Getter
    string getNomArt()const{
        return NomArt;
    }
    string getNacionalidad()const {
        return Nacionalidad;
    }
    int getCantLibros()const {
        return CantidadDeLibrosPublicados;
    }
};


class Libro{
private:
    string Titulo;
    int precio;
    Autor Genero;
public:
    Libro(string tutuloL,int precioL,Autor GenL) {
        this->Titulo = tutuloL;
        this->precio = precioL;
        this->Genero = GenL;
    }
    void MostrarLibro() {
        cout << "Titulo: " << Titulo << endl;
        cout << "Precio:" << precio << endl;
        Genero.MostrarAutor();
    }
    bool EsBestSeller() {

    }
    void CantLibros() {
        int contadorLibros = 0;
        for (int i = 0;i < Genero.getCantLibros();i++) {
            if (Genero.getCantLibros() > 5) {
                contadorLibros = contadorLibros + precio;
            }
        }
    }
};



// EJR 4

class Estudiante {
private:
    string NombreEs;
    int Edad;
public:
    Estudiante() {
        NombreEs = "";
        Edad = 0;
    }
    Estudiante(string NomEs, int edadES) {
        this->NombreEs = NomEs;
        this->Edad = edadES;
    }
    void MostrarEstudiante() {
        cout << "Nombre:" << NombreEs << endl;
        cout << "Edad: " << Edad << endl;
    }
    //Setter
    void setEdad(int NvaEdad) {
        Edad = NvaEdad;
    }
    //Getter 
    string getNom() const{
        return NombreEs;
    }
    int getEdad() const{
        return Edad;
    }
};

class Carrera {
private:
    string CarreraU;
    int Semestre;
    Estudiante Alumno;
public:
    Carrera() {
        CarreraU="";
        Semestre = 0;
    }
    Carrera(string CarrU,int semU,Estudiante Alum) {
        this->CarreraU = CarrU;
        this->Semestre = semU;
        this->Alumno = Alum;
    }
    void MostrarCarrera() {
        cout << "Carrera: "<<CarreraU <<endl;
        cout << "Semestre: " << Semestre << endl;
        Alumno.MostrarEstudiante();
    }
    //setters 
    void setSemestre(int NvuSemestre){
        Semestre = NvuSemestre;
    }
    void setCarrera(string NvuCarrera) {
        CarreraU = NvuCarrera;
    }
    //Getters
    int getSemestre() {
        return Semestre;
    }
    string getCarrera() {
        return CarreraU;
    }
};







int main(){
   // EJR 1:

    /*

    Factura Antiguedad[TAM];
    Cliente c1("Juan", "12345", "555-6567", 29);
    Cliente c2("Ivan", "67890", "555-7564", 34);
    Cliente c3("Samy","68594","555-4233",21);
   // Antiguedad[0] = Factura(10,350,c1);
    //Antiguedad[1] = Factura(5, 75, c2);
   // Antiguedad[2] = Factura(8,110,c3);
    //Monto total;
    
    
    int MontoTotal = 0;
    for (int i = 0;i < TAM;i++) {
            MontoTotal = MontoTotal + Antiguedad[i].getMonto();
    }
    cout << "Monto Total:" << MontoTotal << endl;
    
   
   //Facturas "NORMALES"


    int contador=0;
    for (int i = 0;i < 3;i++) {
        contador = 1 + contador;
    }
    cout << "Cantidad de Clientes:" << contador << endl;


    //Promedio de Facturas
    int prom = 0;
    for (int i = 0;i < TAM;i++) {
        Antiguedad[i];
        prom = prom + 1;
    }
    cout << "Promedio de facturas: " << prom / 3 << endl;

    */

    //EJR 2

    Pedido pedidos[5];

    Cliente2 cl1("Omar", "Av.Antezana", "555-9858");
    Cliente2 cl2("Yessica","Av.Circunvalacion","555-2444");
    Cliente2 cl3("Norman", "Av.Blanco Galindo", "555-4342");
    
    pedidos[1] = Pedido(8,10,50,cl1);
    pedidos[2] = Pedido(5, 7, 105, cl2);
    pedidos[3] = Pedido(7, 13, 99, cl3);
    int contadorP = 0;
    for (int i = 0;i < 10;i++) {
        if (pedidos[i].getCantP()>100) {
            contadorP++;
        }
    }
    cout << "Cantidad de productos mayores:" << contadorP << endl;

    //EJR 3

    Libro milibro[10];
    milibro[0] = Libro("La iliada", 50);
    milibro[1] = Libro("La iliada", 50);
    milibro[2] = Libro("Harry Potter", 50);
    milibro[3] = Libro("100 anios de soledad", 30);
    for (int i = 0;i < 4;i++) {
        milibro->MostrarLibro();
    }

    //EJR 4

    Carrera CARR[5];

    Estudiante es("Julian", 25);
    Estudiante es2("Mohammad", 22);
    Estudiante es3("Lisa", 20);
    Estudiante es4("Fabiana", 23);


    CARR[0] = Carrera("Sistemas",4,es);
    CARR[1] = Carrera("Medicina", 3, es2);
    CARR[2] = Carrera("Psicologia", 2, es3);
    CARR[3] = Carrera("Civil", 5, es4);
    
    CARR[0].MostrarCarrera();
    CARR[1].MostrarCarrera();
    CARR[2].MostrarCarrera();
    CARR[3].MostrarCarrera();





}

