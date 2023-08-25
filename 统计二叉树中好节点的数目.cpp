//1448. 统计二叉树中好节点的数目
//给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。
//「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。

//示例 1：
//输入：root = [3,1,4,3,null,1,5]
//输出：4
//解释：图中蓝色节点为好节点。
//根节点 (3) 永远是个好节点。
//节点 4 -> (3,4) 是路径中的最大值。
//节点 5 -> (3,4,5) 是路径中的最大值。
//节点 3 -> (3,1,3) 是路径中的最大值。

#include <iostream>
#include <queue>

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val); // 调用递归函数，初始最大值为根节点的值
    }

    // 递归函数，参数为当前节点和当前路径上的最大值
    int dfs(TreeNode* node, int max_val) {
        if (!node) {
            return 0; // 节点为空，返回 0
        }

        int good_count = 0; // 记录好节点的数量
        if (node->val >= max_val) {
            good_count++; // 当前节点是好节点
            max_val = node->val; // 更新最大值
        }

        // 递归处理左右子节点，将好节点数量累加
        good_count += dfs(node->left, max_val);
        good_count += dfs(node->right, max_val);

        return good_count; // 返回好节点的总数量
    }
};

int main() {
    // 构造一个二叉树作为示例
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution solution;
    int result = solution.goodNodes(root);
    std::cout << "好节点的数量：" << result << std::endl;

    // 释放内存，防止内存泄漏
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
