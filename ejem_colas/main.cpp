#include <iostream>
#include "colas.h"

using namespace std;

int main(){

    Cola Cola;
    Cola.encolar(20);
    cout<<"Añadir(20)"<<endl;
    Cola.encolar(10);
    cout<<"Añadir(10)"<<endl;
    cout<<"Leer: "<<Cola.desencolar()<<endl;



    return 0;
}
