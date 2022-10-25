#include <stdio.h>
#include <stdlib.h>

struct contacto{
    char nombre[20];
    int telefono;
    char edad;
    contacto *siguiente;
};
typedef contacto *ptrcontacto;


int main(){








    return 0;
}
 /*
 FUNCIONES DE RESEVRA DE MEMORIA

 malloc: función que nos reserva la memoria que le pidamos y nos devuelve
 unpuntero apuntando a la primera direccion de las que haya reservado su
 prototipo es asi; void *malloc(int n_bytes);

//primero=(struct contacto *)malloc(sizeof(struct contacto));
//puntero=(int *)malloc(sizeof(int)*4); sizeof para decir cuanto espacio vamos a utilizar y convertimos
//el puntero devuelto a un puntero int



 */
