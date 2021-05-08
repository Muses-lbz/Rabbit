/* 变量的访问和修改 */
#include <stdio.h>

int main(void)
{
	int data = 24;

	printf("data = %d\n", data + 1);
	data = 26;
	printf("data = %d\n", data);

	return 0;
}