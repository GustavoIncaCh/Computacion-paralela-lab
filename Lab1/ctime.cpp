#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>
const int MAX=1020;

using namespace std;
int main()
{
    // Def Matriz
    double A[MAX][MAX], x[MAX], y[MAX];
    srand (time(NULL));
    // Def Matriz con valores aleatorios, el vector y con 0's
    for (int i=0;i<MAX;i++){
      for (int j=0;j<MAX;j++){
        A[i][j]=rand()%100;
      }
      x[i]=rand()%100;
      y[i]=0;
    }

    //Primer loop
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    for (int i=0;i<MAX;i++){
      for (int j=0;j<MAX;j++){
        y[i]+=A[i][j]*x[j];
      }
    }

    end = chrono::system_clock::now();
    // Diferencia entre el final e incio de tiempo de ejecucion
    chrono::duration<double> elapsed_seconds = end - start;
    // Fin de ejecucion
    time_t end_time = chrono::system_clock::to_time_t(end);
    cout<<"Primer Loop"<<endl;
    cout << "calculo terminado en " << ctime(&end_time)
        << "tiempo transcurrido: " << elapsed_seconds.count() << "s\n";

    // Vector X=0
    for (int i=0;i<MAX;i++){
      y[i]=0;
    }
    // Segundo loop
    chrono::time_point<chrono::system_clock> start1, end1;
    start1 = chrono::system_clock::now();
    for (int j=0;j<MAX;j++){
      for (int i=0;i<MAX;i++){
        y[i]+=A[i][j]*x[j];
      }
    }
    end1 = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start1;
    time_t end_time1 = chrono::system_clock::to_time_t(end1);
    cout<<"Segundo Loop"<<endl;
    cout << "calculo terminado en " << ctime(&end_time1)
        << "tiempo transcurrido: " << elapsed_seconds1.count() << "s\n";
}
