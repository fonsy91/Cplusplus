/*
 * ArbolCLientes.cpp
 *
 *  Created on: Dec 10, 2016
 *  Authores: Angel Herencia y Alfonso
 */

#include <iostream>
#include <string>

#include "Practica2.h"





//Definicones de la clase ArbolClientes
ArbolClientes::ArbolClientes(){
	raiz = NULL;
	actual = NULL;
	contador = 0;
	altura = 0;
	nextId = 1;
}
// Poda: borrar todos los nodos a partir de uno, incluido
void ArbolClientes::Podar(NodoCli* &nodo)
{
	// Algoritmo recursivo, recorrido en postorden
	if(nodo) {
		Podar(nodo->izquierdo); // Podar izquierdo
		Podar(nodo->derecho);   // Podar derecho
		delete nodo;            // Eliminar nodo
		nodo = NULL;
	}
}

// Insertar un int en el �rbol ABB
void ArbolClientes::Insertar(Cliente *cliente)
{
	NodoCli *padre = NULL;
	nextId++;//Como solo uno de los returns implica no aumentar el contador, lo que hago es aumentarlo y en caso de no insertar lo disminuyo
	actual = raiz;
	// Buscar el int en el �rbol, manteniendo un puntero al nodo padre
	while(!Vacio(actual) && cliente->dni != actual->cliente->dni) {
		padre = actual;
		if(cliente->dni > actual->cliente->dni) actual = actual->derecho;
		else if(cliente->dni < actual->cliente->dni) actual = actual->izquierdo;
	}

	// Si se ha encontrado el elemento, regresar sin insertar
	if(!Vacio(actual)){
		nextId--;
		return;
	}
	// Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
	// el nodo raiz
	if(Vacio(padre)) raiz = new NodoCli(cliente);
	// Si el int es menor que el que contiene el nodo padre, lo insertamos
	// en la rama izquierda
	else if(cliente->dni < padre->cliente->dni) padre->izquierdo = new NodoCli(cliente);
	// Si el int es mayor que el que contiene el nodo padre, lo insertamos
	// en la rama derecha
	else if(cliente->dni > padre->cliente->dni) padre->derecho = new NodoCli(cliente);
}

// Eliminar un elemento de un �rbol ABB
void ArbolClientes::Borrar(const int dni)
{
	NodoCli *padre = NULL;
	NodoCli *nodo;
	Cliente *aux;

	actual = raiz;
	// Mientras sea posible que el valor est� en el �rbol
	while(!Vacio(actual)) {
		if(dni == actual->cliente->dni) { // Si el valor esta en el nodo actual
			if(EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos
				if(padre){ // Si tiene padre (no es el nodo raiz)
					// Anulamos el puntero que le hace referencia
					if(padre->derecho == actual) padre->derecho = NULL;
					else if(padre->izquierdo == actual) padre->izquierdo = NULL;}
				delete actual; // Borrar el nodo
				actual = NULL;
				return;
			}
			else { // Si el valor est� en el nodo actual, pero no es hoja
				// Buscar nodo
				padre = actual;
				// Buscar nodo m�s izquierdo de rama derecha
				if(actual->derecho) {
					nodo = actual->derecho;
					while(nodo->izquierdo) {
						padre = nodo;
						nodo = nodo->izquierdo;
					}
				}
				// O buscar nodo m�s derecho de rama izquierda
				else {
					nodo = actual->izquierdo;
					while(nodo->derecho) {
						padre = nodo;
						nodo = nodo->derecho;
					}
				}
				// Intercambiar valores de no a borrar u nodo encontrado
				// y continuar, cerrando el bucle. El nodo encontrado no tiene
				// por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
				// de que s�lo se eliminan nodos hoja.
				aux = actual->cliente;
				actual->cliente = nodo->cliente;
				nodo->cliente = aux;
				actual = nodo;
			}
		}
		else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
			padre = actual;
			if(dni > actual->cliente->dni) actual = actual->derecho;
			else if(dni < actual->cliente->dni) actual = actual->izquierdo;
		}
	}
}

// Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolClientes::InOrden(void (*func)(Cliente*, bool) , NodoCli *nodo, bool r)
{
	if(r) nodo = raiz;
	if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
	func(nodo->cliente, true);
	if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolClientes::PreOrden(void (*func)(Cliente*, bool), NodoCli *nodo, bool r)
{
	if(r) nodo = raiz;
	func(nodo->cliente, true);
	if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
	if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
// el prototipo:
// void func(int&);
void ArbolClientes::PostOrden(void (*func)(Cliente*, bool), NodoCli *nodo, bool r)
{
	if(r) nodo = raiz;
	if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
	if(nodo->derecho) PostOrden(func, nodo->derecho, false);
	func(nodo->cliente, true);
}

// Buscar un valor en el �rbol
bool ArbolClientes::Buscar(const int dni)
{
	actual = raiz;

	// Todav�a puede aparecer, ya que quedan nodos por mirar
	while(!Vacio(actual)) {
		if(dni == actual->cliente->dni) return true; // int encontrado
		else if(dni > actual->cliente->dni) actual = actual->derecho; // Seguir
		else if(dni < actual->cliente->dni) actual = actual->izquierdo;
	}
	return false; // No est� en �rbol
}

NodoCli* ArbolClientes::getCli(const int dni){
	actual = raiz;

	// Todav�a puede aparecer, ya que quedan nodos por mirar
	while(!Vacio(actual)) {
		if(dni == actual->cliente->dni) return actual; // int encontrado
		else if(dni > actual->cliente->dni) actual = actual->derecho; // Seguir
		else if(dni < actual->cliente->dni) actual = actual->izquierdo;
	}
	return NULL; // No está en árbol
}

// Calcular la altura del nodo que contiene el int dat
int ArbolClientes::Altura(const int dni)
{
	int altura = 0;
	actual = raiz;

	// Todav�a puede aparecer, ya que quedan nodos por mirar
	while(!Vacio(actual)) {
		if(dni == actual->cliente->dni) return altura; // int encontrado
		else {
			altura++; // Incrementamos la altura, seguimos buscando
			if(dni > actual->cliente->dni) actual = actual->derecho;
			else if(dni < actual->cliente->dni) actual = actual->izquierdo;
		}
	}
	return -1; // No est� en �rbol
}

// Contar el n�mero de nodos
const int ArbolClientes::NumeroNodos()
{
	contador = 0;

	auxContador(raiz); // FUnci�n auxiliar
	return contador;
}

// Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolClientes::auxContador(NodoCli *nodo)
{
	contador++;  // Otro nodo
	// Continuar recorrido
	if(nodo->izquierdo) auxContador(nodo->izquierdo);
	if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del �rbol, que es la altura del nodo de mayor altura.
const int ArbolClientes::AlturaArbol()
{
	altura = 0;

	auxAltura(raiz, 0); // Funci�n auxiliar
	return altura;
}

// Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
// postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
// altura de la m�xima actual
void ArbolClientes::auxAltura(NodoCli *nodo, int a)
{
	// Recorrido postorden
	if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
	if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
	// Proceso, si es un nodo hoja, y su altura es mayor que la actual del
	// árbol, actualizamos la altura actual del árbol
	if(EsHoja(nodo) && a > altura) altura = a;
}

int ArbolClientes::getNextId(){
	return nextId;
}

// Función de prueba para recorridos del Árbol -->podría o deberia ir en Paractica2 cpp, pero ahi se queda, que tiene relación con el árbol
void Mostrar(Cliente *d, bool mostrarReps)
{
	cout << "Número de historial: "<<d->numHistorial <<endl;
	cout << "Nombre y apellidos: "<<d->nomApe<<endl;
	cout << "DNI: "<< d->dni <<endl;
	if(mostrarReps){
	cout << endl<<"Historial de reparaciones:"<<endl;
		d->historial->listarRep();
	}
	cout << endl<<endl;
}


