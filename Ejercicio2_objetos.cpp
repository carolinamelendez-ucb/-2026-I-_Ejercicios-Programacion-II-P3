// Ejercicio2_objetos.cpp 
// 08/02/26

/* Ejercicio 2. Crea una clase llamada Producto. 
● Implementar los siguientes atributos: nombre, precio, stock 
● Crea un constructor con nombre y precio (stock inicia en 0). 
● Implementa setters para todos los atributos 
● Método mostrar(). 
En el main: 
1. Crear producto. 
2. Mostrar. 
3. Actualizar stock. 
4. Actualizar precio. 
5. Mostrar nuevamente. */

#include <iostream>
#include <string>
using namespace std;

class Producto
{
  //ATRIBUTOS
  private:
      string nombre;
      float precio;
      int stock;

  public:
      //CONSTRUCTOR
      Producto(string nom, float pre, int sto)
      {
          nombre = nom;
          precio = pre;
          stock = sto;
      }
      //METODO MOSTRAR()
      void mostrar()
      {
          cout << "Nombre: " << nombre << endl;
          cout << "Precio: " << precio << endl;
          cout << "Stock: " << stock << endl;
      }
      //METODO SET
      void setNombre(string nuevoNombre)
      {
          this->nombre = nuevoNombre;
      }
      void setPrecio(float nuevoPrecio)
      {
          this->precio = nuevoPrecio;
      }
      void setStock(int nuevoStock)
      {
          this->stock = nuevoStock;
      }
          
};

int main()
{
    cout << "-- PRODUCTO 1 --\n" << endl;
    Producto producto1 = Producto("Coca-Cola", 15.5,0);
    producto1.mostrar();

    cout << "\nActualizando datos del PRODUCTO 1...\n" << endl;
    producto1.setPrecio(18.20);
    producto1.setStock(35);
    producto1.mostrar();

    return 0;
}

