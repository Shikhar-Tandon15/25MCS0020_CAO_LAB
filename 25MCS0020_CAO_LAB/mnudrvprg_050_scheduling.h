#include "stdio.h";
#include "050_Scheduling_Static.h";
#include "050_Scheduling_Dynamic.h";
#include "050_Scheduling_Guided.h";

int fn_mnudrvprg_050_scheduling() {
	int choice;
	while (true) {
		printf("###########################################\n");
		printf("List of choices: \n");
		printf("0: Exit\n1. Static Scheduling(without chunks)\t2. Static Scheduling(with chunks)\t3. Static Scheduling(uneven iterations)\n");
		printf("4: Dynamic Scheduling(without chunks)\t5. Dynamic Scheduling(with chunks)\t6. Dynamic Scheduling(uneven iterations)\n");
		printf("7: Guided Scheduling(without chunks)\t8. Guided Scheduling(with chunks)\t9. Guided Scheduling(uneven iterations)\n\n");
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
			fn_static_02();
			break;
		}
		case 4: {
			fn_dynamic_01();
			break;
		}
		case 5: {
			fn_dynamic_with_chunk();
			break;
		}
		case 6: {
			fn_dynamic_02();
			break;
		}
		case 7: {
			fn_guided_01();
			break;
		}
		case 8: {
			fn_guided_with_chunk();
			break;
		}
		case 9: {
			fn_guided_02();
			break;
		}
		default:
			printf("Wrong choice");
		}
	}
	return 0;
}