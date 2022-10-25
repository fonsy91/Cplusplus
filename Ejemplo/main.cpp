#include <iostream>
#include "Tren.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
Tren tren1,tren2,tren3,tren4,tren5;
Vagon vagonA,vagonB,vagonC,vagonE,vagonF;
int main()

{
    srand(time(NULL));
    int nv;
    int num;
    nv=3+rand()%(6-3);//SE CREA ALEATORIAMENTE EL NUMERO DE VAGONES
    for (int i=0; i<nv; i++)
    {
        vagonA.id_tren=123;
        if(i==0)
        {
            vagonA.origen="Sevilla";
            vagonA.destino="Valladolid";
            vagonA.nvagon=0001;
            vagonA.carga="Sin carga";
            tren1.insertarVagon(vagonA);
        }
        else
        {
            string dest[5]= {"Valladolid","Zaragoza","Burgos","Orense","Bilbao"};
            int d;
            string destino;
            d=rand()%5;
            destino=dest[d];
            vagonA.destino=destino;

            string carg[5]= {"Alimentos","Materiales de Construccion","Componentes Electronicos","Vehiculos","Ganado"};
            int c;
            string carga;
            c=rand()%5;
            carga=carg[c];
            vagonA.carga=carga;

            num=1000+rand()%(10000-1000);
            vagonA.nvagon=num;
            tren1.insertarVagon(vagonA);

        }
    }
    cout<<"+++++++++++++TREN1++++++++++++"<<endl;
    tren1.mostrarTren();

    nv=3+rand()%(6-3);
    for (int i=0; i<nv; i++)
    {
        vagonB.id_tren=456;
        if(i==0)
        {
            vagonB.origen="Zamora";
            vagonB.destino="Zaragoza";
            vagonB.nvagon=0001;
            vagonB.carga="Sin Carga";
            tren2.insertarVagon(vagonB);
        }
        else
        {

            string dest1[5]= {"Valladolid","Zaragoza","Burgos","Orense","Bilbao"};
            int d1;
            string destino1;
            d1=rand()%5;
            destino1=dest1[d1];
            vagonB.destino=destino1;

            string carg1[5]= {"Alimentos","Materiales de Construccion","Componentes Electronicos","Vehiculos","Ganado"};
            int c1;
            string carga1;
            c1=rand()%5;
            carga1=carg1[c1];
            vagonB.carga=carga1;


            int num1=1000+rand()%(10000-1000);
            vagonB.nvagon=num1;
            tren2.insertarVagon(vagonB);
        }
    }
    cout<<"+++++++++++++TREN2++++++++++++"<<endl;
    tren2.mostrarTren();

    nv=3+rand()%(6-3);
    for (int i=0; i<nv; i++)
    {
        vagonC.id_tren=224;
        if(i==0)
        {
            vagonC.origen="Badajoz";
            vagonC.destino="Burgos";
            vagonC.nvagon=0001;
            vagonC.carga="Sin carga";
            tren3.insertarVagon(vagonC);

        }

        else
        {
            string dest2[5]= {"Valladolid","Zaragoza","Burgos","Orense","Bilbao"};
            int d2;
            string destino2;
            d2=rand()%5;
            destino2=dest2[d2];
            vagonC.destino=destino2;

            string carg2[5]= {"Alimentos","Materiales de Construccion","Componentes Electronicos","Vehiculos","Ganado"};
            int c2;
            string carga2;
            c2=rand()%5;
            carga2=carg2[c2];
            vagonC.carga=carga2;

            int num1=1000+rand()%(10000-1000);
            vagonC.nvagon=num1;
            tren3.insertarVagon(vagonC);
        }
    }

    cout<<"+++++++++++++TREN3++++++++++++"<<endl;
    tren3.mostrarTren();

    nv=3+rand()%(6-3);//SE CREA ALEATORIAMENTE EL NUMERO DE VAGONES
    for (int i=0; i<nv; i++)
    {
        vagonE.id_tren=801;
        if(i==0)
        {
            vagonE.origen="Cuenca";
            vagonE.destino="Orense";
            vagonE.nvagon=1;
            vagonE.carga="Sin carga";
            tren4.insertarVagon(vagonE);
        }
        else
        {
            string dest3[5]= {"Valladolid","Zaragoza","Burgos","Orense","Bilbao"};
            int d3;
            string destino3;
            d3=rand()%5;
            destino3=dest3[d3];
            vagonE.destino=destino3;

            string carg3[5]= {"Alimentos","Materiales de Construccion","Componentes Electronicos","Vehiculos","Ganado"};
            int c3;
            string carga3;
            c3=rand()%5;
            carga3=carg3[c3];
            vagonE.carga=carga3;

            int num2=1000+rand()%(10000-1000);
            vagonE.nvagon=num2;
            tren4.insertarVagon(vagonE);
        }
    }
    cout<<"+++++++++++++TREN4++++++++++++"<<endl;
    tren4.mostrarTren();

    nv=3+rand()%(6-3);
    for (int i=0; i<nv; i++)
    {
        vagonF.id_tren=652;
        if(i==0)
        {
            vagonF.origen="Albacete";
            vagonF.destino="Bilbao";
            vagonF.nvagon=0001;
            vagonF.carga="Sin carga";
            tren5.insertarVagon(vagonF);
        }
        else
        {
            string dest4[5]= {"Valladolid","Zaragoza","Burgos","Orense","Bilbao"};
            int d4;
            string destino4;
            d4=rand()%5;
            destino4=dest4[d4];
            vagonF.destino=destino4;

            string carg4[5]= {"Alimentos","Materiales de Construccion","Componentes Electronicos","Vehiculos","Ganado"};
            int c4;
            string carga4;
            c4=rand()%5;
            carga4=carg4[c4];
            vagonF.carga=carga4;

            int num3=1000+rand()%(10000-1000);
            vagonF.nvagon=num3;
            tren5.insertarVagon(vagonF);
        }
    }
    cout<<"+++++++++++++TREN5++++++++++++"<<endl;
    tren5.mostrarTren();

    cout<<"............Los Trenes llegan al intercambiador.........\n\n"<<endl;

    tren1.CambiarVagon(tren1,tren2,tren3,tren4,tren5);
    tren2.CambiarVagon(tren2,tren1,tren3,tren4,tren5);
    tren3.CambiarVagon(tren3,tren1,tren2,tren4,tren5);
    tren4.CambiarVagon(tren4,tren1,tren2,tren3,tren5);
    tren5.CambiarVagon(tren5,tren1,tren2,tren3,tren4);

    cout<<"+++++++++++++TREN1++++++++++++\n"<<endl;
    tren1.mostrarTren();
    cout<<"+++++++++++++TREN2++++++++++++\n"<<endl;
    tren2.mostrarTren();
    cout<<"+++++++++++++TREN3++++++++++++\n"<<endl;
    tren3.mostrarTren();
    cout<<"+++++++++++++TREN4++++++++++++\n"<<endl;
    tren4.mostrarTren();
    cout<<"+++++++++++++TREN5++++++++++++\n"<<endl;
    tren5.mostrarTren();

    return 0;
}
