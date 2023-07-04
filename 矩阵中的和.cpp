#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 比较函数，用于排序
static int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

// 计算二维数组中最大值之和的函数
int matrixSum(int** nums, int numsSize, int* numsColSize)
{
    int res = 0;
    int m = numsSize; // 行数
    int n = numsColSize[0]; // 列数

    // 对每一行进行排序
    for (int i = 0; i < m; i++)
    {
        qsort(nums[i], n, sizeof(int), cmp);
    }

    // 计算每一列的最大值之和
    for (int j = 0; j < n; j++)
    {
        int maxVal = 0;
        for (int i = 0; i < m; i++)
        {
            maxVal = (int)fmax(maxVal, nums[i][j]);
        }
        res += maxVal;
    }

    return res;
}

int main()
{
    int numsSize = 4;
    int numsColSize[] = { 3, 3, 3, 3 };

    // 动态分配二维数组的内存空间
    int** nums = (int**)malloc(numsSize * sizeof(int*));
    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = (int*)malloc(numsColSize[i] * sizeof(int));
        if (nums[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    // 手动赋值给 nums 数组的元素
    nums[0][0] = 7;
    nums[0][1] = 2;
    nums[0][2] = 1;
    nums[1][0] = 6;
    nums[1][1] = 4;
    nums[1][2] = 2;
    nums[2][0] = 6;
    nums[2][1] = 5;
    nums[2][2] = 3;
    nums[3][0] = 3;
    nums[3][1] = 2;
    nums[3][2] = 1;

    int result = matrixSum(nums, numsSize, numsColSize);
    printf("Result: %d\n", result);

    // 释放动态分配的内存
    for (int i = 0; i < numsSize; i++) {
        free(nums[i]);
    }
    free(nums);

    return 0;
}
