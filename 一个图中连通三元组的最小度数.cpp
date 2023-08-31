//1761. 一个图中连通三元组的最小度数
//给你一个无向图，整数 n 表示图中节点的数目，edges 数组表示图中的边，其中 edges[i] = [ui, vi] ，表示 ui 和 vi 之间有一条无向边。
//一个 连通三元组 指的是 三个 节点组成的集合且这三个点之间 两两 有边。
//连通三元组的度数 是所有满足此条件的边的数目：一个顶点在这个三元组内，而另一个顶点不在这个三元组内。
//请你返回所有连通三元组中度数的 最小值 ，如果图中没有连通三元组，那么返回 -1 。

//示例 1：
//输入：n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
//输出：3
//解释：只有一个三元组 [1,2,3] 。构成度数的边在上图中已被加粗。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> isConnected(n + 1, vector<bool>(n + 1, false));
        vector<int> degrees(n + 1, 0);

        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            isConnected[u][v] = isConnected[v][u] = true;
            degrees[u]++;
            degrees[v]++;
        }

        int minDegree = INT_MAX;

        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                if (isConnected[u][v]) {  // Only consider connected nodes
                    for (int w = v + 1; w <= n; ++w) {
                        if (isConnected[v][w] && isConnected[u][w]) {  // Form a trio
                            int trioDegree = degrees[u] + degrees[v] + degrees[w] - 6;  // Subtract shared edges
                            minDegree = min(minDegree, trioDegree);
                        }
                    }
                }
            }
        }

        return (minDegree == INT_MAX) ? -1 : minDegree;
    }
};

int main() {
    Solution solution;
    int n = 6;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}};
    int result = solution.minTrioDegree(n, edges);
    cout << "Minimum degree of connective triplets: " << result << endl;
    return 0;
}
