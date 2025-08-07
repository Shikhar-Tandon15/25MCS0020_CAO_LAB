#include "run_time_environment_routines.h"
#include <cstdlib>
void fn_mnudrvprg_for_rte_routines() {
	int choice;
	while (true) {
		printf("###########################################\n");
		printf("List of choices: \n");
		printf("0: Exit\t 1. omp_set_num_threads()\t 2. omp_get_num_threads()\t 3. omp_get_max_threads()\t 4. omp_get_thread_num()\t 5. omp_get_num_procs()\t 6. omp_in_parallel()\t 7. omp_set_dynamic()\t 8. omp_get_dynamic()\t 9. omp_set_nested()\t 10. omp_get_nested()  \n\n");
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
			fn_rter_omp_set_num_threads();
			break;
		}
		case 2: {
			fn_rter_omp_get_num_threads();
			break;
		}
		case 3: {
			fn_rter_omp_get_max_threads();
			break;
		}
		case 4: {
			fn_rter_omp_get_thread_num();
			break;
		}
		case 5: {
			fn_rter_omp_get_num_procs();
			break;
		}
		case 6: {
			fn_rter_omp_in_parallel();
			break;
		}
		case 7: {
			fn_rter_omp_set_dynamic();
			break;
		}
		case 8: {
			fn_rter_omp_get_dynamic();
			break;
		}
		case 9: {
			fn_rter_omp_set_nested();
			break;
		}
		case 10: {
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
