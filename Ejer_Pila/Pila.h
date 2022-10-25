#ifndef PILA_H
#define PILA_H


class Pila{

    class NodoPila{
        public:
            NodoPila *siguiente; //direccion de memoria a si misma
            int elemento;
            NodoPila(int x){ //funcionn Nodo Pila dentro del constructor
                elemento=x;
                siguiente=0;
            }

    };
    NodoPila *cima; //elemento hasta el final de la pila
    public:
        Pila(){
            cima=0;
        }
        void insertar(int elemento);
        int quitar();
        int cimaPila();
        int PilaVacia();
        void limpiarPila();
        ~Pila(){
            limpiarPila();
        }

};

#endif // PILA_H
