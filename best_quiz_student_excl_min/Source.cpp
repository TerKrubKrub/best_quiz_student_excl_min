#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct person
{
	char code[10];
	int score[10];
	int totalScore;
};

person p[1000];
int min[1000];
int max = 0;

void input(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		min[i] = 99;
		p[i].totalScore = 0;
		scanf("%s", &p[i].code);
		for (int j = 0; j < y; j++)
		{
			scanf("%d", &p[i].score[j]);
			p[i].totalScore += p[i].score[j];
			if (p[i].score[j] < min[i])
			{
				min[i] = p[i].score[j];
			}
		}
	}
	for (int i = 0; i < x; i++)
	{
		int count = 0;
		for (int j = 0; j < y; j++)
		{
			if (p[i].score[j] == min[i])
			{
				count++;
			}
		}
		if (count == 1) p[i].totalScore -= (count * min[i]);
		else if (count > 1) p[i].totalScore -= ((count-1) * min[i]);
	}
}
void maxScore(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		if (p[i].totalScore > max) max = p[i].totalScore;
	}
}
int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	input(n, t);
	maxScore(n, t);
	printf("%d\n", max);
	for (int i = 0; i < n; i++)
	{
			if (p[i].totalScore == max)
			{
				printf("%s\n", p[i].code);
			}
	}
	return 0;
}