void menuAdmin(){
	int opc = 0;
	int seguir = 1;
	int memoria = 0;
	Usuario *aux = new Usuario;
	aux = NULL;
	do{
		printf("\a");
		system("cls");
		caja();
		SetConsoleTextAttribute(hCon, 11);
		gotoxy(35, 5);
		cout<<".- MENU DE ADMINISTRADOR -.";
		SetConsoleTextAttribute(hCon, 14);
		gotoxy(35, 6);
		cout<<"Bienvenid@ administrador/a "<<usuarioActivo->nombre;
		gotoxy(35, 7);
		cout<<"1.-Registrar";
		gotoxy(35, 8);
		cout<<"2.-Ver";
		gotoxy(35, 9);
		cout<<"3.-Modificar";
		gotoxy(35, 10);
		cout<<"0.-Salir";
		
		do{
			gotoxy(35, 11);
			opc = validaEntero();
		}while(opc>3 || opc<0);
		
		if(opc==0){
			system("cls");
			break;
		}
		
		cout<<endl;
		switch(opc){
			case 1:
				printf("\a");
				do{
					do{
						system("cls");
						caja();
						SetConsoleTextAttribute(hCon, 11);
						gotoxy(35, 5);
						cout<<"REGISTROS";
						SetConsoleTextAttribute(hCon, 14);
						gotoxy(35, 6);
						cout<<"1.-Registrar Estacion";
						gotoxy(35, 7);
						cout<<"2.-Registrar Ruta";
						gotoxy(35, 8);
						cout<<"3.-Registrar Usuario/Administrador";
						gotoxy(35, 9);
						cout<<"0.-Salir";
						gotoxy(35, 10);
						opc = validaEntero();
					}while(opc>3 || opc<0);
					if(opc==0){
						break;
					}
					switch(opc){
						case 1:
							cout<<endl;
							registrarEstacion();
							break;
						case 2:
							cout<<endl;
							registrarRuta();
							break;
						case 3:
							cout<<endl;
							registrarUser(usuarioActivo);
							break;
					}
				}while(true);
				break;
			case 2:
				printf("\a");
				do{
					do{
						system("cls");
						caja();
						SetConsoleTextAttribute(hCon, 11);
						gotoxy(35, 5);
						cout<<"CONSULTAS";
						SetConsoleTextAttribute(hCon, 14);
						gotoxy(35, 6);
						cout<<"1.-Ver todos los Pasajeros";
						gotoxy(35, 7);
						cout<<"2.-Ver todos los Administradores";
						gotoxy(35, 8);
						cout<<"3.-Ver todas las Estaciones";
						gotoxy(35, 9);
						cout<<"4.-Ver todas las Rutas";
						gotoxy(35, 10);
						cout<<"0.-Salir";
						gotoxy(35, 11);
						opc = validaEntero();
					}while(opc>4 || opc<0);
					if(opc==0){
						break;
					}
					do{
						gotoxy(35, 12);
						cout<<"Ver direcciones de memoria? 1: si, 0:No ";
						memoria=validaEntero();
					}while(memoria>1 || memoria<0 );
					system("cls");
					caja();
					SetConsoleTextAttribute(hCon, 14);
					switch(opc){
						case 1:
							printf("\a");
							gotoxy(15, 5);
							cout<<"PASAJEROS:";
							if(memoria==1){
								imprimirPasajeros(8, 6, memoria);
							}else{
								imprimirPasajeros(15, 6, memoria);
							}
							SetConsoleTextAttribute(hCon, 14);
							gotoxy(35, 20);
							cout<<"1.-Ver rutas de usuario";
							gotoxy(35, 21);
							cout<<"2.-Ver historial de usuario";
							gotoxy(35, 22);
							cout<<"0.-Regresar";
							do{
								gotoxy(35, 23);
								opc = validaEntero();
							}while(opc>2 || opc<0);
							if(opc==0){
								break;
							}else{
								if(opc==1){
									printf("\a");
									do{
										gotoxy(35, 24);
										cout<<"Cual es el id del usuario? ";
										opc = validaEntero();
									}while(opc>ultUser->id_usuario || opc<primUser->id_usuario);
									system("cls");
									caja();
									SetConsoleTextAttribute(hCon, 14);
									aux=primUser;
									while(aux!=NULL){
										if(aux->id_usuario==opc){
											aux->primero=NULL;
											leerRutasUsuario(aux);
											
											
											
											gotoxy(25, 5);
											cout<<"Rutas del usuario N."<<aux->id_usuario;
											imprimirRutasUsuario(25, 6,aux);
											gotoxy(35, 24);
											getchar();
											system("pause");
											break;
										}
										aux = aux->sig;
									}
									break;
								}else{
									
									if(opc==2){
										printf("\a");
										do{
											gotoxy(35, 24);
											cout<<"Cual es el id del usuario? ";
											opc = validaEntero();
										}while(opc>ultUser->id_usuario || opc<primUser->id_usuario);
										system("cls");
										caja();
										SetConsoleTextAttribute(hCon, 14);
										aux = primUser;
										while(aux!=NULL){
											if(aux->id_usuario==opc){
												aux->primRecorrido=NULL;
												aux->primero=NULL;
												leerRecorridoUsuario(aux);
												leerRutasUsuario(aux);
												historial(15, 5,aux);
												gotoxy(35, 24);
												getchar();
												system("pause");
												break;
											}
											aux = aux->sig;
										}
										break;
									}
								}
							}
							
							
							break;
						case 2:
							printf("\a");
							gotoxy(15, 5);
							cout<<"ADMINISTRADORES:";
							if(memoria==1){
								imprimirAdmin(8, 6, memoria);	
							}else{
								imprimirAdmin(15, 6, memoria);
							}
							SetConsoleTextAttribute(hCon, 14);
							gotoxy(35, 25);
							system("pause");
							break;
						case 3:
							printf("\a");
							gotoxy(35, 5);
							cout<<"ESTACIONES:";
							if(memoria==1){
								imprimirEstaciones(28, 6, memoria);	
							}else{
								imprimirEstaciones(35, 6, memoria);
							}
							SetConsoleTextAttribute(hCon, 14);
							gotoxy(35, 20);
							system("pause");
							break;
						case 4:
							printf("\a");
							gotoxy(25, 5);
							cout<<"RUTAS:";
							if(memoria==1){
								imprimirRutas(12, 6, memoria);	
							}else{
								imprimirRutas(25, 6, memoria);
							}
							SetConsoleTextAttribute(hCon, 14);
							gotoxy(35, 20);
							system("pause");
							break;
					}
				}while(true);
				break;
			case 3:
				printf("\a");
				do{
					do{
						system("cls");
						caja();
						SetConsoleTextAttribute(hCon, 11);
						gotoxy(35, 5);
						cout<<"MODIFICACIONES";
						SetConsoleTextAttribute(hCon, 14);
						gotoxy(35, 6);
						cout<<"1.-Estacion";
						gotoxy(35, 7);
						cout<<"2.-Ruta";
						gotoxy(35, 8);
						cout<<"3.-Usuario";
						gotoxy(35, 9);
						cout<<"4.-Administrador";
						gotoxy(35, 10);
						cout<<"0.-Salir";
						gotoxy(35, 11);
						opc = validaEntero();
					}while(opc>4 || opc<0);
					if(opc==0){
						break;
					}
					system("cls");
					caja();
					SetConsoleTextAttribute(hCon, 14);
					switch(opc){
						case 1:
							printf("\a");
							modificarEstacion();
							break;
						case 2:
							printf("\a");
							modificarRuta();
							break;
						case 3:
							printf("\a");
							modificarUsuario(NULL);
							break;
						case 4:
							printf("\a");
							modificarUsuario(NULL);
							break;
					}
				}while(true);
				break;
		}
		
	}while(true);
	
}

