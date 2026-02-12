using namespace std;
#include <iostream>
#include <string>
class Cliente {
private:
    string nombre;
    int saldo;
    bool habilitado;
    public:
        Cliente() {
            nombre = "";
            saldo = 0;
            habilitado = false;
        }
    Cliente(string N, int S, bool H)
    {
        this->nombre = N;
        this->saldo = S;
        this->habilitado = H;
    }
    int getsaldo() {
        return saldo;
    }
    int gethabilitado() {
        return habilitado;
    }

};
class Pedido {
private:
    string codigo;
    int importe;
    string objeto;
    Cliente cliente;
public:
    Pedido(string C, int I, string O,Cliente cliente)
    {
        this->codigo = C;
        this->importe = I;
        this->objeto = O;
        this->cliente = cliente;

        if (importe < cliente.getsaldo()) {
            if (cliente.gethabilitado()) {
                cout << "se habilito el pedido" << endl;
            }
            else
            {
                cout << "no esta habilitado para el pedido" << endl;
            }
        }
        else
        {
            cout << "no hay saldo suficiente" << endl;
        }

    }
};

int main()
{
    Cliente cliente1("Mauricio", 100, true);
    Pedido pedido1("ABBSS", 50, "sapotron", cliente1);
    
}

