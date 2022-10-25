#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

void contrasena(int);
double media();
void primo();

const int minimo=0,maximo=10;

using namespace std;

int main(){

    //programa que determina si una contraseña es correcta

    int contra;
    cout<<"Ingrese una contraseña: ";
    cin>>contra;
    contrasena(contra);
    cout<<endl;
    media();
    cout<<endl;
    primo();



    return 0;
}

void contrasena(int contra){
    if(contra==1234){
        cout<<"contraseña conrrecta";
    }else{
        cout<<"contraseña incorrecta";
    }
}

double media(){
    using namespace std;
    float x,y,z,media;
    cout<<endl;
    cout<<"MEDIA DE NOTAS."<<endl;
    cout<<"Introduce la 1 nota: ";
    cin>>x;
    cout<<"Introduce la 2 nota: ";
    cin>>y;
    cout<<"Introduce la 3 nota: ";
    cin>>z;
    media=(x+y+x)/3;
    cout<<"La media de tus notas es: " << media;
}

void primo(){
    int n;
    cout<<"Introduzca un numero entre " <<minimo<<" y "<<maximo<<"."<<endl;
    cin>>n;

    if((n<minimo) || (n>maximo)){
        cout<<"El valor "<< n <<" esta fuera de rango."<<endl;
    }
    else{
        switch(n){
            case 0: cout<<"No existe definicion de primo en este caso"<<endl;
                break;
            case 2: case 3: case 5: case 7: cout<<"Es primo"<<endl; break;
            default: cout<<"No es primo"<<endl;
        };
    }
}


