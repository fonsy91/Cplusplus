#include "Arbol.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//Borra todos los nodos a partir de uno, incluido
void Arbol::podar(pNodo &nodo){
    if(nodo){
        podar(nodo->izquierda); //poder izquierdo
        podar(nodo->derecha);   //podar derecha
        delete nodo;            //eliminar nodo
        nodo=NULL;
    }
}

//Inserta un char en el arbol
void Arbol::insertarNodo(char dat){
    Nodo *padre=NULL;
    actual=raiz;
    //busca el char en el arbol, manteniendo un puntero al nodo padre
    while(!esVacio(actual) && dat !=actual->dato){
        padre=actual;
        if(dat>actual->dato) actual=actual->derecha;
        else if(dat<actual->dato) actual=actual->izquierda;
    }
    //si se ha encontrado el elemento, regresar sin insertar
    if(!esVacio(actual)) return;
    //si padre es NULL, entonces el arbol esta vacio, el nuevo nodo sera el nodo raiz
    if(esVacio(padre)) raiz=new Nodo(dat);
    //si el char es menor que el que contiene el nodo padre, lo insertamos en la rama izquierda
    else if(dat<padre->dato) padre->izquierda=new Nodo(dat);
    //si el char es mayor que el que contiene el nodo padre, lo insertamos en la rama derecha
}







































