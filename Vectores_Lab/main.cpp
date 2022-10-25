#include <iostream>

using namespace std;

int main(){

char nombre[20];

cout<<"Escriba su nombre completo: ";
cin.getline(nombre,20);
cout<<endl<<"Su nombre es: "<<nombre;

int n=75;
cout<<n<<endl;
cout<<&n<<endl;


return 0;

}
