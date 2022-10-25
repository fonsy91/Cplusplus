#ifndef COLAS_H
#define COLAS_H

#include <iostream>

class Nodo{
    private:
        int valor;
        Nodo *siguiente;
        friend class Cola;

    public:
        Nodo(int v, Nodo *sig=NULL){
            valor=v;
            siguiente=sig;
        }
};
typedef nodo *pnodo;


class Cola{
    public:
        Cola(): ultimo(NULL), primero(NULL){}
        ~Cola();
        void encolar(int v);
        int desencolar();

    private:
        pnodo primero,ultimo;


};


#endif // COLAS_H
