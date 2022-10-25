#include "Pila.h"


int Pila::PilaVacia(){
    return cima==0;
}
//******************************

void Pila::insertar(int elemento){
    NodoPila *nuevo;   //crea un nodo nuevo una direccion de memoria apuntando a un nodo
    nuevo=new NodoPila(elemento); // y a ese nuevo nodo le pasa por parametro un entero
    nuevo->siguiente=cima;  //el elemento nuevo va a apuntar a la cima
    cima=nuevo; // y la cima va a apuntar al nuevo elemento
}
//*******************************
int Pila::quitar(){
    if(PilaVacia()){
        throw "Pila vacia, no se puede extraer.";
    }
    int aux=cima->elemento; //creamos un entero auxiliar que va a ser igual al elemento que se encuentre en la cima
    cima=cima->siguiente;// y la cima va a ser igual al elemento siguiente
    return aux;
}
//********************************
int Pila::cimaPila(){
    if(PilaVacia()){
        throw "Pila vacia";
    }
    return cima->elemento;
}
//**********************************
void Pila::limpiarPila(){
    NodoPila *n;
    while(!PilaVacia()){
        n=cima;
        cima=cima->siguiente;
        delete n;
    }
}
//************************
























