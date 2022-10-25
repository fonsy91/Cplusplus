#include <iostream>
#include <conio.h>
#include <stdlib.h>>

using namespace std;

struct Nodo{
    int valor;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};


//PROTOTIPOS DE LAS FUNCIONES****************************************
void menu();
Nodo *crearNodo(int,Nodo *); //entero y nodo padre
void insertarNodo(Nodo *&,int,Nodo *); //arbol, entero y nodo padre
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *); //funcion de tipo nodo y le pasamos el arbol
void reemplazar(Nodo *,Nodo *);
void destruir(Nodo *);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);

//Creamos el arbol***************************************************
Nodo *arbol=NULL;

//FUNCIONES**********************************************************
//*******************************************************************

Nodo *crearNodo(int n,Nodo *padre){
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->valor=n;
    nuevo_nodo->der=NULL;
    nuevo_nodo->izq=NULL;
    nuevo_nodo->padre=padre;
    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre){ //[5]//4

  if(arbol==NULL){                    //si el arbol esta vacio
        Nodo *nuevo_nodo=crearNodo(n,padre);  //creamos un nuevo nodo
        arbol=nuevo_nodo;               //lo insertamos en el arbol
    }
    else{                               //Si el arbol no esta vacio
        int valorRaiz;
        valorRaiz=arbol->valor;         //obtenemos el valor de la raiz
        if(n<valorRaiz){                //si n es menor que la raiz
            insertarNodo(arbol->izq,n,arbol); //insertamos por la izquierda
        }
        else{                           //si no
            insertarNodo(arbol->der,n,arbol); //lo insertamos por la derecha
        }
    }
    cout<<"El nodo ha sido introducido correctamente";
}

void menu(){
    int dato,opcion,contador=0;
    do{
        cout<<endl;
        cout<<"\t.:MENU:."<<endl;
        cout<<"1.Insertar un nuevo nodo"<<endl;
        cout<<"2.Mostara el arbol completo"<<endl;
        cout<<"3.Buscar un elemento en el arbol"<<endl;
        cout<<"4.Recorrer el arbol en preorden"<<endl;
        cout<<"5.Recorrer el arbol en inOrden"<<endl;
        cout<<"6.Recorrer el arbol en postOrden"<<endl;
        cout<<"7.Salir"<<endl;
        cout<<endl;
        cout<<"Introduzca una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Introduce un numero: ";
                cin>>dato;
                insertarNodo(arbol,dato,NULL);
                break;
            case 2:
                cout<<"\nMostarndo el arbol completo:\n\n";
                mostrarArbol(arbol,contador);
                cout<<"\n";
                break;
            case 3:
                cout<<"\nIntroduce el elemento a buscar: ";
                cin>>dato;
                if(busqueda(arbol,dato)==true){
                    cout<<"\nElemento "<<dato<<" a sido encontrado\n";
                }
                else{
                    cout<<"\nElemento no encontrado\n";
                }
                break;
            case 4:
                cout<<"\nRecorrido en preOrden: ";
                preOrden(arbol);
                cout<<"\n\n";
                break;
            case 5:
                cout<<"\nRecorrido en inOrden: ";
                inOrden(arbol);
                cout<<"\n\n";
                break;
            case 6:
                cout<<"\nRecorrido en postOrden: ";
                postOrden(arbol);
                cout<<"\n\n";
                break;
        }
    }while(opcion!=7);
}

void mostrarArbol(Nodo *arbol, int cont){
    if(arbol==NULL){
        return;
    }
    else{
        mostrarArbol(arbol->der,cont+1);
        for(int i=0; i<cont;i++){
            cout<<"   ";
        }
        cout<<arbol->valor<<endl;
        mostrarArbol(arbol->izq,cont+1);
    }
}

bool busqueda(Nodo *arbol, int n){
    if(arbol==NULL){
        return false;
    }
    else if(arbol->valor==n){
        return true;
    }
    else if(n<arbol->valor){
        return busqueda(arbol->izq,n);
    }
    else{
        return busqueda(arbol->der,n);
    }
}


//FUNCIONES DE RECORRIDOS DE ARBOLES*********************************
//*******************************************************************

void preOrden(Nodo *arbol){
    if(arbol==NULL){
        return;
    }
    else{
        cout<<arbol->valor<<" - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(Nodo *arbol){
    if(arbol==NULL){
        return;
    }
    else{
        inOrden(arbol->izq);
        cout<<arbol->valor<<" - ";
        inOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol){
    if(arbol==NULL){
        return;
    }
    else{
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->valor<<" - ";
    }
}


//FUNCIONES PARA ELIMINAR UN NODO**************************************
//*********************************************************************
void eliminar(Nodo *arbol, int n){
    if(arbol==NULL){
        return;
    }
    else if(n<arbol->valor){
        eliminar(arbol->izq,n);
    }
    else if(n>arbol->valor){
        eliminar(arbol->der,n);
    }
    else{
        eliminarNodo(arbol);
    }
}

Nodo *minimo(Nodo *arbol){ //funcion para hallar el nodo mas izquierdo
    if(arbol==NULL){
        return NULL;
    }
    if(arbol->izq){
        return minimo(arbol->izq);
    }
    else{ //si no tiene hijo izquierdo retornamos el mismo nodo
        return arbol;
    }
}

void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
    if(arbol->padre){
        //arbol->padre asignarle su nuevo hijo
        if(arbol->valor=arbol->padre->izq->valor){
            arbol->padre->izq=nuevoNodo;
        }
        else if(arbol->valor == arbol->padre->der->valor){
            arbol->padre->der=nuevoNodo;
        }
    }
    if(nuevoNodo){
        //asignamos su nuevo padre
        nuevoNodo->padre=arbol->padre;
    }
}

void destruir(Nodo *nodo){
    nodo->izq=NULL;
    nodo->der=NULL;
    delete nodo;
}

void eliminarNodo(Nodo *nodoEliminar){
    if(nodoEliminar->izq && nodoEliminar->der){
        Nodo *menor;
        menor=minimo(nodoEliminar->der);
        nodoEliminar->valor=menor->valor;
        eliminarNodo(menor);
    }
    else if(nodoEliminar->izq){
        reemplazar(nodoEliminar,nodoEliminar->izq);
        destruir(nodoEliminar);
    }
    else if(nodoEliminar->der){
        reemplazar(nodoEliminar,nodoEliminar->der);
        destruir(nodoEliminar);
    }
}



int main(){

    menu();



    return 0;
}

//pagina para saber sobre arboles binarios
//https://www.youtube.com/watch?v=YQAWruF0iwQ

/*
ARBOLES BINARIOS

Son �rboles de orden dos es decir o tienen 0,1 o 2 hijos

Recorridos:

1->Anchura
2->preorden----raiz,arbol izquierdo,arbol derecho
3->Inorden-----arbol izquierdo,raiz,arbol derecho
4->Postorden---arbol izquierdo,arbol derecho,raiz

Los ultimos 3 son en profuncidad

-Opereaciones elementales: inserccion,eliminacion y localizacion

-ARBOLES BINARIOS DE BUSQUEDA
Un arbol binario es de busqueda cuando R no es vacia y si tiene un subarbol izquiedo
la raiz de este es menor a R y a la vez el subarbol izquierdo tambien es de busqueda y si
tiene un subarbol derecho la raiz de este sera mayor a R


*/
