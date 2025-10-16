#include "stdio.h"
#include "omp.h"

void fn_static_01()
{
	int i;
	int n = 16;

	omp_set_num_threads(4);
	printf("Static Scheduling Example:\n");

#pragma omp parallel for schedule(static)
	for (i = 0; i < n; i++) {
		printf("Iteration %d handled by thread %d \n", i, omp_get_thread_num());
	}

}

void fn_static_with_chunk()
{
	int i;
	int n = 16;

	omp_set_num_threads(4);
	printf("Static Scheduling with Chunk Size 2:\n");

#pragma omp parallel for schedule(static,2)
	for (i = 0; i < n; i++) {
		printf("Iteration %d handled by thread %d \n", i, omp_get_thread_num());
	}

}

void fn_static_02()
{
	int i;
	int n = 18;

	omp_set_num_threads(4);
	printf("Static Scheduling with uneven iterations Example:\n");

#pragma omp parallel for schedule(static)
	for (i = 0; i < n; i++) {
		printf("Iteration %d handled by thread %d \n", i, omp_get_thread_num());
	}

}
