/**
 * Nombre: TokenRing.c
 * Objetivo: enviar datos a traves de MPI
 * Autor: Alejandro Pérez Toga
 * Fecha: 9 sep 2015
 */
#include <mpi.h>
#include <stdio.h>
#include <math.h>

//variable para enviar dato entre los procesadores
double tI= 0;
double tF=0;
int numero=2; //numero de veces que estar el TokenRing

int main(int argc,char* argv[]){

  //id de cada proceso y numero total de procesadores
  int idProc, numProc;
  int i= 0,dato = 100;
  //preguntar el nuemero de vueltas que dará el dato

/*
  printf("Cuantas veces se hara la comunicacion de token Ring?\n");
  numero = scanf("%d",&num);
*/
  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &idProc);
  MPI_Comm_size (MPI_COMM_WORLD, &numProc);

//Proceso 0  envia al proceso 1 y recive del proceso 9 
if(idProc == 0){

  while(i<=numero){
    tI = MPI_Wtime();
    MPI_Send(&dato,1, MPI_INT,1, 200,MPI_COMM_WORLD);
    printf("Soy el proceso: %d envio dato:  %d al proceso 1 \n",idProc,dato );

    MPI_Recv(&dato,1, MPI_INT,9, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    printf("Soy el proceso: %d recivi dato:  %d del  proceso 9   \n",idProc,dato );

    tF= MPI_Wtime();
    printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
    i=i+1;

    if (i == numero) {
      /* code */
      break;
    }


    printf("\n");
  }
}
//Proceso 1 recive del proceso 0 y envia al 2
if(idProc == 1){
  while(i<numero){
    tI = MPI_Wtime();
    MPI_Recv(&dato,1, MPI_INT,0, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    printf("Soy el proceso: %d recivi dato:  %d del  proceso 0 \n",idProc,dato );
    dato = dato + 10;

    MPI_Send(&dato,1, MPI_INT,2, 200,MPI_COMM_WORLD);
    printf("Soy el proceso: %d envio dato:  %d al proceso 2 \n",idProc,dato );

    tF= MPI_Wtime();
    printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
    i=i+1;
    printf("\n");
  }
}
//Proceso 2 recive del  proceso 1 y manda al 3
if(idProc == 2){
  while(i<numero){
    tI = MPI_Wtime();
    MPI_Recv(&dato,1, MPI_INT,1, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    printf("Soy el proceso: %d recivi dato:  %d del  proceso 1 \n",idProc,dato );
    dato = dato + 10;

    MPI_Send(&dato,1, MPI_INT,3, 200,MPI_COMM_WORLD);
    printf("Soy el proceso: %d envio dato:  %d al proceso 3 \n",idProc,dato );

    tF= MPI_Wtime();
    printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
    i=i+1;
    printf("\n");
  }
}
  //Proceso 3 recive del  proceso 2 y manda al 4
  if(idProc == 3){
    while(i<numero){
      tI = MPI_Wtime();
      MPI_Recv(&dato,1, MPI_INT,2, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      printf("Soy el proceso: %d recivi dato:  %d del  proceso 2 \n",idProc,dato );
      dato = dato + 10;

      MPI_Send(&dato,1, MPI_INT,4, 200,MPI_COMM_WORLD);
      printf("Soy el proceso: %d envio dato:  %d al proceso 4 \n",idProc,dato );

      tF= MPI_Wtime();
      printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
      i=i+1;
      printf("\n");
    }
  }
    //Proceso 4 recive del  proceso 3 y manda al 5
    if(idProc == 4){
      while(i<numero){
        tI = MPI_Wtime();
        MPI_Recv(&dato,1, MPI_INT,3, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("Soy el proceso: %d recivi dato:  %d del  proceso 3 \n",idProc,dato );
        dato = dato + 10;

        MPI_Send(&dato,1, MPI_INT,5, 200,MPI_COMM_WORLD);
        printf("Soy el proceso: %d envio dato:  %d al proceso 5 \n",idProc,dato );

        tF= MPI_Wtime();
        printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
        i=i+1;
        printf("\n");
      }
    }

      //Proceso 5 recive del  proceso 4 y manda al 6
      if(idProc == 5){
        while(i<numero){
          tI = MPI_Wtime();
          MPI_Recv(&dato,1, MPI_INT,4, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
          printf("Soy el proceso: %d recivi dato:  %d del  proceso 4 \n",idProc,dato );
          dato = dato + 10;

          MPI_Send(&dato,1, MPI_INT,6, 200,MPI_COMM_WORLD);
          printf("Soy el proceso: %d envio dato:  %d al proceso 6 \n",idProc,dato );

          tF= MPI_Wtime();
          printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
          i=i+1;
          printf("\n");
        }
      }
        //Proceso 6 recive del  proceso 5 y manda al 7
        if(idProc == 6){
          while(i<numero){
            tI = MPI_Wtime();
            MPI_Recv(&dato,1, MPI_INT,5, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            printf("Soy el proceso: %d recivi dato:  %d del  proceso 5 \n",idProc,dato );
            dato = dato + 10;

            MPI_Send(&dato,1, MPI_INT,7, 200,MPI_COMM_WORLD);
            printf("Soy el proceso: %d envio dato:  %d al proceso 7 \n",idProc,dato );

            tF= MPI_Wtime();
            printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
            i=i+1;
            printf("\n");
          }
        }
        //Proceso 7 recive del  proceso 6 y manda al 8
        if(idProc == 7){
          while(i<numero){
            tI = MPI_Wtime();
            MPI_Recv(&dato,1, MPI_INT,6, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            printf("Soy el proceso: %d recivi dato:  %d del  proceso 6 \n",idProc,dato );
            dato = dato + 10;

            MPI_Send(&dato,1, MPI_INT,8, 200,MPI_COMM_WORLD);
            printf("Soy el proceso: %d envio dato:  %d al proceso 8 \n",idProc,dato );

            tF= MPI_Wtime();
            printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
            i=i+1;
            printf("\n");
          }
        }
        //Proceso 8 recive del  proceso 7 y manda al 9
        if(idProc == 8){
          while(i<numero){
            tI = MPI_Wtime();
            MPI_Recv(&dato,1, MPI_INT,7, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            printf("Soy el proceso: %d recivi dato:  %d del  proceso 7 \n",idProc,dato );
            dato = dato + 10;

            MPI_Send(&dato,1, MPI_INT,9, 200,MPI_COMM_WORLD);
            printf("Soy el proceso: %d envio dato:  %d al proceso 9 \n",idProc,dato );

            tF= MPI_Wtime();
            printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
            i=i+1;
            printf("\n");
          }
        }
        //Proceso 9 recive del  proceso 8 y manda al 0
        if(idProc == 9){
          while(i<numero){
            tI = MPI_Wtime();
            MPI_Recv(&dato,1, MPI_INT,8, 200,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            printf("Soy el proceso: %d recivi dato:  %d del  proceso 8 \n",idProc,dato );
            dato = dato + 10;

            MPI_Send(&dato,1, MPI_INT,0, 200,MPI_COMM_WORLD);
            printf("Soy el proceso: %d envio dato:  %d al proceso 0 \n",idProc,dato );

            tF= MPI_Wtime();
            printf("El tiempo que duro la comunicacion es: %e\n",tF-tI );
            i=i+1;
            printf("\n");
          }
        }
/*
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
*/

  MPI_Finalize();



  return 0;
}
