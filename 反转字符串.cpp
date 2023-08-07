//344. 反转字符串
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

//示例 1：
//输入：s = ["h","e","l","l","o"]
//输出：["o","l","l","e","h"]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;           // 指向字符串开头的指针
        int right = s.size() - 1; // 指向字符串末尾的指针

        while (left < right) {
            // 交换两个指针指向的字符
            swap(s[left], s[right]);
            // 移动指针
            left++;
            right--;
        }
    }
};

int main() {
    Solution solution;
    vector<char> s = { 'h', 'e', 'l', 'l', 'o' };

    solution.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}
