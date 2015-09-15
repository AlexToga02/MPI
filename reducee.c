/**
 * Nombre: reducee.c
 * Objetivo: realiza la funcion MPI_Reduce
 * Autor: Alejandro Pérez Toga
 * Fecha: 11 sep 2015
 */
#include <mpi.h>
#include <stdio.h>


int local_sum,global_sum;


int main(int argc,char* argv[]){

  //id de cada proceso y numero total de procesadores
  int idProc, numProc;
  local_sum=10;

  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &idProc);
  MPI_Comm_size (MPI_COMM_WORLD, &numProc);


  MPI_Reduce(&local_sum, &global_sum,1,MPI_INT,
  MPI_SUM,0,MPI_COMM_WORLD);

  if (idProc == 0)
    printf("La suma es:  %d\n", global_sum);

  MPI_Finalize();
  return 0;

}
