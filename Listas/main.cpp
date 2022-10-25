#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


struct Nodo{
    int elemento;
    Nodo *siguiente;
};
typedef Nodo *ptrNodo;

//PROTOTIPOS**********
void insertar(ptrNodo &, int); //esta funcion inserta de una forma ordenada
void insertarIzq(ptrNodo &, int);
void insertarDer(ptrNodo &, int);
void mostrar(ptrNodo &lista);
void primerValor(ptrNodo &lista);


//FUNCIONES***********
void insertar(ptrNodo &lista, int valor){
    ptrNodo aux,aux1,aux2;

    aux=new Nodo();         //reserva espacio para un nuevo nodo
    aux->elemento=valor;    //introducimos el valor en el nodo
    aux1=lista;             //aux1 y lista apuntan a NULL

    //hay 3 tipos de insercciones si la lsita esta vacia
    //si hay un nodo(antes o despues) o si hay dos o mas
    //insertar antes despues o entre medias

    while((aux1 != NULL)&&(aux1->elemento<valor)){
        //cuando ya tenemos un elemento en la lista
        //los elementos insertados se introduciran de menor a mayor
        //los elementos menores que el existente se introduciran por la izquirda
        aux2=aux1;
        aux1=aux1->siguiente;
    }
    //Este condicional nos dice si va al principio al medio o al final

    if(lista==aux1){    //significa que va al principio y que el elemento que queremos insertar es menor al que tenemos
        lista=aux;      //aux ahora apunta al nuevo nodo
    }
    else{
        aux2->siguiente=aux;    // El nodo es mayor al existente y entonces se introducira por la derecha
    }

    aux->siguiente=aux1;        //aux1 apunta al nodo mas viejo el que ya estaba
    cout<<"El elemento ha sido insertado correctamente "<<endl;
}

void insertarIzq(ptrNodo &lista, int valor){

    ptrNodo nuevo_nodo,aux;
    nuevo_nodo=new Nodo();          //espacio para un nuevo nodo
    nuevo_nodo->elemento=valor;     //al campo dato le asigno valor


    if(lista==NULL){
        lista=nuevo_nodo;
    }
    else{
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }

    cout<<"El elemento ha sido insertado correctamente "<<endl;
}

void insertarDer(ptrNodo &lista, int valor){
    ptrNodo nuevo_nodo,aux;
    nuevo_nodo=new Nodo();
    nuevo_nodo->elemento=valor;
    nuevo_nodo->siguiente=NULL;


    if(lista==NULL){
        lista=nuevo_nodo;
    }
    else{
        aux=lista;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo_nodo;
    }
    aux=nuevo_nodo->siguiente;


    cout<<"El elemento ha sido insertado correctamente "<<endl;
}

void primerValor(ptrNodo &lista){
    int e;
    if(lista==NULL){
        cout<<"error no hay elementos en la lista";
    }
    else{
        e=lista->elemento;
        cout<<"El primer valor de la lista es: "<<e<<endl;
    }

}

void mostrar(ptrNodo &lista){
    while(lista!=NULL){
        cout<<" "<<lista->elemento;
        lista=lista->siguiente;
    }
}

int main(){

    ptrNodo lista=NULL;
    int dato;
    char res;

    do{
        cout<<"Introduce un dato en la lista: ";
        cin>>dato;
        insertarIzq(lista,dato);
        //insertarDer(lista,dato);
        cout<<"Desea seguir introduciendo datos: ";
        cin>>res;
    }while((res=='s')||(res=='S'));
    cout<<endl;
    primerValor(lista);
    mostrar(lista);


    //voy por el video 104 terminado empezar 105
    return 0;
}

/*

Listas simplemente enlazadas: cada nodo(elemento) contiene un unico
enlace que conecta ese nodo al siguiente (adelante)
operaciones:
-insertar un elemento en la lista enlazada
-mostrar los elementos de una lista enlazada
-Buscar un elemento en una lista enlazada
-Eliminar un elemnto en una lista enlazada
******************************************************************
Lista doblemente enlazada: cada nodo contiene dos enlaces, uno a su
nodo predecesor y otro al nodo sucesor (adelante)(atras)

*/
