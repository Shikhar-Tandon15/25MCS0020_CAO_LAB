#include "stdio.h";
#include "050_Scheduling_Static.h";
#include "050_Scheduling_Dynamic.h";
#include "050_Scheduling_Guided.h";

int fn_mnudrvprg_050_scheduling() {
	int choice;
	while (true) {
		printf("###########################################\n");
		printf("List of choices: \n");
		printf("0: Exit\n1. Static Scheduling(without chunks)\t 2. Static Scheduling(with chunks)\n");
		printf("3: Dynamic Scheduling(without chunks)\t 4. Dynamic Scheduling(with chunks)\n");
		printf("5: Guided Scheduling(without chunks)\t 6. Guided Scheduling(with chunks)\n\n");
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
			fn_static_01();
			break;
		}
		case 2: {
			fn_static_with_chunk();
			break;
		}
		case 3: {
			fn_dynamic_01();
			break;
		}
		case 4: {
			fn_dynamic_with_chunk();
			break;
		}
		case 5: {
			fn_guided_01();
			break;
		}
		case 6: {
			fn_guided_with_chunk();
			break;
		}
		default:
			printf("Wrong choice");
		}
	}
	return 0;
}