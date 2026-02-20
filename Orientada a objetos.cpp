#include <iostream>
#include <string>

using namespace std;
//Atributos
class Reloj
{
private:
    int tamano;
    int anio;
    string marca;
    string calidad;
    string color;

public:
    Reloj() {
        tamano = 15;
        anio = 2026;
        marca = "Apple";
        calidad = "Normal ";
        color = "Verde";
    }
    Reloj(int t, int a, string m, string q, string c) {
        tamano = t;
        anio = a;
        marca = m;
        calidad = q;
        color = c;
    }
    void mostrar() {
        cout << "Tamano" << tamano;
        cout << "Anio" << anio;
        cout << "Marca" << marca;
        cout << "Calidad" << calidad;
        cout << "Color" << color;

    }
    void  MediR()
    {
        cout << "Midiendo Ritmo cardiaco.." << endl;
    }
    void  Comunicar()
    {
        cout << "Comunicandote con tus conocidos.." << endl;
    }
    void  Personalizar()
    {
        cout << "Personalizando tu reloj" << endl;
    }
    void  Verhora()
    {
        cout << "Revisando la hora" << endl;
    }
    void Notificacion()
    {
        cout << "Recibiste una notificacion" << endl;
    }
};

void setanio(int nuevoanio)
int main()
{
    cout << "Reloj 1" << endl;
    Reloj  Reloj1 = Reloj(15,2026,"Apple","Normal","Verde");
    Reloj1.mostrar();
    Reloj  Reloj2 = Reloj(13, 2026, "Apple", "Fit", "Rojo");
    Reloj  Reloj3 = Reloj(17, 2026, "Apple", "Pro", "Amarillo");
    cout << "Reloj 4" << endl;
    Reloj  Reloj4 = Reloj(18, 2026, "Apple", "Pro Max", "Verde");
    Reloj4.mostrar();
    Reloj1.Notificacion();
    Reloj1.Notificacion();
    Reloj1.Notificacion();
    Reloj1.Notificacion();
    Reloj1.Comunicar();


}
