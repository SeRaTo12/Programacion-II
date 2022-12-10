int modificarEstacion(){
	int opc=0;
	int estado=0;
	Estacion *aux = primEstacion;
	string nombre="";
	int numEstacion=0;
	gotoxy(35, 5);
	cout<<"Modificar:";
	gotoxy(35, 6);
	cout<<"1.-Nombre";
	gotoxy(35, 7);
	cout<<"2.-Estado";
	gotoxy(35, 8);
	cout<<"0.-Regresar";
	
	do{
		gotoxy(35, 9);
		opc = validaEntero();
		if(opc==0){
			return 0;
		}
	}while(opc>2 || opc<1);
	
	imprimirEstaciones(35,10, 0);
	gotoxy(35, 20);
	cout<<"Cual numero de estacion que quieres modificar? ";
	numEstacion=validaEntero();
	system("cls");
	caja();
	SetConsoleTextAttribute(hCon, 14);
	do{
		if(aux->id_lugar == numEstacion){
			switch(opc){
				case 1:
					gotoxy(35, 5);
					cout<<"Cual es el nuevo nombre de la estacion? ";
					cin>>nombre;
					aux->nombre = nombre;
					gotoxy(35, 7);
					cout<<"Nombre de la estacion actualizado excitosamente!";
					Sleep(3000);
					return 0;
					break;
				case 2:
					gotoxy(35, 5);
					if(aux->estado==activo){
						cout<<"1.-Desactivar"<<endl;
					}else{
						cout<<"1.-Activar"<<endl;
					}
					estado=validaEntero();
					if(aux->estado==activo){
						aux->estado=inactivo;
					}else{
						aux->estado=activo;
					}
					gotoxy(35, 7);
					cout<<"Estado actualizado excitosamente!"<<endl;
					Sleep(3000);
					return 0;
					break;
			}
		}else{
			aux = aux->sig;
		}	
	}while(aux!=primEstacion);
	
	cout<<"No se encontro la estación"<<endl;
	return 0;
}

void modificarRuta(){
	int opcRuta = 0;
	int opcModificar = 0;
	int valor = 0;
	Ruta *modifica = primRuta;
	Estacion *aux = primEstacion;
	imprimirRutas(15,5, 0);
	
	do{
		gotoxy(35, 15);
		cout<<"Que ruta modificar?";
		opcRuta=validaEntero();
		if(opcRuta<primRuta->id_ruta || opcRuta>ultRuta->id_ruta) cout<<"Ruta no existente"<<endl;
	}while(opcRuta<primRuta->id_ruta || opcRuta>ultRuta->id_ruta);
	system("cls");
	caja();
	SetConsoleTextAttribute(hCon, 14);
	gotoxy(35, 5);
	cout<<"Que quieres modificar?";
	gotoxy(35, 6);
	cout<<"1.- Estado";
	gotoxy(35, 7);
	cout<<"2.- Hora Inicio";
	gotoxy(35, 8);
	cout<<"3.- Hora Fin";
	gotoxy(35, 9);
	cout<<"4.- Primera Estacion";
	gotoxy(35, 10);
	cout<<"5.- Ultima Estacion";
	do{
		gotoxy(35, 11);
		opcModificar=validaEntero();
	}while(opcModificar<1 || opcModificar > 5);
	for(int i=1;i<opcRuta;i++){
		modifica = modifica->sig;
	}
	switch(opcModificar){
		case 1:
			do{
				gotoxy(35, 12);
				cout<<"Ingresa el estado. 0 Inactivo, 1 Activo ";
				valor=validaEntero();
			}while(valor<0 || valor > 1);
			modifica->estado=valor;
			break;
		case 2:
			do{
				gotoxy(35, 12);
				cout<<"Ingresa la hora de inicio ";
				valor=validaEntero();
			}while(valor<0 || valor>24);
			modifica->horaInicio=valor;
			break;
		case 3:
			do{
				gotoxy(35, 12);
				cout<<"Ingresa la hora de fin ";
				valor=validaEntero();
			}while(valor<0||valor>24);
			modifica->horaFin=valor;
			break;
		case 4:
			system("cls");
			caja();
			SetConsoleTextAttribute(hCon, 14);
			imprimirEstaciones(35,5, 0);
			do{
				gotoxy(35, 15);
				cout<<"Ingresa la primer estacion ";
				valor=validaEntero();
			}while(valor<primEstacion->id_lugar||valor>primEstacion->id_lugar);
			while(valor!=aux->id_lugar){ //Avanzamos con aux a la que sera la primera estacion y la asignamos
				aux=aux->sig;
			}
			modifica->primero = aux;
			break;
		case 5:
			system("cls");
			caja();
			SetConsoleTextAttribute(hCon, 14);
			imprimirEstaciones(35,5,0);
			do{
				gotoxy(35, 15);
				cout<<"Ingresa la ultima estacion ";
				valor=validaEntero();
			}while(valor<primEstacion->id_lugar||valor>primEstacion->id_lugar);
			while(valor!=aux->id_lugar){ //Avanzamos con aux a la que sera la primera estacion y la asignamos
				aux=aux->sig;
			}
			modifica->ultimo = aux;
			break;
	}
}

