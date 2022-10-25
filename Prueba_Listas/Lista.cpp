#include "Lista.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#define NULL 0L


using namespace std;

Lista::~Lista(){
    pnodo aux;
    while(cabeza){
        aux=cabeza;
        cabeza=cabeza;
        delete aux;
    }
    actual=NULL;
}

void Lista::insertarNodo(int v){
    pnodo aux;   //puntero temporal aux que se utiliza como puntero al nuevo nodo
    if(listaVacia()){
        cabeza=new Nodo(v,NULL); //se reserva espacio de memoria para el nodo
        final=cabeza;
    }
    else{
        aux=new Nodo(v,NULL);
        final->siguiente=aux; //el ultimo antes de insertar aux ahora apunta a aux que es el ultimo
        final=aux;      //ahora final el igual a aux es decir el ultimo nodo
    }
}

void Lista::borrarNodo(int v){
    pnodo anterior;
    actual=cabeza;
    while(actual->valor != v && (actual->siguiente)!= NULL){
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual==cabeza){
        cabeza=actual->siguiente;
    }
    else{
        anterior->siguiente=actual->siguiente;
        if(actual==final){
            final=anterior;
        }
    }
    actual->siguiente=NULL;
    delete actual;
}

bool Lista::listaVacia(){
    return cabeza==NULL;
}

void Lista::mostrarLista(){
    Nodo *aux;
    aux=cabeza;
    while(aux != NULL){
        cout<<aux->valor<<"->";
        aux=aux->siguiente;
    }
    cout<<endl;
}

void Lista::esSiguiente(){
    if(actual) actual=actual->siguiente;
}

void Lista::esPrimero(){
    actual=cabeza;
}

void Lista::esUltimo(){
    esPrimero();
    if(!listaVacia())
    while(actual->siguiente)
    esSiguiente();
}

bool Lista::esActual(){
    return actual != NULL;
}

int Lista::valorActual(){
    return actual->valor;
}




















