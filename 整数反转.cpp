#include <stdio.h>
#include <stdlib.h>

int reverse(int x)
{
	long long int  r = 0;
	while (x)
	{
		r = r * 10 + (x % 10);
		x /= 10;
	}
	if (r > 2147483647)
		return 0;
	if (r < -2147483648)
		return 0;
	//return (int)r;
	printf("%d\n\n", (int)r);
	return 0;
}

int main()
{
	int x;
	scanf_s("%d", &x);
	reverse(x);
	system("pause");
	return 0;
}
