#include "CCirculo.h"
#define Pi 3.14159265

//fichero con el desarrolo de las funciones....

//Constructor por defecto
CCirculo::CCirculo(){
    rad=new float;
    *rad=0;
}
//Constructor sobrecargado
CCirculo::CCirculo(float r){
    rad=new float;
    *rad=r;
}
//Destructor
CCirculo::~CCirculo(){
    delete rad;
}
//Establecer el radio del circulo
CCirculo::radio(float r){
    *rad=r;
}
//Establecer el diametro del circulo
CCirculo::diametro(float d){
    *rad=d/2;
}
//calcula el area del circulo
float CCirculo::area(){
    return Pi*(*rad)*(*rad);
}
//calcula el perimetro del circulo
float CCirculo::perimetro(){
    return 2*Pi*(*rad);
}











