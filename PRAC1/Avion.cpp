#include "Avion.h"
#include <iostream>
#include <string>
using namespace std;


Avion::~Avion(){
    pnodo aux;
    while(primero){
        aux=primero;
        primero=primero->siguiente;
        delete aux;
    }
    actual=NULL;
}


void Avion::mostrarDatos(){
    NodoAvion *aux;
    aux=primero;
    while(aux){
        cout<<"Vuelo"<<aux->aereo.IdeVuelo<<"   "<<"Origen"<<aux->aereo.IdeInter<<"    "<<"Destino"<<aux->aereo.IdeAeroDes<<"    "<<"Hsalida"<<aux->aereo.Hsalida<<"    "<<"Hdestino"<<aux->aereo.Hdestino<<"    "<<"Hllegada"<<aux->aereo.Hllegada<<"    "<<"Tespera"<<aux->aereo.Tespera<<"    "<<"Ncombus"<<aux->aereo.Ncombustible<<endl;
        aux=aux->siguiente;
    }
        cout<<endl;
}

//Funcion esVacia dice si la cola esta vacia*************************************
bool Avion::esVacia(){
    return primero==0;
}
//Funcion aterrizar es decir encolamineto del avion******************************
void Avion::insertarAvion(Datos a){
    pnodo nuevo;
    nuevo=new NodoAvion(a);
    if(!esVacia()){
        ultimo->siguiente=nuevo;
        ultimo=nuevo;
    }
    if(esVacia()){
        primero=nuevo;
    }
}
//Funcion desencolar avion***************************************************
void Avion::borrarAvion(){
    pnodo nodo,auxi;
    nodo=primero;
    if(!nodo){
        cout<<"No hay nodos";
    }
    primero=nodo->siguiente;
    delete nodo;
    cout<<"desencolado";
    if(!primero){
        ultimo=NULL;
    }
}











