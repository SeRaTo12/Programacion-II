void imprimirUsuarios(int x, int y){ //Esta funcion imprime los datos de todos los Pasajeros
	Usuario *aux = primUser;
	gotoxy(x, y);
	SetConsoleTextAttribute(hCon, 2);
	cout<<"ID "<<setw(15);
	SetConsoleTextAttribute(hCon, 3);
	cout<<"Nombre "<<setw(15);
	SetConsoleTextAttribute(hCon, 4);
	cout<<"Apellido "<<setw(15);
	SetConsoleTextAttribute(hCon, 5);
	cout<<"Sexo "<<setw(15);
	SetConsoleTextAttribute(hCon, 6);
	cout<<"TipoUsuario "<<setw(15);
	SetConsoleTextAttribute(hCon, 7);
	cout<<"Estado "<<setw(15);
	SetConsoleTextAttribute(hCon, 8);
	cout<<"Contrasena"<<endl;
	while(aux!=NULL){
			y+=1;
			gotoxy(x, y);
			SetConsoleTextAttribute(hCon, 2);
			cout<<aux->id_usuario<<setw(15);
			SetConsoleTextAttribute(hCon, 3);
			cout<<aux->nombre<<setw(15);
			SetConsoleTextAttribute(hCon, 4);
			cout<<aux->apellido<<setw(15);
			SetConsoleTextAttribute(hCon, 5);
			if(aux->sexo == hombre){
				cout<<"Hombre"<<setw(15);
			}else{
				cout<<"Mujer"<<setw(15);
			}
			SetConsoleTextAttribute(hCon, 6);
			if(aux->TipoUsuario == pasajero){
				cout<<"Pasajero"<<setw(15);
			}else{
				cout<<"Administrador"<<setw(15);
			}
			SetConsoleTextAttribute(hCon, 7);
			if(aux->estado == activo){
				cout<<"Activo"<<setw(15);
			}else{
				cout<<"Inactivo"<<setw(15);
			}
			SetConsoleTextAttribute(hCon, 8);
			cout<<aux->password<<endl;
			aux = aux->sig;
	}
}

void imprimirPasajeros(int x, int y, int memoria){ //Esta funcion imprime los datos de todos los Pasajeros
	Usuario *aux = primUser;
	gotoxy(x, y);
	SetConsoleTextAttribute(hCon, 2);
	cout<<"ID "<<setw(15);
	SetConsoleTextAttribute(hCon, 3);
	cout<<"Nombre "<<setw(15);
	SetConsoleTextAttribute(hCon, 4);
	cout<<"Apellido "<<setw(15);
	SetConsoleTextAttribute(hCon, 5);
	cout<<"Sexo "<<setw(15);
	SetConsoleTextAttribute(hCon, 6);
	cout<<"TipoUsuario "<<setw(15);
	
	if(memoria == 1){
		SetConsoleTextAttribute(hCon, 7);
		cout<<"Estado "<<setw(15);
		SetConsoleTextAttribute(hCon, 8);
		cout<<"Actual"<<setw(15);
		SetConsoleTextAttribute(hCon, 9);
		cout<<"Siguiente"<<endl;
	}else{
		SetConsoleTextAttribute(hCon, 7);
		cout<<"Estado"<<endl;
	}
	while(aux!=NULL){
		if(aux->TipoUsuario==pasajero){
			y+=1;
			gotoxy(x, y);
			SetConsoleTextAttribute(hCon, 2);
			cout<<aux->id_usuario<<setw(15);
			SetConsoleTextAttribute(hCon, 3);
			cout<<aux->nombre<<setw(15);
			SetConsoleTextAttribute(hCon, 4);
			cout<<aux->apellido<<setw(15);
			SetConsoleTextAttribute(hCon, 5);
			if(aux->sexo == hombre){
				cout<<"Hombre"<<setw(15);
			}else{
				cout<<"Mujer"<<setw(15);
			}
			SetConsoleTextAttribute(hCon, 6);
			if(aux->TipoUsuario == pasajero){
				cout<<"Pasajero"<<setw(15);
			}else{
				cout<<"Administrador"<<setw(15);
			}
			SetConsoleTextAttribute(hCon, 7);
			if(aux->estado == activo){
				if(memoria==1){
					cout<<"Activo"<<setw(15);
				}else{
					cout<<"Activo"<<endl;
				}
				
			}else{
				if(memoria==1){
					cout<<"Inactivo"<<setw(15);
				}else{
					cout<<"Inactivo"<<endl;
				}
				
			}
			if(memoria == 1){
				SetConsoleTextAttribute(hCon, 8);
				cout<<aux<<setw(15);
				SetConsoleTextAttribute(hCon, 9);
				cout<<aux->sig<<endl;
			}
		}
		aux = aux->sig;
	}
}

