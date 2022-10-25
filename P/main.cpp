#include "Avion.h"
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


int main(){

    Cola aproximacion,espera;
    Datos avacio;
    int cont1=0;
    int cont2=0;

    srand(time(NULL));
    int nv=15; //numero de aviones a generar
    cout<<"***************************************************"<<endl;
    cout<<"**************TORRE DE CONTROL TMA*****************"<<endl;
    cout<<"***************************************************"<<endl;
    cout<<endl;
    cout<<"Aviones aproximandose al aeropuerto..."<<endl;
    cout<<endl;
    for(int i=0; i<nv; i++){
        avacio={"","","",0,0,0,0,""};
        string IdeVuelo[6]={"FRA3456","AFL2500","MDR4500","BRU2345","LON8956","RUS3451"}; //identificadores de vuelo(compañia)
        string IdeInter[6]={"MAD","STN","AGP","CPH","LON","FRA"}; //identificador de aeropuerto de origen
        string IdeAeroDes[6]={"ARG","SUE","DIN","EST","ITA","MAD"}; //identificador de aeropuerto de destino
        string Ncombustible[3]={"Alto","Medio","Bajo"};

        int ide1,ide2,ide3,hs,ms,hd,md,hl,ml,te,com;
        string vuelo,origen,destino,combusti;

        ide1=rand()%6;
        ide2=rand()%6;
        ide3=rand()%6;

        hs=rand()%23;   //hora salida
        ms=rand()%59;   //minutos salida
        hd=rand()%23;   //hora destino
        md=rand()%59;   //minutos destino
        hl=rand()%23;   //hora llegada
        ml=rand()%59;   //minutos llegada
        te=rand()%6;   //tiempo de espera
        com=rand()%3;   //nivel de combustible

        vuelo=IdeVuelo[ide1];
        origen=IdeInter[ide2];
        destino=IdeAeroDes[ide3];
        combusti=Ncombustible[com];

        //Prototipo de avión
        avacio={vuelo,origen,destino,hs*100+ms,hd*100+md,hl*100+ml,te,combusti};

        if(avacio.Ncombustible=="Alto"){
            espera.encolarAvion(avacio);
        }

        if((avacio.Ncombustible=="Medio")or(avacio.Ncombustible=="Bajo")){
            aproximacion.encolarAvion(avacio);
        }

        cont1=cont1+1;
    }
    cout<<"**************************************"<<endl;
    cout<<"**********COLA DE ESPERA**************"<<endl;
    cout<<endl;
    cout<<"El numero de aviones encolados son: "<<espera.Cuantos()<<endl;
    cout<<endl;
    espera.mostrarDatos();

    cout<<"***************************************"<<endl;
    cout<<"**********COLA DE APROXIMACION*********"<<endl;
    cout<<endl;
    cout<<"El numero de aviones encolados son: "<<aproximacion.Cuantos()<<endl;
    cout<<endl;
    aproximacion.mostrarDatos();

    cout<<"********CENTRO DE CONTROL***********"<<endl;
    cout<<"************ATERRIZAJE***************"<<endl;
    cout<<endl;
    cout<<"Desencolandose aviones de la zona de aterrizaje..."<<endl;
    cout<<endl;
    for(int i=0; i=aproximacion.Cuantos();i++){
        cout<<"Aterrizando avion: "<<aproximacion.desencolarAvion().IdeVuelo<<endl;
    }



    return 0;
}

