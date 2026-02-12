#include <iostream>
#include <string>

using namespace std;
const int AntiguedadMinDescuento = 2 ;

class Cliente
{
    protected:
    string nombre;
    bool tipoCliente;
    int antiguedadCliente;

    public:
    Cliente(string _nombre , bool _tipoCliente, int _antiguedadCliente)
    {
        this ->nombre = _nombre;
        this -> tipoCliente = _tipoCliente;
        this -> antiguedadCliente = _antiguedadCliente;
    }

    string getNombre()
    {
        return nombre;
    }

    int getAntiguedad()
    {
        return antiguedadCliente;
    }

    bool getTipoCliente ()
    {
        return tipoCliente;
    }

};

class Factura 
{
    private:
    string nombreFactura;
    int montoBaseFactura;
    Cliente cliente;

    public:

    Factura(string _nombreFactura , int _montoBaseFactura, Cliente _cliente)
    {
        this ->nombreFactura = _nombreFactura;
        this ->montoBaseFactura = _montoBaseFactura;
        
    }

    bool comprobarTipoCliente()
    {
        int esClieteValido = cliente.getTipoCliente();
        return esClieteValido;
    }

    int comprobarAntiguedad()
    {
        int esAntiguo = cliente.getAntiguedad();
        return esAntiguo;
    }

    void calcularTotal()
    {
        int getAntiguedad = cliente.getAntiguedad();
        int total=0;
        if( comprobarAntiguedad()==2 && comprobarTipoCliente()== true )
        {
            total = montoBaseFactura * 0.10;
            cout << " Con Descuento " << total << endl;
        }
        else
        {
            total = montoBaseFactura;
            cout << " Sin Descuento " << total << endl;
        }
    }
};

void ejercicio2()
{
    Cliente cliente1 = Cliente("Marcelo",false,3);
    Factura factura1 = Factura("Marcelo Factura" , 200 ,cliente1);
    factura1.calcularTotal();

}



int main()
{
    ejercicio2();
    return 0;
}
