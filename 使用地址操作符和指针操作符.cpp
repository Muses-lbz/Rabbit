/* 使用地址操作符和指针操作符 */
#include <stdio.h>

int main(void) {
	int key = 0;								/* 定义变量key */

	printf("Please input a integer:");
	scanf("%d", &key);							/* 从屏幕输入一个数赋值给变量key */
	printf("key\t= %d\n", key);					/* 输出key的值 */

	printf("&key\t= %p\n", &key);				/* 打印key的地址 */
	printf("*(&key)\t= %d\n", *(&key));			/* 打印地址为&key的内存空间的内容 */

	return 0;
}
