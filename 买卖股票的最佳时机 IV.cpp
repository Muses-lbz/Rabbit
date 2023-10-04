// 188. 买卖股票的最佳时机 IV
//给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
//设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//示例 1：
//输入：k = 2, prices = [2,4,1]
//输出：2
//解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k <= 0) return 0;

        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for (int j = 1; j <= k; j++) {
            int buy = prices[0];
            for (int i = 1; i < n; i++) {
                buy = min(buy, prices[i] - dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i - 1][j], prices[i] - buy);
            }
        }

        return dp[n - 1][k];
    }
};

int main() {
    Solution solution;
    int k = 2;
    vector<int> prices = { 2, 4, 1 };
    int maxProfit = solution.maxProfit(k, prices);

    cout << "最大利润为: " << maxProfit << endl;

    return 0;
}
