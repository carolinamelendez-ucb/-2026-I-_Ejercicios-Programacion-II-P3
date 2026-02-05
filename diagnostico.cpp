using namespace std;
#include <iostream>
#define TAM 50
int ejercicio1(int vec[TAM], int n,int res[TAM])
{
    int k = 0;
    for (int i = 0;i < n;i++)
    {
        if (vec[i] % 2 == 0)
        {
            res[k] = vec[i];
             k++;

        }
    }

    return k;

}
int ejercicio2(int vec[TAM], int n)
{
    int res=0;
    for (int i = 0;i < n;i++)
    {
        res = vec[i] + res;
    }
    return res;

}
int main()
{
    int Total;
    int k;
    int vec[] = { 13,22,5,8,34,55,60 };
    int res[TAM];
    int n = 7;
    k=ejercicio1(vec, n, res);
    for (int i = 0;i < k;i++)
    {
        cout << res[i] << " " << endl;
    }
    Total=ejercicio2(vec, n);
    cout<<"el total de la suma es: "<< Total << endl;


   
}

