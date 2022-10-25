#ifndef CCIRCULO_H
#define CCIRCULO_H

//Fichero de cabecera donde se declaran los prototipos de las clases
//,funciones,constructor y destructor

class CCirculo
{
    public: //Variables y funciones de la clase de ambito publico
        CCirculo();                     //constructor por defecto
        CCirculo(float);                //constructor sobrecargado
        virtual ~CCirculo();            //Destructor

        radio(float r); //funcion del radio del circulo
        diametro(float d); //funcion del diametro del circulo
        float area();   //calculo del area del circulo
        float perimetro();  //calculo del perimetro del circulo

    private:
        float *rad;
};

#endif // CCIRCULO_H
