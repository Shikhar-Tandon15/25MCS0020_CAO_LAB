#include <stdio.h>
#include <stdlib.h>
#include<omp.h>

#ifdef N
#undef N
#endif

void fn_vector_add_serial(float* a, float* b, float* c, int N) {
    for (int i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }
}

void fn_vector_add_parallel(float* a, float* b, float* c, int N) {
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
        printf("c[%d] = %.2f (computed by thread %d)\n",
            i, c[i], omp_get_thread_num());
    }
}

void fn_print_array(float* c, int N) {
    printf("\nResult:\n");
    for (int i = 0; i < N; i++) {
        printf("c[%d] = %.2f\n", i, c[i]);
    }
}

void fn_run_shared_serial() {
    int N = 10;
    float a[10], b[10], c[10];

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

    double start = omp_get_wtime();
    fn_vector_add_serial(a, b, c, N);
    double end = omp_get_wtime();

    printf("\n--- SERIAL VECTOR ADDITION ---\n");
    fn_print_array(c, N);

    printf("\nSerial Execution Time = %f ms\n", (end - start) * 1000);
}

void fn_run_shared_parallel() {
    int N = 10;
    float a[10], b[10], c[10];

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

    omp_set_num_threads(4);

    double start = omp_get_wtime();
    fn_vector_add_parallel(a, b, c, N);
    double end = omp_get_wtime();

    printf("\n--- PARALLEL VECTOR ADDITION ---\n");
    fn_print_array(c, N);

    printf("\nParallel Execution Time = %f ms\n", (end - start) * 1000);
}

void fn_run_shared_both() {
    int N = 10;
    float a[10], b[10], c1[10], c2[10];

    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }

    double start_s = omp_get_wtime();
    fn_vector_add_serial(a, b, c1, N);
    double end_s = omp_get_wtime();
    double ETser = end_s - start_s;

    omp_set_num_threads(4);
    double start_p = omp_get_wtime();
    fn_vector_add_parallel(a, b, c2, N);
    double end_p = omp_get_wtime();
    double ETpar = end_p - start_p;

    double cores = omp_get_max_threads();
    double speedup = ETser / ETpar;
    double efficiency = (speedup / cores) * 100;

    printf("\n--- SERIAL OUTPUT ---\n");
    fn_print_array(c1, N);
    printf("\n");
    printf("\n--- PARALLEL OUTPUT ---\n");
    fn_print_array(c2, N);

    printf("\n==========================================       PERFORMANCE ANALYSIS       ============================================\n");
    printf("Serial Time      : %f ms\n", ETser * 1000);
    printf("Parallel Time    : %f ms\n", ETpar * 1000);
    printf("Speedup          : %f\n", speedup);
    printf("Efficiency       : %f %%\n", efficiency);
    printf("========================================================================================================================\n");
}