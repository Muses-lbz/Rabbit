//1123. 最深叶节点的最近公共祖先
//给你一个有根节点 root 的二叉树，返回它 最深的叶节点的最近公共祖先 。

//回想一下：
//叶节点 是二叉树中没有子节点的节点
//树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
//如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。

//示例 1：
//输入：root = [3,5,1,6,2,0,8,null,null,7,4]
//输出：[2,7,4]
//解释：我们返回值为 2 的节点，在图中用黄色标记。
//在图中用蓝色标记的是树的最深的节点。
//注意，节点 6、0 和 8 也是叶节点，但是它们的深度是 2 ，而节点 7 和 4 的深度是 3 。

#include <iostream>
#include <vector>
#include <utility>

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
    pair<TreeNode*, int> findLCA(TreeNode* root) {
        if (!root)
            return { nullptr, 0 };

        auto left = findLCA(root->left);
        auto right = findLCA(root->right);

        if (left.second > right.second)
            return { left.first, left.second + 1 };
        else if (left.second < right.second)
            return { right.first, right.second + 1 };
        else
            return { root, left.second + 1 };
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto result = findLCA(root);
        return result.first;
    }
};

// Helper function to create a binary tree from an array
TreeNode* createTree(vector<int>& values, int index) {
    if (index >= values.size() || values[index] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}

int main() {
    // Example input: [3,5,1,6,2,0,8,null,null,7,4]
    vector<int> values = { 3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4 };

    // Create the binary tree from the input array
    TreeNode* root = createTree(values, 0);

    Solution solution;
    TreeNode* result = solution.lcaDeepestLeaves(root);

    cout << "The lowest common ancestor of deepest leaves is: " << result->val << endl;

    // Clean up the dynamically allocated memory
    delete root;

    return 0;
}
