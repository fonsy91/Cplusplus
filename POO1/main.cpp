#include <iostream>

using namespace std;

class clase1{
    public: //permite que otras funciones accedan
        void fun1(){
            cout<<"Este texto esta en clase1"<<endl;
        }
};

class persona{
    public:
        persona(int i){ //CONSTRUCTOR
            setName(i);
        }
        void setName(int x){
        edad=x;

        }
        int getName(){
            return edad;
        }


    private:
        int edad;

};

int main(){

    persona juan(20);
    cout<<juan.getName()<<endl;

    persona raul(25);
    cout<<raul.getName()<<endl;





    return 0;
}






