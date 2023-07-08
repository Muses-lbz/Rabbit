//2178. 拆分成最多数目的正偶数之和
//给你一个整数 finalSum 。请你将它拆分成若干个 互不相同 的正偶数之和，且拆分出来的 正偶数数目 最多 。
///比方说，给你 finalSum = 12 ，那么这些拆分是 符合要求 的（互不相同的正偶数且和为 finalSum）：(2 + 10) ，(2 + 4 + 6) 和 (4 + 8) 。它们中，(2 + 4 + 6) 包含最多数目的整数。
//注意 finalSum 不能拆分成 (2 + 2 + 4 + 4) ，因为拆分出来的整数必须互不相同。
//请你返回一个整数数组，表示将整数拆分成 最多 数目的正偶数数组。如果没有办法将 finalSum 进行拆分，请你返回一个 空 数组。你可以按 任意 顺序返回这些整数。
//示例 1：
//输入：finalSum = 12
//输出：[2,4,6]
//解释：以下是一些符合要求的拆分：(2 + 10)，(2 + 4 + 6) 和 (4 + 8) 。
//(2 + 4 + 6) 为最多数目的整数，数目为 3 ，所以我们返回 [2,4,6] 。
//[2,6,4] ，[6,2,4] 等等也都是可行的解。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 定义函数，计算最大的偶数拆分
    vector<long long> maximumEvenSplit(long long finalSum) {
        // 如果目标和为奇数，则无法拆分成偶数的和，返回空数组
        if (finalSum & 1)
            return {};
        
        vector<long long> res;  // 存储拆分结果
        for (int cur = 2; cur <= finalSum; cur += 2) {
            res.push_back(cur);   // 将偶数加入结果数组
            finalSum -= cur;      // 减去已经加入的偶数
        }
        
        // 如果无法刚好拆分完毕，将余数与等差数列的最后一项合并
        if (finalSum != 0)
            res.back() += finalSum;
        
        return res;  // 返回拆分结果
    }
};

int main() {
    long long finalSum;
    cout << "Enter the final sum: ";
    cin >> finalSum;

    Solution solution;
    vector<long long> result = solution.maximumEvenSplit(finalSum);

    cout << "Maximum even split: ";
    for (long long num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
