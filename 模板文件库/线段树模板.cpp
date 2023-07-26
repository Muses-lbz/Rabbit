/*这个模板中的线段树采用数组实现，并且在构建和查询过程中使用递归的方式。
模板中的注释详细解释了每个函数的作用和递归过程，帮助你理解线段树的构建和查询过程。
你可以根据需要进行修改和扩展，以适应不同类型的区间查询问题。*/

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree; // 用于存储线段树的数组
    int n; // 原始数组的元素个数

    // 构建线段树的函数
    // node：当前节点在树中的索引
    // left，right：当前节点所代表的区间范围
    void buildTree(const vector<int>& nums, int node, int left, int right) {
        // 基本情况：如果当前节点表示数组中的一个单独元素
        if (left == right) {
            tree[node] = nums[left];
            return;
        }

        // 找到中间索引，将区间分为两半
        int mid = left + (right - left) / 2;

        // 递归构建左子树
        buildTree(nums, 2 * node + 1, left, mid);

        // 递归构建右子树
        buildTree(nums, 2 * node + 2, mid + 1, right);

        // 更新当前节点的值为左右子树值的和
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // 在线段树上执行区间和查询的函数
    // node：当前节点在树中的索引
    // left，right：当前节点所代表的区间范围
    // queryLeft，queryRight：查询的区间范围
    int queryRange(int node, int left, int right, int queryLeft, int queryRight) {
        // 如果当前节点的区间完全在查询区间之外
        if (left > queryRight || right < queryLeft) {
            return 0; // 返回0，因为该节点的和不会影响查询结果
        }

        // 如果当前节点的区间完全在查询区间之内
        if (left >= queryLeft && right <= queryRight) {
            return tree[node]; // 返回当前节点的和，因为它完全影响查询结果
        }

        // 如果当前节点的区间部分重叠于查询区间
        int mid = left + (right - left) / 2;

        // 递归查询左子树
        int leftSum = queryRange(2 * node + 1, left, mid, queryLeft, queryRight);

        // 递归查询右子树
        int rightSum = queryRange(2 * node + 2, mid + 1, right, queryLeft, queryRight);

        // 返回左右子树查询结果的和
        return leftSum + rightSum;
    }

public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        buildTree(nums, 0, 0, n - 1);
    }

    int query(int left, int right) {
        return queryRange(0, 0, n - 1, left, right);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(nums);

    cout << segTree.query(1, 3) << endl; // 输出：15（查询索引1到3的元素和）

    return 0;
}
