/**
 * Nombre: Operacionesbasics.c
 * Objetivo: muestra como asignar tareas independientes
 * a cada procesador
 * Autor: Alejandro Pérez Toga
 * Fecha: 4 sep 2015
 */
#include <mpi.h>
#include <stdio.h>

int main(int argc,char* argv[]){
  //Declaramos dos numeros enteros
  int num1 = 10;
  int num2 = 10;
  //id de cada proceso y numero total de procesadores
  int idProc, numProc;

  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &idProc);
  MPI_Comm_size (MPI_COMM_WORLD, &numProc);

  if(idProc == 0){
    printf("Soy el proceso: %d me toco hacer la suma \n",idProc);
    printf("La suma es: %d \n",num1+num2);
  }
  if(idProc == 1){
      printf("Soy el proceso: %d me toco hacer la resta \n",idProc);
      printf("La diferencia  es: %d \n",num1-num2);

  }
  if(idProc == 2){
      printf("Soy el proceso: %d me toco hacer la multiplicacion \n",idProc);
      printf("El producto  es: %d \n",num1*num2);

  }
  if(idProc == 3){
      printf("Soy el proceso: %d me toco hacer la division \n",idProc);
      printf("El cociento  es: %f \n",(float)num1/(float)num2);

  }

  MPI_Finalize();

  return 0;

}
