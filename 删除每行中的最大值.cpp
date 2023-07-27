//2500. 删除每行中的最大值
//给你一个 m x n 大小的矩阵 grid ，由若干正整数组成。
//执行下述操作，直到 grid 变为空矩阵：
//从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。
//将删除元素中的最大值与答案相加。
//注意 每执行一次操作，矩阵中列的数据就会减 1 。
//返回执行上述操作后的答案。

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class Solution {
public:
    int deleteGreatestValue(std::vector<std::vector<int>>& grid) {
        int m = grid.size();        // 矩阵的行数
        int n = grid[0].size();     // 矩阵的列数
        int s = 0;                  // 变量用于存储所有最大值的和

        // 对每一行进行升序排序
        for (auto& v : grid)
            std::sort(v.begin(), v.end());

        // 遍历每一列
        for (int j = 0; j < n; j++) {
            int mx = INT_MIN;       // 变量用于存储当前列中的最大值

            // 找到当前列中的最大值
            for (int i = 0; i < m; i++)
                mx = std::max(mx, grid[i][j]);

            s += mx;                // 将最大值加到和中
        }

        return s;                   // 返回最终的和作为结果
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = { {1, 2, 4}, {3, 3, 1} };
    int answer = solution.deleteGreatestValue(grid);
    std::cout << "Answer: " << answer << std::endl;

    return 0;
}
