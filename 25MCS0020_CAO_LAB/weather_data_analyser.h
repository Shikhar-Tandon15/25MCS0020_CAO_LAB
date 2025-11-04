#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define STATIONS 10
#define DAYS 365

void fn_weather_data_analyser() {
    float temps[STATIONS][DAYS];
    float avg_temp[STATIONS];
    float min_temp[STATIONS];
    float max_temp[STATIONS];

    srand(time(NULL));

    for (int i = 0; i < STATIONS; i++) {
        for (int j = 0; j < DAYS; j++) {
            temps[i][j] = ((rand() % 501) / 10.0) - 10.0;
        }
    }

    double start_time = omp_get_wtime();

#pragma omp parallel for
    for (int i = 0; i < STATIONS; i++) {
        float sum = 0.0;
        float min_v = temps[i][0];
        float max_v = temps[i][0];

        for (int j = 0; j < DAYS; j++) {
            float t = temps[i][j];
            sum += t;
            if (t < min_v) min_v = t;
            if (t > max_v) max_v = t;
        }

        avg_temp[i] = sum / DAYS;
        min_temp[i] = min_v;
        max_temp[i] = max_v;

        printf("Station %d handled by thread %d | Min: %.2fC, Max: %.2fC, Avg: %.2fC\n",
            i + 1, omp_get_thread_num(), min_v, max_v, avg_temp[i]);
    }

    double end_time = omp_get_wtime();

    printf("\nWeather Data Analysis Completed in %f seconds using %d thread(s).\n",
        end_time - start_time, omp_get_max_threads());


}
