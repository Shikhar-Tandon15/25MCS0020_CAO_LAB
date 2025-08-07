#include <stdio.h>
#include <omp.h>

void fn_helloworld_srl() {
	printf("Hello world serial \n");
}

void fn_helloworld_prl() {
#pragma omp parallel
	printf("Hello world parallel \n");
}