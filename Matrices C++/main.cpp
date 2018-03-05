#include <iostream>
#include <ctime>
using namespace std;
clock_t Tiempo2, Tiempo1;
int main() {
		long double TiempoTotal, t;
        double promedio [10];
        int elementos;
        for (int i = 10; i <= 100; i=i+10) {
            int tamanno = i;
            int matrizuno [tamanno][tamanno];
            int matrizdos [tamanno][tamanno];
            for (int j = 0; j < tamanno; j++) {
                for (int k = 0; k < tamanno; k++) {
                    matrizuno[j][k] = 1;
                    matrizdos[j][k] = 2;
                }
            }
            int matriztres [tamanno][tamanno];
            for (int h = 0; h < 10; h++) {
                Tiempo1 = clock();
                for (int j = 0; j < tamanno; j++) {
                    for (int k = 0; k < tamanno; k++) {
                        matriztres[j][k] = 0;
                        for (int f = 0; f < tamanno; f++) {
                            matriztres[j][k] += matrizdos[j][f] * matrizuno[f][k];
                        }
                    }
                }
                Tiempo2 = clock();
                TiempoTotal = ((double)(Tiempo2 - Tiempo1)/CLOCKS_PER_SEC)*1000;
                elementos = tamanno * tamanno;
                t = (TiempoTotal / ((tamanno * elementos) + (tamanno - 1) * elementos));
                int posicion = (i - 10)/10;
                promedio[posicion] += t;
            }
        }
        for (int i = 0; i < 10; i++) {
            cout<<(promedio[i]/10)<<'\n';
        }
	return 0;
}
