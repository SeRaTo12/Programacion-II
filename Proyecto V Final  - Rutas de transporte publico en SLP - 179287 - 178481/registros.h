void registrarUser(Usuario *root){
	Usuario *nuevo = new Usuario; //Generamos usuario
	int opc=0;
	string password, password2;
	bool bandera = true;
	
	nuevo->sig=NULL;
	nuevo->estado=activo; //Los nuevos usuarios siempre estaran activos
	
	if(primUser==NULL){
		//Si aun no hay ningun usuario, el ptimero tendra id = 1
		nuevo->id_usuario = 1;
	}else{
		//Si ya existen usuarios, aumentamos de 1 en 1 los id´s
		nuevo->id_usuario = (ultUser->id_usuario)+1;
	}
	system("cls");
	caja();
	SetConsoleTextAttribute(hCon, 14);
	gotoxy(35, 3);
	cout<<"REGISTRO";
	//Si es admin puede elegir si registrar a un pasajero o a otro admin
	if(root->TipoUsuario==admin){ 
		if(primUser==NULL){
			nuevo->TipoUsuario=admin;
		}else{
			gotoxy(35, 4);
			cout<<"Registrar: 1.-Pasajero, 2.-Administrador: ";
			do{
				opc = validaEntero(); //Validamos entrada
			}while(opc!=2 && opc!=1);
			if(opc==1){
				nuevo->TipoUsuario=pasajero;
			}
			if(opc==2){
				nuevo->TipoUsuario=admin;
			}
		}
			
	}else{
		//Cuando es pasajero solo puede registrarse como pasajero
		nuevo->TipoUsuario = pasajero;
	}
	gotoxy(35, 5);
	cout<<"Nombre: ";
	cin>>nuevo->nombre;
	gotoxy(35, 6);
	cout<<"Apellido: ";
	cin>>nuevo->apellido;
	
	do{
		gotoxy(35, 7);
		cout<<"Sexo: 0.-Mujer, 1.-Hombre: ";
		nuevo->sexo=validaEntero();
	}while(nuevo->sexo!=0 && nuevo->sexo!=1);
	
	
	do{
		bandera = true;
		gotoxy(35, 8);
		cout<<"Ingresa tu password: ";
		cin>>nuevo->password;
		gotoxy(35, 9);
		cout<<"Confirma tu password: ";
		cin>>password2;
		
		if(nuevo->password!=password2){ 
			//Hacemos una pequeña confirmacion de password
			gotoxy(35, 10);
			cout<<"Los password no coinciden!, intenta nuevamente";
			bandera = false;
		}
	}while(bandera == false);
	
	//Los usuarios son una lista simple
	if(primUser == NULL){
		nuevo->sig=NULL;
		primUser = nuevo;
		ultUser = nuevo;
	}else{
		ultUser->sig = nuevo;
		ultUser = nuevo;
	}
	gotoxy(35, 12);
	cout<<"¡REGISTRO EXITOSO!"<<endl;
	
	Sleep(3000);
	system("cls");
	caja();
	SetConsoleTextAttribute(hCon, 14);
}

void registrarEstacion(){
	Estacion *nuevo = new Estacion; //Generamos nueva estacion
	
	system("cls");
	caja();
	SetConsoleTextAttribute(hCon, 14);
	//Generamos ID's seriados a las estaciones y lo mostramos el de la que se acaba de generar 
	if(primEstacion == NULL){
		nuevo->id_lugar = 1;
	}else{
		nuevo->id_lugar = ultEstacion->id_lugar+1;
	}
	gotoxy(35, 5);
	cout<<"REGISTRANDO ESTACION";
	gotoxy(35, 6);
	cout<<"ID de la nueva estacion: "<<nuevo->id_lugar;
	gotoxy(35, 7);
	cout<<"Nombre de la nueva estaciOn: ";
	cin>>nuevo->nombre;
	
	//Generamos un tiempo aleatorio entre 5 y 15 minutos para que existe de diferencia entre esta estacion y la otra
	nuevo->tiempoAestacion = 5 + rand() % 11; 
	
	nuevo->estado = activo; //Las nuevas estaciones siempre estaran activas
	
	//Las estaciones son una lista circular simple
	if(primEstacion == NULL){
		primEstacion = nuevo;
		ultEstacion = nuevo;
	}else{
		ultEstacion->sig = nuevo; 
		ultEstacion = nuevo;
		ultEstacion->sig = primEstacion;
	}
	gotoxy(35, 9);
	cout<<"¡ESTACION REGISTRADA EXITOSAMENTE!"<<endl;
	Sleep(3000);
}

