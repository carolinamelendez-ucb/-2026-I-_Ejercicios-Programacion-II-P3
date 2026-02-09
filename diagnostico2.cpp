#include <iostream>
#include <string>

using namespace std;

int main()
{
    int arr[]={1,2,3,4,5};
    int tam=5;
    int contenedor = 0;

    for (int i = 0 ; i < tam ; i ++)
    {
        contenedor+=arr[i];
    }
    cout << " suma total : " << contenedor <<endl ;
    return 0;
}