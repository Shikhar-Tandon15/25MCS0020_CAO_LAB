# include <stdio.h>
#include <omp.h>

void fn_performance_analysis() {
	double starts, ends;
	starts= omp_get_wtime();

	printf("Hello world serial printed by thread ID: %d \n", omp_get_thread_num());
	ends= omp_get_wtime();

	double ETser = ends - starts;
	printf("Execution time of serial program= %f ms \n \n \n", ETser);

	

	double startp, endp;
	startp = omp_get_wtime();

#pragma omp parallel
	printf("Hello world parallel printed by thread ID: %d\n ", omp_get_thread_num());
	endp = omp_get_wtime();

	double ETper = endp - startp;
	printf("Execution time of parallel program= %f ms \n", ETper);
	
	double speedup, efficiency;
	speedup = ETser / ETper;
	int core = omp_get_max_threads();
	efficiency = (speedup / core) * 100;

	printf("The speedup and efficiency are %f and %f respectively", speedup, efficiency);



}
