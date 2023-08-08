//1749. 任意子数组和的绝对值的最大值
//给你一个整数数组 nums 。一个子数组 [numsl, numsl+1, ..., numsr-1, numsr] 的 和的绝对值 为 abs(numsl + numsl+1 + ... + numsr-1 + numsr) 。
//请你找出 nums 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值 。

//abs(x) 定义如下：
//如果 x 是负整数，那么 abs(x) = -x 。
//如果 x 是非负整数，那么 abs(x) = x 。
 

//示例 1：
//输入：nums = [1,-3,2,3,-4]
//输出：5
//解释：子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5 。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxEndingHere(n);
        vector<int> minEndingHere(n);

        // 初始化以第一个元素结尾的子数组的最大和和最小和
        maxEndingHere[0] = nums[0];
        minEndingHere[0] = nums[0];

        // 初始化最大绝对和为第一个元素的绝对值
        int maxAbsolute = abs(nums[0]);

        // 遍历数组
        for (int i = 1; i < n; ++i) {
            // 更新以当前元素结尾的子数组的最大和
            maxEndingHere[i] = max(nums[i], maxEndingHere[i - 1] + nums[i]);
            // 更新以当前元素结尾的子数组的最小和
            minEndingHere[i] = min(nums[i], minEndingHere[i - 1] + nums[i]);
            // 更新最大绝对和，取当前最大和和最小和的绝对值的较大值
            maxAbsolute = max(maxAbsolute, max(abs(maxEndingHere[i]), abs(minEndingHere[i])));
        }

        return maxAbsolute;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, -3, 2, 3, -4 };
    int result = solution.maxAbsoluteSum(nums);
    cout << "Maximum absolute sum of any subarray: " << result << endl;

    return 0;
}
