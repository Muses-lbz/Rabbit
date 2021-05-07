/* 使用extern声明变量 */
#include <stdio.h>

int main(void) {
	extern int data;				/* 声明一个变量data */
	printf("data = %d\n", data);	/* 输出data的值 */

	return 0;
}

int data = 23;						/* 定义变量data */