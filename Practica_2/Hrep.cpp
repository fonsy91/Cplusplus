/*
 * Hrep.cpp
 *
 *  Created on: Dec 10, 2016
 *  Authores: Angel Herencia y Alfonso
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

#include "Practica2.h"



/*Definicion del historial de reparaciones*/

//<<constructor>>
HRep::HRep(){
	primero = NULL;
	nextId = 1;
}
//<<destructor>>
HRep::~HRep(){
	while(primero){
		free(eliminar(1));
	}
}


void HRep::insertar(bool isRandom){
	Reparacion *rep = new Reparacion();
	if(isRandom){
		rep = randomizaRep();
	}
	else{
		string teclado;
		bool seguir = true;
		int result = 0;
		//Vamos a pedir los datos de entrada al usuario por teclado
		//Lo primero el tipo de reparación
		do{
			cout<<"Introduzca el tipo de reparación realizada:"<<endl;
			cout<<"\t1- Revisión\n\t2- Cambio de aceite\n\t3- Cambio de filtros\n\t4- Carga de Aire Acondicionado\n\t5- Cambio de Ruedas"<<endl;
			cout<<"\t6- Cambio de batería\n\t7- Correa de distribución\n\t8- Junta de culata\n\t9- Cambio de embrague\n\t10- Otros\n\t11- Cancelar"<<endl;
			cin.clear();
			//cin>>teclado;
			getline(cin, teclado);
			result = atoi(teclado.c_str());
			switch(result){
			case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:
				seguir = false;
				break;
			case 11:
				return;
			default:
				cout<<"\t*** Opción no válida***"<<endl<<endl;
			}
		}while(seguir);
		rep->tipo_rep =  static_cast<tipoRep>(result);


		//Lo siguiente es el precio, que para todas las reparaciones es estandar, espepto para el tipo otros, en cuyo caso el usuario ha de meter el coste por teclado
		seguir = true;
		if(rep->tipo_rep == Otros){
			do{
				cout<<"Introduzca el coste de la reparación o pulse -1 para cancelar"<<endl;
				cin.clear();
				//cin>>teclado;
				getline(cin, teclado);
				int temp = atoi(teclado.c_str());
				if(temp < 0){
					return;
				}else if(temp > 0){
					seguir = false;
					result = temp;
				}
				else{
					cout<<"\tNo ha introducido una cifra correcta"<<endl<<endl;
				}
			}while(seguir);
			rep->coste = result;
		}
		else{
			rep->coste = precioRep[rep->tipo_rep];
		}

		//Por último la fecha, que se mete la actual del sistema.
		rep->fecha = time(0);
		//cout<<rep->coste<<endl;
	}

	insertar(rep);
}

void HRep::eliminar(){
	if(esVacio()){
		cout<<"El historial de reparaciones está vacío."<<endl;
		return;
	}
	bool seguir = true;
	int result = 0;
	string teclado;
	do{
		cout<<endl<<endl;
		cout<<"Elija la opción que desea realizar."<<endl;
		cout<<"\t1- Eliminar por ID.\n\t2- Eliminar por fecha.\n\t3- Eliminar por tipo de reparación.\n\t4- Eliminar por coste.\n\t5- Cancelar\n";
		cin.clear();
		//cin>>teclado;
		getline(cin, teclado);
		result = atoi(teclado.c_str());
		switch(result){
		case 1:
			//seguir = !interfaceElimPos();//Al final no la hago usable al usuario porque daría problemas si se intenta eliminar por posición, cuando esa posición se ha visto en una lista parcial (busqueda)
			seguir = !interfaceElimId("", true);
			break;
		case 2:
			seguir = !interfaceElimFecha();
			break;
		case 3:
			seguir = !interfaceElimTipo();
			break;
		case 4:
			seguir = !interfaceElimCoste();
			break;
		case 5:
			return;

		default:
			cout<<"\t*** Opción inválida ***"<<endl;
			break;
		}

	}while(seguir);
}

bool HRep::esVacio(){
	//return getNumRep() == 0?true:false;  //lo cambio porque si hay elementos en el historial tiene que recorrer la lista entera para algo que sabe al  principio
	return primero?false:true;
}

NodoRep *HRep::getPrimero(){
	return primero;
}

int HRep::getNumRep(){
	if(primero){
		NodoRep *iterador = primero;
		int cont = 1;
		while(iterador->getSigRep()){
			cont++;
			iterador = iterador->getSigRep();
		}
		return cont;
	}
	return 0;
}

void HRep::imprimeRep(int cont, Reparacion* rep) {
	cout << "\t- "<<cont << endl;
	cout << "\t  IdRep: " << rep->idRep << endl;
	cout << "\t  Fecha de reparación: " << getFechaStr(rep) << endl;
	cout << "\t  Tipo de reparación: " << tipoRepStr[rep->tipo_rep] << endl;
	cout << "\t  Coste: " << rep->coste << endl << endl;
}

void HRep::listarRep(){
	if(!esVacio()){
		NodoRep *iterador = primero;
		int cont = 1;
		do{
			Reparacion *rep = iterador->getRep();
			imprimeRep(cont++, rep);
			iterador = iterador->getSigRep();
		}while(iterador);
		return;
	}
	cout<<"No hay reparaciones para mostrar"<<endl;

}

