//Leetcode 110
#include <iostream>
#include <cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int level(TreeNode* root){
        if(root == NULL) return 0;
        int leftLevel = level(root->left);
        int rightLevel = level(root->right);
        return max(leftLevel, rightLevel) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int leftHeight = level(root->left);
        int rightHeight = level(root->right);
        if(abs(leftHeight - rightHeight) > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = new TreeNode(5);

    Solution solution;
    bool result = solution.isBalanced(root);
    if(result) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    delete root->left->left->left->left;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
