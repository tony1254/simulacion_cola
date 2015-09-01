

#define _colores_h_


#include "gotoxy.h"


using namespace std;
/*Funcion Practica para llamar a los colores de fondo/letra recibe parametros en base a la formula X=A*16+B   A=fondo B= letra */
void color(int X) 
{ 
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X); 
} /*
0 = Negro 
1 = Azul 
2 = Verde 
3 = Aguamarina 
4 = Rojo 
5 = Purpura 
6 = Amarillo 
7 = Blanco 
8 = Gris 
9 = Azul claro 
A = Verde claro 
B = Aguamarina claro 
C = Rojo claro 
D = Purpura claro 
E = Amarillo claro 
F = Blanco brillante */


/**Funcion que pone Puntos suspendivos y oculta el return 0 **/
void psf(){
	color(15);
	gotoxy(1,14);
	cout<<"Dejar Precionado ESC...";
	
	//char tecla;
	//tecla = getch();
	//cout<<"esta\""<<tecla<<"\"";
	/*
	do
	{
	cout<<"hola";
	}while ((getch())!=27);
	
	*/
		int tecla=0;
	do{
	if(kbhit()){
	tecla=getch();
	}
		Sleep(300);
	if(kbhit()){
	tecla=getch();
	}
		gotoxy(21,14);
		cout<<"                       ";
		Sleep(300);
	if(kbhit()){
	tecla=getch();
	}
		gotoxy(21,14);
		cout<<".";
		Sleep(300);
	if(kbhit()){
	tecla=getch();
	}
		cout<<" .";
		Sleep(300);
	if(kbhit()){
	tecla=getch();
	}	
		cout<<" .";
	
	}while (tecla!=27);
	//system("cls");
	color(0);	
	
}



