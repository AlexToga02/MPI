/**
 * Nombre: reduce_operaciones.c
 * Objetivo: realiza la funcion MPI_Reduce suma,resta multiplicacion y divisio
 * Autor: Alejandro Pérez Toga
 * Fecha: 11 sep 2015
 */
#include <mpi.h>
#include <stdio.h>


int sumatoria,prodGlobal,maxGlobal,minGlobal;


int main(int argc,char* argv[]){

  //id de cada proceso y numero total de procesadores
  int idProc, numProc;
  int local=10;

  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &idProc);
  MPI_Comm_size (MPI_COMM_WORLD, &numProc);


  MPI_Reduce(&local, &sumatoria, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  MPI_Reduce(&local, &prodGlobal, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
  MPI_Reduce(&local, &maxGlobal, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
  MPI_Reduce(&local, &minGlobal, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

  if (idProc == 0){
    printf("La sumatoria es:  %d\n", sumatoria);
    printf("El producto global es: %d\n",prodGlobal);
    printf("El maximo es:   %d\n", maxGlobal);
    printf("El minimo es:   %d\n", minGlobal);
  }


  MPI_Finalize();
  return 0;

}
