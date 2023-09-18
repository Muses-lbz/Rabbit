//337. 打家劫舍 III
//小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
//除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
//如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
//给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

//示例 1:
//输入: root = [3,2,3,null,3,null,1]
//输出: 7 
//解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7

//示例 2:
//输入: root = [3,4,5,1,3,null,1]
//输出: 9
//解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9

#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
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
    unordered_map<TreeNode*, int> memo;

    int rob(TreeNode* root) {
        if (!root) return 0;
        
        // 检查是否已经计算过当前节点
        if (memo.find(root) != memo.end()) {
            return memo[root];
        }
        
        // 偷取当前节点的金额
        int robCurrent = root->val;
        if (root->left) {
            robCurrent += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            robCurrent += rob(root->right->left) + rob(root->right->right);
        }
        
        // 不偷取当前节点的金额
        int skipCurrent = rob(root->left) + rob(root->right);
        
        // 更新memo并返回当前节点的最高金额
        memo[root] = max(robCurrent, skipCurrent);
        return memo[root];
    }
};

int main() {
    // 创建二叉树示例
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution solution;
    int result = solution.rob(root);
    cout << "小偷能够盗取的最高金额是：" << result << endl;

    // 释放动态分配的内存
    delete root->right->right;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
