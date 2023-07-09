/*15. 三数之和
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // 首先对数组进行排序
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // 遍历数组，固定一个数作为第一个元素
        for (int i = 0; i < n - 2; i++) {
            // 如果当前数与前一个数相等，跳过，避免重复解
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i]; // 目标和为0，所以需要找到两个数使得它们的和等于-target

            int left = i + 1; // 左指针指向当前数的下一个数
            int right = n - 1; // 右指针指向数组末尾

            // 在左指针和右指针之间进行搜索
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < target) {
                    left++; // 和小于目标值，左指针右移
                }
                else if (sum > target) {
                    right--; // 和大于目标值，右指针左移
                }
                else {
                    // 找到满足条件的三元组
                    result.push_back({ nums[i], nums[left], nums[right] });

                    // 跳过重复的数
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // 移动指针继续搜索下一个可能的解
                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };

    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    // 输出结果
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*这个程序首先定义了一个名为`Solution`的类，其中包含一个函数`threeSum`用于寻找满足条件的三元组。主函数中创建了一个`Solution`对象，并将输入的整数数组传递给`threeSum`函数进行处理。
`threeSum`函数的主要思路是先对数组进行排序，然后通过遍历数组并固定一个数作为第一个元素，将问题转化为在剩余部分中寻找两个数使它们的和等于目标值。
使用双指针的方法，从左右两端向中间搜索，根据当前和与目标值的大小关系，不断调整指针的位置。当和等于目标值时，找到一个满足条件的三元组，将其加入结果集。
同时，为了避免重复解，需要跳过重复的元素。
最后，程序使用范围-based for循环遍历结果集，并输出每个三元组中的元素。在给定的示例中，输出将是`[-1 -1 2]`和`[-1 0 1]`。*/
