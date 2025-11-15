#include <stdio.h>
#include "00_colours.h"
#include "050_bakery_order_system.h"

int fn_mnudrvprg_bakery() {
    int choice;

    while (1) {

        fn_red();
        printf("************************************************************************************************************************\n");
        fn_reset();
        fn_cyan();
        printf("List of choices: \n\n");
        fn_reset();
        fn_green();
        printf("60: Exit\t\t  61. Serial Order Processing\t\t  62. Parallel Order Processing\t\t  63. Both\n");
        fn_reset();
        fn_red();
        printf("************************************************************************************************************************\n");
        fn_reset();
        fn_cyan();
        printf("Enter your choice: \n");
        scanf_s("%d", &choice);
        fn_reset();

        switch (choice) {

        case 60:
            printf("\nYou chose to exit.");
            return 0;

        case 61:
            printf("\nThis is output of SERIAL Card Game Simulation:\n\n");
            fn_bakery_serial();
            break;

        case 62:
            printf("\nThis is output of PARALLEL Card Game Simulation:\n\n");
            fn_bakery_parallel();
            break;

        case 63:
            printf("\nThis is output of BOTH Serial and Parallel Card Game Simulation:\n\n");
            fn_bakery_both();
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }return 0;
}
