//415. 字符串相加
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

//示例 1：
//输入：num1 = "11", num2 = "123"
//输出："134"

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    string result = "";  // 存储相加结果的字符串
    int carry = 0;  // 进位标志

    // 从字符串的最低位开始逐位相加
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;  // 取 num1 的当前位数字，若已遍历完则取 0
        int digit2 = j >= 0 ? num2[j] - '0' : 0;  // 取 num2 的当前位数字，若已遍历完则取 0
        int sum = digit1 + digit2 + carry;  // 当前位的数字相加

        carry = sum / 10;  // 计算进位
        sum = sum % 10;  // 计算当前位的值

        result += (sum + '0');  // 将当前位的值转为字符并加入结果字符串
        i--;
        j--;
    }

    reverse(result.begin(), result.end());  // 反转结果字符串，得到正确的顺序

    return result;
}

int main() {
    string num1, num2;
    cout << "请输入非负整数 num1: ";
    cin >> num1;
    cout << "请输入非负整数 num2: ";
    cin >> num2;

    string sum = addStrings(num1, num2);
    cout << "两个数字的和为: " << sum << endl;

    return 0;
}
