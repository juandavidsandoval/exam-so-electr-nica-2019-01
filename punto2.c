
#include <stdio.h>

#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include <time.h>
#include <pthread.h>
float x=1250;
float y= 250;
float z= 25;

float v;
float resul=0;



pthread_mutex_t puerta;

void *crear_puerta(){
	pthread_mutex_init(&puerta,NULL);
}
void *cerrar_puerta (){
	pthread_mutex_lock(&puerta);
}
void *abrir_puerta (){
	pthread_mutex_unlock(&puerta);
}
void *destruir_puerta (){
	pthread_mutex_destroy(&puerta);
}

void *worker() {
    cerrar_puerta();
    
    v = z/y;
    
    
    abrir_puerta();
    return NULL;
}

void *worker1() {
      cerrar_puerta();
      resul = x * v;

      abrir_puerta();   
      return(NULL);
}



int main(int argc, char *argv[]) {

    crear_puerta();
    pthread_t p1, p2;
    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker1, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf ("Initial value : %f\n", resul);

    return 0;

    destruir_puerta();



}