int modificarRutaUsuario(){
	rutasUsuario *modifica = usuarioActivo->primero;
	int opcRuta;
	int opc2;
	int valor;
	bool encontrado=false;
	 
	while(!encontrado){ //Mientras no encuentre la ruta seguira en el while
	 	encontrado=true;
	 	system("cls");
	 	caja();
	 	SetConsoleTextAttribute(hCon, 14);
	 	gotoxy(35, 5);
		cout<<".- MODIFICAR MIS RUTAS -.";
		imprimirRutasUsuario(15,6,usuarioActivo);
		gotoxy(35, 15);
		cout<<"Que ruta quieres modificar? ";
		cout<<" 0.- Salir";
		gotoxy(35, 16);
		cout<<"Opc: ";
		opcRuta=validaEntero(); //Leemos la ruta del usuario
		if(opcRuta==0){
	 		return 0;
		}
	 	
	 	modifica=usuarioActivo->primero; //situamos el apuntador modifica en la primer ruta del usuario
	 	while(opcRuta!=modifica->id_ruta && modifica!=NULL){ //Con este while recorremos las rutas que tiene el usuario, 
	 	//Mientras la id de la ruta modificar sea diferente a la que pidio el usuario y sea diferente de null
		 	modifica=modifica->sig;//Cambia a la siguiente ruta que tenga guardada el usuario
		 	if(modifica==NULL){ //Si la ruta es NULL deja de buscar
		 		gotoxy(35, 17);
		 		cout<<"Ruta no encontrada"<<endl;
		 		break;
			}
		}
		if(modifica==NULL){  //Si la modifica es NULL entonces no encontro nada, encontrado es false y vuelve a preguntar la ruta que quiera el usuario
		 	encontrado = false;
		}
	}
	system("cls");
	caja();
	SetConsoleTextAttribute(hCon, 14);
	gotoxy(35, 5);
	cout<<"Que quieres modificar?"; 
	gotoxy(35, 6);
	cout<<"1.- Dia de abordaje";
	gotoxy(35, 7);
	cout<<"2.- Hora de abordaje"<<endl;
	do{
		gotoxy(35, 8);
	 	opc2=validaEntero();
	}while(opc2<1||opc2>2);
	switch(opc2){
	 	case 1:
	 		do{
	 			gotoxy(35, 9);
				cout<<"¿Que dia la vas a tomar? (1-30) ";
				valor=validaEntero();
			}while(valor>30 || valor<1);
			modifica->dia=valor;
	 		break;
	 	case 2:
	 		do{
	 			gotoxy(35, 9);
				cout<<"¿A que hora lo vas a tomar? (1-24) ";
				valor=validaEntero();
			}while(valor>24 || valor<1);
			modifica->hora=valor;
	 		break;
	}
	gotoxy(35, 11);
	cout<<"¡LA RUTA SE MODIFICO EXITOSAMENTE!";
	Sleep(3000);
	return 0;
}

