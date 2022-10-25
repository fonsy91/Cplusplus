#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
using namespace std;

class Nodo{
    private:
        int valor;
        Nodo *siguiente;
        friend class Lista;
    public:
        Nodo(int v, Nodo *sig=NULL){
            valor=v;
            siguiente=sig;
        }
};
typedef Nodo *pnodo;


class Lista{
    private:
        pnodo cabeza,final;
        pnodo actual;

    public:
        Lista(){cabeza=actual=NULL;}
        ~Lista();
        void insertarNodo(int v);
        void borrarNodo(int v);
        bool listaVacia();
        void mostrarLista();
        void esSiguiente();
        void esPrimero();
        void esUltimo();
        bool esActual();
        int valorActual();
};

#endif // LISTA_H
