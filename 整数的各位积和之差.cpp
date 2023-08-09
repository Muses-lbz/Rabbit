//1281. 整数的各位积和之差
//给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。

//示例 1：
//输入：n = 234
//输出：15 
//解释：
//各位数之积 = 2 * 3 * 4 = 24 
//各位数之和 = 2 + 3 + 4 = 9 
//结果 = 24 - 9 = 15

#include <iostream>

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        }

        int difference = product - sum;
        return difference;
    }
};

int main() {
    Solution solution;
    int n = 234;
    int result = solution.subtractProductAndSum(n);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
