/**
 * Nombre: send.c
 * Objetivo: enviar datos a traves de MPI
 * Autor: Alejandro Pérez Toga
 * Fecha: 9 sep 2015
 */
#include <mpi.h>
#include <stdio.h>
#include <math.h>

//variable para enviar dato entre los procesadores
int dato= 0;
double tI= 0;
double tF=0;

int main(int argc,char* argv[]){

  //id de cada proceso y numero total de procesadores
  int idProc, numProc;
  int i= 0;

  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &idProc);
  MPI_Comm_size (MPI_COMM_WORLD, &numProc);

//Proceso  que va a enviar los datos
int  n= 10;

  if(idProc == 0){
    while(i<10){
      tI = MPI_Wtime();
      dato = 100;
      MPI_Send(&dato,1, MPI_INT,1, 200,MPI_COMM_WORLD);
      printf("Soy el proceso: %d envio dato:  %d al proceso 1 \n",idProc,dato );

      MPI_Recv(&dato,1, MPI_INT,1, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      printf("Soy el proceso: %d recivi dato:  %d del  proceso 0 \n",idProc,dato );

      tF= MPI_Wtime();
      printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );

      i=i+1;
      }


  }

//Proceso 1 que va a recibir los datos
  if(idProc == 1){
    while(i<10){
      tI = MPI_Wtime();
      MPI_Recv(&dato,1, MPI_INT,0, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      printf("Soy el proceso: %d recivo el dato: %d  del  proceso 0 \n",idProc,dato);
      dato = dato *20;
      MPI_Send(&dato,1, MPI_INT,0, 200,MPI_COMM_WORLD);
      printf("Soy el proceso: %d envio dato:  %d al proceso 1 \n",idProc,dato );
      tF= MPI_Wtime();
      printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );

      i=i+1;
      }

  }


/*
while (i<10) {
  /* code */
  if(idProc == 0){

      tI = MPI_Wtime();
      dato = 100;
      MPI_Send(&dato,1, MPI_INT,1, 200,MPI_COMM_WORLD);
      printf("Soy el proceso: %d envio dato:  %d al proceso 1 \n",idProc,dato );

      MPI_Recv(&dato,1, MPI_INT,1, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      printf("Soy el proceso: %d recivi dato:  %d del  proceso 0 \n",idProc,dato );

      tF= MPI_Wtime();
      printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );

  }

  if(idProc == 1){
      tI = MPI_Wtime();
      MPI_Recv(&dato,1, MPI_INT,0, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      printf("Soy el proceso: %d recivo el dato: %d  del  proceso 0 \n",idProc,dato);
      dato = dato *20;
      MPI_Send(&dato,1, MPI_INT,0, 200,MPI_COMM_WORLD);
      printf("Soy el proceso: %d envio dato:  %d al proceso 1 \n",idProc,dato );
      tF= MPI_Wtime();
      printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
  }


  i=i+1;
}


  MPI_Finalize();



  return 0;
}
