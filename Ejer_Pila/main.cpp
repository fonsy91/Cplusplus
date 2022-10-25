#include <iostream>
#include "Pila.h"
using namespace std;


void pila(){
    Pila p1; //creo un objeto pila de la clase Pila
    /*
    cout<<"****EJERCICIO DE PILAS****";
    cout<<endl;
    cout<<"Los elementos que se han introducido en la pila son: "<<endl;
    cout<<p1.insertar(1)<<endl;
    cout<<p1.insertar(2)<<endl;
    cout<<p1.insertar(3)<<endl;
    cout<<p1.insertar(4)<<endl;
    cout<<p1.insertar(5)<<endl;
    cout<<endl;
    */

    p1.insertar(1);
    p1.insertar(2);
    p1.insertar(3);
    p1.insertar(4);
    p1.insertar(5);

    while(!p1.PilaVacia()){
        cout<<p1.quitar();
    }

}

int main(){

    pila();


    return 0;
}
