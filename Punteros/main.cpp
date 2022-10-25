#include <iostream>

void pasoValor(int x);
void pasoRefe(int *x);

using namespace std;

int main(){

    /*
    PUNTEROS:
    Un puntero almacena la direccion de otro objeto
    el operador & devuleve la direccion de memoria de
    un objeto mientras que * devuelve el objeto apuntado
    por un puntero.
    Su sintaxis es: tipo *nombre_variable
    Ejemplos:

    char c='a';
    char *p=&c --- p aupuntaa la direccion de c

    char c2=*p; ---devuelve el caracter almacenado
    en esa direccion.

    -Declaracion de puntero:
    p y r: son punteros a entero
    q: es un puntero a double cin>>n;
    t: es un puntero a caracter
    */

    int alf=10;
    cout<<&alf<<endl; //muestra direccion de memoria

    int *alfPuntero;
    //Ahora queda inicializarlo
    alfPuntero=&alf;
    cout<<alfPuntero<<endl;

    //Pasar parametros por referencia.

    int tacos=10;
    int pizza=10;

    pasoValor(tacos);
    pasoRefe(&pizza);

    cout<<"Tacos es igual a: "<<tacos<<endl;
    cout<<"Pizza es igual a: "<<pizza<<endl;

    int alf1[5];
    int *mp0=&alf1[0];
    int *mp1=&alf1[1];
    int *mp2=&alf1[2];

    cout<<"El puntero mp1 esta en: "<<mp0<<endl;
    cout<<"El puntero mp2 esta en: "<<mp1<<endl;
    cout<<"El puntero mp3 esta en: "<<mp2<<endl;

    //agregamos dos unidades al puntero mp0

    mp0=mp0+2;
    cout<<"mp0 ahora esta en: "<<mp0<<endl;

    //Arreglo de Punteros

    int n1=10, n2=20, n3=30;
    /*
    Esta es una forma de hacerlo
    int *pnom[3];
    pnom[0]=&n1;
    pnom[1]=&n2;
    */
    int *pnom[3]={&n1,&n2,&n3};

    cout<<pnom[1]<<endl;
    cout<<&n2<<endl;

    *pnom[1]=200; //cambiamos el valor de n2 a 200
    cout<<n2;


    return 0;
}


void pasoValor(int x){//tacos==x
    /*
    En paso por valor a la funcion se le pasa una variable
    con un valor pero vale lo mismo no cambia de valor
    */
    x=97;
}

void pasoRefe(int *x){
    *x=50;
    //Aqui si cambiamos el valor original
}









