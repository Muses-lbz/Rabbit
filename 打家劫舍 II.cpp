//213. 打家劫舍 II
//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
//同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

//示例 1：
//输入：nums = [2,3,2]
//输出：3
//解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // 偷窃第一个房屋到倒数第二个房屋之间的最大金额
        vector<int> dp1(n);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }

        // 不偷窃第一个房屋到最后一个房屋之间的最大金额
        vector<int> dp2(n);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
        }

        // 返回两个子问题的最大值
        return max(dp1[n - 2], dp2[n - 1]);
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2, 3, 2 };
    int result = solution.rob(nums);
    cout << "今晚能够偷窃到的最高金额是：" << result << endl;
    return 0;
}
