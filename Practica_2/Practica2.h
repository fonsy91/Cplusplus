/*
 * declaracioes.h
 *
 *  Created on: Dec 9, 2016
 *      Authores: Angel Herencia y Alfonso Muñoz
 */

#ifndef PRACTICA2_H_
#define PRACTICA2_H_

#include <ctime>
#include <string>


/*                  **********************************                           */

//El orden de las declaraciones ha de ser como está, bueno, se puede cambiar, pero siempre teniendo en cuenta
//que cualquier declaración que se haga y use un tipo de datos, este ha de estar declarado previamente
//aquí hemos tenido suerte, podría darse el caso de que un tipo use otro tipo y ese otro tipo use a su vez
//al primer tipo, ahí estaríamos jodidos de nuevo con los includes. Hay soluciones pero no las acabo de entender.

/***************************************************************************************************************/

using namespace std;


//Variables gloales
const int ORDEN_FECHA = 1;
const int ORDEN_COSTE = 2;
const int ORDEN_FECHA_COSTE = 3; //En caso de igual fecha ordena por coste
const int ORDEN_COSTE_FECHA = 4; //En caso de igual coste ordena por fecha
const int ORDEN_TIPO = 5;

const int SEG_ANIO = 31536000;
const int SEG_MES = 2592000;
const int SEG_DIA = 86400;
enum tipoRep{Nula=0 , Revision=1, CambioAceite=2, CambioFiltros=3, Carga_Aire=4, CambioRuedas=5, Bateria=6, Distribucion=7, JuntaCulata=8, Embrague=9, Otros=10 };
//Sin el static no funciona, hace esta variable global a todos los .cpp que hagan include de declaraciones.h  -->supongo que con un char[][] no daria problemas, pero te obliga a definir el tamaño del array
static const char *tipoRepStr[] = {"Nula","Revisión", "Cambio de aceite", "Cambio de filtros", "Carga de Aire Acondicionado", "Cambio de Ruedas",
			"Cambio de batería", "Correa de distribución", "Junta de culata", "Cambio de embrague", "Otros"};

const int precioRep[] = {0, 50, 30, 80, 30, 200, 100, 400, 600, 900};




/***********************************************************************************/
//Estructuras

//Esta estructura me sirve para ser devuelta a la llamada de un método que recibe un string, lo trocea en un array de strings y lo guarda en esta estructura junto con el número de elementos del array
struct parsedIntList{
	string *listadoStr;
	int *listadoInt;
	int listadoSize;
}typedef parIntList;



struct Reparacion {
	time_t fecha;
	tipoRep tipo_rep;
	int coste;
	int idRep;//ya que hemos creado una función que elimina por posición, esta variable podrá ser útil.
}typedef Reparacion;

//Falta una pero la declaro más adelante, el orden importa
/***********************************************************************************/




//Clase que define la estructura de un Nodo Reparación
/**********************************************************/

class NodoRep{
private:
	Reparacion* rep;
	NodoRep *sigRep;
	friend class H_Rep;
public:
	NodoRep();
	NodoRep(Reparacion* p_reparacion);
	NodoRep(NodoRep *nodo);//Constructor copia  --> es decir que duplica el nodo, con otra dirección de memoria, pero con los mismos valores
	~NodoRep();
	Reparacion* getRep();
	void setRep(Reparacion *rep);//Nos será útil después para ordenar, entre otras cosas
	NodoRep* getSigRep();
	void setSigRep(NodoRep* p_sigRep);
};
/**********************************************************/


//Clase que define la estructura del historial de reparaciones de un cliente dado
/**********************************************************/
class HRep{

public:
    HRep();
	~HRep();
	void insertar(bool isRandom);
	void eliminar();
	NodoRep *getPrimero();
	int getNumRep();
	void listarRep();
	void interfaceBuscar();
	void interfaceOrdenar();
private:
	int nextId;
	NodoRep *primero;
	bool esVacio();
	void insertar(Reparacion* p_rep);
	NodoRep* eliminar(int numRep);
	void ordenar(int tipo_Ordenamiento);
	void auxOrd(NodoRep *p_aux, NodoRep *p_sig, int mode);
	void intercambia(Reparacion* temp, NodoRep* p_aux, NodoRep* p_sig);
	bool interfaceElimPos();
	bool interfaceElimId(string param, bool info);
	bool interfaceElimFecha();
	bool interfaceElimTipo();
	bool interfaceElimCoste();
	bool eliminarPorCosteAux2(HRep *copiaH,int refCoste, bool menores, bool info, bool oIguales);
	bool eliminarPorCosteAux3(HRep* copiaH, bool menores);
	bool eliminarporCosteAux4(int uno, int dos, bool dev, HRep* copiaH);
	bool eliminarPorFecha(bool dev, parsedIntList* parseado, bool menores, bool informe, bool oIguales);
	void setPrimero(NodoRep *param);
	void imprimeRep(int cont, Reparacion* rep);

}typedef HRep;

