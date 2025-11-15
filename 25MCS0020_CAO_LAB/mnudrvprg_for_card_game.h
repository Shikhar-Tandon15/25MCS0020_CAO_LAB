#include <stdio.h>
#include "040_card_game.h"
#include "00_colours.h"

int fn_mnudrvprg_cardgame() {
    int choice;

    while (1) {

        fn_red();
        printf("************************************************************************************************************************\n");
        fn_reset();
        fn_cyan();
        printf("List of choices: \n\n");
        fn_reset();
        fn_green();
        printf("50: Exit\t\t  51. Card Game Serial\t\t  52. Card Game Parallel\t\t  53. Both\n");
        fn_reset();
        fn_red();
        printf("************************************************************************************************************************\n");
        fn_reset();
        fn_cyan();
        printf("Enter your choice: \n");
        scanf_s("%d", &choice);
        fn_reset();

        switch (choice) {

        case 50:
            printf("\nYou chose to exit.");
            return 0;

        case 51:
            printf("\nThis is output of SERIAL Card Game Simulation:\n\n");
            fn_card_game_serial();
            break;

        case 52:
            printf("\nThis is output of PARALLEL Card Game Simulation:\n\n");
            fn_card_game_parallel();
            break;

        case 53:
            printf("\nThis is output of BOTH Serial and Parallel Card Game Simulation:\n\n");
            fn_card_game_both();
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
        }
	}return 0;
}
