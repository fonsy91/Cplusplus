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
        friend class Avion;
    public:
        NodoAvion(Datos v,NodoAvion *sig=NULL){
            aereo=v;
            siguiente=sig;
        }
};
typedef NodoAvion *pnodo;



class Avion{
    private:
        pnodo primero,ultimo;
        pnodo actual;
    public:
        Avion(){
            primero=actual=ultimo=NULL;

        }
        ~Avion();
        void insertarAvion(Datos a); //Equivalente a encolar
        void borrarAvion(); //Equivalente a desencolar
        void verPrimero(); //muestra el primer elemento de la cola
        bool esVacia(); //dice si la cola esta vacia
        void mostrarDatos(); //muestra los datos de un avion

};

#endif // AVION_H
