#include <string>
#include <iostream>
using namespace std;

class casa {
private:
	int nHabi;
	int precio;
	string ubicacion;
public:
	casa(int nHabita, int precio, string ubicacion) {

		this->nHabi = nHabita;
		this->precio = precio;
		this->ubicacion = ubicacion;
	}

	casa(int nHabita,string ubicacion){
		    
		this->nHabi =nHabita;
		this->precio = 0;
		this->ubicacion = ubicacion;
	}
	casa(string ubicacion) {

		this->nHabi = 0;
		this->precio = 0;
		this->ubicacion = ubicacion;
	}

	void setnHabi(int nHabit){
		nHabi= nHabit;
	}

	void setprecio(int prec){
		precio = prec;
	}

	void setubi(int ubi)
	{
		ubicacion = ubi;
	}

	void mostrarcasa(){
		cout << "Ubicacion: " << ubicacion << endl;
		cout << "N. Habitaciones: " << nHabi << endl;
		cout << "Precio: " << precio << endl;
	}
};




int main()
{
	casa micasa1 = casa(4, 200, "Alto Aranjuez");
	micasa1.mostrarcasa();
}


