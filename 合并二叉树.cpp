//617. 合并二叉树
//给你两棵二叉树： root1 和 root2 。
//想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
//你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。
//返回合并后的二叉树。
//注意: 合并过程必须从两个树的根节点开始。

//示例 1：
//输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
//输出：[3,4,5,5,4,null,7]

#include <iostream>

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 如果 root1 为空，返回 root2，表示将 root2 合并到 root1 上
        if (root1 == nullptr) {
            return root2;
        }
        // 如果 root2 为空，返回 root1，表示将 root1 合并到 root2 上
        if (root2 == nullptr) {
            return root1;
        }

        // 创建新节点，值为两个节点值相加
        TreeNode* mergedNode = new TreeNode(root1->val + root2->val);
        
        // 递归地合并左子树和右子树
        mergedNode->left = mergeTrees(root1->left, root2->left);
        mergedNode->right = mergeTrees(root1->right, root2->right);

        return mergedNode;
    }
};

// 辅助函数用于打印树的内容
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution solution;

    // 示例树
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    // 合并树
    TreeNode* mergedTree = solution.mergeTrees(root1, root2);

    std::cout << "合并后的树内容: ";
    printTree(mergedTree);

    return 0;
}
