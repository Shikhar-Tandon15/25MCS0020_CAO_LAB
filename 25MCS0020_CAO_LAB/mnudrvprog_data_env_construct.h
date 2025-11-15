#include"mnudrvprg_shared_clause.h"
#include "00_colours.h"
#include <cstdlib>
#include "mnudrvprg_critical_clause.h"
#include "mnudrvprg_reduction_clause.h"

int fn_mnudrvprg_data_env_construct() {
	int choice;
	while (true) {
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_cyan();
		printf("List of choices: \n\n");
		fn_reset();
		fn_green();
		printf("70. Exit\t\t 71. Shared & Private clauses\t\t 72. Critical Section\t\t 73.Reduction Clause\n");
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
		case 70: {
			printf("\nYou opted to exit program.");
			return 0;
			break;
		}
		case 71: {
			fn_yellow();
			printf("\nYou choose Shared & Private clauses program\n");
			fn_reset();
			fn_mnudrvprg_shared_clause();
			break;
		}
		case 72: {
			fn_yellow();
			printf("\nYou choose Critical Section program.\n");
			fn_reset();
			fn_mnudrvprg_critical_sec();
			break;
		}
		case 73: {
			fn_yellow();
			printf("\nYou choose Reduction clause program.\n");
			fn_reset();
			fn_mnudrvprg_reduction_clause();
			break;
		}
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
