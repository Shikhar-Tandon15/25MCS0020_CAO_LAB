#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
#include"00_colours.h"
#include "mnudrvprg_010_parallel_construct.h"
#include "mnudrvprg_runtime_routines.h"
#include "mnudrvprg_num_square.h"
#include "mnudrvprg_for_card_game.h"
#include "mnudrvprg_for_bakery.h"
#include "mnudrvprog_data_env_construct.h"


int fn_main_page() {
	int i;
	while (1) {

		printf("\n");
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_blue();
		printf("\t\t\t\t    MACSE517-COMPUTER ARCHITECTURE AND ORGANISATION LAB PROGRAMS\n");
		printf("\t\t\t\t\t\t\t    BY\n");
		fn_reset();
		fn_yellow();
		printf("\n");
		printf("\t\t\t\t\t    Reg.No:22MCS0020  Name:Shikhar Tandon\n");
		printf("\n");
		fn_reset();
		fn_blue();
		printf("\t\t\t\t\t    Submitted as part of Lab assessment to\n");
		fn_magenta();
		printf("\t\t\t\t\t\t     Dr.M.RAJASEKHARA BABU\n");
		fn_reset();
		fn_blue();
		printf("\t\t\t\t\t    SCHOOL OF COMPUTER SCIENCE AND ENGINEERING \n");
		printf("\t\t\t\t      VELLORE INSTITUTE OF TECHNOLOGY(VIT),VELLORE-632014\n");
		printf("\t\t\t\t\t\t        November 2025\n");
		fn_reset();
		fn_red();
		printf("************************************************************************************************************************\n");
		fn_reset();
		fn_green(); 
		printf("1-Exit\t      2-Parallel Construct Program \t3-Run-Time Environment Routines\t\t 4-Loop Worksharing Constructs\n");
		printf("\n");
		printf("5-Sections & Single Worksharing Constructs\t6-Scheduling techniques \t\t 7-Data Evironment Constructs \n");
		fn_reset();
		fn_yellow();
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		fn_reset();
		fn_cyan();
		printf("Enter your choice: \n");
		scanf_s("%d", &i);
		fn_reset();
		switch (i) {
		case 1: {
			fn_yellow();
			printf("\nYou choose to exit the program. \n");
			fn_reset();
			exit(0);
		}
		case 2: {
			fn_yellow();
			printf("\nThank you for selecting Parallel Construct Program, now check the below list\n");
			fn_reset();
			fn_mnudrvprg_010_parallel_construct();
			break;
		}
		case 3: {
			fn_yellow();
			printf("\nThank you for selecting Run-Time Environment Routines Program, now check the below list\n");
			fn_reset();
			fn_mnudrvprg_runtime_routines();
			break;
		}
		case 4: {
			fn_yellow();
			printf("\nThank you for selecting Work Sharing Construct-For, now check the below list\n");
			fn_reset();
			fn_mnudrvprg_squares();
			break;
		}
		case 5: {
			fn_yellow();
			printf("\nThank you for selecting Work Sharing Construct-Section and Single, now check the below list\n");
			fn_reset();
			fn_mnudrvprg_cardgame();
			break;
		}
		case 6: {
			fn_yellow();
			printf("\nThank you for selecting Scheduling Techniques Program, now check the below list\n");
			fn_reset();
			fn_mnudrvprg_bakery();
			break;
		}
		case 7: {
			fn_yellow();
			printf("\nThank you for selecting Data Environment Construct Program, now check the below list\n");
			fn_reset();
			fn_mnudrvprg_data_env_construct();
			break;
		}
		default: {
			printf("Opted wrong choice! \n");
		}
		}
	}
	return 0;
}


