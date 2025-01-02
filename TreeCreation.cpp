#include<iostream>
#include<climits>
using namespace std;
class Node{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }

};
void display(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    return root->val + sum(root->left) + sum(root->right);
}
int Product(Node* root){
    if(root == NULL){
        return 1;
    }
    return root->val * Product(root->left) * Product(root->right);
}
int TreeSize(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + TreeSize(root->left) + TreeSize(root->right);
}
int NodeMaximum(Node* root){
    if(root == NULL){
        return INT_MIN;
    }
    int leftMax = NodeMaximum(root->left);
    int rightMax = NodeMaximum(root->right);
    return max(root->val,max(leftMax,rightMax));
}
int NodeMinimum(Node* root){
    if(root == NULL){
        return INT_MAX;
    }
    int leftMin = NodeMinimum(root->left);
    int rightMin = NodeMinimum(root->right);
    return min(root->val,min(leftMin,rightMin));
}
int NodeLevel(Node *root){
    if(root ==NULL){
        return 0;
    }
    int leftLevel = NodeLevel(root->left);
    int rightLevel = NodeLevel(root->right);
    return max(leftLevel,rightLevel) + 1;
}
int TreeHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(TreeHeight(root->left),TreeHeight(root->right)) + 1;
}
int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    display(a);
    cout<<"\nSize: "<<TreeSize(a);
    cout<<"\nLevel: "<<NodeLevel(a);
    cout<<"\nHeight: "<<TreeHeight(a);   
    cout<<"\nSum: "<<sum(a);
    cout<<"\nProduct: "<<Product(a);
    cout<<"\nMin: "<<NodeMinimum(a);
    cout<<"\nMax: "<<NodeMaximum(a);
    return 0;
}