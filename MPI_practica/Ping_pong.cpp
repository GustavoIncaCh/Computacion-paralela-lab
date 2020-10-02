// mpi_tutorial.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <mpi.h>

using namespace std;
int main()
{
	int my_rank;
	int world_size;
	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	//std::cout << "Hello World from process " << my_rank << " out of " << world_size << " processes!!!" << std::endl;

	
	for (int i = 0; i < 12; i++) {
		int ball=0;
		if (my_rank == i % 2) {
			ball++;
			std::cout << "El procedimiento " << my_rank << " pateo la pelota, van " << ball << " golpes" << std::endl;
			MPI_Send(&ball, 1, MPI_INT, !my_rank, 0, MPI_COMM_WORLD);
		}
		else
		{
			MPI_Recv(&ball, 1, MPI_INT, !my_rank, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
			std::cout << "El procedimiento "<<my_rank<<" recibe la pelota de "<<!my_rank <<" van " << ball << " golpes" << endl;
		}
	}
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
