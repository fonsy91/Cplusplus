#include <iostream>
#include "colas.h"

using namespace std;

int main(){

    colas cola;
    cola.encolar(20);
    cout<<"A�adir(20)"<<endl;
    cola.encolar(10);
    cout<<"A�adir(10)"<<endl;
    cout<<"El primero es: "<<cola.verPrimero()<<endl;
    cola.encolar(30);
    cout<<"A�adir(30)"<<endl;
    cout<<"El primero es: "<<cola.verPrimero()<<endl;
    cout<<"Desencolar"<<endl;
    cola.desencolar();
    cout<<"El primero es: "<<cola.verPrimero()<<endl;


    return 0;
}








