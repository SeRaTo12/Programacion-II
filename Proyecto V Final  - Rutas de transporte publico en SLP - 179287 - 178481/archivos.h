void escribirUsuarios(){
	Usuario *aux = primUser;
	ofstream archivo("Usuarios.xls");
	while(aux!=NULL){
		archivo<<aux->id_usuario<<"\t";
		archivo<<aux->nombre<<"\t";
		archivo<<aux->apellido<<"\t";
		archivo<<aux->sexo<<"\t";
		archivo<<aux->TipoUsuario<<"\t";
		archivo<<aux->estado<<"\t";
		archivo<<aux->password<<"\n";
		aux = aux->sig;
	}
	archivo.close();
}


void escribirEstaciones(){
	Estacion *aux = primEstacion;
	ofstream archivo("Estaciones.xls");
	do{
		archivo<<aux->id_lugar<<"\t";
		archivo<<aux->nombre<<"\t";
		archivo<<aux->estado<<"\t";
		archivo<<aux->tiempoAestacion<<"\n";
		aux=aux->sig;
	}while(aux!=primEstacion);
	archivo.close();
}

void escribirRutasGlobales(){
	Ruta *aux = primRuta;
	ofstream archivo("RutasGlobales.xls");
	while(aux != NULL){
		archivo<<aux->id_ruta<<"\t";
		archivo<<aux->primero->id_lugar<<"\t";
		archivo<<aux->ultimo->id_lugar<<"\t";
		archivo<<aux->horaInicio<<"\t";
		archivo<<aux->horaFin<<"\t";
		archivo<<aux->estado<<"\n";
		aux=aux->sig;
	};
	archivo.close();
}

void enteroAcad(int n, char cad[]){
	int nroDig = 0;
	int aux = n;
	while(aux>0){
		aux = aux/10;
		nroDig++;
	}
	cad[nroDig]='\0';
	aux = n;
	int pos = nroDig-1,dig;
	while(pos>=0){
		dig = aux%10;
		aux = aux/10;
		cad[pos] = dig + '0';
		pos--;
	}
}

void escribirRutasUsuario(Usuario *usuarioActivo){ // funcion para escribir las rutas del usuario en archivo propio
	rutasUsuario *aux = usuarioActivo->primero;
	int num = usuarioActivo->id_usuario; //Obtenemos el id del usuario
	char numero[8];
	enteroAcad(num, numero);//Esta funcion la uso para cambiar el int del id usuario a un char, la saque de interne
	char nombre[35] = "RutasUsuarios/rutaUsuario";//Esta cadena tiene la ruta y la primera parte del archivo que se va a generar
	char final[5]=".xls";//Esta cadena tiene la parte final del nombre del archivo
	strcat(nombre, numero);//Aqui concateno la cadena nombre con la cadena numero.
	strcat(nombre, final);//Aqui concateno lo que concatene anteriormente para agregarle el final
	//ejemplo: si el id del usuario que inicio sesión es el 2 entonces la cadena nombre quedaria asi:
	//RutasUsuario/rutaUsuario2.xls
	ofstream archivo(nombre);
	while(aux != NULL){
		archivo<<aux->id_ruta<<"\t";
		archivo<<aux->dia<<"\t";
		archivo<<aux->hora<<"\n";
		aux=aux->sig;
	}
	archivo.close();
}

void escribirRecorridoUsuario(Usuario *usuarioActivo){
	recorridoUsuario *aux = usuarioActivo->primRecorrido;
	int num = usuarioActivo->id_usuario;
	char numero[8];
	enteroAcad(num, numero);
	char nombre[55] = "RecorridosUsuario/recorridoUsuario";
	char final[5]=".xls";
	strcat(nombre, numero);
	strcat(nombre, final);
	ofstream archivo(nombre);
	int ayuda1, ayuda2, ayuda3, ayuda4;
	while(aux!=NULL){
		ayuda1=aux->horaSubida[0];
		ayuda2=aux->horaSubida[1];
		ayuda3=aux->horaBajada[0];
		ayuda4=aux->horaBajada[1];
		archivo<<aux->idRecorrido<<"\t";
		archivo<<aux->idRuta<<"\t";
		archivo<<aux->estado<<"\t";
		archivo<<aux->estacionSubida<<"\t";
		archivo<<aux->estacionBajada<<"\t";
		archivo<<ayuda1<<"\t";
		archivo<<ayuda2<<"\t";
		archivo<<ayuda3<<"\t";
		archivo<<ayuda4<<"\n";
		aux=aux->sig;
	}
	archivo.close();
}

void leerRecorridoUsuario(Usuario *usuarioActual){
	recorridoUsuario *aux = usuarioActual->primRecorrido;
	recorridoUsuario *nuevo=NULL;
	int num = usuarioActual->id_usuario;
	char numero[8];
	enteroAcad(num, numero);
	char nombre[35] = "RecorridosUsuario/recorridoUsuario";
	char final[5]=".xls";
	strcat(nombre, numero);
	strcat(nombre, final);
	ifstream arch(nombre);
	string linea, c;
	int ayuda1;
	int ayuda2;
	int ayuda3;
	int ayuda4;
	gotoxy(35, 7);
	if(arch.fail()) cerr<<"No se encontro ningun archivo"<<endl;
	else{
		while(getline(arch, linea)){
			nuevo = new recorridoUsuario;
			nuevo->sig=NULL;
			stringstream lee(linea);
			lee>>nuevo->idRecorrido;
			getline(lee, c, '\t');
			lee>>nuevo->idRuta;
			getline(lee, c, '\t');
			lee>>nuevo->estado;
			getline(lee, c, '\t');
			lee>>nuevo->estacionSubida;
			getline(lee, c, '\t');
			lee>>nuevo->estacionBajada;
			getline(lee, c, '\t');
			
			lee>>ayuda1;
			getline(lee, c, '\t');
			lee>>ayuda2;
			getline(lee, c, '\t');
			lee>>ayuda3;
			getline(lee, c, '\t');
			lee>>ayuda4;
			getline(lee, c, '\t');
			
			nuevo->horaSubida[0]=ayuda1;
			nuevo->horaSubida[1]=ayuda2;
			nuevo->horaBajada[0]=ayuda3;
			nuevo->horaBajada[1]=ayuda4;			
			if(usuarioActual->primRecorrido == NULL){
				usuarioActual->primRecorrido = nuevo;
				usuarioActual->ultRecorrido = nuevo;
			}else{
				usuarioActual->ultRecorrido->sig = nuevo;
				usuarioActual->ultRecorrido = nuevo;
				nuevo->sig=NULL;
			}
		}
	}
	arch.close();
}

