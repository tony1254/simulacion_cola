
#define _pila_h_

#include "funciones.h"
// LIBRERIA compartido por TONY
struct pila{
      int numero;
      double hllegada;
      double hatiende;
      }fila[101];

int cola=0,fin=101,inicio=1;

float calc_llegada(int val){
     return get_random(val);
                             }
                             
float calc_servicio(int val){
     return get_random(val);
                             }
void pasar_hora(double tiempo){
		color(11);
int min=0, seg=0, hor=0;
float respuesta=0, tmp=tiempo;
hor = tmp/3600;
respuesta = tmp/3600;
tmp=(respuesta-hor)*60;
min = tmp;
respuesta = tmp;
seg=(respuesta-min)*60;
cout<<hor<<":"<<min<<":"<<seg;
cout<<"\n";
color(10);
	
}
 void construir(){
		
		for (int i=0; i<=fin; i++){
	 fila[i].numero = 0;
     fila[i].hllegada =0;
     fila[i].hatiende=0;
		}
 }                            
     /** revisa si esta llena la cola **/
      bool cola_llena(){
           if (cola<100){
                    return false;        
                            }
           return true;
           
           }
   /*revisa si esta vacia la cola**/   
 bool cola_vacia(){
           if (cola<inicio){
                    return true;        
                            }
           return false;
    }     
         /**inserta uno a la fila**/  
void push(double l,double a){
     if (!cola_llena()){
			cola++;
     cout<<"inserto en : "<<cola<<" \n valor: "<<a<<"\n";
	 fila[cola].numero=cola+1;
     fila[cola].hllegada=l;
     fila[cola].hatiende=a;
     
     
     }
     }
/** extrae el primero de la fila**/
pila pop(){
     pila f;
     double l, a;
     l=fila[inicio].hllegada; //cuso de profera
     a=fila[inicio].hatiende;
     
     f.numero=0;
     f.hllegada=l;
     f.hatiende=a;
     
     
     for (int i=1;i<=cola;i++){
         fila[i].numero = fila[i+1].numero-1;
     fila[i].hllegada =fila[i+1].hllegada;
     fila[i].hatiende=fila[i+1].hatiende;
         }
     
         if(cola>0){
				cola--;     
         }
		  
         return f;
}

      
      
      
