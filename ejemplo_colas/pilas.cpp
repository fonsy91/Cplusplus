#include "pilas.h"
#include <iostream>

pilas::~pilas(){
    while(cima) desapilar();
}

void pilas::apilar(int v){
    pNodo nuevo;
    nuevo=new Nodo(v,cima);
    cima=nuevo;
}

int pilas::desapilar(){
    pNodo nodo;
    int v;
    if(!cima) return 0;
    nodo=cima;
    cima=nodo->siguiente;
    v=nodo->valor;
    delete nodo;
    return v;
}





















