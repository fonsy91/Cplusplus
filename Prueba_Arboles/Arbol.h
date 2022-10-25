#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <string>

using namespace std;


class Nodo{
    private:
        int dato;
        Nodo *izquierda;
        Nodo *derecha;
        friend class Arbol;
    public:
        Nodo(int dat, Nodo *izq=NULL, Nodo *der=NULL){
            dato=dat;
            izquierda=izq;
            derecha=der;
        }
};
typedef Nodo *pNodo;




class Arbol{
    private:
        pNodo raiz,actual=NULL;
        int contador,altura;
        void podar(pNodo &nodo);
        void auxContador(pNodo nodo);
        void auxAltura(pNodo nodo, int a );
        void mostrar(int &d);
    public:
        Arbol() : raiz(NULL), actual(NULL){}
        ~Arbol() {podar(raiz);}
        void buscarNodo(char v);
        void insertarNodo(char v);
        void borrarNodo(char v);
        bool esVacio(pNodo nodo){return nodo==NULL;}
        bool esHoja(pNodo nodo){return !nodo->derecha && !nodo->izquierda;}
        int numeroNodos();
        int getAlturaArbol();
        char getValorActual(){return actual->dato;}
        void esRaiz(){actual=raiz;}
        void inOrden(Nodo *nodo);
        void preOrden(Nodo *nodo);
        void posOrden(Nodo *nodo);

};

#endif // ARBOL_H
