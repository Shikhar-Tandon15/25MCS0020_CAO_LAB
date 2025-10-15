#include "stdio.h"
#include "omp.h"

void fn_guided_01()
{
	int i;
	int n = 16;

	omp_set_num_threads(4);
	printf("Guided Scheduling Example:\n");

#pragma omp parallel for schedule(guided)
	for (i = 0; i < n; i++) {
		printf("Iteration %d handled by thread %d \n", i, omp_get_thread_num());
	}

}

void fn_guided_with_chunk()
{
	int i;
	int n = 16;

	omp_set_num_threads(4);
	printf("Guided Scheduling with Chunk Size 2:\n");

#pragma omp parallel for schedule(guided,2)
	for (i = 0; i < n; i++) {
		printf("Iteration %d handled by thread %d \n", i, omp_get_thread_num());
	}

}