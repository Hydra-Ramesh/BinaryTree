//Leetcode 543
#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDia = 0;

    int level(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftLevel = level(root->left);
        int rightLevel = level(root->right);
        return max(leftLevel, rightLevel) + 1;
    }

    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int dia = level(root->left) + level(root->right);
        maxDia = max(dia, maxDia);
        helper(root->left);
        helper(root->right);
        return maxDia;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return helper(root);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the Binary Tree: " << diameter << endl;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
