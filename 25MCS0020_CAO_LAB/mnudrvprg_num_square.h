#include <stdio.h>
#include "00_colours.h"
#include "031_wsc_for_num_square.h"
int fn_mnudrvprg_squares() {
    int choice;

    while (true) {

        fn_red();
        printf("************************************************************************************************************************\n");
        fn_reset();
        fn_cyan();
        printf("List of choices: \n\n");
        fn_reset();
        fn_green();
        printf("40: Exit\t  41. Serial Squares Program\t  42. Parallel Squares Program\t  43. Both\n");
        fn_reset();
        fn_red();
        printf("************************************************************************************************************************\n");
        fn_reset();
        fn_cyan();
        printf("Enter your choice: \n");
        scanf_s("%d", &choice);
        fn_reset();

        switch (choice) {
        case 40:
            printf("\nYou opted to exit program.");
            return 0;

        case 41:
            printf("\nThis is the output of Serial Squares Program.\n\n");
            fn_run_serial();
            break;

        case 42:
            printf("\nThis is the output of Parallel Squares Program.\n\n");
            fn_run_parallel();
            break;

        case 43:
            printf("\nThis is the output of BOTH Serial & Parallel Squares Program.\n\n");
            fn_run_both();
            break;

        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}