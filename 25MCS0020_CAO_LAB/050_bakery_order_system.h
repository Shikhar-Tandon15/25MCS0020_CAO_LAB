#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define NUM_ORDERS 20

void fn_process_order(int order_id, int processing_time) {
    for (int i = 0; i < processing_time * 1000000; i++); 
    printf("Order %d processed by thread %d with time %d\n",
        order_id, omp_get_thread_num(), processing_time);
}

void fn_bakery_order_system() {
    int orders[NUM_ORDERS];
    int processing_times[NUM_ORDERS];
    double start_time, end_time;

    srand(time(NULL));
    for (int i = 0; i < NUM_ORDERS; i++) {
        orders[i] = i + 1;
        processing_times[i] = (rand() % 5) + 1;
    }

    omp_set_num_threads(4);

    printf("\n=== Static Scheduling ===\n");
    start_time = omp_get_wtime();
#pragma omp parallel for schedule(static)
    for (int i = 0; i < NUM_ORDERS; i++) {
        fn_process_order(orders[i], processing_times[i]);
    }
    end_time = omp_get_wtime();
    printf("Static schedule time: %f seconds\n", end_time - start_time);

    printf("\n=== Dynamic Scheduling ===\n");
    start_time = omp_get_wtime();
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < NUM_ORDERS; i++) {
        fn_process_order(orders[i], processing_times[i]);
    }
    end_time = omp_get_wtime();
    printf("Dynamic schedule time: %f seconds\n", end_time - start_time);

    printf("\n=== Guided Scheduling ===\n");
    start_time = omp_get_wtime();
#pragma omp parallel for schedule(guided)
    for (int i = 0; i < NUM_ORDERS; i++) {
        fn_process_order(orders[i], processing_times[i]);
    }
    end_time = omp_get_wtime();
    printf("Guided schedule time: %f seconds\n", end_time - start_time);
}
