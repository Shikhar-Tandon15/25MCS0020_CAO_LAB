#include"060_Data_env_constructs.h"
#include "00_colours.h"
#include <cstdlib>

int fn_mnudrvprg_shared_clause() {
	int choice;
	while (true) {
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_cyan();
		printf("List of choices: \n\n");
		fn_reset();
		fn_green();
		printf("710. Exit\t\t 711. Serial Vector Addition\t\t 712. Parallel Vector Addition\t\t 713.Both\n");
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
		case 710: {
			printf("\nYou opted to exit program.");
			return 0;
			break;
		}
		case 711: {
			printf("\nThis is output of Serial Vector Addition program.\n");
			fn_run_shared_serial();
			break;
		}
		case 712: {
			printf("\nThis is output of Parallel Vector Addition program.\n");
			fn_run_shared_parallel();
			break;
		}
		case 713: {
			printf("\nThis is output of combined serial and parallel vector addition program.\n");
			fn_run_shared_both();
			break;
		}
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
