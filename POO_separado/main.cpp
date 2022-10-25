#include <iostream>
#include <conio.h>
#include "CCirculo.h"

using namespace std;

int main(int argc, char* argv[]){

    float dat;
    CCirculo cir1, cir2, cir3(10);

    cout<<"Radio del circulo: ";
    cin>>dat;
    cir1.radio(dat);
    cout<<endl<<"Diametro del circulo 2: ";
    cin>>dat;
    cir2.diametro(dat);

    cout<<endl<<"Circulo 1, Area= "<<cir1.area()<<" perimetro = "<<cir1.perimetro()<<endl;
    cout<<endl<<"Circulo 2, Area= "<<cir2.area()<<" perimetro = "<<cir2.perimetro()<<endl;
    cout<<endl<<"Circulo 3, Area= "<<cir3.area()<<" perimetro = "<<cir3.perimetro()<<endl;

    return 0;
}