void registrarRuta(){
	//Deben existir almenos 2 estaciones para registrar una ruta
	if(primEstacion!=NULL && ultEstacion->id_lugar>1){
		int opc=0;
		Estacion *aux = primEstacion;  //Tomamos un auxiliar que sera la primera estación
		Ruta *nuevo = new Ruta;//Generamos nueva ruta
		system("cls");
		caja();
		SetConsoleTextAttribute(hCon, 14);
		//Generamos ID's de rutas seriados
		if(primRuta==NULL){
			nuevo->id_ruta = 1;
		}else{
			nuevo->id_ruta = ultRuta->id_ruta+1;
		}
		
		nuevo->estado = activo; //Las nuevas rutas siempre estaran activas
		gotoxy(35, 5);
		cout<<"Registrando la ruta con ID = "<<nuevo->id_ruta;
		gotoxy(35, 6);
		cout<<"Hora de inicio de circulacion: ";
		nuevo->horaInicio=validaEntero();
		
		gotoxy(35, 7);
		cout<<"Hora de fin de circulacion: ";
		nuevo->horaFin=validaEntero();
		
		
		imprimirEstaciones(35, 10,0);
		do{	
			gotoxy(35, 8);
			cout<<"¿Cual es la primera estación de la ruta?: ";
			//Pedimos una estacion que exista
			opc = validaEntero();
		}while(opc < primEstacion->id_lugar || opc > ultEstacion->id_lugar);
		
		while(opc!=aux->id_lugar){ //Avanzamos con aux a la que sera la primera estacion y la asignamos
			aux=aux->sig;
		}
		nuevo->primero = aux;
		
		
		aux = primEstacion; //Reiniciamos aux
		do{
			gotoxy(35, 9);
			cout<<"¿Cual es la ultima estación de la ruta?: ";
			//Pedimos una estacion que exista
			opc = validaEntero();
		}while(opc < primEstacion->id_lugar || opc > ultEstacion->id_lugar);
		
		while(opc!=aux->id_lugar){//Avanzamos con aux a la que sera la ultima estacion y la asignamos
			aux=aux->sig;
		}
		nuevo->ultimo = aux;
		
		//Las rutas son una lista de listas simple
		if(primRuta == NULL){
			primRuta = nuevo;
			ultRuta = nuevo;
		}else{
			ultRuta->sig = nuevo; 
			ultRuta = nuevo;
		}
		gotoxy(35, 20);
		cout<<"!LA RUTA N."<<nuevo->id_ruta<<" SE HA REGISTRADO EXITOSAMENTE¡"<<endl;
		Sleep(3000);
	}else{
		gotoxy(35, 20);
		cout<<"¡DEBEN EXISTIR MINIMO 2 ESTACIONES PARA REGISTRAR UNA RUTA!"<<endl;
		Sleep(3000);
	}
}

int registrarRutasUsuario(){
	int opc=0;
	rutasUsuario *nuevaRuta = new rutasUsuario;
	rutasUsuario *aux = usuarioActivo->primero;
	system("cls");
	caja();
	SetConsoleTextAttribute(hCon, 14);
	gotoxy(35, 5);
	cout<<".- REGISTRAR RUTA -.";
	imprimirRutas(15,6,0);
	gotoxy(15, 15);
	cout<<"¿Cual ruta quieres registrar? ";
	cout<<"0.-Regresar";
	
	do{
		gotoxy(15, 16);
		cout<<"N. Ruta: ";
		opc = validaEntero();
		if(opc==0){
			return 0; 
		}
	}while(opc>ultRuta->id_ruta || opc<1);
	while(aux!=NULL){
		if(aux->id_ruta==opc){
			gotoxy(15, 17);
			cout<<"La ruta ya esta registrada";
			Sleep(3000);
			return 0;
		}
		aux=aux->sig;
	}
	nuevaRuta->id_ruta=opc;
	
	do{
		gotoxy(15, 17);
		cout<<"Que dia la vas a tomar? (1-30) ";
		opc = validaEntero();
	}while(opc>30 || opc<1);
	nuevaRuta->dia=opc;
	
	do{
		gotoxy(15, 18);
		cout<<"A que hora la vas a tomar? (1-24) ";
		opc = validaEntero();
	}while(opc>24 || opc<1);
	nuevaRuta->hora=opc;
	
	nuevaRuta->sig=NULL;
	nuevaRuta->prev=NULL;
	
	if(usuarioActivo->primero==NULL){
		usuarioActivo->primero=nuevaRuta;
		usuarioActivo->ultimo=nuevaRuta;
	}else{
		nuevaRuta->prev=usuarioActivo->ultimo;
		usuarioActivo->ultimo->sig = nuevaRuta;
		usuarioActivo->ultimo = nuevaRuta;
		
		//usuarioActivo->ultimo->sig = NULL;
	}
	gotoxy(15, 19);
	cout<<"RUTA REGISTRADA EXITOSAMENTE!"<<endl;
	Sleep(3000);
	return 0;
}
