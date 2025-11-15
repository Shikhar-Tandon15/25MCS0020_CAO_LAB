#include"060_Data_env_reduction.h"
#include "00_colours.h"
#include <cstdlib>

int fn_mnudrvprg_reduction_clause() {
	int choice;
	while (true) {
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_cyan();
		printf("List of choices: \n\n");
		fn_reset();
		fn_green();
		printf("730. Exit\t 731. Serial Dot Product(using reduction clause)       732. Parallel Dot Product(using reduction clause)\t733.Both\n");
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
		case 730: {
			printf("\nYou opted to exit program.\n");
			return 0;
			break;
		}
		case 731: {
			printf("\nThis is output of Serial Dot Product(using reduction clause) program.\n");
			fn_run_serial_dot();
			break;
		}
		case 732: {
			printf("\nThis is output of Parallel Dot Product(using reduction clause) program.\n");
			fn_run_parallel_dot();
			break;
		}
		case 733: {
			printf("\nThis is output of combined serial and parallel dot product program.\n");
			fn_run_both_dot();
			break;
		}
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
