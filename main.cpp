#include "pila.h"
#include <iomanip> 

using namespace std;

int main(int argc, char *argv[])
{
bool bandera=false;
float hora_inicio=0;
float hora_fin=28800;//480;
float hora= hora_inicio;
float tt=0;
float tiempo_llegada=0;
bool servicio=true;
double tiempo_servicio_liberara=0;
double tiempo_servicio=0;
char resp='s';
float a=0,b=0;
pila salida;
int lamda=1000, mu=600;
int tiempo_ocupado=0;
/*
tiempo_llegada=calc_llegada(lamda);
tiempo_servicio=calc_servicio(mu);
 
 
  push(hora,tiempo_servicio);
  
 
				    					   hora=hora+tiempo_llegada;
				    					

tiempo_llegada=calc_llegada(lamda);
tiempo_servicio=calc_servicio(mu);
 
 
  push(hora,tiempo_servicio);
  salida=  pop();
                                             b=salida.hatiende;
                                              
											       cout<<"pop= "<<salida.numero<<"\n";
											       	cout<<b<<" = ";
				    					pasar_hora(salida.hatiende);
				    					pasar_hora(salida.hllegada);
salida=  pop();				    					                                 
																		            b=salida.hatiende;
                                              
											       cout<<"pop= "<<salida.numero<<"\n";
											       	cout<<b<<" = ";
				    					pasar_hora(salida.hatiende);
				    					pasar_hora(salida.hllegada);
*/
do{
	system("cls");
// Muestra la hora con la que inicia el ciclo 

			cout<<"hora anterior al ultimo atendido: ";
             pasar_hora(hora);
			 cout<<"\n";    
// genera los tiempos			 
                  tiempo_llegada=calc_llegada(lamda);
                  hora=hora+tiempo_llegada;
                  tiempo_servicio=calc_servicio(mu);
                  cout<<"llego a los = ";
				    pasar_hora(tiempo_llegada);
                  //muestra el timpo de servicio que grabara
                  cout<<"hora Actual= ";
				    pasar_hora(hora);
				  cout<<"\n";
				  // condicion de final de dia
                  if(hora<=hora_fin){
                               bandera=true;
                               }else {
                                     bandera=false;
                                     resp='n';
                                     }
                                     
                  if(bandera)
				{
                               if((!cola_vacia())||(!servicio))
							   			{
                                                 if(!cola_llena())
												 {
													cout<<"\n push \n";
                                               		push(hora,tiempo_servicio);
                                               	 }else{
                                                     	cout<<" COLA LLENA \n"<<cola;
                                                      }
                                        }
                               /*if(!servicio){
                                             if(!cola_llena()){
													cout<<"\n push servicio \n";
                                               push(hora,tiempo_servicio);
                                               }else{
                                                     cout<<" COLA LLENA \n";
                                                     }
                                              }*/
                                              
                               else{
                                    servicio=false;
                                    cout<<"\n SERVICIO OCUPADO \n";
                                    tiempo_ocupado=tiempo_ocupado+tiempo_servicio;
                                    tiempo_servicio_liberara=hora+tiempo_servicio;
                                    }
                                    
                               // condicion para limpiar
                  				while((hora>=tiempo_servicio_liberara)&&(!servicio))
								  {
                                            servicio=true; // Libera el servicio
                                            cout<<"\n SERVICIO LIBRE \n";
                                            if(!cola_vacia())
											{
                                            	salida=  pop();
                                            	cout<<"\n lo atendieron a: ";
                                            	pasar_hora(tiempo_servicio_liberara);
                                            	cout<<"\n Tardo : ";
				    							pasar_hora(salida.hatiende);
				    							cout<<"\n llego : ";
				    							pasar_hora(salida.hllegada);
				    							servicio=false;
						            			cout<<"\n hora termino de ser atendido: ";
						            			pasar_hora(tiempo_servicio_liberara);
                                    			cout<<"\n SERVICIO OCUPADO \n";
                                    			tiempo_servicio_liberara=tiempo_servicio_liberara+salida.hatiende;
												cout<<"\n";  
												tiempo_ocupado=tiempo_ocupado+salida.hatiende;
											}
                                    
                                }     
                                    
                }       
            cout<<"cola= "<<cola<<"\n";
                                      
  if ((resp!='n')){
                                
          //cout<<"estadisticas \n";                      
  cout<<"desea seguir viendo uno por uno? s=si n=no \n";
  cin>>resp;                                  
    
                                }
              }while(bandera);                        
cout<<"\n cola antes de terminar= "<<cola<<"\n";     			  			  
cout<<"\n T I E M P O S  \n";   
cout<<"\t Tiempo ocupado= ";   
pasar_hora(tiempo_ocupado);
cout<<"\t Tiempo ocio= ";   
pasar_hora(hora_fin-tiempo_ocupado);
cout<<"\n P O R C E N T A J E S  \n";  
cout<<"\t Tiempo ocupado= " << std::setprecision(4)<<tiempo_ocupado*100/hora_fin<<"%";
cout<<"\t Tiempo ocio= " << std::setprecision(4)<<(hora_fin-tiempo_ocupado)*100/hora_fin<<"%";
cout<<"\n";  
cout<<"\n";  


cout<<"\n";  
cout<<"\n";  
if(cola!=0)
{

			     while((!servicio))
				 {                    
                 servicio=true;
                 	if(!cola_vacia())
				 	{
                 		salida=  pop();
                    	cout<<"\n lo atendieron a: ";
                    	pasar_hora(tiempo_servicio_liberara);
                    	cout<<"\n Tardo : ";
						pasar_hora(salida.hatiende);
						cout<<"\n llego : ";
						pasar_hora(salida.hllegada);
						servicio=false;
            			cout<<"\n hora termino de ser atendido: ";
            			pasar_hora(tiempo_servicio_liberara);
            			cout<<"\n SERVICIO OCUPADO \n";
            			tiempo_servicio_liberara=tiempo_servicio_liberara+salida.hatiende;
						cout<<"\n";  
						tiempo_ocupado=tiempo_ocupado+salida.hatiende;
					}
                                    
                 }
     		cout<<"cola al final= "<<cola<<"\n";   
			 
			 
			 cout<<"\n T I E M P O S \n";   
cout<<"\t Tiempo ocupado= ";   
pasar_hora(tiempo_ocupado);

if((hora_fin-tiempo_ocupado)<0){
	cout<<"\t Tiempo extra= ";  
	pasar_hora((hora_fin-tiempo_ocupado)*(-1));
}else{
	cout<<"\t Tiempo ocio= ";  
	pasar_hora(hora_fin-tiempo_ocupado);
} 

cout<<"\n P O R C E N T A J E S  \n";  
cout<<"\t Tiempo ocupado= " << std::setprecision(4)<<tiempo_ocupado*100/hora_fin<<"%";
if((hora_fin-tiempo_ocupado)<0){	
	cout<<"\t Tiempo extra= " << std::setprecision(4)<<((hora_fin-tiempo_ocupado)*(-1))*100/hora_fin<<"%";
}else{
	cout<<"\t Tiempo ocio= " << std::setprecision(4)<<(hora_fin-tiempo_ocupado)*100/hora_fin<<"%";
} 
cout<<"\n";  
cout<<"\n";  
cout<<"Agradecimientos a Luis Antonio Garcia Aguirre\n";  
}

     getch();
     cout<<"Agradecimientos a Luis Antonio Garcia Aguirre\n";  
     return 1;
}
