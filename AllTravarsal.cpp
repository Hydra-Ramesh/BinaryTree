//Leetcode Question
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Preorder Traversal
class PreorderSolution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

// Postorder Traversal
class PostorderSolution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

// Inorder Traversal
class InorderSolution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

// Helper function to create a binary tree
TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

// Main function to test the traversal solutions
int main() {
    // Create a sample binary tree
    TreeNode* root = createBinaryTree();

    // Preorder Traversal
    PreorderSolution preorderSol;
    vector<int> preorderResult = preorderSol.preorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (int val : preorderResult) cout << val << " ";
    cout << endl;

    // Postorder Traversal
    PostorderSolution postorderSol;
    vector<int> postorderResult = postorderSol.postorderTraversal(root);
    cout << "Postorder Traversal: ";
    for (int val : postorderResult) cout << val << " ";
    cout << endl;

    // Inorder Traversal
    InorderSolution inorderSol;
    vector<int> inorderResult = inorderSol.inorderTraversal(root);
    cout << "Inorder Traversal: ";
    for (int val : inorderResult) cout << val << " ";
    cout << endl;

    return 0;
}
