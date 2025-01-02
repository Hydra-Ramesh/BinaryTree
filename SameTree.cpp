// Leetcode 100
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;

        if (p->val != q->val) return false;

        bool leftAns = isSameTree(p->left, q->left);
        if (!leftAns) return false;

        bool rightAns = isSameTree(p->right, q->right);
        if (!rightAns) return false;

        return true;
    }
};

TreeNode* createTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

TreeNode* createTree2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    Solution solution;

    TreeNode* tree1 = createTree1();
    TreeNode* tree2 = createTree2();

    bool result = solution.isSameTree(tree1, tree2);

    cout << "Are the trees the same? " << (result ? "Yes" : "No") << endl;

    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}
