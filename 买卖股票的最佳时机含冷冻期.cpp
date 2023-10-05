// 309. 买卖股票的最佳时机含冷冻期
//给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
//设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
//卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//示例 1:
//输入: prices = [1,2,3,0,2]
//输出: 3 
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动态规划算法的实现
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        vector<int> cooldown(n, 0);

        buy[0] = -prices[0];

        for (int i = 1; i < n; i++) {
            buy[i] = max(cooldown[i - 1] - prices[i], buy[i - 1]);
            sell[i] = buy[i - 1] + prices[i];
            cooldown[i] = max(sell[i - 1], cooldown[i - 1]);
        }

        return max(sell[n - 1], cooldown[n - 1]);
    }
};

int main() {
    // 输入股票价格数组
    vector<int> prices = { 1, 2, 3, 0, 2 };

    // 创建Solution对象
    Solution solution;

    // 调用maxProfit函数计算最大利润
    int maxProfit = solution.maxProfit(prices);

    // 输出结果
    cout << "最大利润为：" << maxProfit << endl;

    return 0;
}
