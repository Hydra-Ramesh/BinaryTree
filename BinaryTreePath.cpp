//Leetcode 257
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* root, string path, vector<string>& ans) {
        if (!root) return;
        path += to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(path);
        } else {
            helper(root->left, path + "->", ans);
            helper(root->right, path + "->", ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    return root;
}
int main() {
    Solution solution;
    TreeNode* root = createTree();
    vector<string> paths = solution.binaryTreePaths(root);
    cout << "Root-to-leaf paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
