#include "ListaD.h"
#include <iostream>
using namespace std;

ListaD::~ListaD(){
    pnodo aux;
    esPrimero();
    while(cabeza){
        aux=cabeza;
        cabeza=cabeza->siguiente;
        delete aux;
    }
    cabeza=NULL;
    actual=NULL;
    final=NULL;
}


void ListaD::insertarNodo(int v,char c){
    pnodo aux;
    char tipoInsercion;
    tipoInsercion=c;
    if(listaVacia()){
        aux=new Nodo(v,NULL,NULL);
        final=cabeza=aux;
    }
    else if(tipoInsercion=='f'){//insercion por el final
        aux=new Nodo(v,NULL,NULL);
        aux->anterior=final;
        final->siguiente=aux;
        final=aux;
    }
    else if(tipoInsercion=='p'){//insercion por el principio
        aux=new Nodo(v,NULL,NULL);
        aux->siguiente=cabeza;
        cabeza->anterior=aux;
        cabeza=aux;
    }
}

void ListaD::borrarNodo(int v, char c){
    char tipoborrado; tipoborrado=c;

    if(tipoborrado=='f'){//eliminacion por el final
        pnodo aux=NULL;
        if((cabeza==final)){//solo un elemento
            aux=final;
            cabeza=final=NULL;
            aux=NULL;
            delete aux;
        }
        else{
            aux=final;
            final=final->anterior;
            final->siguiente=NULL;
            delete aux;
        }
    }
    else if(tipoborrado=='p'){
        pnodo aux=NULL;
        if((cabeza=final)){
            aux=cabeza;
            cabeza=final=NULL;
            aux=NULL;
            delete aux;
        }
        else{
            aux=cabeza;
            cabeza=cabeza->siguiente;
            cabeza->anterior=NULL;
            delete aux;
        }
    }
}
/*
void ListaD::mostrarLista(char c){
    char tipomostrado; tipomostrado=c;
    pnodo aux;
    if(tipomostrado=='p'){
        esPrimero();
        aux=cabeza;
        while(aux){
            cout<<aux->valor<<"->";
            aux=aux->siguiente;
        }
    }
    else{
        esUltimo();
        aux=final;
        while(aux){
            cout<<aux->valor<<"->";
            aux=aux->anterior;
        }
    }
    cout<<endl;
}
*/

bool ListaD::listaVacia(){
    return cabeza=NULL;
}
/*
void ListaD::esSiguiente(){
    if(actual) actual=actual->siguiente;
}

void ListaD::esAnterior(){
    if(actual) actual=actual->anterior;
}
*/
void ListaD::esPrimero(){
    actual=cabeza;
}
/*
void ListaD::esUltimo(){
    actual=final;
}

bool ListaD::esActual(){
    return actual != NULL;
}

int ListaD::valorActual(){
    if(!listaVacia()) return actual->valor;
}
*/






















