//1222. 可以攻击国王的皇后
//在一个 8x8 的棋盘上，放置着若干「黑皇后」和一个「白国王」。
//给定一个由整数坐标组成的数组 queens ，表示黑皇后的位置；以及一对坐标 king ，表示白国王的位置，返回所有可以攻击国王的皇后的坐标(任意顺序)。

//示例 1：
//输入：queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
//输出：[[0,1],[1,0],[3,3]]
//解释： 
//[0,1] 的皇后可以攻击到国王，因为他们在同一行上。 
//[1,0] 的皇后可以攻击到国王，因为他们在同一列上。 
//[3,3] 的皇后可以攻击到国王，因为他们在同一条对角线上。 
//[0,4] 的皇后无法攻击到国王，因为她被位于 [0,1] 的皇后挡住了。 
//[4,0] 的皇后无法攻击到国王，因为她被位于 [1,0] 的皇后挡住了。 
//[2,4] 的皇后无法攻击到国王，因为她和国王不在同一行/列/对角线上。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        // 创建一个大小为 8x8 的棋盘，初始化为 0
        vector<vector<int>> chessboard(8, vector<int>(8, 0));

        // 标记黑皇后的位置
        for (const auto& queen : queens) {
            chessboard[queen[0]][queen[1]] = 1;
        }

        vector<vector<int>> result;
        // 八个可能的方向
        int directions[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

        for (const auto& dir : directions) {
            int x = king[0] + dir[0];
            int y = king[1] + dir[1];

            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (chessboard[x][y] == 1) {
                    result.push_back({ x, y });
                    break;
                }
                x += dir[0];
                y += dir[1];
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> queens = { {0,1},{1,0},{4,0},{0,4},{3,3},{2,4} };
    vector<int> king = { 0, 0 };

    vector<vector<int>> result = solution.queensAttacktheKing(queens, king);

    // 输出结果
    cout << "可以攻击国王的皇后坐标：" << endl;
    for (const auto& coord : result) {
        cout << "(" << coord[0] << "," << coord[1] << ")" << endl;
    }

    return 0;
}
