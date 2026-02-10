using namespace std;
#include <iostream>
#include <string>
class producto{
private:
string nombre;
int precio;
int stock;
public:
    producto(string N, int P, int S) {
    nombre=N;
    precio=P;
    stock=S;
}
    void setproducto(string N, int P, int S) {
        nombre=N;
        precio=P;
        stock=S;
}
    void mostrar() {
        cout<<"Producto: "<<nombre<<endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
}
};

int main()
{
string N;
int P,S;
    producto producto1("Manzana", 10, 9);
    producto1.mostrar();
    cout<<"Ingrese el nombre, precio y stock del nuevo producto"<<endl;
    cin>>N;
    cin>>P;
    cin>>S;
    producto1.setproducto(N,P,S);
    producto1.mostrar();
}