void imprimirAdmin(int x, int y, int memoria){ //Esta funcion imprime los datos de los administradores
	Usuario *aux = primUser;
	gotoxy(x, y);
	SetConsoleTextAttribute(hCon, 2);
	cout<<"ID "<<setw(15);
	SetConsoleTextAttribute(hCon, 3);
	cout<<"Nombre "<<setw(15);
	SetConsoleTextAttribute(hCon, 4);
	cout<<"Apellido "<<setw(15);
	SetConsoleTextAttribute(hCon, 5);
	cout<<"Sexo "<<setw(15);
	SetConsoleTextAttribute(hCon, 6);
	cout<<"TipoUsuario "<<setw(15);
	if(memoria == 1){
		SetConsoleTextAttribute(hCon, 7);
		cout<<"Estado "<<setw(15);
		SetConsoleTextAttribute(hCon, 8);
		cout<<"Actual"<<setw(15);
		SetConsoleTextAttribute(hCon, 9);
		cout<<"Siguiente"<<endl;
	}else{
		SetConsoleTextAttribute(hCon, 7);
		cout<<"Estado"<<endl;
	}
	while(aux!=NULL){
		if(aux->TipoUsuario==admin){
			SetConsoleTextAttribute(hCon, 2);
			y+=1;
			gotoxy(x, y);
			cout<<aux->id_usuario<<setw(15);
			SetConsoleTextAttribute(hCon, 3);
			cout<<aux->nombre<<setw(15);
			SetConsoleTextAttribute(hCon, 4);
			cout<<aux->apellido<<setw(15);
			SetConsoleTextAttribute(hCon, 5);
			if(aux->sexo == hombre){
				cout<<"Hombre"<<setw(15);
			}else{
				cout<<"Mujer"<<setw(15);
			}
			SetConsoleTextAttribute(hCon, 6);
			if(aux->TipoUsuario == pasajero){
				cout<<"Pasajero"<<setw(15);
			}else{
				cout<<"Administrador"<<setw(15);
			}
			SetConsoleTextAttribute(hCon, 7);
			if(aux->estado == activo){
				if(memoria==1){
					cout<<"Activo"<<setw(15);
				}else{
					cout<<"Activo"<<endl;
				}
				
			}else{
				if(memoria==1){
					cout<<"Inactivo"<<setw(15);
				}else{
					cout<<"Inactivo"<<endl;
				}
				
			}
			if(memoria == 1){
				SetConsoleTextAttribute(hCon, 8);
				cout<<aux<<setw(15);
				SetConsoleTextAttribute(hCon, 9);
				cout<<aux->sig<<endl;
			}
		}
		aux = aux->sig;
	}
}

//Esta funcion imprime los datos del usuario que se le envie
void imprimirDatosUsuario(Usuario *aux){ 
	SetConsoleTextAttribute(hCon, 2);
	cout<<aux->id_usuario<<"\t";
	SetConsoleTextAttribute(hCon, 3);
	cout<<aux->nombre<<"\t";
	SetConsoleTextAttribute(hCon, 4);
	cout<<aux->apellido<<"\t";
	SetConsoleTextAttribute(hCon, 2);
	if(aux->sexo == hombre){
		cout<<"Hombre";
	}else{
		cout<<"Mujer";
	}
	SetConsoleTextAttribute(hCon, 3);
	if(aux->TipoUsuario == pasajero){
		cout<<"Pasajero";
	}else{
		cout<<"Administrador";
	}
	SetConsoleTextAttribute(hCon, 4);
	if(aux->estado == activo){
		cout<<"Activo\t";
	}else{
		cout<<"Inactivo\t";
	}
}

