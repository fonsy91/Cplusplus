/*
 * Nodos.cpp
 *
 *  Created on: Dec 10, 2016
 *  Authores: Angel Herencia y Alfonso Muñoz
 */

#include "Practica2.h"

/*Definiciones de un nodo Cliente*/

NodoCli::NodoCli(Cliente *cliente){
	this->cliente = cliente;
	derecho = NULL;
	izquierdo = NULL;
}

Cliente* NodoCli::getCliente(){
	return cliente;
}




/*Definicion de un nodo Reparacion*/

NodoRep::NodoRep(){
	sigRep = NULL;
	rep = NULL;

}

NodoRep::NodoRep(Reparacion* p_reparacion){
	rep = p_reparacion;
	sigRep = NULL;

}

NodoRep::NodoRep(NodoRep *nodo){//Constructor copia
	rep = new Reparacion();
	rep->coste = nodo->getRep()->coste;
	rep->fecha = nodo->getRep()->fecha;
	rep->idRep = nodo->getRep()->idRep;
	rep->tipo_rep = nodo->getRep()->tipo_rep;
	if(nodo->getSigRep()){
		sigRep = new NodoRep(nodo->getSigRep());
	}else{
		sigRep = NULL;
	}
}

NodoRep::~NodoRep(){/*nothing to destruct*/}

Reparacion* NodoRep::getRep(){
	return rep;
}

void NodoRep::setRep(Reparacion *p_rep){
	rep = p_rep;
}

NodoRep* NodoRep::getSigRep(){
	return sigRep;
}

void NodoRep::setSigRep(NodoRep* p_sigRep){
	sigRep = p_sigRep;
}


