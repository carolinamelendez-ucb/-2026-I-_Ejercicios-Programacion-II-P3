#include <iostream>
#include <string>
using namespace std;


class Libro {
public:
    string codigo;
    string titulo;
    string autor;
    string estado;       // "Disponible", "Prestado", "En reparación"
    int    vecesPrestado;

    Libro() : vecesPrestado(0), estado("Disponible") {}

    Libro(string cod, string tit, string aut)
        : codigo(cod), titulo(tit), autor(aut),
        estado("Disponible"), vecesPrestado(0) {
    }
};


class Estudiante {
public:
    string  ci;
    string  nombre;
    Libro* libroAsignado;   // nullptr = sin préstamo activo

    Estudiante() : libroAsignado(nullptr) {}

    Estudiante(string ci, string nombre)
        : ci(ci), nombre(nombre), libroAsignado(nullptr) {
    }
};


class Biblioteca {
private:
    string      nombre;
    Libro       listaLibros[100];
    Estudiante  listaEstudiantes[100];
    int         totalLibros;
    int         totalEstudiantes;

    // Busca un libro por código
    Libro* buscarLibro(string codigo) {
        for (int i = 0; i < totalLibros; i++)
            if (listaLibros[i].codigo == codigo)
                return &listaLibros[i];
        return nullptr;
    }

    // Busca un estudiante por CI
    Estudiante* buscarEstudiante(string ci) {
        for (int i = 0; i < totalEstudiantes; i++)
            if (listaEstudiantes[i].ci == ci)
                return &listaEstudiantes[i];
        return nullptr;
    }

public:
    Biblioteca(string nombre)
        : nombre(nombre), totalLibros(0), totalEstudiantes(0) {
    }


    void agregarLibro(string cod, string tit, string aut) {
        if (totalLibros >= 100) {
            cout << "Error: capacidad máxima de libros alcanzada.\n";
            return;
        }
        listaLibros[totalLibros++] = Libro(cod, tit, aut);
        cout << "Libro \"" << tit << "\" registrado correctamente.\n";
    }

   
    void agregarEstudiante(string ci, string nombre) {
        if (totalEstudiantes >= 100) {
            cout << "Error: capacidad máxima de estudiantes alcanzada.\n";
            return;
        }
        listaEstudiantes[totalEstudiantes++] = Estudiante(ci, nombre);
        cout << "Estudiante \"" << nombre << "\" registrado correctamente.\n";
    }

 
    void registrarPrestamo(string ci, string codigoLibro) {
        // Validar existencia
        Libro* libro = buscarLibro(codigoLibro);
        Estudiante* est = buscarEstudiante(ci);

        if (libro == nullptr)
            throw string("ERROR: El libro con código \"" + codigoLibro + "\" no existe.");

        if (est == nullptr)
            throw string("ERROR: El estudiante con CI \"" + ci + "\" no existe.");

        // Validar estado del libro
        if (libro->estado == "Prestado")
            throw string("ERROR: El libro \"" + libro->titulo + "\" ya está prestado.");

        if (libro->estado == "En reparación")
            throw string("ERROR: El libro \"" + libro->titulo + "\" está en reparación.");

        // Validar que el estudiante no tenga préstamo activo
        if (est->libroAsignado != nullptr)
            throw string("ERROR: El estudiante \"" + est->nombre +
                "\" ya tiene prestado el libro \"" +
                est->libroAsignado->titulo + "\".");

    
        libro->estado = "Prestado";
        libro->vecesPrestado++;
        est->libroAsignado = libro;

        cout << "Préstamo registrado: \"" << est->nombre
            << "\" -> \"" << libro->titulo << "\"\n";
    }


    void listarEstudiantes() {
        cout << "\n===== Estudiantes y préstamos activos =====\n";
        bool alguno = false;
        for (int i = 0; i < totalEstudiantes; i++) {
            Estudiante& e = listaEstudiantes[i];
            if (e.libroAsignado != nullptr) {
                cout << "  " << e.nombre << " (CI: " << e.ci
                    << ") -> \"" << e.libroAsignado->titulo << "\"\n";
                alguno = true;
            }
        }
        if (!alguno)
            cout << "  Ningún estudiante tiene préstamo activo.\n";
        cout << "===========================================\n\n";
    }


    void libroMasSolicitado() {
        if (totalLibros == 0) {
            cout << "No hay libros registrados.\n";
            return;
        }
        Libro* mejor = &listaLibros[0];
        for (int i = 1; i < totalLibros; i++)
            if (listaLibros[i].vecesPrestado > mejor->vecesPrestado)
                mejor = &listaLibros[i];

        if (mejor->vecesPrestado == 0) {
            cout << "Ningún libro ha sido prestado aún.\n";
            return;
        }
        cout << "\n===== Libro más solicitado =====\n";
        cout << "  Título : " << mejor->titulo << "\n";
        cout << "  Autor  : " << mejor->autor << "\n";
        cout << "  Código : " << mejor->codigo << "\n";
        cout << "  Préstamos: " << mejor->vecesPrestado << "\n";
        cout << "================================\n\n";
    }
};


int main() {
    Biblioteca bib("LUMEN");


    bib.agregarLibro("L001", "El Quijote", "Cervantes");
    bib.agregarLibro("L002", "Cien años de soledad", "García Márquez");
    bib.agregarLibro("L003", "1984", "Orwell");


    bib.agregarEstudiante("12345678", "Ana Pérez");
    bib.agregarEstudiante("87654321", "Luis Flores");
    bib.agregarEstudiante("11111111", "María López");

    cout << "\n--- Préstamos válidos ---\n";
    try { bib.registrarPrestamo("12345678", "L001"); }
    catch (string e) { cout << e << "\n"; }
    try { bib.registrarPrestamo("87654321", "L002"); }
    catch (string e) { cout << e << "\n"; }
    try { bib.registrarPrestamo("11111111", "L001"); }
    catch (string e) { cout << e << "\n"; }  // ya prestado
    try { bib.registrarPrestamo("87654321", "L003"); }
    catch (string e) { cout << e << "\n"; }  // ya tiene libro
    try { bib.registrarPrestamo("99999999", "L001"); }
    catch (string e) { cout << e << "\n"; }  // CI no existe
    try { bib.registrarPrestamo("12345678", "L999"); }
    catch (string e) { cout << e << "\n"; }  // código no existe


    try { bib.registrarPrestamo("11111111", "L002"); }
    catch (string e) { cout << e << "\n"; }

    bib.listarEstudiantes();
    bib.libroMasSolicitado();

    return 0;
}