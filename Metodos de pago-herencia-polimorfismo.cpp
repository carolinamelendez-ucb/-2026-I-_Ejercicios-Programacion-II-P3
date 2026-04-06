// Metodos de pago-herencia-polimorfismo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include <string>
#include "SistemaDePagos.h"
#include "PagoConDescuento.h"
#include "PagoConComisionFija.h"
#include "PagoSinComisionConValidacion.h"
#include "PagoComisionPorcentual.h"
using namespace std;


int main()
{
    SistemaDePagos sistema1 = SistemaDePagos(30);

    sistema1.registrarClientes(new Cliente("carlitos",10));
    sistema1.registrarClientes(new Cliente("josefa",10));
   // sistema1.mostrarClientes();

    sistema1.registrarPagoClinetes("carlitos", new PagoComisionPorcentual(100));
    sistema1.registrarPagoClinetes("carlitos", new PagoConComisionFija(200));
    sistema1.registrarPagoClinetes("josefa", new PagoConDescuento(150));
    sistema1.registrarPagoClinetes("josefa", new PagoSinComisionConValidacion(0));

    sistema1.mostrarClientes();
    cout << endl;

    cout << "TOTAL GENERAL PROCESADO: " << sistema1.calcularTotalSistema() << endl;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