/**********************************************************************************/



/** LA ESTRUCTURA QUE FALTABA, YA SE PUEDE DECLARAR PORQUE HREP ACABA DE SER DECLARADA **/
//Esta estructura define los datos de un cliente dato
struct Cliente{

	int numHistorial;
	string nomApe;
	int dni;
	HRep *y;

}typedef Cliente;

/******************************************************************************************/




//Clase que define la estructura de un Nodo cliente
/**********************************************************/

class NodoCli {
private:
	Cliente *cliente;
	NodoCli *izquierdo;
	NodoCli *derecho;
	friend class ArbolClientes;
public:
	//NodoCli();
	NodoCli(Cliente *cliente);
	~NodoCli(){};
	Cliente* getCliente();
};
/*************************************************************/




//Clase que define la estructura del historial de clientes
/**********************************************************/
class ArbolClientes {
private:

	NodoCli *raiz;
	NodoCli *actual;
	int contador;
	int altura;
	int nextId;

public:
	// Constructor y destructor b�sicos:
	ArbolClientes();
	~ArbolClientes() { Podar(raiz); }
	// Insertar en �rbol ordenado:
	void Insertar(Cliente *cliente);
	// Borrar un elemento del �rbol:
	void Borrar(const int dni);
	// Funci�n de b�squeda:
	bool Buscar(const int dni);
	//Función que busca un nodo por el valor del campo dni de su estructura Cliente y lo devuelve
	NodoCli* getCli(const int dni);
	// Comprobar si el Arbol esta vacio:
	bool Vacio(NodoCli *r) { return r==NULL; }
	// Comprobar si es un nodo hoja:
	bool EsHoja(NodoCli *r) { return !r->derecho && !r->izquierdo; }
	// Contar n�mero de nodos:
	const int NumeroNodos();
	const int AlturaArbol();
	// Calcular altura de un int:
	int Altura(const int dni);
	// Devolver referencia al int del nodo actual:
	int &ValorActual() { return actual->cliente->dni; }
	// Moverse al nodo raiz:
	void Raiz() { actual = raiz; }
	// Aplicar una funci�n a cada elemento del �rbol:
	void InOrden(void (*func)(Cliente*, bool) , NodoCli *nodo=NULL, bool r=true);
	void PreOrden(void (*func)(Cliente*, bool) , NodoCli *nodo=NULL, bool r=true);
	void PostOrden(void (*func)(Cliente*, bool) , NodoCli *nodo=NULL, bool r=true);
	int getNextId();

private:
	// Funciones auxiliares
	void Podar(NodoCli* &);
	void auxContador(NodoCli*);
	void auxAltura(NodoCli*, int);
};
void Mostrar(Cliente *d, bool mostrarReps);
/****************************************************************************/





/*Declaraciones de funciones auxiliares*/

ArbolClientes* init();//Inicia el historial de clientes con un número de clientes mayor que 7 con datos aleatorios
int getRandomNumber(int min, int max);

//Esta función modifica  de una forma aleatoria el contenido de la estructura, usada para inicializar las reparaciones de forma aleatoria.
Reparacion* randomizaRep();
string getFechaStr(Reparacion *rep);//Parsea el timestamp del capmpo fecha de la reparación a un formato legible
Cliente* randomiceCli(int nextId);
int auxParseInt(string str, bool teclado);
bool isInteger(const string & s);
time_t parseDateToTimeStamp(parsedIntList* parseado);
void auxTecladoIn(string *teclado, string comodin);
parsedIntList* parseIntegerList(string *intList, string delimiter, bool rawParse);
bool compruebaFecha(parsedIntList *param);

#endif /* PRACTICA2_H_ */
