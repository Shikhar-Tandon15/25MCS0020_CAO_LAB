#include <stdio.h>
#include "omp.h"
#include <time.h>
#include <cstdlib>


void fn_print_hand(int* hand, int size, const char* player) {
    printf("\n%s's hand: ", player);
    for (int i = 0; i < size; i++) {
        printf("%d ", hand[i]);
    }
    printf("\n");
}

double fn_card_game_serial() {
    int deck[52];
    int player1[26], player2[26];

    for (int i = 0; i < 52; i++)
        deck[i] = i + 1;

    srand(time(NULL));

    double start = omp_get_wtime();

    for (int i = 0; i < 52; i++) {
        int rand_index = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[rand_index];
        deck[rand_index] = temp;
    }

    for (int i = 0; i < 26; i++) player1[i] = deck[i];
    for (int i = 26; i < 52; i++) player2[i - 26] = deck[i];

    double end = omp_get_wtime();
    double ETser = end - start;

    fn_print_hand(player1, 26, "Player 1");
    fn_print_hand(player2, 26, "Player 2");

    printf("\nSerial Execution Time = %f ms\n", ETser);
    return ETser;
}

double fn_card_game_parallel() {
    int deck[52];
    int player1[26], player2[26];

    for (int i = 0; i < 52; i++)
        deck[i] = i + 1;

    srand(time(NULL));
    omp_set_num_threads(4);

    double start = omp_get_wtime();

#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < 52; i++) {
            int rand_index = rand() % 52;
            int temp = deck[i];
            deck[i] = deck[rand_index];
            deck[rand_index] = temp;
        }

#pragma omp sections
        {
#pragma omp section
            for (int i = 0; i < 26; i++) player1[i] = deck[i];

#pragma omp section
            for (int i = 26; i < 52; i++) player2[i - 26] = deck[i];
        }
    }

    double end = omp_get_wtime();
    double ETpar = end - start;

    fn_print_hand(player1, 26, "Player 1");
    fn_print_hand(player2, 26, "Player 2");

    printf("\nParallel Execution Time = %f ms\n", ETpar);
	return ETpar;
}


void fn_card_game_both() {
    double ETser= fn_card_game_serial();
    printf("\n");
    double ETpar= fn_card_game_parallel();
    double speedup = ETser / ETpar;
    int cores = omp_get_max_threads();
    double efficiency = (speedup / cores) * 100;

    printf("\n==========================================       PERFORMANCE ANALYSIS       ============================================\n");
    printf("Serial Time   = %f ms\n", ETser);
    printf("Parallel Time = %f ms\n", ETpar);
    printf("Speedup       = %f\n", speedup);
    printf("Efficiency    = %f %%\n", efficiency);
    printf("========================================================================================================================\n");
}
