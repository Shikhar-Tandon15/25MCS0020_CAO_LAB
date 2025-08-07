#include "stdio.h"
#include "helloworld.h"
#include <cstdlib>

int fn_mnudrvprg_010_parallel_construct() {
	int choice;
	while (true) {
		printf("###########################################\n");
		printf("List of choices: \n");
		printf("0: Exit\t 1. Hello World serial program\t 2. Hello World parallel program\n\n");
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
			printf("This is output of Hello World serial program.\n");
			fn_helloworld_srl();
			break;
		}
		case 2: {
			printf("This is output of Hello World parallel program.\n");
			fn_helloworld_prl();
			break;
		}
		default:
			printf("Wrong choice");
		}
	}
	return 0;
}