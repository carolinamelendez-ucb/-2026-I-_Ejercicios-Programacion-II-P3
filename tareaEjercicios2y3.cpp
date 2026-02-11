#include <iostream>
#include <string>

using namespace std;

// Ejercicio 2

class Persona {
private:
    string nombre;
    int edad;
    string DNI;
    string sexo;
    int peso;
    int altura;

    void comprobarSexo(string s) {
        if (s != "H" && s != "M") {
            sexo = "H";
        }
        else {
            sexo = s;
        }
    }

    void generaDNI() {
        int numero = 12345678;

        if (nombre.length() > 0) {
            int suma = 0;
            for (int i = 0; i < nombre.length(); i++) {
                suma += nombre[i];
            }
            numero = 10000000 + (suma % 90000000);
        }

        string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
        int resto = numero % 23;
        string letra = "";
        letra += letras[resto];

        DNI = to_string(numero) + letra;
    }

public:
    string getNombre() {
        return nombre;
    }

    int getEdad() {
        return edad;
    }

    string getDNI() {
        return DNI;
    }

    string getSexo() {
        return sexo;
    }

    int getPeso() {
        return peso;
    }

    int getAltura() {
        return altura;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setEdad(int edad) {
        this->edad = edad;
    }

    void setSexo(string sexo) {
        comprobarSexo(sexo);
    }

    void setPeso(int peso) {
        this->peso = peso;
    }

    void setAltura(int altura) {
        this->altura = altura;
    }

    Persona() {
        nombre = "";
        edad = 0;
        sexo = "H";
        peso = 0;
        altura = 0;
        generaDNI();
    }

    Persona(string nombre, int edad, string sexo) {
        this->nombre = nombre;
        this->edad = edad;
        comprobarSexo(sexo);
        this->peso = 0;
        this->altura = 0;
        generaDNI();
    }

    Persona(string nombre, int edad, string sexo, int peso, int altura) {
        this->nombre = nombre;
        this->edad = edad;
        comprobarSexo(sexo);
        this->peso = peso;
        this->altura = altura;
        generaDNI();
    }

    int calcularMC() {
        if (altura <= 0) return 0;

        int imc = peso / (altura * altura);

        if (imc < 20) {
            return -1;
        }
        else if (imc >= 20 && imc <= 25) {
            return 0;
        }
        else {
            return 1;
        }
    }

    bool esMayorDeEdad() {
        return edad >= 18;
    }

    string toString() {
        string estadoPeso;
        int resultado = calcularMC();

        if (resultado == -1) {
            estadoPeso = "Debajo del peso ideal";
        }
        else if (resultado == 0) {
            estadoPeso = "Peso ideal";
        }
        else {
            estadoPeso = "Sobrepeso";
        }

        string info = "=== Informacion de la persona ===\n";
        info += "Nombre: " + nombre + "\n";
        info += "Edad: " + to_string(edad) + "\n";
        info += "DNI: " + DNI + "\n";
        info += "Sexo: " + sexo + "\n";
        info += "Peso: " + to_string(peso) + " kg\n";
        info += "Altura: " + to_string(altura) + " m\n";

        if (esMayorDeEdad()) {
            info += "Mayor de edad: Si\n";
        }
        else {
            info += "Mayor de edad: No\n";
        }

        info += "Estado de peso: " + estadoPeso + "\n";

        return info;
    }

    void mostrar() {
        cout << toString() << endl;
    }
};

// Ejercicio 3

class Password {
private:
    int longitud;
    string contrasena;

    string generarCaracter() {
        string caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        static int contador = 0;
        contador++;
        int indice = (contador * 7 + longitud * 3) % caracteres.length();
        string resultado = "";
        resultado += caracteres[indice];
        return resultado;
    }

public:
    int getLongitud() {
        return longitud;
    }

    string getContrasena() {
        return contrasena;
    }

    void setLongitud(int longitud) {
        this->longitud = longitud;
        generarPassword();
    }

