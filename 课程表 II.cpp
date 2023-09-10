//210. 课程表 II
//现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。
//例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
//返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。

//示例 1：
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：[0,1]
//解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 初始化入度和邻接表
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> adjacency(numCourses);

        // 构建入度和邻接表
        for (const vector<int>& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            in_degree[course]++;
            adjacency[prerequisite].push_back(course);
        }

        // 创建一个队列来存储入度为0的课程
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        // 初始化结果列表
        vector<int> result;

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            for (int next_course : adjacency[course]) {
                in_degree[next_course]--;
                if (in_degree[next_course] == 0) {
                    q.push(next_course);
                }
            }
        }

        // 检查是否所有课程都在结果中
        if (result.size() == numCourses) {
            return result;
        }
        else {
            return {};
        }
    }
};

int main() {
    Solution solution;

    int numCourses = 4;
    vector<vector<int>> prerequisites = { {1, 0}, {2, 0}, {3, 1}, {3, 2} };

    vector<int> result = solution.findOrder(numCourses, prerequisites);

    if (!result.empty()) {
        cout << "合理的课程学习顺序为: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }
    else {
        cout << "无法完成所有课程。" << endl;
    }

    return 0;
}
