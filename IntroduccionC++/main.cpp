#include <iostream>
#include <cmath>

void imprimirEdad(int);
double calcArea(double);

using namespace std;

int main()
{

    int x,y;
    x=2;


    cout<<"yo mido ";
    cout<<x;
    cout<<" metros";
    cout<<endl;

    cout<<"Ahora vamos a ver entrada de datos."<<endl;
    cout<<"Pon un numero: ";
    cin>>y;
    y=y+5;
    cout<<"Tu numero es: "<<y<<endl;
    cout<<" "<<endl;

    cout<<"1.FUNCIONES PREDEFINIDAS."<<endl;
    cout<<endl;

     /*
    Existen dos tipos de funciones: las que vienen
    predefinidas por el lenguaje y las que nosotros
    hacemos
    */

    //funcion predefinida
    double z;
    z=sqrt(69);
    cout<<"Esto es una funcion predefinida."<<endl;
    cout<<"La raiz cuadarada de z es: "<< z <<endl;
    cout<<endl;
    cout<<"CREANDO FUNCIONES."<<endl;
    cout<<endl;
    int edad;
    cout<<"Cual es tu edad: ";
    cin>>edad;
    imprimirEdad(edad);
    cout<<endl;

    cout<<"FUNCIONES CON RETORNO."<<endl;
    cout<<endl;
    double radio;
    cout<<"cual es el radio: ";
    cin>>radio;
    cout<<"El area del circulo es: "<<calcArea(radio);


    return 0;
}

//fin de funcion principal
//creamos nustra propia funcion:
//este tipo de funcion no devuelve nada

void imprimirEdad(int edad){
    using namespace std;
    cout<<"Tu edad es: "<<edad<<endl;
}


//fnucion con retorno

double calcArea(double radio){
    double pi=3.14, area;
    //area=pi*(radio*radio);
    area=pi* pow(radio,2);
    return area;
}