//Si los metodos de eliminar los hubiese hecho de otra forma ahora sería mucho mas sencillo, ya que podría crear copias, borrar lo que no interesa y mostrar por pantalla la copia
//Pero está claro que ya no lo voy a cambiar, la idea es que todos funcionasen como borrarPorCoste (al final para el case 3 si que lo he cambiado), podría cambiar el case 2 y case 1 cren
void HRep::interfaceBuscar(){
	while(1){
		cout<<endl<<"Menú de búsqueda de reparaciones."<<endl;
		cout<<"Elija una de las siguiente opciones:"<<endl;
		cout<<"\t1- Buscar reparaciones por id.\n\t2- Buscar reparaciones por fecha.\n\t3- Buscar reparaciones por coste."<<endl;
		cout<<"\t4- Buscar reparaciones por tipo.\n\tPULSE -1 PARA CANCELAR."<<endl<<endl;
		int result = auxParseInt("", true);
		if(result < 1){
			return;
		}
		switch(result){
		case 1://Busqueda por id
		{
			bool algoquemostrar = false;
			string teclado;
			cout<<"Introduzca la id de la reparación que desea buscar en el historial."<<endl;
			cout<<"Si desea buscar varias reparaciones introduzca sus id's separadas por el delimitador  ,"<<endl;
			cout<<"Pulse -1 para cancelar."<<endl;
			cin.clear();
			getline(cin, teclado);
			//cin>>teclado;
			if(teclado.compare("-1") == 0){
				cout<<"Cancelado."<<endl;
				continue;
			}
			parsedIntList *parseado = parseIntegerList(&teclado, ",", true);
			NodoRep *iter = primero;
			int cont = 1;//Uso este contador para mostrar la posición real en la lista, ya que borrar por posición usa la pos  real
			while(iter){
				for(int i=0; i<parseado->listadoSize; i++){
					if(iter->getRep()->idRep == parseado->listadoInt[i]){
						imprimeRep(cont++,iter->getRep());
						algoquemostrar  = true;
						break;
					}

				}
				iter = iter->getSigRep();
			}
			if(!algoquemostrar){
				cout<<"Nada que mostrar"<<endl;
			}
			free(parseado);
			break;
		}
		case 2://Busqueda por fecha
		{
			string teclado;
			cout<<endl;
			cout<<"Pulse una de las siguientes opciones.\n\t1- Buscar reparaciones anteriores a una fecha."<<endl;
			cout<<"\t2- Buscar reparaciones posteriores a una fecha.\n\t3- Buscar reparaciones entre dos fechas.\n\t4- Cancelar."<<endl;
			result = auxParseInt(teclado, true);
			switch(result){
			case 1: case 2:
			{
				bool algoquemostrar = false;
				auxTecladoIn(&teclado, "Introduzca la fecha de referencia, TODOS LAS REPARACIONES ANTERIORES A ESA FECHA SERÁN MOSTRADAS");
				parsedIntList* parseado = parseIntegerList(&teclado, "/", true);
				bool fechaCorrecta = compruebaFecha(parseado);
				if(!fechaCorrecta){
					cout<<endl<<"fecha incorrecta!!??"<<endl;
					continue;
				}
				time_t fechaRef = parseDateToTimeStamp(parseado);
				NodoRep *iter = primero;
				int cont = 1;
				while(iter){
					if(result == 1?iter->getRep()->fecha < fechaRef : iter->getRep()->fecha > fechaRef){
						imprimeRep(cont++, iter->getRep());
						algoquemostrar  = true;
					}
					iter = iter->getSigRep();
				}
				if(!algoquemostrar){
					cout<<"Nada que mostrar"<<endl;
				}
				free(parseado);
				break;
			}
			case 3:
			{
				//Voy a crear una copia del hostorial, borro de la copia lo que no quiere mostrar y a listo
				string teclado;
				NodoRep *primCop = new NodoRep(primero);
				HRep *copiaH = new HRep();
				copiaH->setPrimero(primCop);

				cout<<"Para mostrar reparaciones entre dos fechas dadas siga las instrucciones."<<endl;
				cout<<"Primero se le pedirá una fecha, después otra, el sistema eliminará las mostrará realizadas en ese intervalo de tiempo"<<endl;
				cout<<"No importa el orden de entrada de las fechas, es decir, que no tiene por que poner la más antigua primero"<<endl<<endl;


				auxTecladoIn(&teclado, "Introduzca la primera fecha de referencia.");
				parsedIntList* parseado = parseIntegerList(&teclado, "/", true);
				bool fechaCorrecta = compruebaFecha(parseado);
				if(!fechaCorrecta){
					cout<<endl<<"fecha incorrecta!!??"<<endl;
					continue;
				}
				time_t fechaRef1 = parseDateToTimeStamp(parseado);

				auxTecladoIn(&teclado, "Introduzca la segunda fecha de referencia.");
				parsedIntList* parseado2 = parseIntegerList(&teclado, "/", true);
				fechaCorrecta = compruebaFecha(parseado2);
				if(!fechaCorrecta){
					cout<<endl<<"fecha incorrecta!!??"<<endl;
					continue;
				}
				time_t fechaRef2 = parseDateToTimeStamp(parseado2);
				bool minPrimera = fechaRef1<fechaRef2?true:false;
				copiaH->eliminarPorFecha(false, minPrimera?parseado:parseado2, true, false,false);
				copiaH->eliminarPorFecha(false, minPrimera?parseado2:parseado, false, false,false);
				if(copiaH->getNumRep() == 0){
					cout<<"Nada que mostrar"<<endl;
				}
				copiaH->listarRep();
				copiaH->~HRep();
				free(copiaH);
				free(parseado);
				free(parseado2);
				break;
			}
			case 4:
				cout<<"Cancelado."<<endl;
				continue;
			}//switch interno case2
			break;
		}//case 2 externo
		case 3:
		{

			string teclado;
			cout<<endl;
			cout<<"Pulse una de las siguientes opciones.\n\t1- Mostrar reparaciones con coste inferior a uno dado."<<endl;
			cout<<"\t2- Mostrar reparaciones con coste superior a uno dado.\n\t3- Mostrar las reparaciones cuyo precio esté entre dos dados."<<endl;
			cout<<"\t4- Mostrar todas las reparaciones con un coste dado.\n\t5- Cancelar."<<endl;
			cin.clear();
			//cin>>teclado;
			getline(cin, teclado);
			int result = atoi(teclado.c_str());
			//Sigo haciendo copia que me es más rápido
			HRep *copiaH = new HRep();
			NodoRep *primCop = new NodoRep(primero);
			copiaH->setPrimero(primCop);


			switch(result){
			case 1:
			{
				cout<<"Introduzca el coste. Todas las reparaciones con un coste inferior serán mostradas."<<endl;
				int costeRef = auxParseInt("", true);
				eliminarPorCosteAux2(copiaH, costeRef, false, false, false);
				if(copiaH->getNumRep() == 0){
					cout<<"Nada que mostrar"<<endl;
				}
				copiaH->listarRep();
				copiaH->~HRep();
				free(copiaH);
				continue;
			}
			case 2:
			{
				cout<<"Introduzca el coste. Todas las reparaciones con un coste mayor serán mostradas."<<endl;

				int costeRef = auxParseInt("", true);
				eliminarPorCosteAux2(copiaH, costeRef, true, false, false);
				if(copiaH->getNumRep() == 0){
					cout<<"Nada que mostrar"<<endl;
				}
				copiaH->listarRep();
				copiaH->~HRep();
				free(copiaH);
				continue;

			}
			case 3:
			{
				cout<<"Para mostrar las reparaciones entre dos costes dados siga las instrucciones."<<endl;
				cout<<"Deberá introducir dos costes de referencia, da igual si inserta primero el mayor o al contrario."<<endl;
				cout<<"Introduzca el primer coste de referencia y pulse intro o pulse -1 para cancelar."<<endl;
				int uno = auxParseInt("", true);
				if(uno < 0){
					cout<<"Cancelado"<<endl;
					continue;
				}
				cout<<"Introduzca el segundo coste de referencia y pulse intro o pulse -1 para cancelar."<<endl;
				int dos = auxParseInt("", true);
				if(dos < 0){
					cout<<"Cancelado"<<endl;
					continue;
				}
				if(uno>dos){
					eliminarPorCosteAux2(copiaH, uno, false, false, false);
					eliminarPorCosteAux2(copiaH, dos, true, false, false);
				}
				else if(dos>uno){
					eliminarPorCosteAux2(copiaH, uno, true, false, false);
					eliminarPorCosteAux2(copiaH, dos, false, false, false);
				}
				else{
					eliminarPorCosteAux2(copiaH, uno, true, false, false);
					eliminarPorCosteAux2(copiaH, dos, false, false, false);
				}
				if(copiaH->getNumRep() == 0){
					cout<<"Nada que mostrar"<<endl;
				}
				copiaH->listarRep();
				copiaH->~HRep();
				free(copiaH);
				continue;
			}
			case 4:
			{
				cout<<"Introduzca el coste. Todas las reparaciones con ese coste serán mostradas."<<endl;
				int costeRef = auxParseInt("", true);
				eliminarPorCosteAux2(copiaH, costeRef, true, false, false);
				eliminarPorCosteAux2(copiaH, costeRef, false, false, false);
				if(copiaH->getNumRep() == 0){
					cout<<"Nada que mostrar"<<endl;
				}
				copiaH->listarRep();
				copiaH->~HRep();
				free(copiaH);
				continue;
			}
			case 5:
				cout<<"Cancelado."<<endl;
				continue;
			}//switch interno
			break;
		}
		case 4:
		{
			string teclado;
			cout<<"Introduzca el tipo de reparación que desea buscar en el historial"<<endl;
			cout<<"Si desea buscar varias tipos reparación, introduzca los tipos separados por el delimitador  ,"<<endl;
			for(int i=1; i<11;i++){
				cout<<i<<"- "<<tipoRepStr[i]<<endl;
			}
			cout<<endl<<"Pulse -1 para cancelar"<<endl;

			cin.clear();
			getline(cin, teclado);
			//cin>>teclado;
			if(teclado.compare("-1") == 0){
				cout<<"Cancelado"<<endl;
				continue;
			}
			parsedIntList *parseado = parseIntegerList(&teclado, ",", false);
			NodoRep *iter = primero;
			int cont = 1;
			while(iter){
				for(int i=0; i<parseado->listadoSize; i++){
					if(iter->getRep()->tipo_rep == parseado->listadoInt[i]){
						imprimeRep(cont++,iter->getRep());
						break;
					}
				}
				iter = iter->getSigRep();
			}
			free(parseado);
			continue;
		}
		}//switch externo
	}//while
}

