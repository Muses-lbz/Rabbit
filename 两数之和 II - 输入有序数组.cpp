//167. 两数之和 II - 输入有序数组
//给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 
//numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
//你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
//你所设计的解决方案必须只使用常量级的额外空间。
//示例 1：
//输入：numbers = [2,7,11,15], target = 9
//输出：[1,2]
//解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 定义函数，输入参数为非递减排序的整数数组和目标数
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0;                    // 左指针，指向数组的开头
        int right = numbers.size() - 1;  // 右指针，指向数组的末尾

        // 双指针法
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];  // 计算两个指针所指的数的和

            if (sum == target)
            {
                // 如果和等于目标数，返回满足条件的两个数的下标（下标从1开始，所以需要加1）
                return { left + 1, right + 1 };
            }
            else if (sum < target)
            {
                // 如果和小于目标数，说明需要增加和，移动左指针向右
                left++;
            }
            else
            {
                // 如果和大于目标数，说明需要减小和，移动右指针向左
                right--;
            }
        }

        // 如果没有找到满足条件的两个数，返回空数组
        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> numbers = { 2, 7, 11, 15 };
    int target = 9;

    // 调用函数，获取满足条件的两个数的下标
    vector<int> result = solution.twoSum(numbers, target);

    if (result.empty())
    {
        // 如果结果为空数组，表示没有找到满足条件的两个数
        cout << "No two numbers found." << endl;
    }
    else
    {
        // 如果结果不为空数组，打印满足条件的两个数的下标
        cout << "Indices of the two numbers: " << result[0] << ", " << result[1] << endl;
    }

    return 0;
}
