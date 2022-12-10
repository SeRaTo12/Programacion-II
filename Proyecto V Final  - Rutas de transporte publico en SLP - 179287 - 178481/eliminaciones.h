int eliminarRutasUsuario(){
	rutasUsuario *aux = new rutasUsuario;
	bool bandera=false;
	int opc=0;
	system("cls");
	caja();
	SetConsoleTextAttribute(hCon, 14);
	gotoxy(35, 5);
	cout<<".- ELIMINAR MIS RUTAS -.";
	gotoxy(35, 6);
	cout<<"Tus rutas son: ";
	imprimirRutasUsuario(15,7,usuarioActivo);
	do{
		gotoxy(35, 15);
		cout<<"Cual Ruta quieres eliminar?";
		cout<<" 0.-Regresar";
		gotoxy(35, 16);
		cout<<"Id de la ruta: ";
		//Leemos el dato ingresado
		opc = validaEntero();
		if(opc==0){ //En caso de ser cero terminamos la función
			return 0;
		}
		//Reiniciamos la variable de las rutas del usuario 
		aux = usuarioActivo->primero;
		while(aux!=NULL){
			if(opc==aux->id_ruta){
				bandera = true; //Si encuentra la ruta registrada en las rutas del usuario cambiamos la bandera a true
				break;
			}
			aux=aux->sig;
		}
	}while(bandera==false);
	
	if(aux!=NULL){
		if(aux->prev == NULL && aux->sig==NULL){ //Es la unica ruta
			free(aux);
			aux=NULL;
		}else{
			if(aux->prev == NULL && aux->sig!=NULL){ //En caso de ser la primera ruta
				usuarioActivo->primero = aux->sig;
				free(aux);
				aux=NULL;
			}else{
				if(aux->prev != NULL && aux->sig==NULL){ //En caso de ser la ultima ruta
					usuarioActivo->ultimo = aux->prev;
					free(aux);
					aux=NULL;
				}else{
					if(aux->prev != NULL && aux->sig!=NULL){ //Es un nodo intermedio
						aux->prev->sig = aux->sig;
						aux->sig->prev = aux->prev;						
					}
				}
			}
		}
	}
	gotoxy(35, 17);
	cout<<"RUTA ELIMINADA EXITOSAMENTE!";
	Sleep(3000);
	return 0;
}
