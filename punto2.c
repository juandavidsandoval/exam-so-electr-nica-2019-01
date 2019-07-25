
#include <stdio.h>

#include <stdlib.h>
#include "common.h"
#include "common_threads.h"


float x = 1250;
float y = 350;
float z = 25;
float v = 0 ;
float resultado = 0;



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

void *worker23() {
    cerrar_puerta();
    v = z/y;
    abrir_puerta();
    return 0;
}

void *worker1() {
     cerrar_puerta();
     float v;
     resultado = x * v;

     abrir_puerta();   
     return(0);
}



int main(int argc, char *argv[]) {


    pthread_t p1, p2;
    crear_puerta();
    
    Pthread_create(&p1, NULL, worker1, NULL);
    Pthread_create(&p2, NULL, worker23, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf ("RESULTADO DE OPERACIÓN : %f\n", resultado);

    printf ("Resultado de V: %f\n", v);
    return 0;

    destruir_puerta();



}
