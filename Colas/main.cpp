#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Nodo{
    int elemento;
    Nodo *siguiente;
};
typedef Nodo *ptrCola;

//PROTOTIPOS
void encolar(ptrCola &, ptrCola &, int);
bool vacia(ptrCola &);
void primero(ptrCola &);
void desecolar(ptrCola &, ptrCola &, int &);

//FUNCIONES
bool vacia(ptrCola &frente){
    //otra forma de condicional es esta:
    //return (frente==NULL)? ture:false;
    //traduccion si frente es NULL devuelve true sino false

    if(frente==NULL){
        return true;
    }
    else{
        return false;
    }
}

void encolar(ptrCola &frente, ptrCola &fin, int valor){
    ptrCola aux;

    aux=new Nodo();         //creamos un nuevo nodo
    aux->elemento=valor;    //al campo elemento del nodo le damos un valor
    aux->siguiente=NULL;    //al campo siguiente le damos NULL
    if(vacia(frente)){      //Si cola vacia
        frente=aux;         //esta apuntando al nuevo nodo
    }
    else{
        //si hay mas de un nodo el que era el ultimo ahora es el
        //penultimo por ello fin->sig debe apuntar al nuevo nodo(ahora el ultimo)
        fin->siguiente=aux;
    }
    fin=aux;                //esta apuntando al nuevo nodo
    cout<<"Elemento "<<valor<<" Introducido correctamente"<<endl;
}

void primero(ptrCola &c){
    int prim;
    if(c==NULL){
        cout<<"La cola esta vacia error..."<<endl;
    }
    else{
        prim=c->elemento;
    }
    cout<<"El elemento primero de la cola es: "<<prim<<endl;
}

void desecolar(ptrCola &frente, ptrCola &fin, int &valor){
    ptrCola aux;
    valor=frente->elemento; //guardamos en valor el elemento que gurda frente
    aux=frente;             //hacemos que el puntero aux apunte a donde lo hace frente
    if(frente==fin){        // si solo existe un nodo
        //En el caso de que halla un solo nodo los punteros frente y
        //fin apuntan a NULL
        frente=NULL;
        fin=NULL;
    }
    else{
        //si hay mas de un nodo como vamos a eliminar frente este debe
        //apuntar al siguiente para no perder los datos y ya
        //podriamos eliminar aux que apuntaba al primero
        frente=frente->siguiente;
    }
    delete aux;

}

void mostrar(ptrCola &c){
    ptrCola aux;
    aux=c->siguiente;
    cout<<"El primer valor es: "<<c->elemento<<endl;
    cout<<"El resto son: ";
    while(aux!=NULL){
        cout<<" "<<aux->elemento;
        aux=aux->siguiente;
    }
}


int main(){
    ptrCola frente=NULL;
    ptrCola fin=NULL;
    int dato;
    char res;

    do{
        cout<<"Introduzca un dato en la cola: ";
        cin>>dato;
        encolar(frente,fin,dato);
        cout<<"Desea introducir mas datos (s/n)";
        cin>>res;
    }while((res=='s')||(res=='S'));

    cout<<"Mostramos la cola sin eliminaciones"<<endl;
    mostrar(frente);
    cout<<endl;


    cout<<"Eliminando los nodos de la cola"<<endl;
    while(frente!=NULL){
        desecolar(frente,fin,dato);
        if(frente!=NULL){
            cout<<dato<<" , ";
        }
        else{
            cout<<dato<<".";
        }
    }
    //primero(frente);

    return 0;
}
