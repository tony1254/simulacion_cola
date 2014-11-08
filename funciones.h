#define _funciones_h_
#include "colores.h"
// LIBRERIA DE TONY
float urand(){
      return((float)rand()/RAND_MAX);
      }

float genexp(double lamda){
    float u,x;
    u=urand();
    x=(-1/lamda)*log(u);
    return(x);
    }
    


float get_random(int n) {
    struct timeval num;
    gettimeofday(&num, NULL);
    srand(num.tv_usec);
    return rand() % n + 1;
}

// LIBRERIA DE TONY

/*
int main () {
    printf("Random number between 1 and 12: %d \n", get_random(12));
    return 0;
}*/
