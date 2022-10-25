#include <iostream>

using namespace std;

/*
Punteros definicion: un puntero es un dato que contiene una direccion de memoria,existe una
direccion especial representada por NULL que significa que no apunta a ninguna direccion su
sintaxis es: <tipo> *<identificador>, &<id>: devuelve la direccion de memoria donde comienza
la variable id

z=*pt1;:cuando a una variale le asignamos un puntero con el asterisco estamos asignandole a la
variable el valor donde apunta el puntero

*/

int main(){

    int y=5;//reserva un espacion de memoria para la variable
    int z=3;
    int *pt1; //reserva espacion para una variable de tipo puntero
    int *pt2;

    pt1=&y; //el puntero pt1 apunta a la direccion de (y) y guarda en su espacio de memoria la direccion de (y)
    cout<<pt1<<endl; //variable puntero que es igual a la direccion de y por la asignacion
    cout<<&pt1<<endl; //direccion del propio puntero
    cout<<&y<<endl; //direccion de y

    z=*pt1; //z es igual a lo que contiene la variable donde apunta el punero pt1
    cout<<z<<endl;

    *pt1=7; // asignamos un valor de 7 donde apunta el puntero

    pt2=pt1; // estamos diciendo que el puntero pt2 apunte a la misma direccion de memoria que pt1

    pt2=&z; //estamos diciendo que el pt2 apunte a la direccion de z

    *pt2=*pt1; //que en la direccion de pt2 asigne lo que contenga pt1

    y=(*pt1)+1; // a la variable y le suma 1

    //PUNTERO A PUNTEROS******************************************************
    //Un puntero a puntero es un puntero que contiene la direccion de memoria de otro puntero
    int a=5;
    int *p; //puntero a un entero
    int **q; //puntero que apunta a otro puntero
    p=&a; //puntero p que apunta a entero (a)
    q=&p; //puntero q apunta a puntero p
    //para acceder al valor de a podemos hacerlo de tres formas:
    //1º: a forma habitual
    //2º: *p a traves del puntero p
    //3º: **q a traves del puntero q
    //q contiene la direccion de p que contiene la direccion de a

    //VECTORES Y PUNTEROS*********************************************************
    //sintaxis: <tipo><identificador>[<dimension>]
    //estamos resevando memoria par almacenar dimension de elementos de <tipo>
    int v[3];
    int *pt;
    pt=&v[0]; //tambien se puede poner asi: p=v;
    *v=6; //estoy asignando un valor de 6 a la posicion 0
    *pt=6; //estoy asignando un valor de 6 a la posicion 0
    cout<<*v<<endl;
    cout<<*pt<<endl;

    //RESERVA Y LIBERACION DE MEMORIA********************************************
    /*
    La memoria se organiza as:
    -Segmento de codigo: donde se almacena el codigo del programa
    -Memoria estatica: donde se almacenan las variables globales y estaticas
    -Pilas: se almacenan variables automaticas es decir las locales
    -Heap: las variables dinamicas
    Cuando se quiere utilizar el heap primero hay que reservar la memoria que se
    desea ocupar en c++ se usa el operador New y para liberar el espacio reservado se
    usa el operador delete. Si no liberarmos memoria ese espacio nunca lo podremos
    volver a utilizar
    */







    return 0;
}













