#include "stdio.h"
#include "omp.h"


void fn_rter_omp_set_num_threads() {
	int nthreads;
	printf("Enter the number of threads: \n");
	scanf_s("%d", &nthreads);
	omp_set_num_threads(nthreads);
    #pragma omp parallel
	printf("Hello world with given no. of threads. \n");
}

void fn_rter_omp_get_num_threads() {
	int nthreads;
	#pragma omp parallel
	nthreads = omp_get_num_threads();
	printf("The number of threads used are %d \n",nthreads);
}
void fn_rter_omp_get_max_threads() {
	int mthreads;  
	mthreads = omp_get_max_threads();
	printf("The maximum number of threads used are %d \n", mthreads);
}
void fn_rter_omp_get_thread_num() {
#pragma omp parallel
	printf("Hello world parallel printed by thread ID: %d\n ", omp_get_thread_num());
}

void fn_rter_omp_get_num_procs() {
	int nprocess;
	nprocess = omp_get_num_procs();
	printf("The number of processors available are %d \n", nprocess);
}
void fn_rter_omp_in_parallel() {
	printf("The region is enclosed in parallel execution: %d\n\n", omp_in_parallel());
#pragma omp parallel
	printf("The region is enclosed in parallel execution: %d\n", omp_in_parallel());
}
void fn_rter_omp_set_dynamic() {
	omp_set_dynamic(0);
	printf("Dynamic thread adjustment is disabled \n");

}
void fn_rter_omp_get_dynamic() {
	printf("Dynamic thread adjustment is enabled: %d\n\n\n", omp_get_dynamic());
	omp_set_dynamic(1);
	printf("Dynamic thread adjustment is enabled: %d\n", omp_get_dynamic());
}
void fn_rter_omp_set_nested() {
	omp_set_nested(1);
#pragma omp parallel num_threads(2)
	{
		int outer_id = omp_get_thread_num();
		printf("Outer thread %d is running\n", outer_id);

#pragma omp parallel num_threads(2)
		{
			int inner_id = omp_get_thread_num();
			printf("  Inner thread %d (inside outer thread %d)\n", inner_id, outer_id);
		}
	}
}
void fn_rter_omp_get_nested() {

	printf("Nested parallelism enabled? %d\n", omp_get_nested());

}

