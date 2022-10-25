#include "Tren.h"
#include <time.h>
#include <stdlib.h>


Tren::~Tren()
{
    pnodo aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}
void Tren::insertarVagon(Vagon v)
{
    pnodo aux;
    if (TrenVacio())
    {
        cabeza = new NodoVagon(v, NULL);
        ultimo=cabeza;
    }
    else
    {
        aux= new NodoVagon(v,NULL);
        ultimo->siguiente=aux;
        ultimo=aux;
    }
}
void Tren::borrarVagon(Vagon v)
{   pnodo anterior;
    actual = cabeza;
    while (actual->vag.nvagon !=v.nvagon && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual==cabeza)  // Primer elemento
    {
        cabeza = actual->siguiente;
    }
    else
    {   anterior->siguiente = actual->siguiente;
        if (actual==ultimo)
        {
            ultimo=anterior;
        }
    }
    actual->siguiente=NULL;
    delete actual;
}

bool Tren::TrenVacio()
{
    return cabeza == NULL;
}
void Tren::mostrarTren()
{
    NodoVagon *aux;
    aux = cabeza;
    while(aux)
    {
    cout <<"Id.TREN:"<<aux->vag.id_tren<<"  "<<"Numero de Vagon:"<<aux->vag.nvagon<<"  "<<"Origen:"<<aux->vag.origen<<"   "<< "Destino:"<<aux->vag.destino<<"   "<< "Carga:"<<aux->vag.carga<<endl;
    aux = aux->siguiente;
    }
    cout << endl;


}
void Tren::CambiarVagon(Tren &t1,Tren &t2,Tren &t3,Tren &t4,Tren &t5)
{
    NodoVagon *aux;
    aux = t1.cabeza;
    Vagon va;
    while (aux)
    {
        va = aux->vag;
        aux = aux->siguiente;
        if (va.destino!=t1.cabeza->vag.destino)
        {

            if (va.destino == t2.cabeza->vag.destino)
            {
                va.id_tren=t2.cabeza->vag.id_tren;
                t2.insertarVagon(va);
            }
            if (va.destino == t3.cabeza->vag.destino)
            {
                va.id_tren=t3.cabeza->vag.id_tren;
                t3.insertarVagon(va);
            }
            if (va.destino == t4.cabeza->vag.destino)
            {
                va.id_tren=t4.cabeza->vag.id_tren;
                t4.insertarVagon(va);
            }
            if (va.destino == t5.cabeza->vag.destino)
            {
                va.id_tren=t5.cabeza->vag.id_tren;
                t5.insertarVagon(va);
            }
            t1.borrarVagon(va);
            aux = t1.cabeza;

        }
    }

}


