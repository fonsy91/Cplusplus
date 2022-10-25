#include <iostream>
#include "cuenta_corriente.h"
using namespace std;

int main(){
    //obtener los datos del usuario
    double saldo;

    //se leen las variables del programa
    //datos para el objeto mi_Cuenta esta es mi cuenta
    cout<<"Tecle los datos de mi cuenta: "<<endl;
    cout<<"Saldo inicial: ";
    cin>>saldo;
    //llamada al constructor se crea un objeto de la clase
    //cuenta_corriente se le pasa un interes mensual cualquiera
    cuenta_corriente mi_cuenta(saldo,1.0);

    //Datos para el objeto su_cuenta
    //Esta es otra cuenta ejmplo la de la peña
    cout<<"\nTeclee los datos de su cuenta: "<<endl;
    cout<<"Saldo inical: ";
    cin>>saldo;
    cuenta_corriente su_cuenta(saldo,1.0);

    //Transferencia
    int tr=1;
    double cantidad=0.0;
    while(tr==1){
        cout<<"\nTeclee los datos de la transferencia"
            <<"\n1. de mi_cuenta a su_cuenta"
            <<"\n2. de su_cuenta a mi_cuenta"<<endl;
            cin>>tr;
            cout<<"\nTeclee la cantidad: "<<flush;
            cin>>cantidad;
            cout<<"\nLos saldos antes de la transferencia son: "
                <<"\n En mi_cuenta: "<<mi_cuenta.obtener_saldo()
                <<"\n En su_cuenta: "<<su_cuenta.obtener_saldo()
                <<endl;
            if(tr==1){
                if(mi_cuenta.transfer(su_cuenta,cantidad)==0.0)
                    cout<<"\nSaldo insuficiente en mi_cuenta"
                        <<endl;
            }
            else if(tr==2){
                if(su_cuenta.transfer(mi_cuenta,cantidad)==0.0)
                    cout<<"\nSaldo insuficiente en su_cuenta"
                        <<endl;
            }
            else
                cout<<"\nTransferencia mal definida: "
                    <<"Teclee de nuevo."<<endl;

            cout<<"\nLos saldos tras la transferencia son:"
                <<"\n En mi_cuenta: "<<mi_cuenta.obtener_saldo()
                <<"\n En su_cuenta: "<<su_cuenta.obtener_saldo()
                <<endl;
            cout<<"\nDesea hacer una nueva transferencia? "
                <<"Teclee 1(Si) o 2(No)"<<endl;
                cin>>tr;
    }
    cout<<"Ya he terminado. "<<endl;

    return 0;
}
