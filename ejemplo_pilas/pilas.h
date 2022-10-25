#ifndef PILAS_H
#define PILAS_H


class Nodo{
    private:
        int valor;
        Nodo *siguiente;
        friend class pilas;
    public:
        Nodo(int v, Nodo *sig=0){
            valor= v;
            siguiente=sig;
        }
};
typedef Nodo *pNodo;



class pilas{
    private:
        pNodo cima;
    public:
        pilas(): cima(0){}
        ~pilas();
        void apilar(int v);
        int desapilar();
};

#endif // PILAS_H
