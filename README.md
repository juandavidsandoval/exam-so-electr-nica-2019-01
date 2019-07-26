# exam-so-electr-nica-2019-01
## Primer parcial de sistemas operativos.
## Primer punto: Continuando con el análisis del problema podemos evidenciar que la segunda parte se demora mucho más que la primera. Este se debe a que en la segunda parte el abrir y cerrar puerta están dentro del ciclo for por lo cual por cada una de interacciones lo abre y lo cierra, por esto se demora mucho más que cuando solo se abre y se cierra una vez la puerta.
## Segundo punto: El resultado final es 89.285, se hicieron dos workers uno que recogiera a la variable v con la división de las variables declaradas en ese worker y con esa v pudimos llegar al resultado final. 
## Tercer punto: Evidenciamos que el hijo siempre espera al padre mediante un waitpid, aunque aparece la carpeta justo en el momento antes de que el hijo se ejecute.
## Cuarto punto 1: Cuando ejecutamos dos procesos de la forma 5:100, vemos como cada uno de ellos se ejecuta 5 veces usando el 100% de la CPU. En el proceso PID: 0, vemos que en paralelo mientras éste se ejecuta las 5 veces, el proceso PID: 1 se encuentra listo (READY) para ser ejecutado. Una vez el 0 ha terminado entra en estado DONE, abriendo paso al 1 para que lleve a cabo sus 5 repeticiones. Observamos que es un proceso no-expropiativo por lo que cada uno de los procesos termina su ciclo para darle paso al otro de acceder a la CPU.
## Cuarto punto 2: El proceso 0 (PID: 0) se ejecuta 4 veces usando un 100% de la cpu, mientras el proceso 1 (PID: 1) se halla listo (READY) para ser ejecutado. Una vez terminadas las repeticiones del proceso 0 (DONE), el proceso 1 (que es de entrada y salida → IO) se posiciona para ser ejecutado una sola vez pero debido a que es un proceso IO, se emulan las 4 repeticiones que debe esperar de la ejecución del proceso 0 en la cpu para que ésta pase a ejecutarlo y finalmente ambos queden en estado DONE.
