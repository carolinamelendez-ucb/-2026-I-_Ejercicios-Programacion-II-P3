#include <iostream>
#include <string>
using namespace std;

class Transporte {
protected:
    string placa;

public:
    Transporte(string placa) {
        this->placa = placa;
    }

    string getPlaca() {
        return placa;
    }

    virtual float calcularCosto(float d) = 0;
    virtual void mostrar() = 0;
};

class Terrestre : public Transporte {
public:
    Terrestre(string placa) 
        : Transporte(placa) {}

    float calcularCosto(float d) override {
        float costo = d * 0.5;
        if (d > 100) {
            costo = costo * 1.10; 
        }
        return costo;
    }

    void mostrar() override {
        cout << "Terrestre - Placa: " << placa << endl;
    }
};

class Aereo : public Transporte {
public:
    Aereo(string placa) 
        : Transporte(placa) {}

    float calcularCosto(float d) override {
        float costo = d * 2.0;
        if (d > 1000) {
            costo = costo * 0.85; 
        }
        return costo;
    }

    void mostrar() override {
        cout << "Aereo - Placa: " << placa << endl;
    }
};

class Maritimo : public Transporte {
public:
    Maritimo(string placa) 
        : Transporte(placa) {}

    float calcularCosto(float d) override {
        float costo = d * 1.2;
        if (d > 500) {
            costo = costo + 50; 
        }
        return costo;
    }

    void mostrar() override {
        cout << "Maritimo - Placa: " << placa << endl;
    }
};

class Operador {
private:
    string nombre;
    string ci;
    float distancia;
    Transporte* transporte;

public:
    Operador(string nombre, string ci, float distancia) {
        this->nombre = nombre;
        this->ci = ci;
        this->distancia = distancia;
        this->transporte = nullptr;
    }

    string getCI() { 
        return ci; 
    }

    void asignarTransporte(Transporte* t) {
        this->transporte = t;
    }

    float calcularCosto() {
        if (transporte != nullptr) {
            return transporte->calcularCosto(distancia);
        }
        return 0;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "CI: " << ci << endl;
        cout << "Distancia: " << distancia << endl;
        if (transporte != nullptr) {
            transporte->mostrar();
            cout << "Costo: " << calcularCosto() << endl;
        }
    }
};

class VectorTransportes {
private:
    Transporte** lista;
    int tamanio;
    int indice;

public:
    VectorTransportes(int tamanio) {
        this->tamanio = tamanio;
        this->indice = 0;
        lista = new Transporte * [tamanio];
    }

    bool existePlaca(string placa) {
        for (int i = 0; i < indice; i++) {
            if (lista[i]->getPlaca() == placa)
                return true;
        }
        return false;
    }

    void agregar(Transporte* t) {
        if (indice < tamanio && !existePlaca(t->getPlaca())) {
            lista[indice++] = t;
        }
        else {
            cout << "Placa duplicada";
        }
    }

    Transporte* buscar(string placa) {
        for (int i = 0; i < indice; i++) {
            if (lista[i]->getPlaca() == placa)
                return lista[i];
        }
        return nullptr;
    }
};

class VectorOperadores {
private:
    Operador** lista;
    int tamanio;
    int indice;

public:
    VectorOperadores(int tamanio) {
        this->tamanio = tamanio;
        this->indice = 0;
        lista = new Operador * [tamanio];
    }

    bool existeCI(string ci) {
        for (int i = 0; i < indice; i++) {
            if (lista[i]->getCI() == ci)
                return true;
        }
        return false;
    }

    void agregar(Operador* o) {
        if (indice < tamanio && !existeCI(o->getCI())) {
            lista[indice++] = o;
        }
        else {
            cout << "CI duplicado";
        }
    }

    Operador* buscar(string ci) {
        for (int i = 0; i < indice; i++) {
            if (lista[i]->getCI() == ci)
                return lista[i];
        }
        return nullptr;
    }

    float costoTotal() {
        float total = 0;
        for (int i = 0; i < indice; i++) {
            total += lista[i]->calcularCosto();
        }
        return total;
    }

    void menorCosto() {
        if (indice == 0) return;
        int pos = 0;
        for (int i = 1; i < indice; i++) {
            if (lista[i]->calcularCosto() < lista[pos]->calcularCosto()) {
                pos = i;
            }
        }
        cout << "Operador con menor costo ==> " << endl;
        lista[pos]->mostrar();
    }
};

class Sistema {
private:
    VectorTransportes transportes;
    VectorOperadores operadores;

public:
    Sistema(int t, int o) 
        : transportes(t), operadores(o) {}

    void registrarTransporte(Transporte* t) {
        transportes.agregar(t);
    }

    void registrarOperador(Operador* o) {
        operadores.agregar(o);
    }

    void asignar(string ci, string placa) {
        Operador* op = operadores.buscar(ci);
        Transporte* tr = transportes.buscar(placa);
        if (op && tr) {
            op->asignarTransporte(tr);
        }
    }

    void costoOperador(string ci) {
        Operador* op = operadores.buscar(ci);
        if (op) {
            cout << "Costo del operador " << ci << ": " << op->calcularCosto() << endl;
        }
    }

    void costoTotal() {
        cout << "Costo total sistema: " << operadores.costoTotal() << endl;
    }

    void menorCosto() {
        operadores.menorCosto();
    }
};

int main() {
    Sistema s(10, 10);
    s.registrarTransporte(new Terrestre("T1"));
    s.registrarTransporte(new Aereo("A1"));
    s.registrarTransporte(new Maritimo("M1"));
    s.registrarOperador(new Operador("Juan", "123", 150));
    s.registrarOperador(new Operador("Ana", "456", 1200));
    s.registrarOperador(new Operador("Luis", "789", 600));
    s.asignar("123", "T1");
    s.asignar("456", "A1");
    s.asignar("789", "M1");
    s.costoOperador("123");
    s.costoTotal();
    s.menorCosto();
}