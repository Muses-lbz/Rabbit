//1851. 包含每个查询的最小区间
//给你一个二维整数数组 intervals ，其中 intervals[i] = [lefti, righti] 表示第 i 个区间开始于 lefti 、结束于 righti（包含两侧取值，闭区间）。
//区间的 长度 定义为区间中包含的整数数目，更正式地表达是 righti - lefti + 1 。
//再给你一个整数数组 queries 。第 j 个查询的答案是满足 lefti <= queries[j] <= righti 的 长度最小区间 i 的长度 。如果不存在这样的区间，那么答案是 -1 。
//以数组形式返回对应查询的所有答案。

//示例 1：
//输入：intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
//输出：[3,3,1,4]
//解释：查询处理如下：
//- Query = 2 ：区间 [2,4] 是包含 2 的最小区间，答案为 4 - 2 + 1 = 3 。
//- Query = 3 ：区间 [2,4] 是包含 3 的最小区间，答案为 4 - 2 + 1 = 3 。
//- Query = 4 ：区间 [4,4] 是包含 4 的最小区间，答案为 4 - 4 + 1 = 1 。
//- Query = 5 ：区间 [3,6] 是包含 5 的最小区间，答案为 6 - 3 + 1 = 4 。

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> res(n, -1);
        vector<pair<int, int>> pa(n);
        
        // 将查询值和索引组成的pair存储在pa中
        for (int i = 0; i < n; ++i)
            pa[i] = { queries[i], i };
        
        // 按照查询值从小到大排序
        sort(pa.begin(), pa.end());
        
        // 按照区间起始值从小到大排序
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        int p = 0;
        // 使用最小堆来存储区间长度和区间的结束值
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int i = 0; i < n; ++i) {
            // 将与当前查询值起始值相符的区间加入最小堆
            while (p < intervals.size() && pa[i].first >= intervals[p][0]) {
                pq.push({ intervals[p][1] - intervals[p][0] + 1, intervals[p][1] });
                ++p;
            }
            
            // 从堆中删除已经过期的区间
            while (!pq.empty() && pa[i].first > pq.top().second)
                pq.pop();
            
            // 如果堆不为空，取堆顶元素作为结果
            if (!pq.empty())
                res[pa[i].second] = pq.top().first;
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = { {1, 4}, {2, 5}, {7, 9} };
    vector<int> queries = { 2, 3, 10 };
    vector<int> result = solution.minInterval(intervals, queries);

    cout << "Result: ";
    for (int length : result) {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}
