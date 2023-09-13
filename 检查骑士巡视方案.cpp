//2596. 检查骑士巡视方案
//骑士在一张 n x n 的棋盘上巡视。在 有效 的巡视方案中，骑士会从棋盘的 左上角 出发，并且访问棋盘上的每个格子 恰好一次 。
//给你一个 n x n 的整数矩阵 grid ，由范围 [0, n * n - 1] 内的不同整数组成，其中 grid[row][col] 表示单元格 (row, col) 是骑士访问的第 grid[row][col] 个单元格。骑士的行动是从下标 0 开始的。
//如果 grid 表示了骑士的有效巡视方案，返回 true；否则返回 false。
//注意，骑士行动时可以垂直移动两个格子且水平移动一个格子，或水平移动两个格子且垂直移动一个格子。下图展示了骑士从某个格子出发可能的八种行动路线。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // 用于记录每个格子是否被访问过

        int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1}; // 垂直移动的偏移量
        int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2}; // 水平移动的偏移量

        int row = 0, col = 0; // 从左上角开始
        visited[row][col] = true;

        for (int step = 1; step < n * n; ++step) {
            for (int dir = 0; dir < 8; ++dir) {
                int newRow = row + dr[dir];
                int newCol = col + dc[dir];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited[newRow][newCol] && grid[newRow][newCol] == step) {
                    visited[newRow][newCol] = true;
                    row = newRow;
                    col = newCol;
                    break;
                }
            }
        }

        // 最后检查是否所有格子都被访问过
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    // 创建 Solution 类的对象
    Solution solution;

    // 示例输入矩阵 grid
    vector<vector<int>> grid = {
        {0, 59, 36, 58, 57, 7, 8, 39},
        {35, 22, 61, 6, 59, 42, 57, 58},
        {32, 59, 52, 4, 11, 38, 63, 16},
        {13, 16, 31, 28, 9, 32, 25, 38},
        {56, 11, 10, 49, 18, 29, 50, 31},
        {41, 48, 51, 26, 53, 24, 3, 30},
        {54, 15, 12, 27, 20, 37, 34, 5},
        {17, 14, 47, 2, 45, 60, 1, 62}
    };

    // 调用 checkValidGrid 函数检查骑士巡视方案
    bool isValid = solution.checkValidGrid(grid);

    // 根据结果输出信息
    if (isValid) {
        cout << "这是一个有效的骑士巡视方案。" << endl;
    } else {
        cout << "这不是一个有效的骑士巡视方案。" << endl;
    }

    return 0;
}
