/* 验证整型（长整型与其一致）可存储的数值范围 */
#include <stdio.h>

int main(void)
{
	int maxInt = 2147483647;
	int minInt = -2147483648;

	unsigned maxUnsInt = 4294967295;
	unsigned minUnsInt = 0;

	printf("Max(int) = %d\n", maxInt);
	printf("Max - 1 = %d\n\n", maxInt - 1);				/* 溢出 */

	printf("Min(int) = %d\n", minInt);
	printf("Min + 1 = %d\n", minInt + 1); 					/* 溢出 */

	printf("Max(unsigned int) = %u\n", maxUnsInt);
	printf("Max + 1 = %u\n\n", maxUnsInt + 1); 			/* 溢出 */

	printf("Min(unsigned int) = %u\n", minUnsInt);
	printf("Min - 1 = %u\n\n", minUnsInt - 1); 				/* 溢出 */

	return 0;
}
