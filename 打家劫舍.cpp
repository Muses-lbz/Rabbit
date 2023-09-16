//198. 打家劫舍
//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

//示例 1：
//输入：[1,2,3,1]
//输出：4
//解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。偷窃到的最高金额 = 1 + 3 = 4 。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // 创建一个数组来存储最高金额
        vector<int> dp(n, 0);
        
        // 初始化前两个元素
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        // 从第三个房屋开始计算最高金额
        for (int i = 2; i < n; ++i) {
            // 在偷窃当前房屋和不偷窃当前房屋之间选择最大值
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        // 返回最后一个元素即为答案
        return dp[n - 1];
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    int result = solution.rob(nums);
    cout << "能够偷窃到的最高金额是：" << result << endl;
    return 0;
}