void HRep::interfaceOrdenar(){
	cout<<"Seleccione una de las siguientes opciones de ordenación."<<endl;
	cout<<"\t1- Ordenar por fecha ascendente.\n\t2- Ordenar por fecha descendente.\n\t3- Ordenar por coste ascendente.\n"<<
			"\t4- Ordenar por coste descendente.\n\t5- Ordenar por fecha y coste ascendente.\n"<<
			"\t6- Ordenar por fecha y coste descendente\n\t7- Ordenar por coste y fecha ascendente\n"<<
			"\t8- Ordenar por coste y fecha descendente\n\t9- Ordenar por tipo de reparación\n\t10- Cancelar."<<endl;
	int result = auxParseInt("", true);
	switch(result){
	case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
		ordenar(result);
		break;
	case 10: default:
		return;

	}
}
void HRep::ordenar(int tipo_Ordenamiento){
	//Ordenamos con el método de la burbuja mejorado, como sé cuantos elementos tiene el historial de reparaciones, me voy a apoyar en eso para usar un for en vez de un while
	//Es más sencillo cambiar el "valor" de cada nodo, en vez de andar rompiendo y creando nuevos enlaces en los nodos
	//Un poco más complicado que con arrays pero se podrá hacer antes o después
	for(int i = 0; i<getNumRep()-1; i++){
		NodoRep *aux = primero;
		NodoRep *siguiente = aux->getSigRep();
		for(int k=0 ; k<getNumRep()-1-i; k++){
			auxOrd(aux, siguiente, tipo_Ordenamiento);
			aux = siguiente;
			siguiente = siguiente->getSigRep();
		}
	}
	//Para dar claridad al bucle he implementado dos funciones auxiliares  auxOrd()  e intercambia()
}



