#include "librerias.h"
int main(){
	/*
	*
	*	UNIVERSIDAD POLITÉCNICA DE SAN LUIS POTOSÍ
	*
	*	Equipo:
	*		Rivera Carreon Brian Issai - 178481
	*		Rodriguez Torres Sebastián - 179287
	*
	*	Fecha: 23 de Noviembre de 2022
	*	Materia: Programación II
	*	Semestre: Tercer Semestre
	*	Profesora: Guadalupe Ledesma Ramos
	*
	*/
	
	//Usuario Dios
	Usuario *root = new Usuario;
	root->id_usuario = 0;
	root->estado = activo;
	root->password = "admin";
	root->TipoUsuario = admin;
	
	primEstacion = NULL;
	ultEstacion = NULL;
	primRuta = NULL;
	ultRuta = NULL;
	primUser = NULL;
	ultUser = NULL;
	
	//Debemos leer los archivos de rutas, usuarios y estaciones
	leerUsuarios();
	leerEstaciones();
	leerRutasGlobales();
	presentacion();
	getchar();
	system("cls");
	
	if(!inicio(root)){
		gotoxy(35, 25);
		cout<<"Saliendo...";
		escribirUsuarios();	
		return 0;
	}
	printf("\a");
	
	menuPrincipal();
	
	getchar();
	
	if(usuarioActivo->TipoUsuario==pasajero){
		escribirRutasUsuario(usuarioActivo);
		escribirRecorridoUsuario(usuarioActivo);	
	}
	
	escribirUsuarios();
	escribirEstaciones();
	escribirRutasGlobales();
	return 0;
}
