#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

float fn_dot_prod(float* a, float* b, int N) {
    float sum = 0.0;

#pragma omp parallel for
    for (int i = 0; i < N; i++) {
#pragma omp critical
        sum += a[i] * b[i];
    }

    return sum;
}

void fn_run_dot_prod() {
    int N = 10;
    float a[10], b[10], result;

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

    result = fn_dot_prod(a, b, N);

    printf("Dot product result: %.2f\n", result);

}

