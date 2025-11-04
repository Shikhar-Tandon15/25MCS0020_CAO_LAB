#include <stdio.h>
#include <omp.h>

void fn_calc_dot_prod() {
    int N = 10;
    float a[10], b[10], sum = 0.0;

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += a[i] * b[i];
    }

    printf("Dot product result(using reduction): %.2f\n", sum);

}
