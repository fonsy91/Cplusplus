#include <iostream>
#include <conio.h>

using namespace std;

void machaca1(int x, int *y){ //int* indica que y es un puntero
        *y=x; // y es un puntero y debo acceder al valor que apunta
        return;
    }

void machaca2(int x, int &y){ //direccion de y
        y=x; //este cambio altera al original
        return;
    }

int main(){

    int a,b;
    cout<<"Escribe dos datos enteros: ";
    cin>> a >> b;

    int copia=b;

    cout<<"Antes de machaca1: "<<a<<" y "<<b<<endl;
    machaca1(a,&b),//como quiero pasar un puntero saco la direccion de b
    cout<<"Despues de machaca1: "<<a<<" y "<<b<<endl<<endl;
    b=copia;//restauramos b ara probar el segundo metodo

    cout<<"Antes de machaca2: "<<a<<" y "<<b<<endl;
    machaca2(a,b);//como se pasa por referencia no hace falta la direccion
    cout<<"Despues de machaca2: "<<a<<" y "<<b<<endl;
    cout<<endl;

    //Mas con punteros
    //Un puntero a x

    int x=15;
    int *ptrX;
    ptrX=&x;
    cout<<x<<endl;
    cout<<*ptrX<<endl;
    cout<<&ptrX<<endl;






    return 0;
}
