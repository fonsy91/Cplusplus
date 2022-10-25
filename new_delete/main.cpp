#include <iostream>

using namespace std;

/*
new: lo que hace es reservar memoria dinamica es decir memoria ram

*/

class Clase{
    public:
        Clase(int num){
            n=num;
        }
        int n;
};



int main(){
    //creamos un puntero de tipo entero y reservarle en la memoria ram
    //un entero que vale 6
    /*
    int *pNum=new int(6);
    char *c=new char[250];
    c[80]='f';
    cout<<pNum<<endl;
    cout<<c[80]<<endl;

    delete c; //librea la memoria que estaba usando c
    */
     //doble puntero y reservamos  memoria para 10
    //elementos y el doble puntero apunta a un vector de 10 elementos
    /*
    int **i=new int *[10];
    for(int n=0; n<10; n++){
        i[n]=new int[20];
    }
    delete[]i;
    */

    //ahora usamos todo esto pero con objetos

    //Clase alfa(5);
    Clase alfa=Clase(5);
    Clase *beta=new Clase(10);

    int Clase::*pNum;
    pNum=&Clase::n;

    cout<<alfa.*pNum<<endl;
    cout<<beta->*pNum;
    delete beta;
    Clase.



    return 0;
}
