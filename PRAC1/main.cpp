#include "Avion.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;


int main(){

    Avion avion1,avion2;
    Datos dat1,dat2;

    dat1.IdeVuelo="FR1234";
    dat1.IdeInter="MADRID";
    dat1.IdeAeroDes="LONDRES";
    dat1.Hsalida=2134;
    dat1.Hdestino=2312;
    dat1.Hllegada=4566;
    dat1.Tespera=20;
    dat1.Ncombustible="Alto";

    //*********************************************
    /*
    dat1.IdeVuelo="MD5678";
    dat1.IdeInter="FRANCIA";
    dat1.IdeAeroDes="MADRID";
    dat1.Hsalida=2038;
    dat1.Hdestino=1689;
    dat1.Hllegada=1425;
    dat1.Tespera=50;
    dat1.Ncombustible="Medio";
    //*********************************************
    */

    avion1.insertarAvion(dat1);
    avion1.mostrarDatos();
    //avion2.insertarAvion(dat2);
    //avion2.mostrarDatos();

    return 0;
}









