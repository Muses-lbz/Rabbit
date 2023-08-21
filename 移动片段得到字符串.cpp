// 2337. 移动片段得到字符串
//给你两个字符串 start 和 target ，长度均为 n 。每个字符串 仅 由字符 'L'、'R' 和 '_' 组成，其中：
//字符 'L' 和 'R' 表示片段，其中片段 'L' 只有在其左侧直接存在一个 空位 时才能向 左 移动，而片段 'R' 只有在其右侧直接存在一个 空位 时才能向 右 移动。
//字符 '_' 表示可以被 任意 'L' 或 'R' 片段占据的空位。
//如果在移动字符串 start 中的片段任意次之后可以得到字符串 target ，返回 true ；否则，返回 false 。

//示例 1：
//输入：start = "_L__R__R_", target = "L______RR"
//输出：true
//解释：可以从字符串 start 获得 target ，需要进行下面的移动：
//- 将第一个片段向左移动一步，字符串现在变为 "L___R__R_" 。
//- 将最后一个片段向右移动一步，字符串现在变为 "L___R___R" 。
//- 将第二个片段向右移动散步，字符串现在变为 "L______RR" 。
//可以从字符串 start 得到 target ，所以返回 true 。

#include <iostream>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n && j < n) {
            // 跳过 start 中的空位
            while (i < n && start[i] == '_') {
                i++;
            }
            // 跳过 target 中的空位
            while (j < n && target[j] == '_') {
                j++;
            }
            if (i < n && j < n) {
                if (start[i] != target[j]) {
                    return false;
                }
                char c = start[i];
                // 判断是否满足移动规则
                if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
        }
        // 检查剩余的空位是否符合规则
        while (i < n) {
            if (start[i] != '_') {
                return false;
            }
            i++;
        }
        while (j < n) {
            if (target[j] != '_') {
                return false;
            }
            j++;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string start = "_L__R__R_";
    string target = "L______RR";

    if (solution.canChange(start, target)) {
        cout << "是的，可以进行转化。" << endl;
    } else {
        cout << "不可以进行转化。" << endl;
    }

    return 0;
}