//Métodos de ámbito privado

void HRep::insertar(Reparacion* p_rep)
{
	//para cuando se inserta en copias temporales del historial no tiene que cambiar el id
	if(p_rep->idRep < 1){
		p_rep->idRep = nextId++;
	}
	NodoRep* nuevo = new NodoRep(p_rep); // Se crea un nodo nuevo
	if(primero){
		nuevo->setSigRep(primero);
	}
	primero = nuevo;
	p_rep->idRep = getNumRep();//el id no tiene mucho sentido que tenga un id más alto una reparación más antigua, pero esto es causa de generarlos aleatoriamente, con los que se generan a posteriore si tiene sentido
}

NodoRep* HRep::eliminar(int p_numRep)
{
	if(p_numRep > 0 && getNumRep() >= p_numRep){//Si el nº de reparación a eliminar es positivo y menor o igual que el total de reparaciones de la lista, continúa
		NodoRep* iterador = primero; //
		if(p_numRep == 1){
			primero = primero->getSigRep();
			return iterador;//TODO eliminar de memoria cuando acabe de usar el Nodo devuelto, lo devulvo por si necesito datos previa eliminación del nodo
		}
		for(int i=0; i<p_numRep-2; i++){//Quiero posicionar el iterador justo delante del Nodo a eliminar
			iterador = iterador->getSigRep();
		}
		NodoRep *borrar = iterador->getSigRep();//creo un puntero que apunta al elemento a borrar, que contiene el puntero al siguiente elemento de la lista (ya que este nodo va a ser borrado)
		iterador->setSigRep(borrar->getSigRep());//si borrar es el último, su puntero al siguiente nodo será NULL, con lo cual el nuevo último también apuntará a NULL
		//Por seguridad, hago que el puntero sigRep del Nodo a eliminar apunte a NULL
		borrar->setSigRep(NULL);
		return borrar;
	}
	return NULL;//No existe ese número de reparación (el número me refiero al que se muestra por pantalla, ya que la estructura reparación no tiene un campo NumRep)
}

void HRep::intercambia(Reparacion* temp, NodoRep* p_aux, NodoRep* p_sig) {
	temp = p_aux->getRep();
	p_aux->setRep(p_sig->getRep());
	p_sig->setRep(temp);
}


//En función del tipo de ordenación , mira las variables necesarias y actúa en consecuencia
void HRep::auxOrd(NodoRep *p_aux, NodoRep *p_sig, int mode){
	Reparacion *temp;
	switch(mode){
	case 1://Fecha ascendente
		if(p_aux->getRep()->fecha > p_sig->getRep()->fecha){
			intercambia(temp, p_aux, p_sig);
		}
		break;
	case 2://Fecha descendente
		if(p_aux->getRep()->fecha < p_sig->getRep()->fecha){
			intercambia(temp, p_aux, p_sig);
		}
		break;
	case 3://Precio ascendente
		if(p_aux->getRep()->coste > p_sig->getRep()->coste){
			intercambia(temp, p_aux, p_sig);
		}
		break;
	case 4://Precio descendente
		if(p_aux->getRep()->coste < p_sig->getRep()->coste){
			intercambia(temp, p_aux, p_sig);
		}
		break;
	case 5://Fecha_Coste ascendente
		if(p_aux->getRep()->fecha > p_sig->getRep()->fecha){
			intercambia(temp, p_aux, p_sig);
		}
		else if(p_aux->getRep()->fecha == p_sig->getRep()->fecha){
			if(p_aux->getRep()->coste > p_sig->getRep()->coste){
				intercambia(temp, p_aux, p_sig);
			}
		}
		break;
	case 6://Fecha_Coste descendente
		if(p_aux->getRep()->fecha < p_sig->getRep()->fecha){
			intercambia(temp, p_aux, p_sig);
		}
		else if(p_aux->getRep()->fecha == p_sig->getRep()->fecha){
			if(p_aux->getRep()->coste < p_sig->getRep()->coste){
				intercambia(temp, p_aux, p_sig);
			}
		}
		break;
	case 7://Coste_Fecha ascendente
		if(p_aux->getRep()->coste > p_sig->getRep()->coste){
			intercambia(temp, p_aux, p_sig);
		}
		else if(p_aux->getRep()->coste == p_sig->getRep()->coste){
			if(p_aux->getRep()->fecha > p_sig->getRep()->fecha){
				intercambia(temp, p_aux, p_sig);
			}
		}
		break;

	case 8://Coste_Fecha descendente
		if(p_aux->getRep()->coste < p_sig->getRep()->coste){
			intercambia(temp, p_aux, p_sig);
		}
		else if(p_aux->getRep()->coste == p_sig->getRep()->coste){
			if(p_aux->getRep()->fecha < p_sig->getRep()->fecha){
				intercambia(temp, p_aux, p_sig);
			}
		}
		break;
	case 9://Tioo ascendente
		if(p_aux->getRep()->tipo_rep > p_sig->getRep()->tipo_rep){
			intercambia(temp, p_aux, p_sig);
		}
		break;
	case 10://Tipo descendente
		if(p_aux->getRep()->tipo_rep < p_sig->getRep()->tipo_rep){
			intercambia(temp, p_aux, p_sig);
		}
		break;
	}

}

