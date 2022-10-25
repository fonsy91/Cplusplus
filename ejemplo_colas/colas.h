#ifndef COLAS_H
#define COLAS_H

class Nodo{
    private:
        int valor;
        Nodo *siguiente;
        friend class colas;

    public:
        Nodo(int v, Nodo *sig=0){
            valor=v;
            siguiente=sig;
        }
};
typedef Nodo *pnodo;


class colas{
    public:
        colas();
        ~colas();
        bool esVacia();
        void encolar(int v);
        void desencolar();
        int verPrimero();

    private:
        pnodo inicio,fin;
};

#endif // COLAS_H








