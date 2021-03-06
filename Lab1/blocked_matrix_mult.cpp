#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>
const int MAX=10;

using namespace std;
int main()
{
    // def matrices, A, B, y R=resultado
    double A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    srand (time(NULL));
    // Def Matrices con valores aleatorios, R con 0's
    for (int i=0;i<MAX;i++){
      for (int j=0;j<MAX;j++){
        A[i][j]=rand()%100;
        B[i][j]=rand()%100;
        R[i][j]=0;
      }
    }
    int B2=MAX/2;
    // def variables para el tiempo
    chrono::time_point<chrono::system_clock> start, end;
    // multiplication classica - 3 bucles anidados
    start = chrono::system_clock::now();
    // loops que se van moviendo deacuerdo a nuestro divisor de bloque
    for (int ii = 0; ii < MAX; ii+=B2) {
      for (int jj = 0; jj < MAX; jj+=B2) {
        for (int kk = 0; kk < MAX; kk+=B2) {
          //loops originales los cuales ahora solo llegan hasta los puntos de division de bloque
          for (int i = ii; i < ii+B2; i++) {
            for (int j = jj; j < jj+B2; j++) {
              for (int k = kk; k < kk+B2; k++) {
                //operacion original de multiplicacion de matrices - clasica
                R[i][j] += A[i][k]*B[k][j];
              }
              cout<<"j "<<&j<<" ";
            }
            cout<<"i "<<&i<<endl;
          }
          cout<<"kk "<<kk<<endl;
        }
        cout<<"jj "<<jj<<endl;
      }
      cout<<"ii "<<ii<<endl;
    }
    end = chrono::system_clock::now();
    // Diferencia entre el final e incio de tiempo de ejecucion
    chrono::duration<double> elapsed_seconds = end - start;
    // Fin de ejecucion
    time_t end_time = chrono::system_clock::to_time_t(end);
    cout<<"Multiplicacion de Matrices - Bloques"<<endl;
    cout << "calculo terminado en  " << ctime(&end_time)
        << "tiempo transcurrido: " << elapsed_seconds.count() << "s\n";
    /*
    // visualizacion del resultado - solo para comprar respuesta
    for (int i=0;i<MAX;i++){
      for (int j=0;j<MAX;j++){
        cout<<R[i][j]<<" ";
      }
      cout<<"\n";
    }
    */
}
