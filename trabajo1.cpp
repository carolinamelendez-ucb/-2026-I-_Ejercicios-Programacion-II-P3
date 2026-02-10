
using namespace std;
#include <iostream>
#include <string>
class Libro {
private:
    string titulo;
    string autor;
    int paginas;
    public:
        Libro(string t, string a,int p)
        {
        titulo=t;
        autor=a;
        paginas=p;
    }
        void setPaginas(int p) {
        paginas=p;

    }
        void mostrar() {
            cout << "Titulo: " << titulo << endl;
            cout<< "Autor: "<<autor<<endl;
            cout<<"Numero de paginas: "<<paginas<<endl;
        }
};

int main()
{
int p;
Libro libro1("fisica","manolo peerez",500);
    libro1.mostrar();
    cout << "ingrese el nuevo numero de paginas" << endl;
    cin >> p;
    libro1.setPaginas(p);
    libro1.mostrar();

}
