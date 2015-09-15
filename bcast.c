/**
 * Nombre: MPI_Bcast.c
 * Objetivo: realiza el envio dedatos a traves de un grupo de procesadores
 * Autor: Alejandro Pérez Toga
 * Fecha: 11 sep 2015
 */
#include <mpi.h>
#include <stdio.h>


int main(int argc,char* argv[]){

  int vec[4];
  vec[0]=0;
  vec[1]=0;
  vec[2]=0;
  vec[3]=0;
  //id de cada proceso y numero total de procesadores
  int idProc, numProc;



  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &idProc);
  MPI_Comm_size (MPI_COMM_WORLD, &numProc);



  if(idProc == 0){
      vec[0]=8;
      vec[1]=7;
      vec[2]=6;
      vec[3]=4;

      printf("Soy el proceso: %d envie los datos a los procesadores \n",idProc);
  }
MPI_Bcast(&vec,4,MPI_INT,0,MPI_COMM_WORLD);
// se envia el vector . tipo int, del proceso 0 ,aa)


//Todos los procesos que sean diferente de 0 reciben el vector
  if(idProc != 0){
    int i=0;
    printf("Soy el proceso: %d recivi los datos \n",idProc);
    for (i=0;i < 4; i++) {
      printf("Elemento: [%d]= %d \n",i,vec[i]);
    }
  }

  MPI_Finalize();
  return 0;

}
