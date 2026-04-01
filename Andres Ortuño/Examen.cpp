#include <iostream>
#include "Sistema.h"
using namespace std;

int main()
{
    Sistema* miSistema = new Sistema(20, 20);
    miSistema->agregarRepartidor(new Repartidor("Jose", 1, "Zona1"));
    miSistema->agregarRepartidor(new Repartidor("Carlos", 2, "Zona1"));
    miSistema->agregarRepartidor(new Repartidor("Benjamin", 3, "Zona2"));
    miSistema->agregarRepartidor(new Repartidor("Sebastian", 4, "Zona2"));
    miSistema->agregarRepartidor(new Repartidor("Alejandro", 5, "Zona3"));
    miSistema->agregarRepartidor(new Repartidor("Omar", 6, "Zona3"));
    miSistema->agregarRepartidor(new Repartidor("Nestor", 7, "Zona4"));
    miSistema->agregarRepartidor(new Repartidor("Diego", 8, "Zona4"));
    miSistema->agregarRepartidor(new Repartidor("Mauricio", 1, "Zona1"));

    miSistema->agregarPedido(new Pedido(1, "Moliere", "Zona1", 8, 10));
    miSistema->agregarPedido(new Pedido(2, "Circunvalacion", "Zona1", 9, 10));
    miSistema->agregarPedido(new Pedido(3, "Heroinas", "Zona1", 9.5, 10));
    miSistema->agregarPedido(new Pedido(4, "Pando", "Zona2", 10, 10));
    miSistema->agregarPedido(new Pedido(5, "Prado", "Zona2", 10.5, 10));
    miSistema->agregarPedido(new Pedido(6, "America", "Zona2", 11, 10));
    miSistema->agregarPedido(new Pedido(7, "Melchor", "Zona3", 11.5, 10));
    miSistema->agregarPedido(new Pedido(8, "Rosa", "Zona3", 12, 10));
    miSistema->agregarPedido(new Pedido(9, "Rosa", "Zona8", 12, 10));//Pedido al que no se le va a asignar repartidor
    miSistema->agregarPedido(new Pedido(1, "Guillen", "Zona1", 8, 10));

    miSistema->agregarProductoAPedido(1, new Producto("A", 2, 15));
    miSistema->agregarProductoAPedido(1, new Producto("B", 3, 20.5));
    miSistema->agregarProductoAPedido(2, new Producto("C", 4, 10));
    miSistema->agregarProductoAPedido(3, new Producto("D", 5, 5));
    miSistema->agregarProductoAPedido(4, new Producto("E", 6, 3));
    miSistema->agregarProductoAPedido(5, new Producto("F", 7, 4.5));
    miSistema->agregarProductoAPedido(6, new Producto("G", 8, 6.5));
    miSistema->agregarProductoAPedido(7, new Producto("H", 9, 1.5));
    miSistema->agregarProductoAPedido(8, new Producto("I", 10, 2));
    miSistema->agregarProductoAPedido(8, new Producto("J", 5, 9.5));

    miSistema->finalizarPedido(1);
    miSistema->finalizarPedido(1);//solo para sumar cantidad de pedidos
    miSistema->finalizarPedido(1);//solo para sumar cantidad de pedidos
    miSistema->finalizarPedido(1);//solo para sumar cantidad de pedidos
    miSistema->finalizarPedido(3);
    miSistema->finalizarPedido(3);//solo para sumar cantidad de pedidos
    miSistema->finalizarPedido(3);//solo para sumar cantidad de pedidos
    miSistema->finalizarPedido(5);
    miSistema->finalizarPedido(5);//solo para sumar cantidad de pedidos
    miSistema->finalizarPedido(7);

    cout << endl;
    miSistema->calcularCostoTotalDelPedido(1);
    miSistema->calcularCostoTotalDelPedido(2);
    miSistema->calcularCostoTotalDelPedido(3);
    miSistema->calcularCostoTotalDelPedido(4);
    miSistema->calcularCostoTotalDelPedido(5);
    miSistema->calcularCostoTotalDelPedido(6);
    miSistema->calcularCostoTotalDelPedido(7);
    miSistema->calcularCostoTotalDelPedido(8);
    cout << endl;
    miSistema->mostrarRepartidoresOrdenados();//de forma descendente
    cout << endl;
    miSistema->calcularCostoTodosPedidos();
}