void imprimirEstaciones(int x, int y, int memoria){ //Esta funcion imprime los datos de las estaciones
	Estacion *aux = primEstacion;
	gotoxy(x, y);
	SetConsoleTextAttribute(hCon, 2);
	cout<<"ID "<<setw(10);
	SetConsoleTextAttribute(hCon, 3);
	cout<<"Nombre "<<setw(15);
	SetConsoleTextAttribute(hCon, 4);
	cout<<"Tiempo "<<setw(15);
	if(memoria == 1){
		SetConsoleTextAttribute(hCon, 5);
		cout<<"Estado "<<setw(15);
		SetConsoleTextAttribute(hCon, 6);
		cout<<"Actual"<<setw(15);
		SetConsoleTextAttribute(hCon, 7);
		cout<<"Siguiente"<<endl;
	}else{
		SetConsoleTextAttribute(hCon, 5);
		cout<<"Estado"<<endl;
	}
	if(primEstacion==NULL){
		cout<<"Aun no hay estaciones";
	}else{
		do{
			y+=1;
			gotoxy(x, y);
			SetConsoleTextAttribute(hCon, 2);
			cout<<aux->id_lugar<<setw(10);
			SetConsoleTextAttribute(hCon, 3);
			cout<<aux->nombre<<setw(15);
			SetConsoleTextAttribute(hCon, 4);
			cout<<aux->tiempoAestacion<<setw(15);
			SetConsoleTextAttribute(hCon, 5);
			if(aux->estado == activo){
				if(memoria==1){
					cout<<"Activo"<<setw(15);
				}else{
					cout<<"Activo"<<endl;
				}
				
			}else{
				if(memoria==1){
					cout<<"Inactivo"<<setw(15);
				}else{
					cout<<"Inactivo"<<endl;
				}
				
			}
			if(memoria == 1){
				SetConsoleTextAttribute(hCon, 6);
				cout<<aux<<setw(15);
				SetConsoleTextAttribute(hCon, 7);
				cout<<aux->sig<<endl;
			}
			aux = aux->sig;
		}while(aux != primEstacion);
	}
}

//Esta funcion imprime Todas las rutas
void imprimirRutas(int x, int y, int memoria){ 
	Ruta *aux = primRuta;
	gotoxy(x, y);
	SetConsoleTextAttribute(hCon, 2);
	cout<<"ID"<<setw(10);
	SetConsoleTextAttribute(hCon, 3);
	cout<<"Estado "<<setw(15);
	SetConsoleTextAttribute(hCon, 4);
	cout<<"H.Ini"<<setw(15);
	SetConsoleTextAttribute(hCon, 5);
	cout<<"H.Fin"<<setw(15);
	SetConsoleTextAttribute(hCon, 6);
	cout<<"Prim.E."<<setw(15);
	if(memoria == 1){
		SetConsoleTextAttribute(hCon, 7);
		cout<<"Ult.E. "<<setw(15);
		SetConsoleTextAttribute(hCon, 8);
		cout<<"Actual"<<setw(15);
		SetConsoleTextAttribute(hCon, 9);
		cout<<"Siguiente"<<endl;
	}else{
		SetConsoleTextAttribute(hCon, 7);
		cout<<"Ult.E."<<endl;
	}
	while(aux!=NULL){
		y+=1;
		gotoxy(x, y);
		SetConsoleTextAttribute(hCon, 2);
		cout<<aux->id_ruta<<setw(10);
		SetConsoleTextAttribute(hCon, 3);
		if(aux->estado == activo){
			cout<<"Activa"<<setw(15);
		}else{
			cout<<"Inactiva"<<setw(15);
		}
		SetConsoleTextAttribute(hCon, 4);
		cout<<aux->horaInicio<<setw(15);
		SetConsoleTextAttribute(hCon, 5);
		cout<<aux->horaFin<<setw(15);
		SetConsoleTextAttribute(hCon, 6);
		cout<<aux->primero->nombre<<setw(15);
		if(memoria==1){
			SetConsoleTextAttribute(hCon, 7);
			cout<<aux->ultimo->nombre<<setw(15);
			SetConsoleTextAttribute(hCon, 8);
			cout<<aux<<setw(15);
			SetConsoleTextAttribute(hCon, 9);
			cout<<aux->sig<<endl;
		}else{
			SetConsoleTextAttribute(hCon, 7);
			cout<<aux->ultimo->nombre<<endl;
		}
		
		aux=aux->sig;
	}
}

