//979. 在二叉树中分配硬币
//给你一个有 n 个结点的二叉树的根结点 root ，其中树中每个结点 node 都对应有 node.val 枚硬币。整棵树上一共有 n 枚硬币。
//在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。移动可以是从父结点到子结点，或者从子结点移动到父结点。
//返回使每个结点上 只有 一枚硬币所需的 最少 移动次数。

#include <iostream>
#include <cstdlib>

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 解决方案类
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        helper(root, moves);
        return moves;
    }

private:
    // 辅助函数，计算节点需要移动的硬币数量
    int helper(TreeNode* node, int& moves) {
        if (!node) {
            return 0;
        }

        // 递归处理左子树和右子树
        int left_moves = helper(node->left, moves);
        int right_moves = helper(node->right, moves);

        // 计算当前节点需要移动的硬币数量
        moves += abs(left_moves) + abs(right_moves);
        int diff = node->val + left_moves + right_moves - 1;

        return diff;
    }
};

// 用于构建二叉树的辅助函数
TreeNode* buildTree(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) {
    TreeNode* root = new TreeNode(val);
    root->left = left;
    root->right = right;
    return root;
}

int main() {
    // 构建测试用例
    TreeNode* root = buildTree(3,
        buildTree(0),
        buildTree(0)
    );

    Solution solution;
    int moves = solution.distributeCoins(root);
    std::cout << "Minimum moves: " << moves << std::endl;

    // 释放内存，防止内存泄漏
    // 这一步在实际问题中可能不需要，取决于具体情况
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
