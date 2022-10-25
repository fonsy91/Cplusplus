#include "Avion.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;


Cola::~Cola(){
    while(primero){
        desencolarAvion();
    }
}


void Cola::mostrarDatos(){
    NodoAvion *aux;
    aux=primero;
    while(aux!=NULL){
        cout<<"Vuelo: "<<aux->aereo.IdeVuelo<<"   "<<"Origen: "<<aux->aereo.IdeInter<<"    "<<"Destino: "<<aux->aereo.IdeAeroDes<<"    "<<"Hsalida: "<<aux->aereo.Hsalida<<"    "<<"Hdestino: "<<aux->aereo.Hdestino<<"    "<<"Hllegada: "<<aux->aereo.Hllegada<<"    "<<"Tespera: "<<aux->aereo.Tespera<<" H"<<"    "<<"Ncombus: "<<aux->aereo.Ncombustible<<endl;
        aux=aux->siguiente;

    }
        cout<<endl;
}


//Funcion de encolamineto del avion******************************
void Cola::encolarAvion(Datos a){
    pnodo nuevo;
    nuevo=new NodoAvion(a);
    if(ultimo) ultimo->siguiente=nuevo; //si la cola no esta vacia se añade uno ha continuacion del ultimo

    ultimo=nuevo;

    if(!primero) primero=nuevo; // si el primero es null la cola esta vacia y el primero apunta al nuevo nodo
}
//Funcion desencolar avion***************************************************
Datos Cola::desencolarAvion(){
    pnodo nodo;   //variable de tipo nodoAvion
    Datos a;     //variable tipo datos
    nodo=primero; //nodo apunta al primer elemento de la cola

    if(!nodo){} // sin no hay nodos en la cola devuelve cero aunque en este caso no es necesario

    primero=nodo->siguiente; //se asigna al primero la direccion del segundo nodo

    a=nodo->aereo;  //se guarda el valor de retorno

    delete nodo; //se borra el nodo
    //si la cola esta vacia el ultimo debe ser null
    if(!primero){
        ultimo=NULL;
    }
    return a; // si no esta vacia se devuelve el avion
}

bool Cola::ColaVacia(){
    if(primero==NULL){
        return true;
    }else{
        return false;
    }
}

int Cola::Cuantos(){
    NodoAvion *aux, *aux1; //variables de tipo NodoAvion
    aux=primero; //aux ahora es el primer nodo de la cola
    int i=0;

    if(primero==NULL){ //si esta vacia devuleve cero nodos
        return 0;
    }
    while(aux!=NULL){ //si la cola no esta vacia
        aux1=aux->siguiente;
        aux=aux1;
        i++;
    }
    return i;

}










