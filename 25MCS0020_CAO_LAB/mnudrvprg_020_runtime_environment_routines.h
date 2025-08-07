#include "stdio.h"
#include <cstdlib>
#include "ret_et_helloworld.h"
#include "ret_tid_helloworld.h"
#include "ret_practice.h"

int fn_mnudrvprg_020_runtime_environment_routines() {
	int choice;
	while (true) {
		printf("###########################################\n");
		printf("List of choices: \n");
		printf("0: Exit\t 1. Execution time for serial program\t 2. Execution time for parallel program.\t 3. Thread ID for serial program\t 4. Thread ID for parallel program.\t 5. SpeedUp and Efficiency \n\n");
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
			fn_ret_et_helloworld_srl();
			break;
		}
		case 2: {
			fn_ret_et_helloworld_prl();
			break;
		}
		case 3: {
			fn_ret_tid_helloworld_srl();
			break;
		}
		case 4: {
			fn_ret_tid_helloworld_prl();
			break;
		}
		case 5: {
			fn_practice1();
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