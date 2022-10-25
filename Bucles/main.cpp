#include <iostream>
#include <conio.h>

using namespace std;

void media();
void bucleDo();
void tabla();

int main()
{
    cout<<"VAMOS A TRABAJAR CON BUCLES."<<endl;
    cout<<endl;
    //media();
    cout<<endl;
    //bucleDo();
    cout<<endl;
    tabla();


    return 0;
}
//FIN PROGRAMA PRNCIPAL


void media(){
    int cuantos;

    cout<<"¿Cuantos datos va a introducir: ";
    cin>> cuantos;

    if(cuantos<=0){
        cout<<"La cantidad es incorrecta\n";
    }
    else{

        int llevo=0;
        double suma,dato,media=0;
        while(llevo<cuantos){
            llevo++;
            cout<<"Introduzca un dato: "<< llevo <<" / "<< cuantos <<" : ";
            cin>>dato;
            suma=suma+dato;
        };
        media=suma/cuantos;
        cout<<"La media de los "<< cuantos <<" datos es "<< media <<".\n";

    };


}


void bucleDo(){

    int i=0;

    do{
        cout<<" "<< i;
        i++;

    }while(i<=20);
}

/*
Escribir un programa que escriba en pantalla la tabla de
multiplicar de un entero entre 1 y 10 leído de teclado
*/

void tabla(){

    int n,res;

    cout<<"Que tabla desea hacer: ";
    cin>>n;

    if((n>10)||(n<1)){
        cout<<"La tabla elegida no es valida...";
    }else{

        for(int i=1;i<=10;i++){
            res=n*i;
            cout<< n <<" x "<< i <<" = "<< res <<endl;

        }
    }
}









