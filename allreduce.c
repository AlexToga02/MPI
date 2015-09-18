/**
 * Nombre: allreduce.c
 * Objetivo: realiza la funcion MPI_AllReduce suma,resta multiplicacion y divisio
 * Autor: Alejandro Pérez Toga
 * Fecha: 18 sep 2015
 */

#include <mpi.h>
#include <stdio.h>


int global_sum,prodGlobal,maxGlobal,minGlobal;

 //Método main
int main(int argc,char* argv[]){

  //id de cada proceso y numero total de procesadores
  int idProc, numProc;
  int local=10;

  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &idProc);
  MPI_Comm_size (MPI_COMM_WORLD, &numProc);

  if (idProc == 0) {
    local =2;
    /* code */
  }

  MPI_Allreduce(&local, &global_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
  MPI_Allreduce(&local, &prodGlobal, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
  MPI_Allreduce(&local, &maxGlobal, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
  MPI_Allreduce(&local, &minGlobal, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);



  printf("Soy el proceso %d, el globla_sum es: %d \n",idProc,global_sum );
  printf("Soy el proceso %d, el prodGlobal es: %d \n",idProc,prodGlobal );
  printf("Soy el proceso %d, el max es: %d \n",idProc,maxGlobal );
  printf("Soy el proceso %d, el min: %d \n",idProc,minGlobal );

  MPI_Finalize();
  return 0;

}
