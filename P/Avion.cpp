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
    if(ultimo) ultimo->siguiente=nuevo;

    ultimo=nuevo;

    if(!primero) primero=nuevo;
}
//Funcion desencolar avion***************************************************
Datos Cola::desencolarAvion(){
    pnodo nodo;   //variable de tipo nodoAvion
    Datos a;     //variable tipo datos
    nodo=primero;

    if(!nodo){}

    primero=nodo->siguiente; //accedemos al contenido de siguiente

    a=nodo->aereo;

    delete nodo;
    if(!primero){
        ultimo=NULL;
    }
    return a;
}

bool Cola::ColaVacia(){
    if(primero==NULL){
        return cout<<"No hay datos en la cola"<<endl;
    }else{
        return cout<<"Hay datos en la cola"<<endl;
    }
}


int Cola::Cuantos(){
    NodoAvion *aux, *aux1;
    aux=primero;
    int i=0;

    if(primero==NULL){
        //cout<<"La cola esta vacia"<<endl;
        return 0;
    }
    while(aux!=NULL){
        aux1=aux->siguiente;
        aux=aux1;
        i++;
    }
    return i;
    //cout<<"Los aviones encolados son: "<<i<<endl;
}


void Cola::crearAviones(){
    srand(time(NULL));
    int nv;
    nv=3+rand()%(6-3);
    for(int i=0; i<nv; i++){
        Datos avacio={"","","",0,0,0,0,""};
        string IdeVuelo[6]={"FRA3456","AFL2500","MDR4500","BRU2345","LON8956","RUS3451"}; //identificadores de vuelo
        string IdeInter[6]={"MAD","STN","AGP","CPH","LON","FRA"}; //identificador de aeropuerto de origen
        string IdeAeroDes[6]={"ARG","SUE","DIN","EST","ITA","MAD"}; //identificador de aeropuerto de destino
        string Ncombustible[3]={"Alto","Medio","Bajo"};

        int ide1,ide2,ide3,hs,hd,hl,te,com;
        string vuelo,origen,destino,combusti;

        ide1=rand()%6;
        ide2=rand()%6;
        ide3=rand()%6;

        hs=rand()%23;
        hd=rand()%23;
        hl=rand()%23;
        te=rand()%23;
        com=rand()%3;

        vuelo=IdeVuelo[ide1];
        origen=IdeInter[ide2];
        destino=IdeAeroDes[ide3];
        combusti=Ncombustible[com];
        cout<<"Vuelo: "<<vuelo<<"   "<<"Origen: "<<origen<<"    "<<"Destino: "<<destino<<"    "<<"Hsalida: "<<hs<<"    "<<"Hdestino: "<<hd<<"    "<<"Hllegada: "<<hl<<"    "<<"Tespera: "<<te<<"    "<<"Ncombus: "<<combusti<<endl;
        avacio={vuelo,origen,destino,hs,hd,hl,te,combusti};


    }

}




