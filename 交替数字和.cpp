//2544. 交替数字和
//给你一个正整数 n 。n 中的每一位数字都会按下述规则分配一个符号：
//最高有效位 上的数字分配到 正 号。
//剩余每位上数字的符号都与其相邻数字相反。
//返回所有数字及其对应符号的和。
//示例 1：
//输入：n = 521
//输出：4
//解释：(+5) + (-2) + (+1) = 4

#include <iostream>

class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0, sign = 1;
        while (n != 0)
        {
            sum += sign * (n % 10);
            sign = -sign;
            n /= 10;
        }
        return -sign * sum;
    }
};

int main() {
    Solution solution;

    int n = 12345;
    int result = solution.alternateDigitSum(n);
    std::cout << "Alternate Digit Sum: " << result << std::endl;

    n = 1000;
    result = solution.alternateDigitSum(n);
    std::cout << "Alternate Digit Sum: " << result << std::endl;

    system("pause");
    return 0;
}
