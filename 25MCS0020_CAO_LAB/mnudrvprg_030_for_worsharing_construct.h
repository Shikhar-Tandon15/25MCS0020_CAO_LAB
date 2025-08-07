#include <cstdlib>
#include "030_wsc_for_pp1.h"
#include "031_wsc_for_num_square.h"
int fn_mnudrvprg_030_for_worksharing_construct() {
	int choice;
	while (true) {
		printf("###########################################\n");
		printf("List of choices: \n");
		printf("0: Exit\t 1. Worksharing construct using 1 construct. \t 2. Worksharing construct using 2 constructs\t 3. Worsharing construct showing square of matrix\n\n");
		printf("###########################################\n");

		printf("Enter your choice: \n");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 0: {
			printf("You opted to exit program. \n");
			exit(0);
		}
		case 1: {
			fn_wsc_for_1construct();
			break;
		}
		case 2: {
			fn_wsc_for_2constructs();
			break;
		}
		case 3: {
			fn_num_square();
			break;
		}
		default:
		{
			printf("Wrong choice");
		}
		}
		return 0;
	}
}
