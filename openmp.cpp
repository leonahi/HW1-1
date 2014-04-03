#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <omp.h>




int main(int argc, char *argv[]) {
	int N, T;
	float **A;
	float **B;
	float **C;
	double start, end;
	if (argc != 3){
			printf("too few or too many arguements");
					exit(1);}
	else{N = atoi(argv[1]);
		T = atoi(argv[2]);
	//printf("%d",N);

	A = (float**)calloc(N,sizeof(float*));
	for(int i = 0; i < N; i++)
	        {A[i] = (float*)malloc(N * sizeof(float));}
	B = (float**)malloc(N*sizeof(float*));
	for(int i = 0; i < N; i++)
	        B[i] = (float*)malloc(N * sizeof(float));
	C = (float**)malloc(N*sizeof(float*));
	for(int i = 0; i < N; i++)
	        C[i] = (float*)malloc(N * sizeof(float));


	srand((float)time(0));
	for(int i = 0; i < N; i++) {
	        for(int j = 0; j < N; j++) {
	            A[i][j] = (float)rand();
	            B[i][j] = (float)rand();
	        }
	    }
	}
	
start = omp_get_wtime();
	

#pragma omp parallel for shared(A,B,C,N) num_threads(T)
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        for( int k = 0; k < N; k++) {

            C[i][j] += A[i][k] * B[k][j];
        }
      }
   }


end = omp_get_wtime();

	printf("%d %d %f\n", N, T,double(end-start));
	free(A);
	free(B);
	free(C);
	return 0;
}
