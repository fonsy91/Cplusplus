#include "colas.h"

Cola::~Cola(){
    while(primero) desencolar();
}

void Cola::encolar(int v){
    pnodo nuevo;
    nuevo=new Nodo(v);

    if(ultimo) ultimo->siguiente=nuevo;

    ultimo=nuevo;

    if(!primero) primero=nuevo;
}

 int Cola::desencolar(){
    pnodo nodo;
    int v;

    nodo=primero;
    if(!nodo) return 0;

    primero=nodo->siguiente

    v=nodo->valor

    delete nodo;

    if(!primero) ultimo=NULL;

    return v;


 }
