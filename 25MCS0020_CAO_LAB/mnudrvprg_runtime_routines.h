#include "mnudrvprg_perf_anal.h"
#include "00_colours.h"
#include "mnudrvprg_for_rte_routines.h"
int fn_mnudrvprg_runtime_routines() {
	int choice;
	while (true) {
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_cyan();
		printf("List of choices: \n\n");
		fn_reset();
		fn_green();
		printf("30: Exit\t\t 31. Performance Analysis\t\t 32. Runtime Environment Routines\n");
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
		case 30: {
			printf("You opted to exit program.");
			return 0;
			break;
		}
		case 31: {
			fn_yellow();
			printf("\nYou choose Performance Analysis Program.\n");
			fn_reset();
			fn_mnudrvprg_perf_analysis();
			break;
		}
		case 32: {
			fn_yellow();
			printf("\nYou choose Runtime Environment Routines.\n");
			fn_reset();
			fn_mnudrvprg_for_rte_routines();
			break;
		}
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
