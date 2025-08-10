#include "stdio.h"


#define N 12
double ETser, ETper;
void fn_initializeArray(int a[]) {
	for (int i = 0; i < N; i++) {
		a[i] = i + 1;
	}
}

void fn_computeSquares_srl(int a[], int square[]) {
	double starts, ends;
	starts = omp_get_wtime();
	printf("Serial Execution:\n");
	for (int i = 0; i < N; i++) {
		square[i] = a[i] * a[i];
		printf("Square of a[%d]:%d^2 = %d\n", i, a[i], square[i]);
	}
	ends = omp_get_wtime();
	ETser = ends - starts;
	printf("\nExecution time of serial program= %f ms \n", ETser);
	printf("#####################################################\n\n");
}
void fn_computeSquares_prl(int a[], int square[]) {
	double startp, endp;
	startp = omp_get_wtime();
	printf("Parallel Execution:\n");
   #pragma omp parallel for
	for (int i = 0; i < N; i++) {
		square[i] = a[i] * a[i];
		printf("Square of a[%d]:%d^2 = %d printed by thread %d\n", i, a[i], square[i],omp_get_thread_num());
	}
	endp = omp_get_wtime();
	ETper = endp - startp;
	printf("\nExecution time of parallel program= %f ms \n", ETper);
	printf("#####################################################\n\n");
}
void fn_displayResults(int square[]) {
	printf("Squared Results: \n");
	for (int i = 0; i < N; i++) {
		printf("square[%d] = %d\n", i, square[i]);
	}
}
void fn_arr_performance_analysis() {
	
	double speedup, efficiency;
	speedup = ETser / ETper;
	int core = omp_get_max_threads();
	efficiency = (speedup / core) * 100;

	printf("The speedup and efficiency are %f and %f respectively\n", speedup, efficiency);
	printf("#####################################################\n\n");
}
int fn_num_square() {
	int a[N], square[N];
	fn_initializeArray(a);
	fn_computeSquares_srl(a, square);
	fn_computeSquares_prl(a, square);
	fn_arr_performance_analysis();
	fn_displayResults(square);
	return 0;
}