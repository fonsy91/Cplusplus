#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Estructura de datos: es un grupo de elementos agrupados bajo
un mismo nombre, con diferentes tipos y longuitudes
*/

struct grupo{
    int entero;
    string cadena;
    vector<string>arr;

};

int main(){

    //Objeto de una estructura de datos
    grupo objeto;
    objeto.entero=3;
    objeto.cadena="Hola tio";
    objeto.arr.push_back("uno");
    objeto.arr.push_back("dos");
    objeto.arr.push_back("tres");

    cout<<"Entero= "<<objeto.entero<<" :cadena= "<<objeto.cadena<<endl;
    cout<<"Elementos del array arr: ";
    for(int x=0; x<objeto.arr.size(); x++){
        //size: numero de elementos de array
        cout<<objeto.arr[x]<<" ";
    }
    cout<<endl;

    return 0;
}
