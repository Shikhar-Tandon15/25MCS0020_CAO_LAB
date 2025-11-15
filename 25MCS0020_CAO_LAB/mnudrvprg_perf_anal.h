#include "performance_analysis.h"
#include "00_colours.h"

int fn_mnudrvprg_perf_analysis() {
	int choice;
	while (true) {
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_cyan();
		printf("List of choices: \n\n");
		fn_reset();
		fn_green();
		printf("310: Exit\t\t 311. Hello World serial program\t\t 312. Hello World parallel program\t\t 313.Both\n");
		fn_reset();
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_cyan();
		printf("Enter your choice: \n");
		scanf_s("%d", &choice);
		fn_reset();
		switch (choice)
		{
		case 310: {
			printf("\nYou opted to exit program. \n");
			return 0;
			break;
		}
		case 311: {
			printf("\nThis is output of Hello World serial program.\n\n");
			fn_serial_program();
			break;
		}
		case 312: {
			printf("\nThis is output of Hello World parallel program.\n\n");
			fn_parallel_program();
			break;
		}
		case 313: {
			printf("\nThis is output of combined Hello World serial and parallel program.\n\n");
			fn_performance_analysis();
			break;
		}
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