bool HRep::interfaceElimPos(){
	string teclado;
	cout<<"Introduzca la posición de la reparación que desea eliminar del historial"<<endl;
	cout<<"Si desea eliminar varias reparaciones, introduzca sus posiciones separadas por el delimitador  ,"<<endl;
	cout<<"Pulse -1 para cancelar"<<endl;
	cin.clear();
	getline(cin, teclado);
	//cin>>teclado;
	if(teclado.compare("-1") == 0){
		cout<<"Cancelado"<<endl;
		return false;
	}
	parsedIntList *parseado = parseIntegerList(&teclado, ",", false);
	bool dev = false;
	for(int i=0; i<parseado->listadoSize; i++){
		cout<<endl;
		//int posEliminar = atoi(parseado->listadoStr[i].c_str());
		int posEliminar = parseado->listadoInt[i];
		if(posEliminar > 0){//Intenta convertir a entero los strings parseados para eliminar esas posiciones
			NodoRep *temp = eliminar(posEliminar);
			if(temp){
				cout<<"Se ha eliminado del historial de reparaciones la siguiente reparación:"<<endl;
				cout<<"ID: "<<temp->getRep()->idRep<<endl<<"Fecha: "<<getFechaStr(temp->getRep())<<endl
						<<"Tipo: "<<tipoRepStr[temp->getRep()->tipo_rep]<<endl<<"Coste: "<<temp->getRep()->coste<<endl<<endl;
				dev=true;
				free(temp);
				continue;
			}
		}
		if(posEliminar<0){
			cout<<"Posición   -->  "<<(-1)*posEliminar<<"   <--  repetida al introducir datos!??"<<endl;
		}
		else{
			cout<<"Posición   -->  "<<parseado->listadoStr[i].c_str()<<"   <--  no existe"<<endl;//uso esa variable así no me muestra 0 del resultado atoi()
		}
	}
	free(parseado);
	return dev;
}

bool HRep::interfaceElimId(string p_param, bool info){//No es muy bonito esto de que sea llamada la interface sin "interface", pero me solventa sin tocar demasiado
	parsedIntList *parseado ;
	if(p_param.empty()){
		string teclado;
		cout<<"Introduzca la id de la reparación que desea eliminar del historial"<<endl;
		cout<<"Si desea eliminar varias reparaciones introduzca sus id's separadas por el delimitador  ,"<<endl;
		cout<<"Pulse -1 para cancelar"<<endl;
		cin.clear();
		getline(cin,teclado);
		if(teclado.compare("-1") == 0){
			cout<<"Cancelado"<<endl;
			return false;
		}
		parseado = parseIntegerList(&teclado, ",", false);
	}
	else{
		parseado = parseIntegerList(&p_param, ",", false);
	}
	bool dev = false;

	//Bien, ahora tenemos una lista con las id's de las reparaciones a eliminar, tan solo necesitamos saber sus posiciones en la lista para llamar a eliminar(int pos)
	//Para ello vamos a recorrer el historial comparando el campo id con la lista de ids a eliminar, si hay coincidencia, se apunta la guarda la posición en otro array
	//temporal que tendrá todas las posiciones
	if(parseado->listadoSize > 0){
		NodoRep *iterador = primero;
		int cont = 1;
		while(iterador){
			bool avanzarIter = true;
			for(int i=0; i<parseado->listadoSize; i++){
				int idVictima = atoi(parseado->listadoStr[i].c_str());
				//cout<<idVictima<<endl;
				if(idVictima < 1){
					//cout<<"ID  -->"<<parseado->listado[i].c_str()<<"  <--   inválido."<<endl;//Se repite mucho el mensaje, hay que hacerlo de otra forma
					continue;
				}
				if(iterador->getRep()->idRep == idVictima){
					avanzarIter = false;
					iterador = iterador->getSigRep();
					NodoRep *victima = eliminar(cont);
					if(info){
						cout<<"Se ha eliminado del historial de reparaciones la siguiente reparación:"<<endl;
						cout<<"ID: "<<victima->getRep()->idRep<<endl<<"Fecha: "<<getFechaStr(victima->getRep())<<endl
								<<"Tipo: "<<tipoRepStr[victima->getRep()->tipo_rep]<<endl<<"Coste: "<<victima->getRep()->coste<<endl<<endl;
					}
					dev=true;
					free(victima);
					break;
				}
			}
			if(avanzarIter){
				cont++;
				iterador = iterador->getSigRep();
			}
		}
		/*
		if(info){//Al final no lo muestro porque los datos positivos que no estan en la lista no aparacen como errores y tampoco es cuestion de hacerlo como en el comentario anterior
			//Bucle que muestra los errores
			for(int i=0; i<parseado->listadoSize; i++){
				int intparsed = atoi(parseado->listadoStr[i].c_str());
				if(intparsed < 0){
					cout<<"ID  -->"<<intparsed*-1<<"  <--   dato introducido repetido??."<<endl;
				}else if(intparsed == 0){
					cout<<"ID   -->  "<<parseado->listadoStr[i].c_str()<<"   <--  no existe"<<endl;//uso esa variable así no me muestra 0 del resultado atoi()
				}
			}
		}*/
		free(parseado);
	}
	return dev;
}


