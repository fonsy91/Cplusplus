#include <iostream>

using namespace std;

int main(){
     /*
    int x,y,*p,*q;

    p=&x; //el puntero p apunta a x
    cout<<&p<<" "<<&x<<endl;
    cout<<p<<" "<<x<<endl;

    *p=5; //muestra lo que contiene donde apunta
    cout<<p<<" "<<x<<endl;

    q=&y;
    *q=23;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<" "<<*q<<endl;

    q=p;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<" "<<*q<<endl;//*q pasa ha valer 5

    *p=35;
    cout<<*p<<" "<<*q<<endl;
    cout<<x<<" "<<y<<endl;
    */
    /*
    int *p, *q, x;

    p=&x;
    *p=14;
    q=p;

    cout<<*p<<" "<<*q<<endl;
    cout<<p<<" "<<q<<endl;
    q=NULL;
    cout<<p<<" "<<q<<endl;
    */
    /*
    int x,y,*p,*q;
    p=&x;
    *p=12;
    q=&y;
    *q=23;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<" "<<*q<<endl;
     *p=*q;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<" "<<*q<<endl;
    q=NULL;
    cout<<q<<endl;
    cout<<*p<<endl;
    cout<<&x<<" "<<&y<<endl;
    cout<<x<<" "<<y<<endl;
    */
    int x,y,*p,*q;
    p=&x;
    *p=14;
    q=p;

    if(p==q) cout<<"Mensaje1 1";

    q=&y;

    if(p==q) cout<<"Mensaje 2";
    *q=14;
    if(p=q) cout<<"Mensaje 3";
    if(*p=*q) cout<<"Mensaje 4";







    return 0;
}
