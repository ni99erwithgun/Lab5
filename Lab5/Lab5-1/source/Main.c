#include <stdio.h>
#include <stdlib.h>
#define STU 3
#define EXAM 4
void printarr(int grades[][EXAM], int pupils, int tests);
void maximum(int grades[][EXAM], int pupils, int tests);
void minimum(int grades[][EXAM], int pupils, int tests);
void average(int grades[][EXAM], int pupils, int tests);
void printMenu();

int main()
{
	int StudentsGrade[STU][EXAM] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };
	void(*processGrages[4])(int[STU][EXAM], int, int) = { printarr,minimum,maximum,average };
	int choice = 0;
	while (choice != 4)
	{
		do {
			printMenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
		{
			(*processGrages[choice])(StudentsGrade, STU, EXAM);
		}
		else
		{
			printf("\tProgram Ended. \n");
		}
	}
	system("pause");
	return 0;
}
void maximum(int grades[][EXAM], int pupils, int tests)
{
	int i, j;
	int highestGrade = 0;

	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] > highestGrade)
				highestGrade = grades[i][j];
		}
	}
	printf("\n\tThe highestgrade is %d\n", highestGrade);

}
void minimum(int grades[][EXAM], int pupils, int tests)
{
	int i, j;
	int lowestGrade=999;

	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] < lowestGrade)
				lowestGrade = grades[i][j];
		}
	}
	printf("\n\tThe lowestgrade is %d\n",lowestGrade);

}
void average(int grades[][EXAM], int pupils, int tests)

{
	int i, j, total;
	for (i = 0; i < pupils; i++)
	{
		total = 0;
		for (j = 0; j < tests; j++)
		{
			total += grades[i][j];
		}
		printf("\n\tThe average grade for student %d is %.1f", i + 1, (double)total / tests);

	}
	printf("\n");
}
void printarr(int grades[][EXAM], int pupils, int tests)
{
	int i, j;

	printf("\n\t\t\t[0]    [1]    [2]    [3]");
	for (i = 0; i < pupils; i++)
	{
		printf("\n\tstudentGrades[%d]", i);
		for (j = 0; j < tests; j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}
void printMenu()
{
	printf("\n");
	printf("\tEnteer a choice:\n");
	printf("\t0 Print the array of grades\n");
	printf("\t1 Find the minimum grades\n");
	printf("\t2 Find the maximum grades\n");
	printf("\t3 Find the average on all tests for each student\n");
	printf("\t4 End program\n");
	printf("choice:");
}