#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define NUM_ORDERS 20

int orders[NUM_ORDERS];
int processing_times[NUM_ORDERS];
double g_ser = 0, g_par_static = 0, g_par_dynamic = 0, g_par_guided = 0;

void fn_process_order(int order_id, int processing_time) {
    for (int i = 0; i < processing_time * 1000000; i++);
    printf("Order %d processed by thread %d (time %d)\n",
        order_id, omp_get_thread_num(), processing_time);
}

void fn_generate_orders() {
    srand(time(NULL));
    for (int i = 0; i < NUM_ORDERS; i++) {
        orders[i] = i + 1;
        processing_times[i] = (rand() % 5) + 1;
    }
}

void fn_bakery_serial() {
    fn_generate_orders();
    double start = omp_get_wtime();

    for (int i = 0; i < NUM_ORDERS; i++) {
        fn_process_order(orders[i], processing_times[i]);
    }

    double end = omp_get_wtime();
    g_ser = end - start;

    printf("\nSerial Time: %f seconds\n", g_ser);
}

void fn_bakery_parallel() {
    fn_generate_orders();
    omp_set_num_threads(4);

    printf("\n=== Static Scheduling ===\n");
    double start = omp_get_wtime();
#pragma omp parallel for schedule(static)
    for (int i = 0; i < NUM_ORDERS; i++) {
        fn_process_order(orders[i], processing_times[i]);
    }
    double end = omp_get_wtime();
    g_par_static = end - start;
    printf("Static Time: %f seconds\n", g_par_static);

    printf("\n=== Dynamic Scheduling ===\n");
    start = omp_get_wtime();
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < NUM_ORDERS; i++) {
        fn_process_order(orders[i], processing_times[i]);
    }
    end = omp_get_wtime();
    g_par_dynamic = end - start;
    printf("Dynamic Time: %f seconds\n", g_par_dynamic);

    printf("\n=== Guided Scheduling ===\n");
    start = omp_get_wtime();
#pragma omp parallel for schedule(guided)
    for (int i = 0; i < NUM_ORDERS; i++) {
        fn_process_order(orders[i], processing_times[i]);
    }
    end = omp_get_wtime();
    g_par_guided = end - start;
    printf("Guided Time: %f seconds\n", g_par_guided);
}

void fn_bakery_both() {
    fn_bakery_serial();
    fn_bakery_parallel();

    double cores = omp_get_max_threads();

    double speedup_static = g_ser / g_par_static;
    double speedup_dynamic = g_ser / g_par_dynamic;
    double speedup_guided = g_ser / g_par_guided;

    double eff_static = (speedup_static / cores) * 100;
    double eff_dynamic = (speedup_dynamic / cores) * 100;
    double eff_guided = (speedup_guided / cores) * 100;

    printf("\n==========================================       PERFORMANCE ANALYSIS       ============================================\n");
    printf("Serial Time       : %f s\n", g_ser);
    printf("Static Time       : %f s | Speedup: %f | Efficiency: %f%%\n",
        g_par_static, speedup_static, eff_static);
    printf("Dynamic Time      : %f s | Speedup: %f | Efficiency: %f%%\n",
        g_par_dynamic, speedup_dynamic, eff_dynamic);
    printf("Guided Time       : %f s | Speedup: %f | Efficiency: %f%%\n",
        g_par_guided, speedup_guided, eff_guided);
    printf("========================================================================================================================\n");
}
