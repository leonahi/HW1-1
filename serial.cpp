#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void MM(float **a,float **b,float **c,int N) {
	int i, j, k;

	   for(i = 0; i < N; i++) {
	      for(j = 0; j < N; j++) {
	        for(k = 0; k < N; k++) {

	            c[i][j] += a[i][k] * b[k][j];
	        }
	      }
	   }

}

	int main(int argc, char *argv[]) {
		int N;
		float **A;
		float **B;
		float **C;
		if (argc != 2){
				printf("too few or too many arguements");
						exit(1);}
		else{N = atoi(argv[1]);
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
		clock_t Start = clock();
		MM(A,B,C,N);
		Start = clock()-Start;
		printf("%d %f\n", N, (double)(Start)/CLOCKS_PER_SEC);
		free(A);
		free(B);
		free(C);
		return 0;
	}
