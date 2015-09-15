/**
 * Nombre: Operaciones2.c
 * Objetivo: muestra como asignar tareas independientes
 * a cada procesador
 * Autor: Alejandro Pérez Toga
 * Fecha: 9 sep 2015
 */
#include <mpi.h>
#include <stdio.h>
#include <math.h>

#define c 300
#define r 300

//Declarar las matrices
int matA[r][c];
int matB[r][c];
int matC[r][c];

double tI= 0;
double tF=0;

int i,j;
double total;
//funciones para llenar las matrices

void llenarMat(){
  for(i=0;i<r;i++){
    for(j=0; j<c; j++){
      matA[i][j]=rand();
      matB[i][j]=rand();
    }
  }
}


int main(int argc,char* argv[]){

  //id de cada proceso y numero total de procesadores
  int idProc, numProc;
  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &idProc);
  MPI_Comm_size (MPI_COMM_WORLD, &numProc);

  llenarMat();
  //tI = MPI_Wtime();


  if(idProc == 0){
    //tI = MPI_Wtime();
    printf("Soy el proceso: %d me toco hacer la suma de las matrices \n",idProc);
    for( i=0;i<r;i++){
       for(j=0; j<c; j++){
             matA[i][j]=  matA[i][j] +   matA[i][j];
        }
    }
    //tF= MPI_Wtime();
    //printf("El tiempo de la suma es: %e\n",tF-tI );
  }

  if(idProc == 1){
    //tI = MPI_Wtime();
      printf("Soy el proceso: %d me toco hacer la resta \n",idProc);
      for(i=0;i<r;i++){
        for(j=0; j<c; j++){
            matC[i][j]=  matA[i][j] -   matB[i][j];
        }
      }
    //  tF= MPI_Wtime();
    //  printf("El tiempo de la resta es: %e\n",tF-tI );

  }
  if(idProc == 2){
  //  tI = MPI_Wtime();
       printf("Soy el proceso: %d me toco hacer la multiplicacion \n",idProc);
       //OPERACION DE MULTIPLICACION
        for (i=1;i<=c;i++){
          for (j=1;j<=r;j++){
              total=total+matA[i][j]*matB[j][i];
          }
          matC[i][j]=total;
       }
    //   tF= MPI_Wtime();
      // printf("El tiempo de la multiplicacion es: %e\n",tF-tI );
  }

  if(idProc == 3){
    //tI = MPI_Wtime();
       printf("Soy el proceso: %d me toco hacer el total \n",idProc);
       //OPERACION DE MULTIPLICACION
        for (i=1;i<=c;i++){
          for (j=1;j<=r;j++){
              total=total+matA[i][j]*matB[j][i];
          }
       }
    //   printf("El total es: %e\n",total );
      // tF= MPI_Wtime();
       //printf("El tiempo del total es: %e\n",tF-tI );

  }
//  tF= MPI_Wtime();
  //printf("El tiempo total del programa es: %e\n",tF-tI );
  MPI_Finalize();

  return 0;

}
