#include <iostream>
#include <string>
#include"Socios.cpp"
using namespace std;



int main(){
    Socios miembros;

    VectorSocios mis_Socios = VectorSocios(10);
    
    mis_Socios.AgregarSocio(new Socios(23, "Oscar", 56));
    mis_Socios.AgregarSocio(new Socios(43, "Pablo", 65));
    mis_Socios.Mostrar_Vector_Socios();




}

