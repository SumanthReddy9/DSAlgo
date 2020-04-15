#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
    int h;
};

int height(node *root){
    if(root == NULL){
        return 0;
    }
    return root->h;
}

int balence(node* root){
    if(root == NULL){
        return 0;
    }
    return (height(root->left) - height(root->right));
}

node *leftRotate(node *root){
    node *t1 = root->right;
    node *t2 = t1->left;

    t1->left = root;
    root->right = t2;

    root->h = max(height(root->left), height(root->right)) + 1;
    t1->h = max(height(t1->left), height(t1->right)) + 1;

    return t1;
}

node *rightRotate(node *root){
    node *t1 = root->left;
    node *t2 = t1->right;

    t1->right = root;
    root->left = t2;

    root->h = max(height(root->left), height(root->right)) + 1;
    t1->h = max(height(root->left), height(root->right)) + 1;

    return t1;
}

node *insertAVL(node *root, int t){
    if(root == NULL){
        node *temp = (node*)malloc(sizeof(node));
        temp->data = t;
        temp->left = NULL;
        temp->right = NULL;
        temp->h = 1;
        root = temp;
        return root;
    }
    if(t > root->data){
        root->right = insertAVL(root->right, t);
    }
    else if(t < root->data){
        root->left = insertAVL(root->left, t);
    }
    else{
        return root;
    }
    root->h = 1 + max(height(root->left), height(root->right));
    int bal = balence(root);
    if(bal > 1 && t < root->left->data){
        return rightRotate(root);
    }
    if(bal < -1 && t > root->right->data){
        return leftRotate(root);
    }
    if(bal > 1 && t > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bal < -1 && t < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

node* preOrder(node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
    else{
        return NULL;
    }
}

int main(){
    int n;
    cin>>n;
    struct node* root = NULL;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        root = insertAVL(root, t);
    }
    preOrder(root);
}
