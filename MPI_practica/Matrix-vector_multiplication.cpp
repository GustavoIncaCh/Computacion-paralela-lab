// Matrix-vector_multiplication.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <malloc.h>
#include <iostream>
#include <time.h>
const double TAM_MAX = 12288;

using namespace std;


int main()
{
    double local_A[TAM_MAX], local_x[TAM_MAX, local_y[TAM_MAX];
    int m, local_m, n, local_n, my_rank, comm_sz;
    MPI_Comm comm;
    double start, finish;
    MPI_Init(NULL, NULL);
    comm = MPI_COMM_WORLD;
    MPI_Comm_size(comm, &comm_sz);
    MPI_Comm_rank(comm, &my_rank);
    double* x;
    n = TAM_MAX;
    m = TAM_MAX;
    local_m = TAM_MAX
    local_n = TAM_MAX;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            double num_rand;
            num_rand = rand() % 100 + 1.0;
            local_A[i * n + j] = num_rand;
        }
    }
    for (int i = 0; i < 10; i++) {
        double num_rand;
        num_rand = rand() % 100 + 1.0;
        local_x[i] = num_rand;
        local_y[i] = 0;
    }

    int local_i, j;
    int local_ok = 1;
    x = (double*)malloc(n * sizeof(double));
    if (x == NULL) local_ok = 0;
    MPI_Allgather(local_x, local_n, MPI_INT,
        x, local_n, MPI_INT, comm);
    start = MPI_Wtime();
    for (local_i = 0; local_i < m; local_i++) {
        local_y[local_i] = 0.0;
        for (j = 0; j < n; j++)
            local_y[local_i] += local_A[local_i * n + j] * x[j];
    }
    finish = MPI_Wtime();
    if (my_rank == 0) {
        cout << "Tiempo transcurrido " << finish - start << " segundos." << endl;
    }

    free(local_A); free(local_x); free(local_y);
    MPI_Finalize();
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
