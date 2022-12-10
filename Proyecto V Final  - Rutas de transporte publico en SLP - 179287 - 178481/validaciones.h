int validaEntero(){
	int entero = 0;
	int bandera = 0;
	
	do{
		bandera = scanf("%d", &entero); 
		fflush(stdin);
	}while(bandera!=1);
	fflush(stdin);
	return entero;
}

void validaCadena(const char elemento[], char cadena[]){
	bool bandera = true;
	int i=0;
	do{
		bandera = true;
		printf("\n%s", elemento);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		
		if(strlen(cadena)>19){
			continue;
		}else{
			for(i = 0; i<(strlen(cadena)); i++){ //obtenemos el tamaño y recorremos cada elemento de la cadena
				//valida que el elemento sea una mayuscula o minuscula
				//if((cadena[i])>=65 && (cadena[i])<=90 || (cadena[i])>=97 && (cadena[i])<=122 || (cadena[i])==' '){
				if(isalpha(cadena[i]) || cadena[i]==' '){
					//continue; //Si esta bien el caracter sigue
					if(i==(strlen(cadena)-1)){
						bandera = false;
					}
				}else{
					//bandera = false;
					break;
				}
			}
		}
	}while(bandera);
	fflush(stdin);
}

float validaFlotante(const char mensaje[]){
	int continuar = 0;
	float flotante = 0;
	
	do{
		printf("\n%s", mensaje);
		continuar = scanf("%f", &flotante);
		fflush(stdin);
		
	}while(continuar != 1);
	fflush(stdin);
	return flotante;
}