void leerRutasUsuario(Usuario *usuarioActual){ //Funcion para leer las rutas del usuario
	rutasUsuario *aux = usuarioActual->primero;
	rutasUsuario *nuevo=NULL;
	int num = usuarioActual->id_usuario;
	char numero[8];
	enteroAcad(num, numero);
	char nombre[35] = "RutasUsuarios/rutaUsuario";
	char final[5]=".xls";
	strcat(nombre, numero);
	strcat(nombre, final);
	
	ifstream arch(nombre);
	string linea, c;
	gotoxy(35, 7);
	if(arch.fail()) cerr<<"No se encontro ningun archivo"<<endl;
	else{
		while (getline(arch, linea)){
			nuevo = new rutasUsuario;
			nuevo->sig = NULL;
			stringstream lee(linea);
			lee>>nuevo->id_ruta;
			getline(lee, c, '\t');
			lee>>nuevo->dia;
			getline(lee, c, '\t');
			lee>>nuevo->hora;
			getline(lee, c, '\t');
			
			if(usuarioActual->primero==NULL){
				usuarioActual->primero=nuevo;
				usuarioActual->ultimo=nuevo;
			}else{
				nuevo->prev=usuarioActual->ultimo;
				usuarioActual->ultimo->sig = nuevo;
				usuarioActual->ultimo = nuevo;
				usuarioActual->ultimo->sig = NULL;
			}
		}
	}
	arch.close();
}

void leerUsuarios(){
	Usuario *nuevo = NULL;
	ifstream arch("Usuarios.xls");
	string linea, c;
	if(arch.fail()) cerr<<"No se encontro ningun archivo"<<endl;
	else{
		while (getline(arch, linea)){
			nuevo = new Usuario;
			nuevo->sig = NULL;
			stringstream lee(linea);
			lee>>nuevo->id_usuario;
			getline(lee, c, '\t');
			getline(lee, nuevo->nombre, '\t');
			getline(lee, nuevo->apellido, '\t');
			lee>>nuevo->sexo;
			getline(lee, c, '\t');
			lee>>nuevo->TipoUsuario;
			getline(lee, c, '\t');
			lee>>nuevo->estado;
			getline(lee, c, '\t');
			getline(lee, nuevo->password, '\n');
			
			if(primUser==NULL){
				primUser = nuevo;
				ultUser = nuevo;
			}else{
				ultUser->sig = nuevo;
				ultUser=nuevo;
			}
		}
	}
	arch.close();
}

void leerEstaciones(){
	Estacion *nuevo = NULL;
	ifstream arch("Estaciones.xls");
	string linea, c;
	if(arch.fail()) cerr<<"No se encontro ningun archivo"<<endl;
	else{
		while(getline(arch, linea)){
			nuevo = new Estacion;
			nuevo->sig=NULL;
			stringstream lee(linea);
			lee>>nuevo->id_lugar;
			getline(lee, c, '\t');
			getline(lee, nuevo->nombre, '\t');
			lee>>nuevo->estado;
			getline(lee, c, '\t');
			lee>>nuevo->tiempoAestacion;
			getline(lee, c, '\t');
			if(primEstacion==NULL){
				primEstacion = nuevo;
				ultEstacion = nuevo;
				ultEstacion->sig=primEstacion;
			}else{
				ultEstacion->sig=nuevo;
				ultEstacion=nuevo;
				ultEstacion->sig=primEstacion;
			}
		}
	}
	arch.close();
}

void leerRutasGlobales(){
	Ruta *nuevo = NULL;
	Estacion *aux = primEstacion;
	ifstream arch("RutasGlobales.xls");
	string linea, c;
	int primero;
	int ultimo;
	
	if(arch.fail()) cerr<<"No se encontro ningun archivo"<<endl;
	else{
		
		while(getline(arch, linea)){
			nuevo = new Ruta;
			nuevo->sig = NULL;
			stringstream lee(linea);
			lee>>nuevo->id_ruta;
			getline(lee, c, '\t');
			lee>>primero;
			getline(lee, c, '\t');
			while(primero!=aux->id_lugar){
				aux=aux->sig;
			}
			
			nuevo->primero=aux;
			lee>>ultimo;
			getline(lee, c, '\t');
			while(ultimo!=aux->id_lugar){
				aux=aux->sig;
			}
			nuevo->ultimo=aux;
			lee>>nuevo->horaInicio;
			getline(lee, c, '\t');
			lee>>nuevo->horaFin;
			getline(lee, c, '\t');
			lee>>nuevo->estado;
			getline(lee, c, '\t');
			
			if(primRuta == NULL){
				primRuta = nuevo;
				ultRuta = nuevo;
			}else{
				ultRuta->sig = nuevo; 
				ultRuta = nuevo;
			}
		}
	}
	arch.close();
}



