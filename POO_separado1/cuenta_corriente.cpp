#include "cuenta_corriente.h"

//funcion round() para redondear centimos
double round(double cantidad);

//constructor de la clase
//abrir cuenta con saldo e interes en %

cuenta_corriente::cuenta_corriente(double inicio, double int100){
    saldo=inicio;
    interes=int100/100.0;
}

//Depositar cantidad en cuenta
void cuenta_corriente::deposito(double cantidad){
    saldo=saldo+cantidad;
}
//funcion retirar cantidad
double cuenta_corriente::pago(double cantidad){
    //si hay saldo suficiente
    if(cantidad<=saldo){
        saldo=saldo-cantidad;
        return cantidad;
    } else{
        return 0.0;
    }
}
//funcion para calcular interes y sumarlo
void cuenta_corriente::abono_interes(){
    //calculo del interes
    double intereses=round(saldo*interes);
    //se incrementea el saldo
    saldo=saldo+intereses;
}
//preguntar saldo
double cuenta_corriente::obtener_saldo(){
    //devuelve el valor del saldo
    return saldo;
}
//funcion para realizar una transferencia
double cuenta_corriente::transfer(cuenta_corriente &destino, double cantidad){
    //Se accede directamente a la variable saldo del objeto
    //origen.Para acceder al saldo de destino se utiliza el operado punto
    if(saldo<cantidad)
        return 0.0;
    saldo=saldo-cantidad;
    destino.saldo+=cantidad;
    return cantidad;


}
//funcion para redondear los centimos
double round(double cantidad){
    long centimos=long(100.0*cantidad+0.5);
    return double(centimos)/100.0;
}







