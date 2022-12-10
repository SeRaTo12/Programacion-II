Usuario *login(){
	Usuario *aux = primUser;
	string password;
	int id=0;
	int nuevo=1;
	//Leemos datos ingresados
	cout<<endl;
	do{
		gotoxy(35, 13);
		cout<<"Id Usuario: ";
		gotoxy(47, 13);
		id = validaEntero();
		if(id==0){
			return NULL;
		}
	}while(id>ultUser->id_usuario || id<primUser->id_usuario );
	gotoxy(35, 15);
	cout<<"Contrasena: ";
	cin>>password;
	
	do{
		if(id==aux->id_usuario){ //Si encuentra al usuario
			if(password==aux->password){ //Si la contraseña coincide
				if(aux->estado == activo){ //En caso de que el usuario este activo
					gotoxy(35, 16);
					cout<<"--HAS INICIADO SESION EXITOSAMENTE--";
					Sleep(2000);
					return aux;
				}else{ //En caso de que el usuario este inactivo
					gotoxy(35, 16);
					cout<<"EL USUARIO SE ENCUENTRA DESHABILITADO";
					return NULL;
				}
			}else{ //Si la contraseña no coincide
				gotoxy(35, 17);
				cout<<"¡LA CONTRASEnA NO COINCIDE!";
				return NULL;
			}
		}else{
			aux=aux->sig;
		}
	}while(aux!=NULL);
	cout<<endl<<"¡EL USUARIO NO EXISTE!"<<endl;
	return NULL;
}

bool inicio(Usuario *root){
	int opc=0;
	caja();
	SetConsoleTextAttribute(hCon, 14);
	gotoxy(35, 12);
	if(primUser == NULL){
		registrarUser(root);
		do{
			usuarioActivo = login();
		}while(usuarioActivo==NULL);
	}else{
		while(true){
			system("cls");
			caja();
			SetConsoleTextAttribute(hCon, 14);
			gotoxy(35, 12);
			do{
				cout<<"0.-Salir, 1.- Iniciar sesion, 2.-Registrarse: ";
				opc = validaEntero();
			}while(opc<0 || opc>2);
			if(opc==0){
				return false;
			}
			if(opc==1){
				//Aqui debemos sustituir los datos del superUsuario a los del login
				usuarioActivo = login();
				if(usuarioActivo!=NULL){
					break;
				}
				
			}
			if(opc==2){
				root->TipoUsuario = pasajero;
				registrarUser(root);
				usuarioActivo = login();
				if(usuarioActivo!=NULL){
					break;
				}
			}
		}
		return true;
	}
}

