#include "run_time_environment_routines.h"
#include <cstdlib>
#include "00_colours.h"

int fn_mnudrvprg_for_rte_routines() {
	int choice;
	while (true) {
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_cyan();
		printf("List of choices: \n\n");
		fn_reset();
		fn_green();
		printf("%-6s %-30s %-30s %-30s\n",
			"","320. Exit",
			"321. omp_set_num_threads()",
			"322. omp_get_num_threads()");

		printf("%-6s %-30s %-30s %-30s\n",
			"", "323. omp_get_max_threads()",
			"324. omp_get_thread_num()",
			"325. omp_get_num_procs()");

		printf("%-6s %-30s %-30s %-30s\n",
			"", "326. omp_in_parallel()",
			"327. omp_set_dynamic()",
			"328. omp_get_dynamic()");

		printf("%-6s %-30s %-30s\n",
			"", "329. omp_set_nested()",
			"330. omp_get_nested()");
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
		case 320: {
			printf("\nYou opted to exit program.\n");
			return 0;
			break;
			
		}
		case 321: {
			fn_rter_omp_set_num_threads();
			break;
		}
		case 322: {
			fn_rter_omp_get_num_threads();
			break;
		}
		case 323: {
			fn_rter_omp_get_max_threads();
			break;
		}
		case 324: {
			fn_rter_omp_get_thread_num();
			break;
		}
		case 325: {
			fn_rter_omp_get_num_procs();
			break;
		}
		case 326: {
			fn_rter_omp_in_parallel();
			break;
		}
		case 327: {
			fn_rter_omp_set_dynamic();
			break;
		}
		case 328: {
			fn_rter_omp_get_dynamic();
			break;
		}
		case 329: {
			fn_rter_omp_set_nested();
			break;
		}
		case 330: {
			fn_rter_omp_get_nested();
			break;
		}
		default:
		{
			printf("Wrong choice");
		}
		}
	}
}
