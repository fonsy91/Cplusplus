#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 4 //definicion de la constante Max indicando el maximo de elementos de la pila

int pila[MAX]; //vector o array de tipo enteron indicando un maximo de 4 elementos
int top; //variable donde se guarda la cima o el ultimo elemento que esta en la parte superior de la pila

//Prototipos de la funciones
void apilar();
void desapilar();
void visualizar();


using namespace std;


int main(){

        int opcion;
        top=-1;

        do{
            cout<<"**********************"<<endl;
            cout<<"1. APILAR"<<endl;
            cout<<"2. DESAPILAR"<<endl;
            cout<<"3. VISUALIZAR"<<endl;
            cout<<"4. SALIR"<<endl;
            cout<<"**********************"<<endl;
            cout<<"Elija una opcion: ";
            cin>>opcion;
            switch(opcion){
                case 1:apilar();
                    break;
                case 2: desapilar();
                    break;
                case 3: visualizar();
                    break;

            }

        }while(opcion!=4);


    return 0;
}

//FUNCIONES DE LA PILA

void apilar(){
    int num;
    if(top==(MAX-1)){
        cout<<"Pila llena\n";
    }
    else{
        cout<<"Introduzca elemento: "<<endl;
        cin>>num;
        top=top+1;
        pila[top]=num;
    }

}

void desapilar(){
    int i;
    if(top==-1){
        cout<<"pila vacia";
    }
    else{
        cout<<"elemento eliminado"<<pila[top];
        top=top-1;
    }

}

void visualizar(){
    int i;
    if(top==-1){
        cout<<"Pila vacia";
    }
    else{
        for(i=top; i>=0; i--){
            cout<<pila[i]<<endl;
        }
    }
}







