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

bool check(Node* root, int val){
    if(root == NULL){
        return false;
    }
    if(root->val == val){
        return true;
    };
    return check(root->left, val) || check(root->right, val);
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
    int val = 4;
    cout<<endl;
    cout<<check(a, val);
    return 0;
}