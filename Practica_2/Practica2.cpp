//============================================================================
// Name        : Practica2.cpp
// Autores      : Angel Herencia y Alfonso Muñoz Casado
// Version     :
// Copyright   : Pr2-GIC-ED_AYA
// Description : Programa principal
//============================================================================

#include "Practica2.h"

#include <math.h>
#include <stddef.h>
#include <unistd.h>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>



using namespace std;

int main() {
	srand(time(NULL));//Importante para que no cree siempre el mismo número aleatorio al iniciar el programa, genera una semilla.



	ArbolClientes* hClientes = init();
	cout<<"Iniciando programa";
	for(int i=0; i<20; i++){
		usleep(25 * pow(10,3));
		cout<<".";
		cout.flush();
	}
	cout<<endl;
	cout<<"Historial de clientes cargado."<<endl;

	while(1){
		cin.clear();
		cout<<"Seleccione una de las siguientes opciones:"<<endl;
		cout<<"\t1- Mostrar historial completo de clientes.\n\t2- Buscar cliente por DNI\n\t3- Añadir nuevo cliente.\n";
		cout<<"\t4- Eliminar un cliente.\n\t5- Salir."<<endl<<endl;
		int result = auxParseInt("", true);
		switch(result){
		case 1:
			hClientes->InOrden(Mostrar);
			break;
		case 2:
		{
			cout<<"Introduzca el dni del cliente que quiere buscar en el historial o pulse -1 para cancelar."<<endl;
			int result = auxParseInt("", true);
			if(result == -1){
				cout<<"Cancelado."<<endl<<endl;
				break;
			}
			NodoCli *cli = hClientes->getCli(result);
			if(cli){
				cout<<"Cliente encontrado"<<endl<<endl;
				Mostrar(cli->getCliente(), false);
				bool seguir = true;
				do{
					cin.clear();
					cout<<"Seleccione una de las siguientes opciones:"<<endl;
					cout<<"\t1- Mostrar historial de reparaciones.\n\t2- Ordenar historial de reparaciones.\n\t3- Buscar reparaciones.\n";
					cout<<"\t4- Insertar nueva reparacion.\n\t5- Borrar reparación.\n\t6- Atrás."<<endl<<endl;
					int result = auxParseInt("", true);
					switch(result){
					case 1:
						cli->getCliente()->historial->listarRep();
						break;

					case 2:
						cli->getCliente()->historial->interfaceOrdenar();
						break;

					case 3:
						cli->getCliente()->historial->interfaceBuscar();
						break;

					case 4:
						cli->getCliente()->historial->insertar(false);
						break;

					case 5:
						cli->getCliente()->historial->eliminar();
						break;

					case 6:
						seguir = false;
						break;
					default:
						break;
					}
				}while(seguir);
			}
			else{
				cout<<"Cliente no encontrado"<<endl<<endl;
				break;
			}
			break;
		}
		case 3:
		{
			cout<<"Introduzca el dni. Debe tener 8 digitos. Introduzca -1 para cancelar."<<endl;
			string dnistr;
			cin.clear();
			getline(cin,dnistr);
			if(dnistr.compare("-1") == 0 || dnistr.length() != 8){
				cout<<"Cancelado"<<endl<<endl;
				break;
			}
			int dni = auxParseInt(dnistr,false);
			if(dni == -1){
				cout<<"Cancelado"<<endl<<endl;
				break;
			}
			cout<<"Introduzca el nombre y los apellidos del cliente. Pulse -1 para cancelar."<<endl;
			//deberia crear otra variable para el nombre y apellidos, pero uso esta que ya no me hace falta
			cin.clear();
			getline(cin, dnistr);
			if(dnistr.compare("-1") == 0){
				cout<<"Cancelado"<<endl<<endl;
				break;
			}
			Cliente *cli = new Cliente();
			cli->dni =  dni;
			cli->nomApe = dnistr;
			cli->numHistorial = hClientes->getNextId();
			cli->historial = new HRep();
			hClientes->Insertar(cli);

			cout<<"Cliente añadido:"<<endl;
			Mostrar(cli, false);
			break;
		}
		case 4:
		{
			cout<<"Introduzca el dni del cliente que quiere eliminar del historial o pulse -1 para cancelar."<<endl;
			int result = auxParseInt("", true);
			if(result == -1){
				cout<<"Cancelado."<<endl<<endl;
				break;
			}
			else{
				if(hClientes->Buscar(result)){
					NodoCli *cli = hClientes->getCli(result);
					if(cli){
						cout<<"Se ha eliminado del historial de clientes el siguiente cliente:"<<endl<<endl;
						Mostrar(cli->getCliente(), true);
						//cout<<endl<<endl;
					}
					//cout<<hClientes->NumeroNodos()<<endl;
					hClientes->Borrar(result);
					//cout<<hClientes->NumeroNodos()<<endl;
				}
			}
			break;
		}
		break;
		case 5:
			cout<<"Programa finalizado."<<endl;
			return 0;
		}
	}



	//cout<<endl<<endl;

	/*hClientes->InOrden(Mostrar);
	cout<<hClientes->Altura(4);
	cout<<hClientes->Altura(3);
	cout<<hClientes->Altura(5);
	cout<<hClientes->Altura(6);
	cout<<hClientes->Altura(2);*/

}