int modificarUsuario(Usuario *user){
	int seguir = 0;
	int opc=0;
	int numUsuario = 0;
	bool bandera = true;
	string password1, password2;
	
	if(user==NULL){
		user=primUser;
	}
	system("cls");
	caja();
	SetConsoleTextAttribute(hCon, 14);
	imprimirUsuarios(15, 5);
	
	do{
		gotoxy(35, 20);
		cout<<"Cual ID del usuario que quieres modificar? ";
		numUsuario=validaEntero();
	}while(numUsuario>ultUser->id_usuario || numUsuario<primUser->id_usuario);	
	
	do{
		if(user->id_usuario == numUsuario){
			system("cls");
			caja();
			SetConsoleTextAttribute(hCon, 14);
			gotoxy(35, 5);
			cout<<"Usuario";
			gotoxy(25, 6);
			imprimirDatosUsuario(user);
			//Presentamos el 
			gotoxy(35, 7);
			cout<<"Modificar:";
			gotoxy(35, 8);
			cout<<"1.-Nombre";
			gotoxy(35, 9);
			cout<<"2.-Apellidos";
			gotoxy(35, 10);
			cout<<"3.-Sexo";
			gotoxy(35, 11);
			cout<<"4.-Contrasena";
			gotoxy(35, 12);
			if(usuarioActivo->TipoUsuario==admin){
				gotoxy(35, 13);
				cout<<"5.-Estado";
			}
			gotoxy(35, 14);
			cout<<"0.-Regresar"<<endl;
		
			do{
				gotoxy(35, 15);
				opc = validaEntero();
				if(opc==0){
					return 0;
				}
			}while(opc>5 || opc<1);	
			system("cls");
			caja();
			SetConsoleTextAttribute(hCon, 14);
			switch(opc){
				case 1:
					//Modificar nombre
					gotoxy(35, 5);
					cout<<"Cual es el nuevo nombre?";
					gotoxy(35, 6);
					cout<<user->nombre<<" => ";
					cin>>user->nombre;
					gotoxy(35, 7);
					cout<<"NOMBRE ACTUALIZADO CORRECTAMENTE!";
					break;
				case 2:
					//Modificar nombre
					gotoxy(35, 5);
					cout<<"Cual es el nuevo apellido?";
					gotoxy(35, 6);
					cout<<user->apellido<<" => ";
					cin>>user->apellido;
					gotoxy(35, 7);
					cout<<"APELLIDO ACTUALIZADO CORRECTAMENTE!";
					break;
				case 3:
					gotoxy(35, 5);
					cout<<"Cual es el nuevo sexo?";
					gotoxy(35, 6);
					cout<<"Actual: ";
					if(user->sexo==hombre){
						cout<<"Hombre";
					}else{
						cout<<"Mujer";
					}
					gotoxy(35, 7);
					cout<<"Nuevo:";
					gotoxy(35, 8);
					cout<<"1.-Hombre"<<endl;
					gotoxy(35, 9);
					cout<<"0.-Mujer"<<endl;
					do{
						gotoxy(35, 10);
						user->sexo=validaEntero();
					}while(user->sexo>1 || user->sexo<0);
					gotoxy(35, 11);
					cout<<"SEXO ACTUALIZADO CORRECTAMENTE!";
					break;
				case 4:
					do{
						bandera = true;
						gotoxy(35, 5);
						cout<<"Ingresa nuevo password: ";
						cin>>password1;
						gotoxy(35, 6);
						cout<<"Confirma tu password: ";
						cin>>password2;
						
						if(password1!=password2){ 
							//Hacemos una pequeña confirmacion de password
							gotoxy(35, 7);
							cout<<"Los password no coinciden!, intenta nuevamente";
							bandera = false;
						}
					}while(bandera == false);
					user->password = password1;
					gotoxy(35, 8);
					cout<<"CONTRASEÑA ACTUALIZADA CORRECTAMENTE!";
					break;
				if(user->TipoUsuario==admin){
					case 5:
						gotoxy(35, 5);
						cout<<"Cual es el nuevo estado?"<<endl;
						gotoxy(34, 6);
						cout<<"Actual: ";
						if(user->estado==activo){
							cout<<"Activo";
						}else{
							cout<<"Inactivo";
						}
						gotoxy(35, 7);
						cout<<"Nuevo:";
						gotoxy(35, 8);
						cout<<"1.-Activo";
						gotoxy(35, 9);
						cout<<"0.-Inactivo";
						do{
							gotoxy(35, 10);
							user->estado=validaEntero();
						}while(user->estado>1 || user->estado<0);
						gotoxy(35, 11);
						cout<<"ESTADO ACTUALIZADO CORRECTAMENTE!";
						break;
				}
			}
			gotoxy(35, 15);
			cout<<"Continuar Modificando? 1=SI, Otro=NO... ";
			seguir=validaEntero();
			if(seguir!=1){
				break;
			}
		}else{
			user = user->sig;
		}	
	}while(user!=NULL);
	return 0;
}
