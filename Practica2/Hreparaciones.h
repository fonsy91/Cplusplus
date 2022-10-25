#ifndef HREPARACIONES_H
#define HREPARACIONES_H
#include <stddef.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int ORDEN_FECHA = 1;
const int ORDEN_COSTE = 2;
const int ORDEN_FECHA_COSTE = 3; //En caso de igual fecha ordena por coste
const int ORDEN_COSTE_FECHA = 4; //En caso de igual coste ordena por fecha
const int ORDEN_TIPO = 5;

const int SEG_ANIO = 31536000;
const int SEG_MES = 2592000;
const int SEG_DIA = 86400;

enum tipoRep{Nula=0 , Revision=1, CambioAceite=2, CambioFiltros=3, Carga_Aire=4, CambioRuedas=5, Bateria=6, Distribucion=7, JuntaCulata=8, Embrague=9, Otros=10 };
const char* tipoRepStr[] = {"Nula","Revisión", "Cambio de aceite", "Cambio de filtros", "Carga de Aire Acondicionado", "Cambio de Ruedas",
		"Cambio de batería", "Correa de distribución", "Junta de culata", "Cambio de embrague", "Otros"};
const int precioRep[] = {0, 50, 30, 80, 30, 200, 100, 400, 600, 900};

struct Reparacion {
	time_t fecha;
	tipoRep tipo_rep;
	int coste;
	int idRep;//ya que hemos creado una función que elimina por posición, esta variable podrá ser útil.

	string getFechaStr(){
		struct tm * now = localtime( &fecha );
		stringstream ss;
		ss << (int)now->tm_mday<< "/" << (int)(now->tm_mon+1) << "/" << (int)(now->tm_year + 1900);
		string str = ss.str();
		return str.c_str();
		//return ctime(&fecha);
	}
	//Esta función modifica  de una forma aleatoria el contenido de la estructura, usada para inicializar las reparaciones de forma aleatoria.
	void randomizaRep(){
		//Primero generamos una fecha aleatoria que parte de la fecha en que se inicializo (epoca UNIX)
		//Se podría mejorar bastante el algoritmo pero no creo que la práctica esté centrada en estos menesteres y el tiempo no sobra, mejor usarlo
		//en mejorar o ampliar algunas funcionalidades más útiles en cuanto a listas y árboles (si es que nos da tiempo al final)
		time_t t = time(0);   // get time now
		//cout<<"Tiempo ahora: "<<t<<endl;
		do{
			fecha = 0;
			//Sumamos cierta cantidad de años
			fecha += getRandomNumber(0, 2016-1970) * SEG_ANIO; //TODO mirar si hay que restar 1 al 2016-1970;
			//Sumamos cierta cantidad de meses
			fecha += getRandomNumber(0,11)*SEG_MES;
			//Sumamos cierta cantidad de días, esperemos no caiga en domingo xdd, aunque no me voy a complicar la vida
			fecha += getRandomNumber(0,30)*SEG_DIA;
			cout << "Fecha: "<< getFechaStr()<<endl;
		}while(t<fecha);

		//Lo siguiente es aleatorizar el tipo de reparación
		switch(getRandomNumber(1,10)){
		case 1:
			tipo_rep = Revision;
			break;
		case 2:
			tipo_rep = CambioAceite;
			break;
		case 3:
			tipo_rep = CambioFiltros;
			break;
		case 4:
			tipo_rep = Carga_Aire;
			break;
		case 5:
			tipo_rep = CambioRuedas;
			break;
		case 6:
			tipo_rep = Bateria;
			break;
		case 7:
			tipo_rep = Distribucion;
			break;
		case 8:
			tipo_rep = JuntaCulata;
			break;
		case 9:
			tipo_rep = Embrague;
			break;
		case 10:
			tipo_rep = Otros;
			break;
		default:
			return;
		}
		cout<<"Tipo de reparación: "<<tipoRepStr[tipo_rep]<<endl;

		//ahora el coste

		coste = (tipo_rep == Otros)?getRandomNumber(30,1500):precioRep[tipo_rep];
		cout<<"Coste: "<<coste<<endl<<endl;
	}
}typedef Reparacion;

/******************************************************************/
//Esta estructura me sirve para ser devuelta a la llamada de un método que recibe un string, lo trocea en un array de strings y lo guarda en esta estructura junto con el número de elementos del array
struct parsedIntList{
	string *listadoStr;
	int *listadoInt;
	int listadoSize;
}typedef parIntList;


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

class Hreparaciones{
    public:
	HRep();
	~HRep();
	void insertar(bool isRandom);
	void eliminar();
	bool esVacio();
	NodoRep *getPrimero();
	int getNumRep();
	void listarRep();
	void interfaceBuscar();
	void ordenar(int tipo_Ordenamiento, bool isDescdendente);
	//HRep* listar
private:
	int nextId;
	NodoRep *primero;
	void insertar(Reparacion* p_rep);
	NodoRep* eliminar(int numRep);
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
	bool isInteger(const string &s);
	parsedIntList* parseIntegerList(string *intList, string delimiter, bool rawParse);
	bool compruebaFecha(parsedIntList *param);
	bool eliminarPorFecha(bool dev, parsedIntList* parseado, bool menores, bool informe, bool oIguales);
	void auxTecladoIn(string *teclado, string comodin);
	int auxParseInt(string str);
	void setPrimero(NodoRep *param);
	void imprimeRep(int cont, Reparacion* rep);
	time_t parseDateToTimeStamp(parsedIntList* parseado);
};

#endif // HREPARACIONES_H
