//834. 树中距离之和
//给定一个无向、连通的树。树中有 n 个标记为 0...n-1 的节点以及 n-1 条边 。
//给定整数 n 和数组 edges ， edges[i] = [ai, bi]表示树中的节点 ai 和 bi 之间有一条边。
//返回长度为 n 的数组 answer ，其中 answer[i] 是树中第 i 个节点与所有其他节点之间的距离之和。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> count(n, 1);  // 记录每个节点的子节点数量
        vector<int> sum(n, 0);    // 记录每个节点到其他节点的距离之和

        // 构建邻接表
        for (const auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // 第一次DFS，计算每个节点的子节点数量和到其他节点的距离之和
        dfs1(0, -1, graph, count, sum);

        // 第二次DFS，计算每个节点到根节点的距离之和
        dfs2(0, -1, graph, count, sum, n);

        return sum;
    }

    void dfs1(int node, int parent, const vector<vector<int>>& graph, vector<int>& count, vector<int>& sum) {
        for (const auto& neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs1(neighbor, node, graph, count, sum);
                count[node] += count[neighbor];                                 // 更新节点的子节点数量
                sum[node] += sum[neighbor] + count[neighbor];                   // 更新节点到其他节点的距离之和
            }
        }
    }

    void dfs2(int node, int parent, const vector<vector<int>>& graph, const vector<int>& count, vector<int>& sum, int n) {
        for (const auto& neighbor : graph[node]) {
            if (neighbor != parent) {
                sum[neighbor] = sum[node] - count[neighbor] + (n - count[neighbor]);   // 更新节点到根节点的距离之和
                dfs2(neighbor, node, graph, count, sum, n);
            }
        }
    }
};

int main() {
    Solution solution;
    int n = 6;
    vector<vector<int>> edges = { {0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5} };
    vector<int> result = solution.sumOfDistancesInTree(n, edges);

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