int menuAutobus(){
	rutasUsuario *ruta = new rutasUsuario;
	ruta = usuarioActivo->primero;
	Estacion *auxEstacion = NULL;
	int opcRuta=0;
	int tiempo=0, t1=0;
	float t2=0;
	int opc=0;
	bool encontrado=false;
	printf("\a");
	printf("\a");
	while(!encontrado){ //Mientras no encuentre la ruta seguira en el while
	 	encontrado=true;
	 	system("cls");
	 	caja();
	 	SetConsoleTextAttribute(hCon, 14);
	 	gotoxy(35, 5);
		cout<<"Tus rutas:";
		imprimirRutasUsuario(35,6,usuarioActivo);
		gotoxy(35, 15);
		cout<<"Cual ruta es?";
		cout<<" 0.-Falsa Alarma"<<endl;
		gotoxy(35, 16);
		cout<<"Opc: ";
		opcRuta=validaEntero();
		if(opcRuta==0){
			return 0;
		}
	 	
		ruta=usuarioActivo->primero; //situamos el apuntador modifica en la primer ruta del usuario
		while(ruta!=NULL && opcRuta!=ruta->id_ruta ){
	 	//Mientras la id de la ruta sea diferente a la que pidio el usuario y sea diferente de null
			ruta=ruta->sig;//Cambia a la siguiente ruta que tenga guardada el usuario
			if(ruta==NULL){
				gotoxy(35, 17);	
				cout<<"Ruta no encontrada"<<endl;
		 		Sleep(2000);
				encontrado = false;
		 		break;
			}
		}
	}
	
	Ruta *auxRuta = primRuta;
		
	while(auxRuta!=NULL){
		if(auxRuta->id_ruta == ruta->id_ruta){ //Nos posicionamos en la ruta que tomo el usuario
			break;
		}
		auxRuta = auxRuta->sig;
	}
	if(auxRuta->estado==inactivo){
		gotoxy(35, 17);
		cout<<"LA RUTA N."<<auxRuta->id_ruta<<" ESTA INACTIVA";
		return 0;
	}
	//El programa llega a este punto con la ruta a la que se subio
	//"ruta" se queda con el valor de la ruta actual
	
	recorridoUsuario *recorridoActual = new recorridoUsuario;
	recorridoActual->horaSubida[0]=0;
	recorridoActual->horaSubida[1]=0;
	recorridoActual->horaBajada[0]=0;
	recorridoActual->horaBajada[1]=0;
	recorridoActual->idRuta= ruta->id_ruta;
	recorridoActual->sig=NULL;
	if(usuarioActivo->primRecorrido == NULL){
		recorridoActual->idRecorrido = 1;
	}else{
		recorridoActual->idRecorrido = usuarioActivo->ultRecorrido->idRecorrido+1;
	}
	
	do{
		printf("\a");
		system("cls");
		caja();
		SetConsoleTextAttribute(hCon, 14);
		gotoxy(35, 5);
		cout<<"Quieres subir a la ruta N."<<ruta->id_ruta<<"?";
		gotoxy(35, 6);
		cout<<"1.-Subir";
		gotoxy(35, 7);
		cout<<"2.-No subir";
		gotoxy(35, 8);
		opc = validaEntero();
	}while(opc>2 || opc<1);
	if(opc==1){
		recorridoActual->estado = siSubio;
		gotoxy(35, 9);
		printf("\a");
		cout<<"¡HA INICIADO TU RECORRIDO!";
		
		recorridoActual->horaSubida[0] = ruta->hora;
		recorridoActual->horaSubida[1] = 0 + rand()%5; //5 minutos aleatorios a los que subio el usuario
		
		//El usuario se sube en la primera estacion de la ruta
		auxEstacion = auxRuta->primero;
		recorridoActual->estacionSubida = auxEstacion->id_lugar;
		
		do{
			tiempo += auxEstacion->tiempoAestacion;
			do{
				printf("\a");
				system("cls");
				caja();
				SetConsoleTextAttribute(hCon, 14);
				gotoxy(35, 5);
				cout<<"Estacion "<<auxEstacion->nombre;
				gotoxy(35, 6);
				cout<<"1.-Bajar aqui"<<endl;
				gotoxy(35, 7);
				cout<<"2.-continuar"<<endl;
				gotoxy(35, 8);
				opc = validaEntero();
			}while(opc>2 || opc<1);
			
			if(opc==1){
				recorridoActual->estacionBajada = auxEstacion->id_lugar;
				
				t1 = (recorridoActual->horaSubida[1]+tiempo)/60; //horas en un entero
				t2 = (recorridoActual->horaSubida[1]+tiempo)/60; //Horas en un flotante
				
				if(t2<1){ //No completo una hora
					recorridoActual->horaBajada[0] = recorridoActual->horaSubida[0];
					recorridoActual->horaBajada[1] += tiempo ;
				}else{
					if(t1>t2){
						recorridoActual->horaBajada[0] += t1-1;
						recorridoActual->horaBajada[1] = recorridoActual->horaSubida[1] + tiempo - (t1-1)*60;
					}else{
						recorridoActual->horaBajada[0] += t1;
						recorridoActual->horaBajada[1] = recorridoActual->horaSubida[1] + tiempo - (t1)*60;
					}
				}
				
				break;
			}
			
			//Ya que la ruta llego a su ultima estacion regresa a la primera
			if(auxEstacion==auxRuta->ultimo){
				auxEstacion = auxRuta->primero;
			}else{
				auxEstacion = auxEstacion->sig;
			}
		}while(true);
		
	}else{
		printf("\a");
		recorridoActual->estado = noSubio;
		recorridoActual->estacionBajada = 0;
		recorridoActual->estacionSubida = 0;
		gotoxy(35, 10);
		cout<<"DEJASTE IR AL AUTOBUS!"<<endl;
	}
	
	gotoxy(35, 11);
	system("pause");
	
	if(usuarioActivo->primRecorrido == NULL){
		usuarioActivo->primRecorrido = recorridoActual;
		usuarioActivo->ultRecorrido = recorridoActual;
	}else{
		usuarioActivo->ultRecorrido->sig = recorridoActual;
		usuarioActivo->ultRecorrido = recorridoActual;
		recorridoActual->sig=NULL;
		usuarioActivo->ultRecorrido->sig=NULL;
	}
	return 0;
}

