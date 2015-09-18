/*
 * Nombre : tokenring.c
 * Objetivo: construye un anillo de procesos con directivas
 *  de comunicación  MPI y da un número de vueltas
 * Autor: alumno de MSC
 *Fecha: 14 septiembre  2015
 */

#include <stdio.h>
#include <mpi.h>


int nv = 0;
int i = 0;

int main(int argc,  char *argv[])
{

  
  int rank, size;  // rank  id de cada proceso  size: número total de procesos
  
  int dato;

  int fst = 1;

  MPI_Init(&argc, &argv);               	/* starts MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);	/* get current process id */
  MPI_Comm_size (MPI_COMM_WORLD, &size);	/* get number of processes */
  

   do {
  

  if (rank == 0) {  //Procesador 0
   
   if (fst)
   {
    // solicita número de vueltas y número de procesos
    printf("Teclea el número de vueltas: ");
    scanf("%d", &dato);
    nv = dato;
    fst = 0;  // Bandera
    MPI_Send(&nv, 1, MPI_INT, ((rank+1)%size), 200,MPI_COMM_WORLD);
    printf( "Soy el proceso: %d enviando el dato: %d\n", rank, nv);
  }

     
   
   MPI_Recv(&nv, 1, MPI_INT, (size-1) , 200,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
   printf( "Soy el proceso: %d recibí el dato: %d\n", rank, nv);
   nv--;

   if (nv == 0){
   	printf(" Valor de nv=0, Proceso terminado ...\n\n");
   	return 0;
   }

   MPI_Send(&nv, 1, MPI_INT, ((rank+1)%size), 200,MPI_COMM_WORLD);
   printf( "Soy el proceso: %d envié el dato: %d\n", rank, nv);
  }


 
  if (rank != 0){
  	MPI_Recv(&nv, 1, MPI_INT, rank-1, 200,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  	printf( "Soy el proceso: %d recibí el dato: %d\n", rank, nv);
    MPI_Send(&nv, 1, MPI_INT, ((rank+1)%size) , 200,MPI_COMM_WORLD);
    printf( "Soy el proceso: %d enviando el dato: %d\n", rank, nv);
  }

  } while ( nv >=0);
  
  MPI_Finalize();  // close de mpi environment
  return 0;
}
