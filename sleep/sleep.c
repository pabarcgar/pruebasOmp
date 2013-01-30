#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
	long dimension = 100000000;

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
			long sum = 0;
			for (i=0; i<3000000000;i++);
				sum = sum + i;
			double tiempoFinal = omp_get_wtime();
		        printf("Tiempo tardado en generar vectores 1: %lf\n", tiempoFinal-tiempoInicio);
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
			long sum2 = 0;
			for (j=0; j<3000000000;j++);
				sum2 = sum2 + j;
	        	double tiempoFinal2 = omp_get_wtime();

		        printf("Tiempo tardado en generar vectores 2: %lf\n", tiempoFinal2-tiempoInicio2);
		}
	}
}