bool HRep::interfaceElimFecha(){
	bool dev = false;
	string teclado;
	cout<<endl;
	cout<<"Pulse una de las siguientes opciones.\n\t1- Eliminar reparaciones anteriores a una fecha."<<endl;
	cout<<"\t2- Eliminar reparaciones posteriores a una fecha.\n\t3- Eliminar las reparaciones entre dos fechas.\n\t4- Cancelar."<<endl;
	cin.clear();
	getline(cin, teclado);
	//cin>>teclado;
	int result = atoi(teclado.c_str());
	switch(result){
	case 1:
	{
		//No puedo crear un método porque incluye código con un return, aunque el case 2 sea prácticamente idéntico
		auxTecladoIn(&teclado, "Introduzca la fecha de referencia, TODOS LAS REPARACIONES ANTERIORES A ESA FECHA SERÁN ELIMINADAS!");
		parsedIntList* parseado = parseIntegerList(&teclado, "/", true);
		bool fechaCorrecta = compruebaFecha(parseado);
		if(!fechaCorrecta){
			cout<<"fecha incorrecta!!??"<<endl;
			return dev;
		}
		dev = eliminarPorFecha(dev, parseado, true, true, false);
		free(parseado);
		break;
	}
	case 2:
	{
		auxTecladoIn(&teclado, "Introduzca la fecha de referencia, TODOS LAS REPARACIONES POSTERIORES A ESA FECHA SERÁN ELIMINADAS!");
		parsedIntList* parseado = parseIntegerList(&teclado, "/", true);
		bool fechaCorrecta = compruebaFecha(parseado);
		if(!fechaCorrecta){
			cout<<"fecha incorrecta!!??"<<endl;
			return dev;
		}
		dev = eliminarPorFecha(dev, parseado, false, true, false);
		free(parseado);
		break;
	}
	case 3:
	{
		cout<<"Para borrar reparaciones entre dos fechas dadas siga las instrucciones."<<endl;
		cout<<"Primero se le pedirá una fecha, después otra, el sistema eliminará las reparaciones realizadas en ese intervalo de tiempo"<<endl;
		cout<<"No importa el orden de entrada de las fechas, es decir, que no tiene por que poner la más antigua primero"<<endl<<endl;
		cout<<"Introduzca la primera fecha de referencia"<< endl;
		cout<<"La fecha debe tener el siguiente formato  -->   DD/MM/YYYY"<<endl;
		cin.clear();
		getline(cin, teclado);
		//cin>>teclado;
		parsedIntList* parseado = parseIntegerList(&teclado, "/", true);
		bool fechaCorrecta = compruebaFecha(parseado);
		if(!fechaCorrecta){
			cout<<"fecha incorrecta!!??"<<endl;
			return dev;
		}

		cout<<"Introduzca la segunda fecha de referencia"<< endl;
		cin.clear();
		getline(cin, teclado);
		//cin>>teclado;
		parsedIntList* parseado2 = parseIntegerList(&teclado, "/", true);
		fechaCorrecta = compruebaFecha(parseado2);
		if(!fechaCorrecta){
			cout<<"fecha incorrecta!!??"<<endl;
			return dev;
		}

		//Si llegamos aquí es que ya tenemos dos fechas correctas y  ya podemos eliminar, vamos a ver cual de las dos fechas es la menor
		bool esMenorPrimera = true;
		for(int i=2; i>=0; i--){
			cout<<parseado->listadoInt[i]<<endl;
			cout<<parseado2->listadoInt[i]<<endl;
			if(parseado->listadoInt[i]>parseado2->listadoInt[i]){esMenorPrimera = false;break;}
		}

		//Ahora creamos una copia del historial -> Diferentes posiciones de memoria, cuidado, que los cambios de una lista no afectan a la otra(como quiero en este caso)
		HRep *copiaHistorial = new HRep();
		NodoRep *as = new NodoRep(primero);
		copiaHistorial->setPrimero(as);
		copiaHistorial->eliminarPorFecha(dev,esMenorPrimera?parseado:parseado2,true, false, false);
		copiaHistorial->eliminarPorFecha(dev,esMenorPrimera?parseado2:parseado,false, false, false);
		//Hecho esto, en la lista copiada deben quedar solamente los que habría que borrar
		//Recorremos la copia y borramos por id en la original

		NodoRep* iter = copiaHistorial->getPrimero();
		while(iter){
			dev = true;
			stringstream ss;
			ss<<iter->getRep()->idRep;
			interfaceElimId(ss.str(), true);
			iter = iter->getSigRep();
		}
		copiaHistorial->~HRep();
		free(copiaHistorial);
		free(parseado);
		return dev;
		//cout<<"****************************"<<endl;
		//copiaHistorial->listarRep();
		//cout<<"*****************"<<endl;

	}
	break;
	case 4:
		cout<<"Cancelado"<<endl;
		return dev;
	default:
		return dev;

	}
	return dev;

}

