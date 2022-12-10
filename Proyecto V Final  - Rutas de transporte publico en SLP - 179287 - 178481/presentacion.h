HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
 void tamano(){
	SMALL_RECT rect;
	COORD coord;
	coord.X = 120; // Definiendo X y
	coord.Y = 30;  // Y para el tamaño del búfer.
	
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = coord.Y-1; // Altura para ventana
	rect.Right = coord.X-1;  // Ancho para ventana
	
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hwnd, coord);       // Establece tamaño del búfer
	SetConsoleWindowInfo(hwnd, TRUE, &rect);
}

void caja(){
	SetConsoleTextAttribute(hCon, 13);
	for(int i=0;i<120;i++){
		gotoxy(i, 1);
		printf("%c", 205);	
	}
	for(int i=0;i<120;i++){
		gotoxy(i, 28);
		printf("%c", 205);	
	}
	for(int i=1;i<29;i++){
		gotoxy(0, i);
		printf("%c", 186);
	}
	for(int i=1;i<29;i++){
		gotoxy(119, i);
		printf("%c", 186);
	}
	gotoxy(0, 1);
	printf("%c", 201);
	gotoxy(119, 1);
	printf("%c", 187);
	gotoxy(0, 28);
	printf("%c", 200);
	gotoxy(119, 28);
	printf("%c", 188);
	
	for(int i=2;i<118;i++){
		gotoxy(i, 2);
		printf("%c", 205);	
	}
	for(int i=2;i<118;i++){
		gotoxy(i, 27);
		printf("%c", 205);	
	}
	for(int i=2;i<28;i++){
		gotoxy(2, i);
		printf("%c", 186);
	}
	for(int i=2;i<28;i++){
		gotoxy(118, i);
		printf("%c", 186);
	}
	gotoxy(2, 2);
	printf("%c", 201);
	gotoxy(118, 2);
	printf("%c", 187);
	gotoxy(2, 27);
	printf("%c", 200);
	gotoxy(118, 27);
	printf("%c", 188);
}

void presentacion(){
	caja();
	gotoxy(42, 5);
	SetConsoleTextAttribute(hCon, 14);
	cout<<"Materia: Programacion II";
	gotoxy(42, 6);
	cout<<"Proyecto Final: ";
	gotoxy(42, 7);
	cout<<"Rutas de transporte en San Luis Potosi";
	gotoxy(42, 9);
	cout<<"Desarrolladores: ";
	gotoxy(42, 10);
	cout<<"Rivera Carreon Brian Issai";
	gotoxy(42, 11);
	cout<<"Rodriguez Torres Sebastian";
	gotoxy(42, 15);
	cout<<"Materia: Programacion II";
	gotoxy(42, 17);
	cout<<"Carrera: ITI";
	gotoxy(42, 20);
	cout<<"Enter para continuar....";
}
