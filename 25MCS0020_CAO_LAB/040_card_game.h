#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>


void fn_print_hand(int* hand, int size, const char* player) {
    printf("\n%s's hand: ", player);
    for (int i = 0; i < size; i++) {
        printf("%d ", hand[i]);
    }
    printf("\n");
}

void fn_card_game_simul() {
    int deck[52];
    int player1[26], player2[26];

    for (int i = 0; i < 52; i++) {
        deck[i] = i + 1;
    }

    srand(time(NULL));  

    omp_set_num_threads(4);

#pragma omp parallel
    {
#pragma omp single
        {
            printf("Game is starting! Shuffling and dealing cards...\n\n");
        }

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
            {
                printf("Player 1 is being dealt cards by Thread %d\n", omp_get_thread_num());
                for (int i = 0; i < 26; i++) {
                    player1[i] = deck[i];
                }
            }

#pragma omp section
            {
                printf("Player 2 is being dealt cards by Thread %d\n", omp_get_thread_num());
                for (int i = 26; i < 52; i++) {
                    player2[i - 26] = deck[i];
                }
            }
        }
    }

    fn_print_hand(player1, 26, "Player 1");
    fn_print_hand(player2, 26, "Player 2");

}
