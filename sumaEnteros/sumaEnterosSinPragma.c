#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
	long dimension = 100000000;
	double initTime = omp_get_wtime();
	long sum1 = 0,sum2 = 0;
	int totalIteraciones = 900000000;
	int i;
	for (i=0; i<totalIteraciones;i++) {
		sum1 = sum1 + i;
	}
	printf("Suma: %ld\n", sum1+sum2);
	double endTime = omp_get_wtime();
	printf("Tiempo total tardado: %lf\n", endTime-initTime);

}
