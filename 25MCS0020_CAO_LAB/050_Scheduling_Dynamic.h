#include "stdio.h"
#include "omp.h"

void fn_dynamic_01()
{
	int i;
	int n = 16;

	omp_set_num_threads(4);
	printf("Dynamic Scheduling Example:\n");

#pragma omp parallel for schedule(dynamic)
	for (i = 0; i < n; i++) {
		printf("Iteration %d handled by thread %d \n", i, omp_get_thread_num());
	}

}

void fn_dynamic_with_chunk()
{
	int i;
	int n = 16;

	omp_set_num_threads(4);
	printf("Dynamic Scheduling with Chunk Size 2:\n");

#pragma omp parallel for schedule(dynamic,2)
	for (i = 0; i < n; i++) {
		printf("Iteration %d handled by thread %d \n", i, omp_get_thread_num());
	}

}
void fn_dynamic_02()
{
	int i;
	int n = 18;

	omp_set_num_threads(4);
	printf("Dynamic Scheduling with uneven iterations Example:\n");

#pragma omp parallel for schedule(dynamic)
	for (i = 0; i < n; i++) {
		printf("Iteration %d handled by thread %d \n", i, omp_get_thread_num());
	}

}