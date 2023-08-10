//1289. 下降路径最小和 II
//给你一个 n x n 整数矩阵 grid ，请你返回 非零偏移下降路径 数字和的最小值。
//非零偏移下降路径 定义为：从 grid 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。

//示例1：
//输入：grid = [[1,2,3],[4,5,6],[7,8,9]]
//输出：13
//解释：
//所有非零偏移下降路径包括：
//[1,5,9], [1,5,7], [1,6,7], [1,6,8],
//[2,4,8], [2,4,9], [2,6,7], [2,6,8],
//[3,4,8], [3,4,9], [3,5,7], [3,5,9]
//下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。

#include <iostream>
#include <vector>
#include <climits> // 用于 INT_MAX
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // 创建一个与原矩阵相同大小的 dp 数组

        // 初始化 dp 数组的第一行为原矩阵的第一行
        for (int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }

        // 使用动态规划计算 dp 数组的每个元素
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 从上一行的每个列中选取除了当前列 j 之外的最小值
                int minPrev = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (k != j) {
                        minPrev = min(minPrev, dp[i - 1][k]);
                    }
                }
                // 当前单元格的值为原矩阵中的值加上上一行的最小值
                dp[i][j] = grid[i][j] + minPrev;
            }
        }

        // 在最后一行中找到最小值作为答案
        int result = INT_MAX;
        for (int j = 0; j < n; ++j) {
            result = min(result, dp[n - 1][j]);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    int result = solution.minFallingPathSum(grid);
    cout << "最小下降路径和: " << result << endl;
    return 0;
}
