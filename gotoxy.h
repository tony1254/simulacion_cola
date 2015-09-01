

#define _gotoxy_h
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>  
#include <time.h>
#include <windows.h>   
#include <math.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>
#include <cstdlib>
#include <iostream> 
  
using namespace std;
void gotoxy(int column, int line)
{
    /*Creo variable con formato de coordenada y le asingo valores de los 
      Prametros que recibi*/
    COORD coord;
    coord.X = column;
    coord.Y = line;

    /*Obtiene e inicialisa una varibale con el punto de handle*/
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    /*llamamos a la funcion que recibe el punto y las cooredenadas */
    if (!SetConsoleCursorPosition(hConsole, coord))
    {
    	/*va aqui el error en caso que no se pueda ejecutar */
       cout<<"\n\n\t\tERROR al ejecutar GotoXY\n\n";
    }
}

