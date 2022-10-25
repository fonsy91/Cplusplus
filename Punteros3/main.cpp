#include <iostream>

using namespace std;

int main(){

    int x,y,*p,*q;

    p=&x;
    cout<<"La direccion de p es: "<<p<<endl;
    cout<<"La direccion de de x es: "<<x<<endl;
    cout<<endl;
    *p=5;
    cout<<"La direccion de p es: "<<p<<endl;
    cout<<"El valor de x es: "<<x<<endl;
    cout<<endl;

    q=&y;//El puntero q apunta a 'y' y asu vez guarda la direccion de y
    *q=23;
    cout<<"La direccion de q es : "<<q<<endl;
    cout<<"Lo que contiene q es : "<<*q<<endl; //muestra lo que contiene donde apunta
    cout<<"Lo que guarda el puntero es: "<<&y<<endl;//Mostramos la direccion de y
    cout<<endl;





//*******************************************************************************






    return 0;
}
