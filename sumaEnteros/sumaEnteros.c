#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
	long dimension = 100000000;
	double initTime = omp_get_wtime();
	long sum1 = 0,sum2 = 0;
	int totalIteraciones = 900000000;
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			double tiempoInicio = omp_get_wtime();
/*			int* vector1 = (int*)malloc(dimension*sizeof(int));
		        int* vector2 = (int*)malloc(dimension*sizeof(int));
        		int i;

		        // generacion de vectores
		        srand ( time(NULL) );
	        	double tiempoInicio = omp_get_wtime();
		        for (i=0; i<dimension; i++) {
		                vector1[i] = rand() %100;
	        	        vector2[i] = rand() %100;
		        }
			free(vector1);
			free(vector2);
*/
			int i;
			for (i=0; i<totalIteraciones/2;i++) {
				sum1 = sum1 + i;
			}
			double tiempoFinal = omp_get_wtime();
		        printf("Tiempo tardado en sumar la primera parte: %lf\n", tiempoFinal-tiempoInicio);
		}
		#pragma omp section
		{
	/*
			int* vector3 = (int*)malloc(dimension*sizeof(int));
        		int* vector4 = (int*)malloc(dimension*sizeof(int));
			int j;
	*/		
			double tiempoInicio2 = omp_get_wtime();
	/*	        for (j=0; j<dimension; j++) {
        		        vector3[j] = rand() %100;
                		vector4[j] = rand() %100;
		        }
	        	double tiempoFinal2 = omp_get_wtime();
			free(vector3);
			free(vector4);*/
			int j;
			for (j=totalIteraciones/2; j<totalIteraciones;j++) {
				sum2 = sum2 + j;
			}
	        	double tiempoFinal2 = omp_get_wtime();

		        printf("Tiempo tardado en sumar la segunda parte: %lf\n", tiempoFinal2-tiempoInicio2);
		}
	}
		printf("Suma: %ld\n", (sum1+sum2));
		double endTime = omp_get_wtime();
		printf("Tiempo total tardado: %lf\n", endTime-initTime);

}
