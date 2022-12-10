//Librerias
//#include <conio.h>
#include <iostream>//cout, cin, fixed, endl
#include <stdlib.h>//malloc
#include <iomanip>//setw
#include <locale.h>//setlocale
#include <windows.h>//SetConsole
#include <string>//string
#include <fstream>
#include <sstream>

#define hombre 1
#define mujer 0
#define activo 1
#define inactivo 0
#define admin 1
#define pasajero 0
#define siSubio 1
#define noSubio 0

using namespace std;

//Lista circular
struct Estacion{
	int id_lugar; //Auto incremental
	string nombre;
	//Variable que guarda un tiempo que hay entre la anterior parada y esta
	int tiempoAestacion; 
	int estado;
	Estacion *sig;
}*primEstacion,*ultEstacion;

//Lista simple de listas circulares
struct Ruta{
	int id_ruta; //Auto incremental
	int estado;
	int horaInicio;
	int horaFin;
	//Lista Simple
	Estacion *primero, *ultimo; //Destino y origen
	Ruta *sig;//Recorer las rutas
}*primRuta,*ultRuta; //Rutas existentes

struct rutasUsuario{
	int id_ruta;
	int dia;
	int hora;
	rutasUsuario *sig, *prev;
};

//Lista simple
struct recorridoUsuario{
	int idRecorrido; //Auto incremental
	int idRuta;
	//Con esta variable evaluamos si el usuario tomo la ruta o no subio
	int estado;
	int estacionSubida;
	int estacionBajada;
	/*horaSubida y horaBajada son arreglos 
		bidimensionales para guardar horas y minutos*/
	int horaSubida[2];
	int horaBajada[2];
	recorridoUsuario *sig;
};

//Lista de listas simple
struct Usuario{
	int id_usuario; //Auto incremental
	string nombre;
	string apellido;
	int TipoUsuario;
	string password;
	int sexo;
	int estado;
	//Rutas registradas por usuario
	rutasUsuario *primero=NULL, *ultimo=NULL; //lista de rutas
	recorridoUsuario *primRecorrido=NULL, *ultRecorrido=NULL; //Lista simple
	Usuario *sig;//para recorrer todos los usuarios
}*primUser,*ultUser;

Usuario *usuarioActivo=NULL;

#include "validaciones.h"
#include "presentacion.h"
#include "impresiones.h"
#include "eliminaciones.h"
#include "modificaciones.h"

#include "registros.h"

#include "archivos.h"
#include "menus.h"
#include "logeo.h"

