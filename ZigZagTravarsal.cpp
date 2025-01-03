#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    int levels(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void nthLevel(TreeNode* root, int curr, int level, vector<int>& v, bool leftToRight) {
        if (root == NULL) {
            return;
        }
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        if (!leftToRight) {
            nthLevel(root->right, curr + 1, level, v, leftToRight);
            nthLevel(root->left, curr + 1, level, v, leftToRight);
        } else {
            nthLevel(root->left, curr + 1, level, v, leftToRight);
            nthLevel(root->right, curr + 1, level, v, leftToRight);
        }
    }

    void orderTraversal(TreeNode* root, vector<vector<int>>& ans) {
        int n = levels(root);
        bool leftToRight = true;
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            nthLevel(root, 1, i, v, leftToRight);
            ans.push_back(v);
            leftToRight = !leftToRight;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        orderTraversal(root, ans);
        return ans;
    }
};

// Function to print the zigzag level order traversal
void printZigzagOrder(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Solution instance
    Solution solution;

    // Perform zigzag level order traversal
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    // Print the result
    cout << "Zigzag Level Order Traversal:" << endl;
    printZigzagOrder(result);

    // Clean up allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
