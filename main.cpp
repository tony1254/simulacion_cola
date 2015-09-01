#include "pila.h"
#include <iomanip> 

using namespace std;

int main(int argc, char *argv[])
{
	char resp='s';
do{
	
bool bandera=false;
float hora_inicio=0;
float hora_fin=28800;//480;
float hora= hora_inicio;
float tt=0;
float tiempo_llegada=0;
bool servicio=true;
double tiempo_servicio_liberara=0;
double tiempo_servicio=0;

float a=0,b=0;
pila salida;
int lamda=1000, mu=600;
int tiempo_ocupado=0;
double c=0,Eta=0;
color(23);
system("cls");
// SOLICITA : los parametros iniciales 
cout<<"I N I C I O\n\n";
cout<<"delimitar el tiempo aleatorio de llegada en segundos (ej.16 minutos): ";
cin>>lamda;
lamda=lamda*60;
cout<<"delimitar el tiempo aleatorio de servicio en segundos(ej.10 minutos): ";
cin>>mu;
mu=mu*60;
cout<<"Ingrese el tiempo que dura el servicio en segundos(ej. 8horas): ";
cin>>hora_fin;
hora_fin=hora_fin*60*60;
//Inicia el Ciclo del sistema
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
                  //muestra al cuanto tiempo llego una nueva interacion
				  cout<<"llego a los = ";
				    pasar_hora(tiempo_llegada);
                  //muestra el timpo Actual
                  cout<<"hora Actual= ";
				    pasar_hora(hora);
				  cout<<"\n";
				  // condicion que reconose el final del dia
                  if(hora<=hora_fin){
                               bandera=true;
                               }else {
                                     bandera=false;
                                     resp='n';
                                     }
                // concicion si el dia aun continua y aun se puede seguir llegando personas
				  if(bandera)
				{
					// reconose si hay alguien en cola y el servicio esta ocupado y lo agrega a la cola
                               if((!cola_vacia())||(!servicio))
							   			{
                                                 if(!cola_llena())
												 {
													cout<<"\n push \n";
													//guarda los parametros para agergar a la cola
                                               		push(hora,tiempo_servicio);
                                               	 }else{
                                                     	cout<<" COLA LLENA \n"<<cola;
                                                      }
                                        }

                               // de lo contrario ocupa el servicio               
                               else{
                                    servicio=false;
                                    color(12);
                                    cout<<"\n SERVICIO OCUPADO \n";
                                    color(10);
                                    tiempo_ocupado=tiempo_ocupado+tiempo_servicio;
                                    tiempo_servicio_liberara=hora+tiempo_servicio;
                                    
                                    Eta=Eta+tiempo_llegada;
                                    c++;
                                    }
                                    
                               // condicion para limpiar si el riempo es superior a el tiempo en que deberia haber salido el ultimo
                  				while((hora>=tiempo_servicio_liberara)&&(!servicio))
								  {
                                            servicio=true; // Libera el servicio
                                            color(2);
                                            cout<<"\n SERVICIO LIBRE \n";
                                            color(10);
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
						            			color(12);
                                    			cout<<"\n SERVICIO OCUPADO \n";
                                    			color(10);
                                    			tiempo_servicio_liberara=tiempo_servicio_liberara+salida.hatiende;
												cout<<"\n";  
											
                                    			Eta=Eta+salida.hllegada;
												c++;
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
cout<<"\n veces que llego alguien= "<<c<<"\n";    
 color(10);
 cout<<"TMS= ";
 color(15);
 cout<<std::setprecision(4)<<c/(tiempo_ocupado/3600)<<"c/h";
 color(10);
 cout<<" TML= ";
 color(15);
 cout<<std::setprecision(4)<<c/8<<"c/h"<<endl;
 color(10);
 cout<<" TMS= Tasa Media de servicio\n TML= Tasa media de Llegada\n";
 
 c=c+cola;
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
cout<<"\n veces que llego alguien= "<<c<<"\n";    
 color(10);
 cout<<"TMS= ";
 color(15);
 cout<<std::setprecision(4)<<c/(tiempo_ocupado/3600)<<"c/h";
 color(10);
 cout<<" TML= ";
 color(15);
 cout<<std::setprecision(4)<<c/(tiempo_servicio_liberara/3600)<<"c/h"<<endl;
 color(10);
 cout<<" TMS= Tasa Media de servicio\n TML= Tasa media de Llegada\n"<<endl;
 cout<<" hora que termino: ";
 pasar_hora(tiempo_servicio_liberara);
 cout<<endl;
}

 resp='s'; 
                                
   
  cout<<"volver a empesar? s=si n=no \n";
  cin>>resp; 

}while((resp!='n'));
cout<<"\n";  
cout<<"\n";  
color(27);
cout<<"CRECION:\n";color(27);
cout<<"Luis Antonio Garcia Aguirre\n";  
cout<<"Carné: 1690-10-1493\n"; 
cout<<"Curso: Simulacion y Modelacion\n"; 
cout<<"UMG 2014\n\n"; 


     getch();
     cout<<"Agradecimientos a Luis Antonio Garcia Aguirre\n";  
     return 1;
}
