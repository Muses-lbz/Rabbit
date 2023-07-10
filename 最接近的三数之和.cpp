/*16. 最接近的三数之和
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在恰好一个解。
示例 1：
  输入：nums = [-1,2,1,-4], target = 1
  输出：2
  解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // 排序数组

        int closestSum = INT_MAX; // 存储最接近的三数之和
        int minDiff = INT_MAX; // 存储当前的最小差值

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1; // 左指针从当前元素的下一个位置开始
            int right = nums.size() - 1; // 右指针从数组末尾开始

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right]; // 当前三数之和
                int diff = abs(sum - target); // 当前三数之和与目标值的差的绝对值

                if (diff < minDiff) {
                    minDiff = diff; // 更新最小差值
                    closestSum = sum; // 更新最接近的三数之和
                }

                if (sum < target)
                    left++; // 如果当前和小于目标值，移动左指针，以增加和的大小
                else
                    right--; // 如果当前和大于目标值，移动右指针，以减少和的大小
            }
        }

        return closestSum; // 返回最接近的三数之和
    }
};

int main() {
    vector<int> nums = { -1, 2, 1, -4 };
    int target = 1;

    Solution solution;
    int closestSum = solution.threeSumClosest(nums, target);

    cout << "Closest sum: " << closestSum << endl;

    system("pause"); // 在Windows上暂停程序，防止控制台窗口立即关闭
    return 0;
}

这段代码的主要思路是使用双指针法来找到与目标值最接近的三数之和。

首先，将输入的整数数组 nums 进行排序，以便于使用双指针法进行遍历。
定义两个变量 closestSum 和 minDiff，分别用于存储最接近的三数之和和当前的最小差值。初始值设为整型最大值 INT_MAX。
开始遍历数组 nums，从第一个元素到倒数第三个元素，依次作为固定的第一个数。
在固定的第一个数的基础上，使用双指针 left 和 right 分别指向固定数的下一个元素和数组的末尾元素。
循环执行以下步骤，直到 left 和 right 相遇：
计算当前的三数之和 sum，即固定数加上 left 指向的数和 right 指向的数。
计算当前的差值 diff，即当前三数之和与目标值 target 的差的绝对值。
如果当前的差值小于最小差值 minDiff，则更新最小差值和最接近的三数之和。
根据当前三数之和与目标值的大小关系，移动指针 left 或 right，以逼近目标值。
循环结束后，返回最接近的三数之和 closestSum。
在主函数中，创建 Solution 类的实例 solution，调用 threeSumClosest 方法，将结果存储在变量 closestSum 中。
最后，输出最接近的三数之和。
代码中的 system("pause") 是为了在Windows上暂停程序，防止控制台窗口立即关闭，以便查看输出结果。如果你使用的是其他操作系统，可以删除该行代码。
