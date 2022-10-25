#include "colas.h"
#include <iostream>

using namespace std;

colas::colas(){
    fin=0;
    inicio=0;
}

colas::~colas(){
    while(inicio) desencolar();
}

bool colas::esVacia(){
    return inicio==0;
}

void colas::encolar(int v){
    pnodo nuevo;
    nuevo=new Nodo(v);
    if(fin) fin->siguiente=nuevo;
    fin=nuevo;
    if(esVacia()) inicio=nuevo;
}

void colas::desencolar(){
    if(esVacia()) cout<<"cola vacia"<<endl;
        else
        {
            pnodo nodo;
            nodo=inicio;
            inicio=nodo->siguiente;
            nodo->siguiente=0;
            delete nodo;
            if(esVacia()) fin=0;
        }
}

int colas::verPrimero(){
    if(esVacia()) cout<<"Cola vacia"<<endl;
    else{
        return inicio->valor;
    }
}









