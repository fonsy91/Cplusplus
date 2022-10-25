#include "Avion.h"
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


int main(){

    Cola aproximacion,espera;
    Datos avacio,avdesencolado;

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
        te=1+rand()%(7-1);   //tiempo de espera
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

    }
    cout<<"**************************************"<<endl;
    cout<<"**********COLA DE ESPERA**************"<<endl;
    cout<<endl;
    cout<<"El numero de aviones encolados son: "<<espera.Cuantos()<<endl;
    cout<<endl;
    //Este procedimineto deberia hacerse con una funcion pero codeblock me daba errores internos no de codigo
    Datos x,z;
    Cola aux;
    for(int j=0; j=espera.Cuantos(); j++){  //desde el primer avion hasta el ultimo
        int tam=espera.Cuantos();           //se guarda en tam el tamaño de cola de espera
        x=espera.desencolarAvion();         // guardo en x el primer avion
        int i=1;                            //i=1
        while(i<tam){                       // si i es mejor que numero de aviones de la cola de espera
            z=espera.desencolarAvion();     //guardo en z el avion desencolado de la cola de espera el segundo
            if(z.Hllegada>x.Hllegada){      //si hll de es mayor que hll de x entonces encolas en cola espera
                espera.encolarAvion(z);
            }else{                          //sino
                espera.encolarAvion(x);     //encolas x en cola de espera
                x=z;                        //si encolas x entoncs x ahora es z
            }
            i=i+1;                          //aumentas el contador
        }
        aux.encolarAvion(x);                //encolas x
    }

    aux.mostrarDatos();

    cout<<"***************************************"<<endl;
    cout<<"**********COLA DE APROXIMACION*********"<<endl;
    cout<<endl;
    cout<<"El numero de aviones encolados son: "<<aproximacion.Cuantos()<<endl;
    cout<<endl;
    //Este procedimineto deberia hacerse con una funcion pero codeblock me daba errores internos no de codigo
    Datos p,r;
    Cola aux1;
    for(int s=0; s=aproximacion.Cuantos(); s++){
        int tam1=aproximacion.Cuantos();
        p=aproximacion.desencolarAvion();
        int l=1;
        while(l<tam1){
            r=aproximacion.desencolarAvion();
            if(r.Hllegada>p.Hllegada){
                aproximacion.encolarAvion(r);
            }else{
                aproximacion.encolarAvion(p);
                p=r;
            }
            l=l+1;
        }
        aux1.encolarAvion(p);
    }

    aux1.mostrarDatos();


    cout<<"********CENTRO DE CONTROL**************"<<endl;
    cout<<"************ATERRIZAJE*****************"<<endl;
    cout<<endl;
    cout<<"Desencolandose aviones de la zona de aterrizaje..."<<endl;
    cout<<"El numero de aviones a desencolar es: "<<aux1.Cuantos()<<endl;
    cout<<endl;
    for(int i=0; i=aux1.Cuantos();i++){
        cout<<"Aterrizando avion: "<<aux1.desencolarAvion().IdeVuelo<<endl;
    }
    cout<<endl;
    cout<<"Centro de control de aterrizaje llamando a TMA..."<<endl;
    cout<<"Loa aviones de la cola de espera pueden aproximarse..."<<endl;
    cout<<"Encolando aviones de la cola de espera a la cola aproximacion"<<endl;
    cout<<endl;
    for(int z=0; z=aux.Cuantos(); z++){
        avdesencolado=aux.desencolarAvion(); //guardas los aviones de la cola de espera en avdesencolado
        aux1.encolarAvion(avdesencolado); //encolas los aviones de avdesencolado en cola de aproximacion

    }
    aux1.mostrarDatos();
    cout<<"Desencolando aviones restantes de la zona de aterrizaje..."<<endl;
    cout<<"El numero de aviones a desencolar es: "<<aux1.Cuantos()<<endl;
    cout<<endl;
    for(int i=0; i=aux1.Cuantos();i++){
        cout<<"Aterrizando avion: "<<aux1.desencolarAvion().IdeVuelo<<endl;
    }


    return 0;
}