bool HRep::interfaceElimTipo(){
	bool dev = false;
	string teclado;
	cout<<"Introduzca el tipo de reparación que desea eliminar del historial"<<endl;
	cout<<"Si desea eliminar varios tipos reparación, introduzca los tipos separados por el delimitador  ,"<<endl;
	for(int i=1; i<11;i++){
		cout<<i<<"- "<<tipoRepStr[i]<<endl;
	}
	cout<<endl<<"Pulse -1 para cancelar"<<endl;

	cin.clear();
	getline(cin, teclado);
	//cin>>teclado;
	if(teclado.compare("-1") == 0){
		cout<<"Cancelado"<<endl;
		return dev;
	}
	parsedIntList *parseado = parseIntegerList(&teclado, ",", false);

	//Voy a hacerlo igual que para entre dos fechas, creo una copia, la recorro, y borro por id, para la máquina igual es peor, pero a mi me facilita bastante la labor en este momento
	//que estoy un poco saturado ya
	HRep *copiaH = new HRep();
	NodoRep *as = new NodoRep(primero);
	copiaH->setPrimero(as);

	NodoRep *iter = as;
	while(iter){
		for(int i=0; i<parseado->listadoSize; i++){
			if(iter->getRep()->tipo_rep == parseado->listadoInt[i]){
				stringstream ss;
				ss<<iter->getRep()->idRep;
				interfaceElimId(ss.str(), true);
				dev = true;
				break;
			}
		}
		iter = iter->getSigRep();
	}

	copiaH->~HRep();
	free(copiaH);
	free(parseado);
	return dev;
}



bool HRep::interfaceElimCoste(){
	bool dev = false;
	string teclado;
	cout<<endl;
	cout<<"Pulse una de las siguientes opciones.\n\t1- Eliminar reparaciones con coste inferior a uno dado."<<endl;
	cout<<"\t2- Eliminar reparaciones con coste superior a uno dado.\n\t3- Eliminar las reparaciones cuyo precio esté entre dos dados."<<endl;
	cout<<"\t4- Eliminar todas las reparaciones con un coste dado.\n\t5- Cancelar."<<endl;
	cin.clear();
	getline(cin, teclado);
	//cin>>teclado;
	int result = atoi(teclado.c_str());
	//Sigo haciendo copia que me es más rápido
	HRep *copiaH;
	NodoRep *as;
	switch(result){
	case 1:
	{
		copiaH = new HRep();
		as = new NodoRep(primero);
		copiaH->setPrimero(as);
		cout<<"Introduzca el coste. TODOS LAS REPARACIONES CON UN COSTE MENOR SERÁN ELIMINADAS.  Pulse -1 para cancelar."<<endl;
		dev = eliminarPorCosteAux3(copiaH, true);
		if (dev) {
			//vaciamos la lista principal
			this->~HRep(); //Ahí va!!, si funcina el this al igual que en Java :))
			//Ahora establecemos un nuevo primero en la lista original
			primero = copiaH->primero;
			free(copiaH);
			cout << "Hecho" << endl;

		}
		break;
	}
	case 2:
	{
		copiaH = new HRep();
		as = new NodoRep(primero);
		copiaH->setPrimero(as);
		cout<<"Introduzca el coste. TODOS LAS REPARACIONES CON UN COSTE MAYOR SERÁN ELIMINADAS.   Pulse -1 para cancelar."<<endl;
		dev = eliminarPorCosteAux3(copiaH, false);
		if (dev) {
			//vaciamos la lista principal
			this->~HRep();
			//Ahora establecemos un nuevo primero en la lista original
			primero = copiaH->primero;
			free(copiaH);
			//cout << "Hecho" << endl;

		}
		break;
	}
	case 3:
	{
		copiaH = new HRep();
		as = new NodoRep(primero);
		copiaH->setPrimero(as);
		cout<<"Para borrar las reparaciones entre dos costes dados siga las instrucciones."<<endl;
		cout<<"Deberá introducir dos costes de referencia, da igual si inserta primero el mayor o al contrario."<<endl;
		cout<<"Introduzca el primer coste de referencia y pulse intro o pulse -1 para cancelar."<<endl;
		int uno = auxParseInt("", true);
		if(uno < 0){
			return dev;
		}
		cout<<"Introduzca el segundo coste de referencia y pulse intro o pulse -1 para cancelar."<<endl;
		int dos = auxParseInt("", true);
		if(dos < 0){
			return dev;
		}

		//Si llegamos aquí es que tenemos dos costes positivos
		//si los dos costes de referencia son iguales, borramos las reparaciones con ese coste

		//Lo que hago es similar que con las fechas
		dev = eliminarporCosteAux4(uno, dos, dev, copiaH);
		//cout<<"*************"<<endl;
		return dev;

	}
	case 4:
	{
		copiaH = new HRep();
		as = new NodoRep(primero);
		copiaH->setPrimero(as);
		cout<<"Introduzca el coste. TODOS LAS REPARACIONES CON UN COSTE IGUAL SERÁN ELIMINADAS.  Pulse -1 para cancelar."<<endl;
		int num = auxParseInt("", true);
		if(num >=0){
			dev = eliminarporCosteAux4(num,num,dev,copiaH);
		}
		return dev;
	}
	case 5:
		cout<<"Cancelado"<<endl;
		return dev;
	default:
		return dev;
	}
	return dev;
}

