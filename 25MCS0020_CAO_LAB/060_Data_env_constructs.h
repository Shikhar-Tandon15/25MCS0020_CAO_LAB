#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void fn_work(float* a, float* b, float* c, int N) {
    float x, y;
    int i;

#pragma omp parallel for private(x, y) shared(a, b, c)
    for (i = 0; i < N; i++) {
        x = a[i];
        y = b[i];
        c[i] = x + y;
    }
}

void fn_run_vector_addition() {
    int N = 10;
    float a[10], b[10], c[10];

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

    fn_work(a, b, c, N);

    printf("Result of vector addition:\n");
    for (int i = 0; i < N; i++) {
        printf("c[%d] = %.2f\n", i, c[i]);
    }
}