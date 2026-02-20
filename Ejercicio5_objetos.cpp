// Ejercicio5_objetos.cpp 
// 09/02/26

/* Ejercicio 5. Crea una clase llamada Pedido 
● Atributos: codigo, producto, cantidad, precioUnitario 
● Crea su constructor … 
● Métodos set para cantidad y precioUnitario. 
● Método calcularTotal() que retorne el total del pedido (cantidad * precioUnitario). 
● Método mostrar() que muestre: 
    ○ código 
    ○ producto 
    ○ cantidad 
    ○ precio unitario 
    ○ total del pedido 
En el main: 
1. Crear 2 objetos Pedido. 
2. Pedir por consola para cada pedido: cantidad, precio unitario 
3. Asignar los valores usando setters. 
4. Mostrar ambos pedidos. 
5. Modificar la cantidad de uno de los pedidos. 
6. Volver a mostrar para comprobar que el total se actualiza. */

#include <iostream>
#include <string>
using namespace std;

class Pedido
{
   //ATRIBUTOS
   private:
       int codigo;
       string producto;
       int cantidad;
       float precio_Unitario;
   public:
       //CONSTRUCTOR
       Pedido(int codigo_p, string producto_p, int cantidad_p, float precioU_p)
       {
           codigo = codigo_p;
           producto = producto_p;
           cantidad = cantidad_p;
           precio_Unitario = precioU_p;
       }
       //METODO SET 
       void setCantidad(int nuevaCantidad)
       {
           this->cantidad = nuevaCantidad;
       }
       void setPrecioU(int nuevoPrecioU)
       {
           this->precio_Unitario = nuevoPrecioU;
       }
       //METODO CALCULAR TOTAL
       float calcularTotal()
       {
           float total = cantidad * precio_Unitario;
           return total;
       }
       //METODO MOSTRAR()
       void mostrar()
       {
           cout << "\n- Codigo: " << codigo << endl;
           cout << "- Producto: " << producto << endl;
           cout << "- Cantidad: " << cantidad << endl;
           cout << "- Precio Unitario: " << precio_Unitario << endl;
           cout << "- TOTAL: " << calcularTotal() << " Bs." << endl;
       }

};


int main()
{
    float Pre;
    int Cant;

    cout << "-- PEDIDO 1 --" << endl;
    cout << "Precio Unitario: ";
    cin >> Pre;
    cout << "Cantidad: ";
    cin >> Cant;
    Pedido p1 = Pedido(1, "Aceite", Cant, Pre);
    p1.mostrar();

    cout << "\n-----------------------------\n" << endl;

    cout << "-- PEDIDO 2 --" << endl;
    cout << "Precio Unitario: ";
    cin >> Pre;
    cout << "Cantidad: ";
    cin >> Cant;
    Pedido p2 = Pedido(2, "Coca-Cola", Cant, Pre);
    p2.mostrar();

    cout << "\n-----------------------------\n" << endl;
    cout << "MODIFICANDO LA CANTIDAD DEL PEDIDO 1..." << endl;
    p1.setCantidad(4);
    cout << "\n-----------------------------" << endl;
    cout << "-- PEDIDO 1 --" << endl;
    p1.mostrar();

    return 0;
}
