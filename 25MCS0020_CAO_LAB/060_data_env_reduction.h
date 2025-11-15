#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int N = 150000;
float a[150000], b[150000];

void fn_init_vectors() {
    for (int i = 0; i < N; i++) {
        a[i] = i * 1.0;
        b[i] = (N - i) * 1.0;
    }
}

float fn_serial_dotprod() {
    float sum = 0.0;
    for (int i = 0; i < N; i++)
        sum += a[i] * b[i];
    return sum;
}

float fn_parallel_dotprod() {
    float sum = 0.0;
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++)
        sum += a[i] * b[i];
    return sum;
}

void fn_run_serial_dot() {
    fn_init_vectors();
    double t1 = omp_get_wtime();
    float result = fn_serial_dotprod();
    double t2 = omp_get_wtime();

    printf("\n--- SERIAL EXECUTION ---\n");
    printf("Result: %.2f\n", result);
    printf("Time: %f seconds\n", t2 - t1);
}

void fn_run_parallel_dot() {
    fn_init_vectors();
    double t1 = omp_get_wtime();
    float result = fn_parallel_dotprod();
    double t2 = omp_get_wtime();

    printf("\n--- PARALLEL EXECUTION ---\n");
    printf("Result: %.2f\n", result);
    printf("Time: %f seconds\n", t2 - t1);
}

void fn_run_both_dot() {
    fn_init_vectors();
    double ts1 = omp_get_wtime();
    float r1 = fn_serial_dotprod();
    double ts2 = omp_get_wtime();
    double serial_time = ts2 - ts1;

    fn_init_vectors();
    double tp1 = omp_get_wtime();
    float r2 = fn_parallel_dotprod();
    double tp2 = omp_get_wtime();
    double parallel_time = tp2 - tp1;

    int p = omp_get_max_threads();
    double speedup = serial_time / parallel_time;
    double efficiency = speedup / p;

    printf("\n--- BOTH EXECUTIONS ---\n");
    printf("Serial Result: %.2f\n", r1);
    printf("Parallel Result: %.2f\n", r2);
    printf("Serial Time: %f\n", serial_time);
    printf("Parallel Time: %f\n", parallel_time);

    printf("\n==========================================       PERFORMANCE ANALYSIS       ============================================\n");
    printf("Speedup: %f\n", speedup);
    printf("Efficiency: %f\n", efficiency);
    printf("========================================================================================================================\n");

}