//207. 课程表
//你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
//在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
//例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
//请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

//示例 1：
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：true
//解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建图和入度数组
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0)); // 二维数组表示课程之间的依赖关系
        vector<int> indegree(numCourses, 0); // 一维数组表示每门课程的入度

        // 遍历 prerequisites 数组，填充图和入度数组
        for (const vector<int>& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            graph[prerequisite][course] = 1; // 有依赖关系的课程在图中标记为1
            indegree[course]++; // 被依赖课程的入度加1
        }

        queue<int> q; // 创建队列用于拓扑排序

        // 将入度为0的课程加入队列
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // 记录已学习的课程数量

        // 开始拓扑排序
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            // 遍历所有课程，更新入度
            for (int i = 0; i < numCourses; i++) {
                if (graph[course][i] == 1) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }

        // 如果已学习的课程数量等于总课程数，返回 true；否则，返回 false。
        return count == numCourses;
    }
};

int main() {
    Solution solution;
    int numCourses = 2;
    vector<vector<int>> prerequisites = { {1, 0} };
    bool result = solution.canFinish(numCourses, prerequisites);
    if (result) {
        cout << "可以完成所有课程的学习。" << endl;
    }
    else {
        cout << "无法完成所有课程的学习。" << endl;
    }
    return 0;
}