void imprimirRutaPorId(int idRuta){ //Esta funcion imprime una ruta en especifico, buscada por el id de ruta
	Ruta *aux = primRuta;
	while(aux!=NULL){
		if(aux->id_ruta==idRuta){
			SetConsoleTextAttribute(hCon, 2);
			cout<<aux->id_ruta<<"\t";
			SetConsoleTextAttribute(hCon, 3);
			if(aux->estado == activo){
				cout<<"Activa"<<"\t";
			}else{
				cout<<"Inactiva"<<"\t";
			}
			SetConsoleTextAttribute(hCon, 4);
			cout<<aux->horaInicio<<"\t";
			SetConsoleTextAttribute(hCon, 5);
			cout<<aux->horaFin<<"\t";
			SetConsoleTextAttribute(hCon, 6);
			cout<<aux->primero->nombre<<"\t";
			SetConsoleTextAttribute(hCon, 7);
			cout<<aux->ultimo->nombre<<"\t";
		}
		aux=aux->sig;
	}
}

int imprimirRutasUsuario(int x, int y, Usuario *usuarioActual){ //Esta funcion imprime las rutas del usuario actual
	Usuario *aux = primUser;
	rutasUsuario *auxRuta;
	while(aux!=NULL){//recoremos a todos los usuarios
		if(aux == usuarioActual){//Si el id usuario del aux1 es igual al usuarioActivo
			auxRuta = aux->primero;
			gotoxy(x, y);
			SetConsoleTextAttribute(hCon, 2);
			cout<<"ID"<<"\t";
			SetConsoleTextAttribute(hCon, 3);
			cout<<"Estado"<<"\t";
			SetConsoleTextAttribute(hCon, 4);
			cout<<"H. Ini"<<"\t";
			SetConsoleTextAttribute(hCon, 5);
			cout<<"H.Fin"<<"\t";
			SetConsoleTextAttribute(hCon, 6);
			cout<<"Prim.E."<<"\t";
			SetConsoleTextAttribute(hCon, 7);
			cout<<"Ult.E."<<"\t";
			SetConsoleTextAttribute(hCon, 8);
			cout<<"Dia"<<"\t";
			SetConsoleTextAttribute(hCon, 9);
			cout<<"Hora";
			//Recorremos todos los nodos mediante un segundo auxiliar
			while(auxRuta!=NULL){
				y+=1;
				gotoxy(x, y);
				imprimirRutaPorId(auxRuta->id_ruta);
				cout<<auxRuta->dia<<"\t"<<auxRuta->hora;
				auxRuta=auxRuta->sig; 
			}
			return 0;
		}
		aux = aux->sig;//Recorremos
	}
	return 0;
}

void historial(int x, int y, Usuario *usuarioActual){
	recorridoUsuario *aux = usuarioActual->primRecorrido;
	gotoxy(x, y);
	SetConsoleTextAttribute(hCon, 2);
	cout<<"ID"<<setw(10);
	SetConsoleTextAttribute(hCon, 3);
	cout<<"Id Ruta "<<setw(15);
	SetConsoleTextAttribute(hCon, 4);
	cout<<"Estado "<<setw(15);
	SetConsoleTextAttribute(hCon, 5);
	cout<<"Estacion Subida"<<setw(20);
	SetConsoleTextAttribute(hCon, 6);
	cout<<"Estacion Bajada."<<setw(20);
	SetConsoleTextAttribute(hCon, 7);
	cout<<"Hora subida"<<setw(15);
	SetConsoleTextAttribute(hCon, 8);
	cout<<"Hora bajada"<<endl;
	while(aux!=NULL){
		y+=1;
		gotoxy(x, y);
		SetConsoleTextAttribute(hCon, 2);
		cout<<aux->idRecorrido<<setw(10);
		SetConsoleTextAttribute(hCon, 3);
		cout<<aux->idRuta<<setw(15);
		SetConsoleTextAttribute(hCon, 4);
		if(aux->estado== siSubio){
			cout<<"Subio"<<setw(15);
		}else{
			cout<<"No subio"<<setw(15);
		}
		SetConsoleTextAttribute(hCon, 5);
		cout<<aux->estacionSubida<<setw(20);
		SetConsoleTextAttribute(hCon, 6);
		cout<<aux->estacionBajada<<setw(20);
		SetConsoleTextAttribute(hCon, 7);
		cout<<aux->horaSubida[0]<<":"<<aux->horaSubida[1]<<setw(15);
		SetConsoleTextAttribute(hCon, 8);
		cout<<aux->horaBajada[0]<<":"<<aux->horaBajada[1]<<endl;
		aux=aux->sig;
	}
}
