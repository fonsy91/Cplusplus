#include "Lista.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>



using namespace std;


int main(){

    Lista lista;
    /*
    lista.insertarNodo(20);
    lista.insertarNodo(10);
    lista.insertarNodo(40);
    lista.insertarNodo(30);

    lista.mostrarLista();

    cout<<"Lista de elementos:"<<endl;
    lista.esPrimero();
    while(lista.esActual()){
        cout<<lista.valorActual()<<endl;
        lista.esSiguiente();
    }
    lista.esPrimero();
    cout<<"Priemro: "<<lista.valorActual()<<endl;
    lista.esUltimo();
    cout<<"Ultimo: "<<lista.valorActual()<<endl;

    lista.borrarNodo(20);
    lista.borrarNodo(10);
    lista.borrarNodo(40);
    lista.borrarNodo(30);

    lista.mostrarLista();
    getchar();
    */

    lista.insertarNodo(10);
    lista.mostrarLista();
    lista.insertarNodo(20);
    lista.mostrarLista();

    lista.borrarNodo(10);
    lista.borrarNodo(20);

    lista.mostrarLista();
    getchar();






    return 0;
}
