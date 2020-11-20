#include<stdio.h>
#include<stdlib.h>

#define ISSUES 5
#define RATING 10

void record(int iss, int rate);
void highestRate();
void lowestRate();
float avgRate(int iss);
void displayResult();

int responses[ISSUES][RATING];
const char *topics[ISSUES] = { "Global warming","Econnomy","War","Health care","Edu" };

int main()
{
	int response, i;
	do
	{
		printf("Please rate the following topics on scale from 1-10""\n 1 to 10\n");

		for(i = 0; i < ISSUES; i++)
		{
			do
			{
				printf("%s?", topics[i]);
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			record(i, response);
		}
		printf("Enter 1 to stop.Enter 0 to rate again.");
	scanf_s("%d", &response);
	}while (response != 1);
	
	displayResult();
	system("pause");
	return 0;
}
void record(int iss, int rate)
{
	responses[iss][rate - 1]++;
}
void highestRate()
{
	int highR = 0, highT = 0,i,j;

	for (i = 0; i < ISSUES; i++)
	{
		int topicR = 0;
		for (j = 0; j < RATING; j++)
		{
			topicR += responses[i][j] * (j + 1);
		}

		if (highR < topicR)
		{
			highR =topicR;
			highR = i;
		}
	}
	printf("the highest rated topic was");
	printf("%s", topics[highT]);
	printf("with a total rating of %d\n", highR);
}
void lowestRate()
{
	int lowR = 999, lowT = 999, i, j;

	for (i = 0; i < ISSUES; i++)
	{
		int topicR = 0;
		for (j = 0; j < RATING; j++)
		{
			topicR += responses[i][j] * (j + 1);
		}
		if (i == 0)
		{
			lowR = topicR;
		}
		if (lowR> topicR)
		{
			lowR = topicR;
			lowR = i;
		}
	}
	printf("the lowest rated topic was");
	printf("%s", topics[lowT]);
	printf("with a total rating of %d\n", lowR);
}
float avgRate(int iss)
{
	float total = 0;
	int counter = 0;
	int i;

	for (i = 0; i < RATING; i++)
	{
		if (responses[iss][i] != 0)
		{
			total += responses[iss][i] * (i + 1);
			counter += responses[iss][i];
		}
	}
	return total / counter;
}
void displayResult()
{
	int i, j;
	printf("%20s", "Topic");

	for (i = 1; i <= RATING; i++)
	{
		printf("%4d", i);
	}

	printf("%20s", "Average Rating");

	for (i = 0; i < ISSUES; i++)
	{
		printf("%20s",topics[i]);

		for (j = 0; j < RATING; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f", avgRate(i));
	}

	highestRate();
	lowestRate();
}



