#ifndef LISTAD_H
#define LISTAD_H


#include <iostream>
#include <string>
using namespace std;

class Nodo{
    private:
        int valor;
        Nodo *siguiente;
        Nodo *anterior;
        friend class ListaD;
    public:
        Nodo(int v, Nodo *sig=NULL,Nodo *ant=NULL){
            valor=v;
            siguiente=sig;
            anterior=ant;
        }
};
typedef Nodo *pnodo;



class ListaD{
    private:
        pnodo cabeza,final,actual;

    public:
        ListaD(){cabeza=actual=final=NULL;}
        ~ListaD();
        void insertarNodo(int v,char c);
        void borrarNodo(int v, char c);
        bool listaVacia();
        void mostrarLista(char c);
        void esSiguiente();
        void esAnterior();
        void esPrimero();
        void esUltimo();
        bool esActual();
        int valorActual();
};

#endif // LISTAD_H
