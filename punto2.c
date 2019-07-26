
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"





float v = 0 ;




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

void *worker23(void *arg) {
    cerrar_puerta();
    float y=350;
    float z=25;
    v = z/y;
    abrir_puerta();
    return 0;
}

void *worker1(void *arg) {
     cerrar_puerta();
     float x=1250;
     sleep(2);
     v = x * v;

     abrir_puerta();   
     return(0);
}



int main(int argc, char *argv[]) {


    pthread_t p1, p2;
    crear_puerta();
    
    Pthread_create(&p1, NULL, worker23, NULL);
    Pthread_create(&p2, NULL, worker1, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf ("RESULTADO DE OPERACIÓN : %f\n", v);

    
    return 0;

    destruir_puerta();



}
