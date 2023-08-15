//833. 字符串中的查找与替换
//你会得到一个字符串 s (索引从 0 开始)，你必须对它执行 k 个替换操作。替换操作以三个长度均为 k 的并行数组给出：indices, sources,  targets。
//要完成第 i 个替换操作:
//检查 子字符串  sources[i] 是否出现在 原字符串 s 的索引 indices[i] 处。
//如果没有出现， 什么也不做 。
//如果出现，则用 targets[i] 替换 该子字符串。
//例如，如果 s = "abcd" ， indices[i] = 0 , sources[i] = "ab"， targets[i] = "eee" ，那么替换的结果将是 "eeecd" 。
//所有替换操作必须 同时 发生，这意味着替换操作不应该影响彼此的索引。测试用例保证元素间不会重叠 。
//例如，一个 s = "abc" ，  indices = [0,1] ， sources = ["ab"，"bc"] 的测试用例将不会生成，因为 "ab" 和 "bc" 替换重叠。
//在对 s 执行所有替换操作后返回 结果字符串 。
//子字符串 是字符串中连续的字符序列。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        vector<pair<int, int>> sortedIndices; // 存储 (原始索引, 替换索引) 的向量
        
        // 创建 (原始索引, 替换索引) 的对，并按原始索引降序排序
        for (int i = 0; i < indices.size(); ++i) {
            sortedIndices.push_back({indices[i], i});
        }
        sort(sortedIndices.rbegin(), sortedIndices.rend());
        
        // 执行替换操作
        for (auto& pair : sortedIndices) {
            int origIndex = pair.first; // 原始索引
            int sourceIndex = pair.second; // 替换索引
            string source = sources[sourceIndex]; // 源子字符串
            string target = targets[sourceIndex]; // 目标子字符串
            
            // 检查原始字符串中 origIndex 处的子字符串是否与 source 匹配
            if (s.substr(origIndex, source.size()) == source) {
                // 将匹配的子字符串替换为目标子字符串
                s.replace(origIndex, source.size(), target);
            }
        }
        
        return s;
    }
};

int main() {
    Solution solution;

    string s = "abcd";
    vector<int> indices = {0};
    vector<string> sources = {"ab"};
    vector<string> targets = {"eee"};

    string result = solution.findReplaceString(s, indices, sources, targets);
    cout << "Result: " << result << endl;

    return 0;
}
