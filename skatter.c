/**
*Uso de la función MPI_Allreduce con MPI*
*Rafael Salazar*
*COPYRIGHT FAXCORP 2015-3915 DO NOT REPLICATE*
**/

#include <stdio.h>
#include <mpi.h>

MPI_Status status;

int main (int argc, char* argv[]) {            
  int miID, procesos, local[4], localplus[4], externo;
  
  srand(time(NULL));
  
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &miID);
  MPI_Comm_size(MPI_COMM_WORLD, &procesos);
  
  if (miID == 0)
  {
    local[0] = rand() % 100 + 1;
    local[1] = rand() % 100 + 1;
    local[2] = rand() % 100 + 1;
    local[3] = rand() % 100 + 1;
  }
    
  
  //MPI_Scatter(dato, n° de datos, tipo, variable de destino, n° de datos a recibir, comunicador)
  MPI_Scatter(&local, 1, MPI_INT, &externo, 1, MPI_INT, 0, MPI_COMM_WORLD);
  
  printf("El proceso %d tiene el número %d\n", miID, externo);
  
  MPI_Gather(&externo, 1, MPI_INT, &localplus, 1, MPI_INT, 0, MPI_COMM_WORLD);
  
  if (miID == 0)
    printf ("Datos: [%d,%d,%d,%d]\n",localplus[0], localplus[1], localplus[2], localplus[3]);
  
  MPI_Finalize();
  return 0;
}
