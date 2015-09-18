/**
* Nombre: mpreduce.c
* Objetivo: realiza la funcion MPI_Reduce de todos los procesos
* Autor: alumnos de AI
* Fecha: 11 septiembre de 2015
*/

#include <mpi.h>
#include <stdio.h>


int  global_sum, global_mul, global_max, global_min;


// Método main
 
int main(int argc, char* argv[])
{
 
int local_sum = 10;
      
   // id de cada proceso y numero total procesadores
  int idProc, numProc;
  
  MPI_Init (&argc, &argv);                        /* starts MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &idProc);        /* get current process id */ 
  MPI_Comm_size (MPI_COMM_WORLD, &numProc);        /* get number of processes */

  if (idProc == 0)
    local_sum = 100;
  


  MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, 
   	MPI_SUM, 0, MPI_COMM_WORLD);

  MPI_Reduce(&local_sum, &global_mul, 1, MPI_INT, 
    MPI_PROD, 0, MPI_COMM_WORLD); 

  MPI_Reduce(&local_sum, &global_max, 1, MPI_INT, 
    MPI_MAX, 0, MPI_COMM_WORLD); 

  MPI_Reduce(&local_sum, &global_min, 1, MPI_INT, 
    MPI_MIN, 0, MPI_COMM_WORLD); 

  if (idProc == 0)
  {
    printf("La suma es:%d\n", global_sum);
    printf("El producto es:%d\n", global_mul);
    printf("El número mayor es :%d\n", global_max);
     printf("El número menor es :%d\n", global_min);
  }



  
  MPI_Finalize();
  return 0;
}