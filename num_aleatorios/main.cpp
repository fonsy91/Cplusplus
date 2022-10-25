#include <iostream>

using namespace std;

int main()
{

    int i,j=0;
    int MAX=10;
    int num=0;

    srand(time(NULL));

    for(i=1; i<4; i++){
        cout<<"Secuencia aleatoria: "<<endl;
        for(j=1; j<MAX; j++){
            num=rand()%5;
            cout<<num;
        }
        cout<<endl;
    }


    return 0;
}
