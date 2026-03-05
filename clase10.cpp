#include <iostream>
#include <string>
#include "Socio.h"
#include "Equipo.h" 
int main()
{
    Socio s1(123, "Carlos",777111);
    Socio s2(654, "Pedro", 777222);

    Equipo e1("RallyTeam", "Subaru", s1, s2);

    e1.mostrarEquipo();

}

