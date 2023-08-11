//1572. 矩阵对角线元素的和
//给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。
//请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。

//示例1：
//输入：mat = [[1,2,3],
//            [4,5,6],
//            [7,8,9]]
//输出：25
//解释：对角线的和为：1 + 5 + 9 + 3 + 7 = 25
//请注意，元素 mat[1][1] = 5 只会被计算一次。

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int diagonalSum(vector<vector<int>>& mat) {
//        int n = mat.size();
//        int diagonalSum = 0;
//
//        for (int i = 0; i < n; i++) {
//            diagonalSum += mat[i][i];  // 主对角线上的元素
//            diagonalSum += mat[i][n - 1 - i];  // 副对角线上且不在主对角线上的元素
//        }
//
//        if (n % 2 == 1) {  // 如果矩阵的大小是奇数，则主对角线上的元素会被重复计算，需要减去一次
//            int mid = n / 2;
//            diagonalSum -= mat[mid][mid];
//        }
//
//        return diagonalSum;
//    }
//};

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int diagonalSum = 0;

        for (int i = 0; i < n; i++)
        {
            diagonalSum += mat[i][i];
            diagonalSum += mat[i][n - 1 - i];
        }

        if (n % 2 == 1)
        {
            int m = n / 2;
            diagonalSum -= mat[m][m];
        }
        return diagonalSum;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = solution.diagonalSum(mat);
    cout << result << endl;  // 输出结果

    return 0;
}
