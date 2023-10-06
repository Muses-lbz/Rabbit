// 714. 买卖股票的最佳时机含手续费
//给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
//你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
//返回获得利润的最大值。
//注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

//示例 1：
//输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
//输出：8
//解释：能够达到的最大利润:  
//在此处买入 prices[0] = 1
//在此处卖出 prices[3] = 8
//在此处买入 prices[4] = 4
//在此处卖出 prices[5] = 9
//总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8

//示例 2：
//输入：prices = [1,3,7,5,10,3], fee = 3
//输出：6

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);

        buy[0] = -prices[0] - fee;

        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i] - fee);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }

        return sell[n - 1];
    }
};

int main() {
    // 示例输入
    vector<int> prices1 = { 1, 3, 2, 8, 4, 9 };
    int fee1 = 2;

    vector<int> prices2 = { 1, 3, 7, 5, 10, 3 };
    int fee2 = 3;

    Solution solution;

    // 调用函数并输出结果
    int result1 = solution.maxProfit(prices1, fee1);
    cout << "示例 1 的最大利润为: " << result1 << endl;

    int result2 = solution.maxProfit(prices2, fee2);
    cout << "示例 2 的最大利润为: " << result2 << endl;

    return 0;
}
