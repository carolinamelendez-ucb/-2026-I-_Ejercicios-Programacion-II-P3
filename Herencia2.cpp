#include <iostream>
#include <string>
using namespace std;


class Transaccion
{
private:
    string tipo;   // "deposito" o "retiro"
    float  monto;
public:
    Transaccion(string tipo, float monto)
    {
        this->tipo = tipo;
        this->monto = monto;
    }

    float getMonto() { return monto; }

    void mostrar()
    {
        cout <<"TIPO :" << tipo << " monto: " << monto << endl;
    }
};


//  VECTOR TRANSACCION — historial interno
class VectorTransaccion
{
private:
    Transaccion** transacciones;
    int           tamanio;
    int           indice;
public:
    VectorTransaccion(int tamanio)
    {
        this->tamanio = tamanio;
        this->indice = 0;
        this->transacciones = new Transaccion * [tamanio];
    }

    ~VectorTransaccion()
    {
        delete[] transacciones;
    }

    void agregar(Transaccion* t)
    {
        if (indice < tamanio)
        {
            transacciones[indice] = t;
            indice++;
        }
    }

    void mostrar()
    {
        if (indice == 0)
        {
            cout << "    (sin movimientos)" << endl;
            return;
        }
        for (int i = 0; i < indice; i++)
            transacciones[i]->mostrar();
    }
};


//  CUENTA — clase padre

class Cuenta
{
protected:
    string             nombre;
    string             numeroCuenta;
    float              balance;
    VectorTransaccion* historial;
public:
    Cuenta(string nombre, string numeroCuenta, float balance)
    {
        this->nombre = nombre;
        this->numeroCuenta = numeroCuenta;
        this->balance = balance;
        this->historial = new VectorTransaccion(50);
    }

    ~Cuenta()
    {
        delete historial;
    }

    void depositar(float monto)
    {
        balance += monto;
        historial->agregar(new Transaccion("deposito", monto));
        cout << "[OK] Deposito de " << monto
            << ". Nuevo balance: " << balance << endl;
    }

   
    void retirar(float monto)
    {
        if (monto > balance)
        {
            cout << "Saldo insuficiente." << endl;
            return;
        }
        balance -= monto;
        historial->agregar(new Transaccion("retiro", monto));
        cout << "Retiro de " << monto
            << "Nuevo balance: " << balance << endl;
    }

    void mostrar()
    {
        cout << "  Nombre        : " << nombre << endl;
        cout << "  Numero cuenta : " << numeroCuenta << endl;
        cout << "  Balance       : " << balance << endl;
        cout << "  Historial     :" << endl;
        historial->mostrar();
    }
};


//  CUENTA CORRIENTE — sin condiciones

class CuentaCorriente : public Cuenta
{
public:
    CuentaCorriente(string nombre, string numeroCuenta, float balance)
        : Cuenta(nombre, numeroCuenta, balance)
    {
    }

   
    void retirar(float monto)
    {
        if (monto > balance)
        {
            cout << "Saldo insuficiente." << endl;
            return;
        }
        balance -= monto;
        historial->agregar(new Transaccion("retiro", monto));
        cout << "Retiro corriente de " << monto
            << "Nuevo balance: " << balance << endl;
    }

    void mostrar()
    {
        cout << "// Cuenta Corriente //" << endl;
        Cuenta::mostrar();
    }
};

//  CUENTA TRANSACCIONAL — cobra 0.3% por retiro

class CuentaTransaccional : public Cuenta
{
public:
    CuentaTransaccional(string nombre, string numeroCuenta, float balance)
        : Cuenta(nombre, numeroCuenta, balance)
    {
    }

    // descuenta monto + 0.3% de comision
    void retirar(float monto)
    {
        float comision = monto * 0.003;
        float totalDesc = monto + comision;

        if (totalDesc > balance)
        {
            cout << "Saldo insuficiente (incluye comision 0.3%)." << endl;
            return;
        }
        balance -= totalDesc;
        historial->agregar(new Transaccion("retiro", totalDesc));
        cout << "Retiro de " << monto << " + comision " << comision << " = " << totalDesc<< " Nuevo balance: " << balance << endl;
    }

    void mostrar()
    {
        cout << "=== Cuenta Transaccional //comision 0.3%//" << endl;
        Cuenta::mostrar();
    }
};

// ============================================================
//  CUENTA JOVEN — maximo 1000 por retiro
// ============================================================
class CuentaJoven : public Cuenta
{
public:
    CuentaJoven(string nombre, string numeroCuenta, float balance)
        : Cuenta(nombre, numeroCuenta, balance)
    {
    }

    
    void retirar(float monto)
    {
        if (monto > 1000)
        {
            cout << "Limite superado maximo a retirar: 1000." << endl;
            return;
        }
        if (monto > balance)
        {
            cout << "Saldo insuficiente." << endl;
            return;
        }
        balance -= monto;
        historial->agregar(new Transaccion("retiro", monto));
        cout << "Retiro joven de " << monto
            << "Nuevo balance: " << balance << endl;
    }

    void mostrar()
    {
        cout << "=== Cuenta Joven //max retiro: 1000// " << endl;
        Cuenta::mostrar();
    }
};


int main()
{
   
    CuentaCorriente    cc("Juan Perez", "CC-001", 5000);
    CuentaTransaccional ct("Maria Lopez", "CT-002", 5000);
    CuentaJoven        cj("Luis Rios", "CJ-003", 5000);

    
    cout << "--- Operaciones Cuenta Corriente ---" << endl;
    cc.depositar(1000);
    cc.depositar(500);
    cc.retirar(200);
    cc.retirar(300);
    cc.retirar(99999); // saldo insuficiente

    
    cout << "Operaciones Cuenta Transaccional ---" << endl;
    ct.depositar(2000);
    ct.retirar(1000);  // descuenta 1000 + 3 de comision = 1003
    ct.retirar(500);   // descuenta 500  + 1.5           = 501.5
    ct.retirar(99999); // saldo insuficiente

   
    cout << "Operaciones Cuenta Joven ---" << endl;
    cj.depositar(800);
    cj.retirar(500);   // ok
    cj.retirar(1000);  // ok — exactamente el limite
    cj.retirar(1001);  // rechazado — supera limite
    cj.retirar(99999); // rechazado — supera limite

    
    
    cout << "         REPORTE FINAL" << endl;
   
    cc.mostrar();
   
    ct.mostrar();
    
    cj.mostrar();

    return 0;
}