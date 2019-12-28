#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

void insertinBST(Node **root, int *t){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = *t;
    temp->left = temp->right = NULL;
    if(*root == NULL){
        *root = temp;
    }
    else{
        if((*root)->data > *t){
            insertinBST(&((*root)->left), t);
        }
        else{
            insertinBST(&((*root)->right), t);
        }
    }
}

void preorder(Node *root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    else
        return;
}

void storeBSTNodes(Node *root, vector<Node*> &nodes){
    if(root != NULL){
        storeBSTNodes(root->left, nodes);
        nodes.push_back(root);
        storeBSTNodes(root->right, nodes);
    }
    else{
        return;
    }
}

Node *buildTreeAgain(vector<Node*>&nodes, int l, int r){
    if(l > r)
        return NULL;
    int mid = (l+r)/2;
    Node *root = nodes[mid];
    root->left = buildTreeAgain(nodes, l, mid-1);
    root->right = buildTreeAgain(nodes, mid+1, r);
    return root;
}

Node *buildBBST(Node *root){
    vector<Node*>nodes;
    storeBSTNodes(root, nodes);
    int n = nodes.size();
    cout<<n<<endl;
    return buildTreeAgain(nodes, 0, n-1);
}

int main(){
    int n;
    cin>>n;
    Node *root = NULL;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        insertinBST(&root, &t);
    }
    preorder(root);
    cout<<endl;
    root = buildBBST(root);
    preorder(root);
}
