#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

float fn_dot_prod_serial(float* a, float* b, int N) {
    float sum = 0.0;
    for (int i = 0; i < N; i++)
        sum += a[i] * b[i];
    return sum;
}

float fn_dot_prod_parallel(float* a, float* b, int N) {
    float sum = 0.0;
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
#pragma omp critical
        sum += a[i] * b[i];
    }
    return sum;
}

void fn_run_dot_prod_serial() {
    int N = 10;
    float a[10], b[10];

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

    double start = omp_get_wtime();
    float result = fn_dot_prod_serial(a, b, N);
    double end = omp_get_wtime();

    printf("\n--- SERIAL DOT PRODUCT ---\n");
    printf("Dot product = %.2f\n", result);
    printf("Execution Time = %f ms\n", (end - start) * 1000);
}

void fn_run_dot_prod_parallel() {
    int N = 10;
    float a[10], b[10];

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

    omp_set_num_threads(4);

    double start = omp_get_wtime();
    float result = fn_dot_prod_parallel(a, b, N);
    double end = omp_get_wtime();

    printf("\n--- PARALLEL DOT PRODUCT ---\n");
    printf("Dot product = %.2f\n", result);
    printf("Execution Time = %f ms\n", (end - start) * 1000);
}

void fn_run_dot_prod_both() {
    int N = 10;
    float a[10], b[10];

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

    omp_set_num_threads(4);

    double s1 = omp_get_wtime();
    float ser = fn_dot_prod_serial(a, b, N);
    double e1 = omp_get_wtime();

    double s2 = omp_get_wtime();
    float par = fn_dot_prod_parallel(a, b, N);
    double e2 = omp_get_wtime();

    double ETser = e1 - s1;
    double ETpar = e2 - s2;

    double speedup = ETser / ETpar;
    int cores = omp_get_max_threads();
    double efficiency = (speedup / cores) * 100;

    printf("\n--- DOT PRODUCT SERIAL & PARALLEL ---\n");
    printf("Serial Result   = %.2f\n", ser);
    printf("Parallel Result = %.2f\n", par);

    printf("\n==========================================       PERFORMANCE ANALYSIS       ============================================\n");
    printf("Serial Time     = %f ms\n", ETser * 1000);
    printf("Parallel Time   = %f ms\n", ETpar * 1000);
    printf("Speedup         = %f\n", speedup);
    printf("Efficiency      = %f %%\n", efficiency);
    printf("========================================================================================================================\n");
}
