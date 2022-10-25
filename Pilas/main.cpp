#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//http://c.conclase.net/edd/?cap=002#inicio
//http://blog.martincruz.me/2012/10/pilas-en-c.html
//http://www.youtube.com/watch?v=tq3Th-zqeA4

struct Nodo{
    int dato;
    Nodo *siguiente;
};
typedef Nodo *ptrPila;  //creamos un nodo de tipo puntero

//PROTOTIPOS DE FUNCIONES*************************************************
void apilar(ptrPila &,int);
void desapilar(ptrPila &,int &);
void cima(ptrPila &);
//************************************************************************

void apilar(ptrPila &p,int valor){ //el valor de p antes de rellenar la pila vale NULL

    ptrPila aux;            //creamos una variable de tipo puntero pila
    aux=new(struct Nodo);   //creamos un espacio para un nodo (aux)
    aux->dato=valor;        //al nuevo nodo le cargamos el valor
    aux->siguiente=p;       //que el campo puntero (siguiente) apunte a NULL
    p=aux;                  //para que el puntero pila apunte al nuevo nodo creado a la cima
    cout<<"Elemento "<<valor<<" ha sido agregado correctamente"<<endl;
}

void desapilar(ptrPila &p, int &valor){
    ptrPila aux;
    aux=p;  //auxiliar apunta al mismo sitio que p los dos a la cima
    valor=aux->dato; //decimos aux apunte al valor del primer elemento
    p=aux->siguiente; //decimos que aux apunte al siguiente elemento
    delete aux;       //eliminamos aux el elemento deseado

}

void cima(ptrPila &p){
    int elem;
    if(p==NULL){
        cout<<"Error la pila esta vacia";
    }
    else{
        elem=p->dato;
    }
    cout<<"El elemento de la cima de la pila es: "<<elem<<endl;
}

bool vacia(ptrPila &p){
    if(p==NULL){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    Nodo *pila=NULL;    //creamos un nodo vacio es decir la pila vacia
    int n;

    cout<<"Introduczca un numero: ";
    cin>>n;
    apilar(pila,n);
    cout<<"Introduzaca un numero: ";
    cin>>n;
    apilar(pila,n);

    cout<<"\nSacando el elementos de al pila: ";
    while(pila!=NULL){ //Mientras no sea el final de la pila
        desapilar(pila,n);
        if(pila!=NULL){
            cout<<n<<" , ";
        }
        else{
            cout<<n<<".";
        }

    }




    cout<<endl;
    return 0;
}
