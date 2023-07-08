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

//    这段代码解决了“两数之和 II - 输入有序数组”的问题。以下是解决思路的详细说明：
//1.  首先，我们定义了一个名为twoSum的函数，该函数接受一个非递减排序的整数数组和一个目标数作为输入参数，并返回满足条件的两个数的下标。
//2.  在函数内部，我们使用双指针法来解决问题。双指针分别指向数组的开头和末尾。
//3.  我们进入一个循环，在每次循环中计算左指针和右指针所指的数的和。
//4.  如果和等于目标数，说明找到了满足条件的两个数，我们将其下标加1（因为题目要求下标从1开始）并返回。
//5.  如果和小于目标数，说明当前和不够大，我们需要增加和，移动左指针向右。
//6.  如果和大于目标数，说明当前和太大，我们需要减小和，移动右指针向左。
//7.  重复执行步骤3到步骤6，直到找到满足条件的两个数或者左指针大于等于右指针。
//8.  如果循环结束后仍然没有找到满足条件的两个数，我们返回一个空数组表示没有找到。
//9.  在主函数中，我们创建一个Solution对象，定义了一个示例输入数组numbers和目标数target。
//10. 我们调用twoSum函数来获取满足条件的两个数的下标，并将结果保存在result变量中。
//11. 最后，我们根据result数组的情况，输出对应的结果信息。如果result为空数组，表示没有找到满足条件的两个数；否则，输出满足条件的两个数的下标。