//Funcines auxiliares

ArbolClientes* init() {
	//Generamos un numero aleatorio que indica el número de clientes a crear
	int numClientes = getRandomNumber(7, 20);
	ArbolClientes* hClientes = new ArbolClientes();

	//Inicializamos dichos Clientes con datos aleatorios y los insertamos en el historial de clientes (arbol binario de busqueda)
	for(int i=0; i<numClientes; i++){
		hClientes->Insertar(randomiceCli(hClientes->getNextId()));
	}
	return hClientes;
}


/*Definiciones de funciones auxiliares*/
int getRandomNumber(int min, int max){
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


//Esta función modifica  de una forma aleatoria el contenido de la estructura, usada para inicializar las reparaciones de forma aleatoria.
Reparacion* randomizaRep(){
	Reparacion *rep = new Reparacion;
	//Primero generamos una fecha aleatoria que parte de la fecha en que se inicializo (epoca UNIX)
	//Se podría mejorar bastante el algoritmo pero no creo que la práctica esté centrada en estos menesteres y el tiempo no sobra, mejor usarlo
	//en mejorar o ampliar algunas funcionalidades más útiles en cuanto a listas y árboles (si es que nos da tiempo al final)
	time_t t = time(0);   // get time now
	//cout<<"Tiempo ahora: "<<t<<endl;
	do{
		rep->fecha = 0;
		//Sumamos cierta cantidad de años
		rep->fecha += getRandomNumber(20, 20+(2016-1990)) * SEG_ANIO;//Quiero un año aleatorio entre 1990 y 2016
		//Sumamos cierta cantidad de meses
		rep->fecha += getRandomNumber(0,11)*SEG_MES;
		//Sumamos cierta cantidad de días, esperemos no caiga en domingo xdd, aunque no me voy a complicar la vida
		rep->fecha += getRandomNumber(0,30)*SEG_DIA;
		//cout << "Fecha: "<< getFechaStr()<<endl;
	}while(t<rep->fecha);

	//Lo siguiente es aleatorizar el tipo de reparación
	switch(getRandomNumber(1,10)){
	case 1:
		rep->tipo_rep = Revision;
		break;
	case 2:
		rep->tipo_rep = CambioAceite;
		break;
	case 3:
		rep->tipo_rep = CambioFiltros;
		break;
	case 4:
		rep->tipo_rep = Carga_Aire;
		break;
	case 5:
		rep->tipo_rep = CambioRuedas;
		break;
	case 6:
		rep->tipo_rep = Bateria;
		break;
	case 7:
		rep->tipo_rep = Distribucion;
		break;
	case 8:
		rep->tipo_rep = JuntaCulata;
		break;
	case 9:
		rep->tipo_rep = Embrague;
		break;
	case 10:
		rep->tipo_rep = Otros;
		break;
	default:
		rep->tipo_rep = Nula;//Esto no debería ocurrir, pero por si acaso
		break;
	}
	//cout<<"Tipo de reparación: "<<tipoRepStr[tipo_rep]<<endl;

	//ahora el coste

	rep->coste = (rep->tipo_rep == Otros)?getRandomNumber(30,1500):precioRep[rep->tipo_rep];
	//cout<<"Coste: "<<coste<<endl<<endl;
	return rep;
}

string getFechaStr(Reparacion *rep){
	struct tm * now = localtime( &rep->fecha );
	stringstream ss;
	ss << (int)now->tm_mday<< "/" << (int)(now->tm_mon+1) << "/" << (int)(now->tm_year + 1900);
	string str = ss.str();
	return str.c_str();
	//return ctime(&fecha);
}

Cliente* randomiceCli(int nextId){
	Cliente *cli = new Cliente;
	cli->numHistorial = nextId;

	int caracteresNomApe = getRandomNumber(8,20);
	char nomApeArr[caracteresNomApe + 1];
	for(int i=0; i<caracteresNomApe; i++){
		nomApeArr[i] = getRandomNumber(97, 122);
	}
	nomApeArr[caracteresNomApe] = '\0';
	string temp(nomApeArr);
	cli->nomApe = temp;
	cli->dni = getRandomNumber(10000000,99999999);
	cli->historial = new HRep();
	//cout<<nomApe<<endl;

	//Por cada cliente generamos un número aleatorio de reparaciones entre 1 y 5
	int numReps = getRandomNumber(1, 5);
	for (int k = 0; k < numReps; k++) {
		cli->historial->insertar(true);
		//char* sTptr = ctime(tPtr);
		//cout<<rep.fecha<<endl;
	}
	return cli;
}


int auxParseInt(string str, bool teclado){//Si le pasamos una cadena no vacia la parsea, si no la toma por teclado
	int dev = -1;
	if(str.empty() && teclado){
		string teclado;
		cin.clear();
		getline(cin, teclado);
		//cin>>teclado;
		if(isInteger(teclado)){
			//cout<<"Es entero"<<endl;
			dev = atoi(teclado.c_str());
			//<<dev<<endl;
		}
		return dev;
	}
	else{
		if(isInteger(str)){
			//cout<<"Es entero"<<endl;
			dev = atoi(str.c_str());
			//<<dev<<endl;
		}
	}
	return dev;
}

bool isInteger(const string & s){//Voy a crear esta función porque atoi da 0 en caso de error, y no siempre eso me vale
	//Ojala entendiese lo que hace, pero funciona bien (parece)
	if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

	char * p ;
	strtol(s.c_str(), &p, 10) ;

	return (*p == 0) ;
}

time_t parseDateToTimeStamp(parsedIntList* parseado){
	time_t date = time(0);
	struct tm* now = localtime(&date);
	now->tm_year = parseado->listadoInt[2] - 1900;
	now->tm_mon = parseado->listadoInt[1] - 1;
	now->tm_mday = parseado->listadoInt[0];
	time_t timeReference = mktime(now);
	return timeReference;
}

void auxTecladoIn(string *teclado, string comodin){
	cout<< comodin << endl;
	cout << "La fecha debe tener el siguiente formato  -->   DD/MM/YYYY"<< endl;
	cin.clear();
	//cin >> *teclado;
	getline(cin, *teclado);
}

parsedIntList* parseIntegerList(string *intList, string delimiter,bool rawParse/*a true solo trocea, sin ordenar*/){
	size_t pos = 0;
	string token;

	string copia = *intList;
	parsedIntList *dev = new parsedIntList();
	int cont = 0;
	//lo parseo una vez para saber cuantos elementos hay y crear un array de ese tamaño
	while ((pos = copia.find(delimiter)) != string::npos) {
		token = copia.substr(0, pos);
		//cout << token << endl;
		copia.erase(0, pos + delimiter.length());
		cont++;
	}

	if(cont == 0){
		dev->listadoStr = new string();
		dev->listadoInt = new int[1];
		dev->listadoStr[0] = copia;
		dev->listadoInt[0] = auxParseInt(copia.c_str(), false);
		dev->listadoSize = 1;
		return dev;
	}
	string *arryStrInt = new string[cont+1];
	int *arryIntInt = new int[cont+1];

	cont = 0;
	copia = *intList;
	while ((pos = copia.find(delimiter)) != string::npos) {
		token = copia.substr(0, pos);
		arryStrInt[cont] = token;
		arryIntInt[cont++] = auxParseInt(token.c_str(), false);
		copia.erase(0, pos + delimiter.length());
	}
	arryStrInt[cont] = copia;
	arryIntInt[cont++] = auxParseInt(copia.c_str(), false);
	dev->listadoStr = arryStrInt;
	dev->listadoSize = cont;
	dev->listadoInt = arryIntInt;
	if(rawParse){
		return dev;
	}

	//El array hay que ordenarlo descendentemente para que no nos afecte cada eliminación con la posición del siguiente Nodo que hay que eliminar, es decir, si primero elimino los
	//primeros, el resto se "desplaza" de posición y entonces no borramos los nodos q ralmete hay que borrar (solo afecta en borrarPorPosicion)

	if(cont>1){
		for(int i=0; i<cont-1; i++){
			for(int k=0; k<cont-1-i; k++){
				//El usuario no debería introducir dos veces la misma posición, si lo hace, lo detecto y pongo el elemento de la derecha [k+1] a un valor opuesto al que tiene
				//al principio lo había puesto a -1, pero poniendo el opuesto, puedo saber que posición repitió
				if(arryStrInt[k].compare(arryStrInt[k+1]) == 0){
					string tmp = "-";
					tmp = tmp.append(arryStrInt[k+1]);
					arryStrInt[k+1] = tmp;
					arryIntInt[k+1] = arryIntInt[k+1]*(-1);
				}
				else if(arryStrInt[k].compare(arryStrInt[k+1]) < 0){
					string temp = arryStrInt[k];
					arryStrInt[k] = arryStrInt[k+1];
					arryStrInt[k+1] = temp;

					int tempInt = arryIntInt[k];
					arryIntInt[k] = arryIntInt[k+1];
					arryIntInt[k+1] = tempInt;
				}
			}
		}
	}

	//cout<<arryStrInt->size();

	//dev->listado = arryStrInt;
	//dev->listadoSize = cont;
	return dev;
}


bool compruebaFecha(parsedIntList *param){
	bool esBisiesto = false;
	if(param->listadoSize != 3){
		return false;
	}

	if(param->listadoInt[2] < 1900 || param->listadoInt[2]>2200){//Un año medianamente "lógico?"
		return false;
	}
	if((param->listadoInt[2]%4 == 0) && ( (param->listadoInt[2]%100 != 0) || (param->listadoInt[2]%400 == 0) ) ){esBisiesto = true;}

	if(param->listadoInt[1] < 1 || param->listadoInt[1] > 12){
		return false;
	}

	switch(param->listadoInt[1]){
	case 1:	case 3:case 5: case 7: case 8: case 10: case 12:
		if(param->listadoInt[0] <1 || param->listadoInt[0] > 31){return false;}
		break;
	case 2:
		if(param->listadoInt[0] <1){return false;}
		if(esBisiesto){
			if(param->listadoInt[0] >29){return false;}
		}
		else{
			if(param->listadoInt[0] >28){return false;}
		}
		break;
	case 4: case 6: case 9: case 11:
		if(param->listadoInt[0] <1 || param->listadoInt[0] > 30){return false;}
		break;
	}
	/*cout<<array[0]<<endl;
	cout<<array[1]<<endl;
	cout<<array[2]<<endl;*/

	return true;
}









