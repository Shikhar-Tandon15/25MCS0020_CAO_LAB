#include"060_Data_env_critical.h"
#include "00_colours.h"
#include <cstdlib>

int fn_mnudrvprg_critical_sec() {
	int choice;
	while (true) {
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_cyan();
		printf("List of choices: \n\n");
		fn_reset();
		fn_green();
		printf("720. Exit\t 721. Serial Dot Product(using critical section)       722. Parallel Dot Product(using critical section)\t723.Both\n");
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
		case 720: {
			printf("\nYou opted to exit program.\n");
			return 0;
			break;
		}
		case 721: {
			printf("\nThis is output of Serial Dot Product(using critical section) program.\n");
			fn_run_dot_prod_serial();
			break;
		}
		case 722: {
			printf("\nThis is output of Parallel Dot Product(using critical section) program.\n");
			fn_run_dot_prod_parallel();
			break;
		}
		case 723: {
			printf("\nThis is output of combined serial and parallel dot product program.\n");
			fn_run_dot_prod_both();
			break;
		}
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
