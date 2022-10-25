#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

void vectores(int vec2[], int tamVec);

using namespace std;

int main(){

    //declaracion he inicializacion de arreglos/vectores/array
    int arreglo[5]={15,57,69,5,80};
    cout<<arreglo[2]<<endl;

    //otro tipo de inicializacion
    int arreglo1[10];
    cout<<"Elem ----- Valor"<<endl;

    for(int i=0; i<=9; i++){
            arreglo1[i]=654;
            cout<<"   "<<i<<" ----- "<<arreglo1[i]<<endl;
    }

    //creando numeros aleatorios
    //El numero 6 divide cualquier numero entre 6 y
    //y devuelve el resto de la division

    srand(time(0)); //funcion que permite hacer numeros aleatorios
    for(int i=0; i<5;i++){
            cout<<1+(rand()%6) <<endl;
    }

    //Programando con arreglos.

    int vec[5];

    cout<<"Introduce los numeros para saber cual es mayor de 5: "<<endl;

    for(int i=0; i<5; i++){
        cin>>vec[i];
    }

    cout<<"Numeros mayor o igual que 5"<<endl;

    for(int i=0; i<5; i++){
        if(vec[i]>=5){
            cout<<vec[i]<<endl;
        }
    }

    //Pasando arreglos/vectores a funciones:

    cout<<"Los arreglos pasados son: "<<endl;

    int martin[5]={1,2,3,4,5};
    int lily[10]={21,2,33,4,6,7,8,1,9,8};

    vectores(martin,5);
    vectores(lily,10);

    //Arreglos/vectores tipo char
    //Hay que poner siempre un elemento mas este \0.

    char nombre[8]={'A','L','F','O','N','S','O','\0'};
    cout<<nombre<<endl;

    //Otra forma es asi;
    //strlne nos devuelve el numero de elementos
    //hay que añadir una biblioteca cstring

    char cadena[]={"Munoz Casado"};
    cout<<cadena<<endl;
    cout<<"El numero de elementos de cadena es: "<<strlen(cadena)<<endl;

    cout<<"Ejemplo de programa usando arreglos."<<endl;
    char usuario[20];
    cout<<"Ponga su nombre aqui: ";
    cin.getline(usuario, 500, 'n');
    //el usuario no puede poner mas de 128 bytes(buffer)
    cout<<"Hey!!! "<< usuario <<" Bienvenido.";

    //Faltan hacer arreglos multidimensionales (matrices).



    return 0;
}

//Funcion vectores.
void vectores(int vec2[], int tamVec){
    for(int i=0; i<tamVec; i++){
        cout<< vec2[i]<<endl;
    }
    cout<<endl;
}






