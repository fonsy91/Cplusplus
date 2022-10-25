#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

struct Datos{
    string IdeVuelo;
    string IdeInter;
    string IdeAeroDes;
    int Hsalida;
    int Hdestino;
    int Hllegada;
    int Tespera;
    string Ncombustible;
};


void crear(){
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
        //cout<<"Vuelo: "<<vuelo<<"   "<<"Origen: "<<origen<<"    "<<"Destino: "<<destino<<"    "<<"Hsalida: "<<hs<<"    "<<"Hdestino: "<<hd<<"    "<<"Hllegada: "<<hl<<"    "<<"Tespera: "<<te<<"    "<<"Ncombus: "<<combusti<<endl;
        avacio={vuelo,origen,destino,hs,hd,hl,te,combusti};
    }
}


int main(){

    Datos a;

    cout<<"CREACION DE AVIONES"<<endl;
    crear();




    return 0;
}
