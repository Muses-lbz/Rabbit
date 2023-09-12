//1462. 课程表 IV
//你总共需要上 numCourses 门课，课程编号依次为 0 到 numCourses-1 。你会得到一个数组 prerequisite ，其中 prerequisites[i] = [ai, bi] 表示如果你想选 bi 课程，你 必须 先选 ai 课程。
//有的课会有直接的先修课程，比如如果想上课程 1 ，你必须先上课程 0 ，那么会以 [0,1] 数对的形式给出先修课程数对。
//先决条件也可以是 间接 的。如果课程 a 是课程 b 的先决条件，课程 b 是课程 c 的先决条件，那么课程 a 就是课程 c 的先决条件。
//你也得到一个数组 queries ，其中 queries[j] = [uj, vj]。对于第 j 个查询，您应该回答课程 uj 是否是课程 vj 的先决条件。
//返回一个布尔数组 answer ，其中 answer[j] 是第 j 个查询的答案。

//示例 1：
//输入：numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
//输出：[false,true]
//解释：课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。

//示例 2：
//输入：numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
//输出：[false,false]
//解释：没有先修课程对，所以每门课程之间是独立的。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // 构建有向图，表示课程的先决条件
        unordered_map<int, unordered_set<int>> graph;
        for (const vector<int>& prereq : prerequisites) {
            graph[prereq[0]].insert(prereq[1]);
        }

        // 使用动态规划来计算所有课程的直接和间接先决条件
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; ++i) {
            dfs(graph, isPrerequisite, i, i);
        }

        // 对每个查询进行答案计算
        vector<bool> result;
        for (const vector<int>& query : queries) {
            result.push_back(isPrerequisite[query[0]][query[1]]);
        }

        return result;
    }

private:
    void dfs(unordered_map<int, unordered_set<int>>& graph, vector<vector<bool>>& isPrerequisite, int source, int current) {
        // 如果已经计算过当前课程是先决条件，直接返回
        if (isPrerequisite[source][current]) {
            return;
        }

        // 标记当前课程为先决条件
        isPrerequisite[source][current] = true;

        // 递归查找当前课程的所有直接和间接先决条件
        for (int neighbor : graph[current]) {
            dfs(graph, isPrerequisite, source, neighbor);
        }
    }
};

int main() {
    Solution solution;
    int numCourses = 4;
    vector<vector<int>> prerequisites = { {1, 0}, {2, 1}, {3, 2} };
    vector<vector<int>> queries = { {0, 1}, {1, 3}, {3, 0}, {0, 2} };

    vector<bool> result = solution.checkIfPrerequisite(numCourses, prerequisites, queries);

    // 打印查询结果
    for (bool res : result) {
        if (res) {
            cout << "是先决条件" << endl;
        }
        else {
            cout << "不是先决条件" << endl;
        }
    }

    return 0;
}
