#ifndef CUENTA_CORRIENTE_H
#define CUENTA_CORRIENTE_H


class cuenta_corriente
{
    public:
        cuenta_corriente(double inicio, double int100);
        void deposito(double cantidad);
        double pago(double cantidad); //hacer un pago
        void abono_interes(); //obtener interes
        double obtener_saldo(); //preguntar el saldo
        //transferencia de objeto a objeto "destino"
        double transfer(cuenta_corriente& destino, double cantidad);
    private:
        double saldo; //saldo actual de la cuenta
        double interes; //interes en tanto por 1
};

#endif // CUENTA_CORRIENTE_H