    Password() {
        longitud = 8;
        generarPassword();
    }

    Password(int longitud) {
        this->longitud = longitud;
        generarPassword();
    }

    void generarPassword() {
        contrasena = "";
        for (int i = 0; i < longitud; i++) {
            contrasena += generarCaracter();
        }
    }

    bool esFuerte() {
        int mayusculas = 0;
        int minusculas = 0;
        int numeros = 0;

        for (int i = 0; i < contrasena.length(); i++) {
            char c = contrasena[i];

            if (c >= 'A' && c <= 'Z') {
                mayusculas++;
            }
            else if (c >= 'a' && c <= 'z') {
                minusculas++;
            }
            else if (c >= '0' && c <= '9') {
                numeros++;
            }
        }

        return (mayusculas > 2 && minusculas > 1 && numeros > 5);
    }

    void mostrar() {
        cout << "=== Informacion de la contrasena ===" << endl;
        cout << "Longitud: " << longitud << endl;
        cout << "Contrasena: " << contrasena << endl;
        cout << "Es fuerte: " << (esFuerte() ? "Si" : "No") << endl;
        cout << endl;
    }
};

void ejercicio2() {
    cout << "\n========== Ejercicio 2: Clase persona ==========\n" << endl;

    Persona persona1;
    persona1.setNombre("Juan Perez");
    persona1.setEdad(25);
    persona1.setSexo("H");
    persona1.setPeso(70);
    persona1.setAltura(1);
    cout << "--- Persona 1 ---" << endl;
    persona1.mostrar();

    Persona persona2("Maria Garcia", 17, "M");
    persona2.setPeso(55);
    persona2.setAltura(1);
    cout << "--- Persona 2 ---" << endl;
    persona2.mostrar();

    Persona persona3("Carlos Lopez", 30, "H", 85, 1);
    cout << "--- Persona 3 ---" << endl;
    persona3.mostrar();

    Persona persona4("Ana Martinez", 22, "X");
    persona4.setPeso(60);
    persona4.setAltura(1);
    cout << "--- Persona 4 ---" << endl;
    persona4.mostrar();
}

void ejercicio3() {
    cout << "\n========== Ejercicio 3: Clase password ==========\n" << endl;

    Password pass1;
    cout << "--- Password 1 ---" << endl;
    pass1.mostrar();

    Password pass2(12);
    cout << "--- Password 2 ---" << endl;
    pass2.mostrar();

    Password pass3(10);
    cout << "--- Password 3 ---" << endl;
    cout << "Contrasena original: " << pass3.getContrasena() << endl;
    cout << "¿Es fuerte? " << (pass3.esFuerte() ? "Si" : "No") << endl << endl;

    pass3.setLongitud(15);
    cout << "--- Password 3 ---" << endl;
    cout << "Contrasena modificada: " << pass3.getContrasena() << endl;
    cout << "¿Es fuerte? " << (pass3.esFuerte() ? "Si" : "No") << endl;
    cout << endl;

    cout << "--- Prueba con diferentes longitudes ---" << endl;
    Password pass4(4);
    cout << "Longitud 4: " << pass4.getContrasena() << " - Fuerte: " << (pass4.esFuerte() ? "Si" : "No") << endl;
    Password pass5(8);
    cout << "Longitud 8: " << pass5.getContrasena() << " - Fuerte: " << (pass5.esFuerte() ? "Si" : "No") << endl;
    Password pass6(16);
    cout << "Longitud 16: " << pass6.getContrasena() << " - Fuerte: " << (pass6.esFuerte() ? "Si" : "No") << endl;
    Password pass7(20);
    cout << "Longitud 20: " << pass7.getContrasena() << " - Fuerte: " << (pass7.esFuerte() ? "Si" : "No") << endl;
    cout << endl;
}

// Funcion principal
int main() {
    ejercicio2();
    ejercicio3();
    return 0;
}