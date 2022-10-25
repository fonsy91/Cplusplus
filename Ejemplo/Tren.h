#ifndef TREN_H
#define TREN_H
#include <iostream>

using namespace std;

struct Vagon
{
    int id_tren;
    int nvagon;
    string origen;
    string destino;
    string carga;
};
class NodoVagon
{
public:
    Vagon vag;
    NodoVagon *siguiente;
    friend class Tren;
public:
    NodoVagon(Vagon v, NodoVagon *sig = NULL)
    {
        vag = v;
        siguiente = sig;
    }
};
typedef NodoVagon *pnodo;



class Tren

{
private:
    pnodo cabeza, ultimo;
    pnodo actual;

public:
    Tren()
    {
        cabeza = actual=ultimo = NULL;
    }
    ~Tren();
    void insertarVagon(Vagon v);
    void borrarVagon(Vagon v);
    bool TrenVacio();
    void mostrarTren();
    void CambiarVagon(Tren &t1,Tren &t2,Tren &t3,Tren &t4,Tren &t5);

};

#endif // TREN_H
