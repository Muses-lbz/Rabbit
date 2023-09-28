// 2251. 花期内花的数目
//给你一个下标从 0 开始的二维整数数组 flowers ，其中 flowers[i] = [starti, endi] 表示第 i 朵花的 花期 从 starti 到 endi （都 包含）。
//同时给你一个下标从 0 开始大小为 n 的整数数组 people ，people[i] 是第 i 个人来看花的时间。
//请你返回一个大小为 n 的整数数组 answer ，其中 answer[i]是第 i 个人到达时在花期内花的 数目 。

//示例 1：
//输入：flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
//输出：[1,2,2,2]
//解释：上图展示了每朵花的花期时间，和每个人的到达时间。
//对每个人，我们返回他们到达时在花期内花的数目。

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> cnt;
        // 遍历花期，记录每个花期的开始和结束，以及花数目的增加和减少
        for (auto &flower : flowers) {
            cnt[flower[0]]++;
            cnt[flower[1] + 1]--;
        }
        int m = persons.size();
        vector<int> indices(m);
        iota(indices.begin(), indices.end(), 0);
        // 按照人的到达时间排序，并创建一个索引数组
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return persons[a] < persons[b];
        });

        vector<int> ans(m);
        int curr = 0;
        auto it = cnt.begin();
        for (int x : indices) {
            // 更新当前在花期内的花的数量
            while (it != cnt.end() && it->first <= persons[x]) {
                curr += it->second;
                it++;
            }
            ans[x] = curr;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> people = {2, 3, 7, 11};
    vector<int> result = solution.fullBloomFlowers(flowers, people);
    
    cout << "每个人在花期内花的数目：" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
