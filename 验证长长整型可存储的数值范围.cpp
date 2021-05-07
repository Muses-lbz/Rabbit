/* 验证长长整型可存储的数值范围 */
#include <stdio.h>

int main(void)
{
	long long int maxLlInt = 9223372036854775807;
	long long int minLlInt = -9223372036854775808;

	unsigned long long int maxUnsLlInt = 18446744073709551615;
	unsigned long long int minUnsLlInt = 0;

	printf("Max(long long int) = %lld\n", maxLlInt);
	printf("Max + 1 = %lld\n\n", maxLlInt + 1); 				/* 溢出 */

	printf("Min(long long int) = %lld\n", minLlInt);
	printf("Min - 1 = %lld\n\n", minLlInt - 1); 					/* 溢出 */

	printf("Max(unsigned long long int) = %llu\n", maxUnsLlInt);
	printf("Max + 1 = %llu\n\n", maxUnsLlInt + 1); 			/* 溢出 */

	printf("Min(unsigned long long int) = %llu\n", minUnsLlInt);
	printf("Min - 1 = %llu\n", minUnsLlInt - 1); 				/* 溢出 */

	return 0;
}
