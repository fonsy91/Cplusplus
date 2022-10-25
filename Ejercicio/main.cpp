/*
La idea va a ser la siguiente: Crearemos un programa que pueda almacenar datos de
hasta 1000 ficheros (archivos de ordenador). Para cada fichero, debe guardar
los siguientes datos: Nombre del fichero (max 40 letras), Tama�o (en KB, n�mero de 0 a 2.000.000.000).
El programa mostrar� un men� que permita al usuario las siguientes operaciones:

1- A�adir datos de un nuevo fichero
2- Mostrar los nombres de todos los ficheros almacenados
3- Mostrar ficheros que sean de m�s de un cierto tama�o (por ejemplo, 2000 KB).
4- Ver todos los datos de un cierto fichero (a partir de su nombre)
5- Salir de la aplicaci�n (como todav�a no sabemos almacenar los datos, �stos se perder�n).
*/

#include <iostream>
#include <string>

using namespace std;

struct tipoDatos
{
    string nombreFich;        // Nombre del fichero
    long tamanyo;            // El tama�o en bytes
};

int numeroFichas=0;  // N�mero de fichas que ya tenemos
int i;               // Para bucles
int opcion;          // La opcion del menu que elija el usuario

string textoTemporal; // Para pedir datos al usuario
int numeroTemporal;

int main(){

    tipoDatos *fichas = new tipoDatos[50];

    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opci�n:" << endl;
        cout << "1.- A�adir datos de un nuevo fichero" << endl;
        cout << "2.- Mostrar los nombres de todos los ficheros" << endl;
        cout << "3.- Mostrar ficheros que sean de mas de un cierto tama�o" << endl;
        cout << "4.- Ver datos de un fichero" << endl;
        cout << "5.- Salir" << endl;

        cin >> opcion;

        // Hacemos una cosa u otra seg�n la opci�n escogida
        switch(opcion)
        {
            case 1: // A�adir un dato nuevo
                if (numeroFichas < 1000)   // Si queda hueco
                {
                    cout << "Introduce el nombre del fichero: ";
                    cin >> fichas[numeroFichas].nombreFich;
                    cout << "Introduce el tama�o en KB: ";
                    cin >> fichas[numeroFichas].tamanyo;
                    numeroFichas++;  // Y tenemos una ficha m�s
                }
                else   // Si no hay hueco para m�s fichas, avisamos
                    cout << "M�ximo de fichas alcanzado (1000)!" << endl;
                break;

            case 2: // Mostrar todos
                for (i=0; i<numeroFichas; i++)
                    cout << "Nombre: " << fichas[i].nombreFich
                        << "; Tama�o: " << fichas[i].tamanyo
                        << "Kb" << endl;
                break;

            case 3: // Mostrar seg�n el tama�o
                cout << "�A partir de que tama�o quieres que te muestre? ";
                cin >> numeroTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].tamanyo >= numeroTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tama�o: " << fichas[i].tamanyo
                            << " Kb" << endl;
                break;

            case 4: // Ver todos los datos (pocos) de un fichero
                cout << "�De qu� fichero quieres ver todos los datos?";
                cin >> textoTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].nombreFich == textoTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tama�o: " << fichas[i].tamanyo
                            << " Kb" << endl;
                break;

            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;

            default: // Otra opcion: no v�lida
                cout << "Opci�n desconocida!" << endl;
                break;
        }
    } while (opcion != 5);  // Si la opcion es 5, terminamos

    return 0;
}