//Aquí lo voy a hacer distinto que con las fechas a ver si me facilita, al final no reuso codigo porque si no se va a complicar demasiado la funcion eliminar por fecha

bool HRep::eliminarPorCosteAux2(HRep *copiaH, int refCoste, bool menores, bool info, bool oIguales){
	bool dev = false;

	NodoRep *iter = copiaH->primero;
	while(iter){
		bool avanzaIter = true;
		if(menores?
				(oIguales?iter->getRep()->coste<=refCoste:iter->getRep()->coste<refCoste):
				(oIguales?iter->getRep()->coste>=refCoste:iter->getRep()->coste>refCoste)){
			stringstream ss;
			ss<<iter->getRep()->idRep;
			iter = iter->getSigRep();
			copiaH->interfaceElimId(ss.str(), info);
			dev = true;
			avanzaIter = false;
			//cout<<"Eliminado "<<endl;
		}
		if(avanzaIter){
			iter = iter->getSigRep();
		}
	}
	return dev;
}

bool HRep::eliminarPorCosteAux3(HRep* copiaH, bool menores) {
	int refCoste = auxParseInt("", true);
	if(refCoste >= 0){
		bool eliminar = eliminarPorCosteAux2(copiaH, refCoste, menores, true, false); //Con esto tenemos la copia del historial con las reparaciones borradas
		return eliminar;
	}
	else{
		cout<<"Cancelado"<<endl;
		return false;
	}
}

bool HRep::eliminarporCosteAux4(int uno, int dos, bool dev, HRep* copiaH) {
	//Si llegamos aquí es que tenemos dos costes positivos
	//si los dos costes de referencia son iguales, borramos las reparaciones con ese coste
	//Lo que hago es similar que con las fechas
	eliminarPorCosteAux2(copiaH, uno < dos ? uno : dos, true, false, false);
	eliminarPorCosteAux2(copiaH, uno < dos ? dos : uno, false, false, false);
	NodoRep* iterador = copiaH->primero;
	while (iterador) {
		stringstream ss;
		ss << iterador->getRep()->idRep;
		interfaceElimId(ss.str(), true);
		iterador = iterador->getSigRep();
		dev = true;
	}
	copiaH->~HRep();
	free(copiaH);
	return dev;
}



//Esta función es un poco compleja porque va a ser usada de tres formas distintas
//Una para eliminar Reparaciones posteriores a una fecha (la fecha va en parseado) si menores es falso
//Otra para eliminar Reparaciones anteriores a una fecha si menores es true

//La que complica un poco esto. Para eliminar reparaciones entre dos fechas dadas, se llamará 2 veces a esta función sobre una copia del historial,
//las reparaciones restantes de esa copia de la lista serán las que verdaderamente se borren del historial original

bool HRep::eliminarPorFecha(bool dev, parsedIntList* parseado,bool menores, bool informe, bool oIguales) {
	time_t timeReference = parseDateToTimeStamp(parseado);
	//cout << timeReference << endl;
	NodoRep* iterador = primero;
	int cont = 1;
	while (iterador) {
		bool avanzaIter = true;
		/*cout<<endl<<endl<<"*************"<<endl;
		 cout<<"Fecha Referencia: "<<timeReference<<endl;
		 cout<<"Fecharep: "<<iterador->getRep()->fecha<<endl;
		 cout<<"*************"<<endl<<endl;*/
		//solo debug

		//Interesante esto, he probado a usar la operación ternaria en la condicion del if y también funciona, asi que me vale para eliminar anteriores o posteriores segun
		//el parametro menores, yahora he añadido menor o igual complicando algo más la condiciónm la he separado en lineas para mayor claridad
		if (menores?
				(oIguales?iterador->getRep()->fecha <= timeReference:iterador->getRep()->fecha < timeReference):
				(oIguales?iterador->getRep()->fecha >= timeReference:iterador->getRep()->fecha > timeReference)) {
			iterador = iterador->getSigRep();
			NodoRep* victima = eliminar(cont);
			if(informe){
				cout<< "Se ha eliminado del historial de reparaciones la siguiente reparación:"<< endl;
				cout << "ID: " << victima->getRep()->idRep << endl << "Fecha: "
						<< getFechaStr(victima->getRep()) << endl << "Tipo: "
						<< tipoRepStr[victima->getRep()->tipo_rep] << endl
						<< "Coste: " << victima->getRep()->coste << endl << endl;
			}
			dev = true;
			avanzaIter = false;
			free(victima);
		}
		if (avanzaIter) {
			iterador = iterador->getSigRep();
			cont++;
		}
	}
	return dev;
}

void HRep::setPrimero(NodoRep *param){
	primero = param;
}


