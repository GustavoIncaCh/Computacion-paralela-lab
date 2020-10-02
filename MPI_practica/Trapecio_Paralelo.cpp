// Trapecio_Paralelo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <mpi.h>



double Trapecio(double left_endpt, double right_endpt, int trap_count, double base_len) {
	double estimate, x;
	int i;
	estimate = ((left_endpt) + (right_endpt)) / 2.0;
	for (i = 1; i <= trap_count - 1; i++) {
		x = left_endpt + i * base_len;
		estimate += (x);
	}
	estimate = estimate * base_len;
	return estimate;
}

using namespace std;
int main()
{
	int my_rank;
	int world_size;
	int n = 24;
	int local_n;
	double a = 0.0, b = 3.0, h, local_a, local_b;
	double local_int, total_int;
	int source;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	h = (b - a) / n;
	local_n = n / world_size;

	local_a = a + my_rank * local_n * h;
	local_b = local_a + local_n * h;
	local_int = Trapecio(local_a, local_b, local_n, h);
	
	if (my_rank != 0) {
		MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	}
	else
	{
		total_int = local_int;
		for (source = 1; source < world_size; source++) {
			MPI_Recv(&local_int, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
			total_int += local_int;
		}
	}
	if (my_rank == 0) {
		cout << "Con n = " << n << " trapezoides, nuestra estimacion de la integral de " << a << " a " << b << " = " << total_int << endl;
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
