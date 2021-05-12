#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int a, b, c;
	char d[] = "This is the first document in this repository.";
	char e[] = "I like l_bz. This is a truth.";
	a = rand()%7;
	b = rand()%7;
	printf("%d %d\n", a, b);
	/*scanf("%d %d", &a, &b);*/
	c = a >= b ? a : b;
	if (c == a)
	{
		/*printf("This is the first document in this repository.");*/
		puts(d);
	}
	else
	{
		/*printf("I like l_bz.");*/
		puts(e);
	}
	system("pause");
	return 0;
}
