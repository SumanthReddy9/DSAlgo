// Maximum sum of nodes in Binary tree such that no two are adjacent

#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> maxSumHelper(Node *root){
    if(root == NULL){
        pair<int, int> res(0, 0);
        return res;
    }
    pair<int, int> res1 = maxSumHelper(root->left);
    pair<int, int> res2 = maxSumHelper(root->right);
    pair<int, int> res;
    res.first = res1.second + res2.second + root->data;
    res.second = max(res1.first, res1.second) + max(res2.first, res2.second);
    return res;
}

int maxSum(Node *root){
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}

int main(){
    Node *root= new Node(10);
    root->left= new Node(1);
    root->left->left= new Node(2);
    root->left->left->left= new Node(1);
    root->left->right= new Node(3);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(5);
    cout << maxSum(root);
    return 0;
}
