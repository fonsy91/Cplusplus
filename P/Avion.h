#ifndef AVION_H
#define AVION_H
#include <iostream>
#include <string>
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




class NodoAvion{
    public:
        Datos aereo;
        NodoAvion *siguiente;
        friend class Cola;
    public:
        NodoAvion(Datos v,NodoAvion *sig=NULL){
            aereo=v;
            siguiente=sig;
        }
};
typedef NodoAvion *pnodo;



class Cola{ //cola
    private:
        pnodo primero,ultimo;

    public:
        Cola(){
            primero=ultimo=NULL;

        }
        ~Cola();
        void encolarAvion(Datos); //Equivalente a encolar
        Datos desencolarAvion(); //Equivalente a desencolar
        bool ColaVacia(); //dice si la cola esta vacia
        void mostrarDatos(); //muestra los datos de un avion
        int Cuantos();// dice cuantos nodos o aviones hay en una cola
        void crearAviones();
};

#endif // AVION_H