void menuPasajero(){
	int opc = 0, opc2=0;
	//Ya que inicio sesion como usuario leemos sus rutas de su archivo
	leerRutasUsuario(usuarioActivo);
	leerRecorridoUsuario(usuarioActivo);
	do{
		printf("\a");
		system("cls");
		caja();
		SetConsoleTextAttribute(hCon, 11);
		//Mostramos el menu del usuario
		gotoxy(40, 5);
		cout<<".- MENU DE PASAJERO -.";
		SetConsoleTextAttribute(hCon, 14);
		gotoxy(40, 6);
		cout<<"Bienvenid@ pasajer@ "<<usuarioActivo->nombre;
		gotoxy(40, 7);
		cout<<"1.-Mis Rutas";
		gotoxy(40, 8);
		cout<<"2.-Estado del autobus";
		gotoxy(40, 9);
		cout<<"0.-Salir";
		//Validamos la opcion que elija el usuario
		do{
			gotoxy(40, 10);
			opc = validaEntero();
			//En caso de que elija la opcion 0 salimos de el programa
		}while(opc>2 || opc<0);
		if(opc==0){
			break;
		}
		switch(opc){
			
			case 1: //Consultas de las rutas del usuario
				printf("\a");
				do{
					system("cls");
					caja();
					SetConsoleTextAttribute(hCon, 11);
					gotoxy(40, 5);
					cout<<".- MIS RUTAS -.";
					SetConsoleTextAttribute(hCon, 14);
					gotoxy(40, 6);
					//Aqui mostramos otro menu de las rutas del usuario
					cout<<"1.-Ver mis rutas";
					gotoxy(40, 7);
					cout<<"2.-Registrar una ruta";
					gotoxy(40, 8);
					cout<<"3.-Eliminar ruta";
					gotoxy(40, 9);
					cout<<"4.-Modificar una ruta";
					gotoxy(40, 10);
					cout<<"0.-Regresar";
					//Validamos la opcion del usuario
					do{
						gotoxy(40, 11);
						opc = validaEntero();
					}while(opc>4 || opc<0);
					if(opc==0){
						break;
					}
					//Segun la opcion que elijio el usuario
					switch(opc){
						case 1:
							printf("\a");
							//Se presentan las rutas de este usuario en particular
							system("cls");
							caja();
							SetConsoleTextAttribute(hCon, 14);
							gotoxy(15, 5);
							cout<<".- MIS RUTAS -.";
							imprimirRutasUsuario(15, 6,usuarioActivo);
							gotoxy(15, 20);
							system("pause");
							break;
						case 2:
							printf("\a");
							//El usuario puede registrar las rutas que va a tomar, la hora y fecha
							registrarRutasUsuario();
							break;
						case 3:
							printf("\a");
							//Aqui el usuario elimina alguna ruta que no desee
							eliminarRutasUsuario();
							break;
						case 4:
							printf("\a");
							//El usuario Modifica la ruta, la bora o la fecha de sus rutas
							modificarRutaUsuario();
							break;
					}
				}while(true);
				break;
			case 2:
				printf("\a");
				do{
					do{
						system("cls");
						caja();
						SetConsoleTextAttribute(hCon, 11);
						gotoxy(35, 5);
						cout<<".- ESTADO DEL AUTOBUS -.";
						SetConsoleTextAttribute(hCon, 14);
						gotoxy(35, 6);
						cout<<"1.-Ha llegado el autobus!";
						gotoxy(35, 7);
						cout<<"2.- Ver Historial";
						gotoxy(35, 8);
						cout<<"0.-Regresar"<<endl;
						gotoxy(35, 9);
						opc = validaEntero();
					}while(opc>2 || opc<0);
					if(opc==0){
						break;
					}
					switch(opc){
						case 1:
							printf("\a");
							menuAutobus();
							break;
						case 2:
							printf("\a");
							system("cls");
							caja();
							SetConsoleTextAttribute(hCon, 14);
							historial(10, 5, usuarioActivo);
							gotoxy(35, 20);
							system("pause");
							break;
					}
				}while(true);
				break;
			}
	}while(true);
}

void menuPrincipal(){
	cout<<endl;
	if(usuarioActivo->TipoUsuario == admin){
		menuAdmin();
	}else{
		menuPasajero();
	}
}
