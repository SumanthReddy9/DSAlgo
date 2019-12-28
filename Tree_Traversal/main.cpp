#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right, *lbro;
};

void ConstructBinaryTree(struct Node** root, int *data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = *data;
    temp->left = temp->right = NULL;
    if(*root == NULL){
        *root = temp;
    }
    else{
        if((*root)->data > *data){
            ConstructBinaryTree(&((*root)->left), data);
        }
        else{
            ConstructBinaryTree(&((*root)->right), data);
        }
    }
}

void preOrder(struct Node *root){
    if(root){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
    else{
        return;
    }
}

void postOrder(struct Node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
    else{
        return;
    }
}

void inOrder(struct Node *root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
    else{
        return;
    }
}

int height(struct Node* root){
    if(root == NULL){
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if(lheight > rheight){
        return 1+lheight;
    }
    else{
        return 1+rheight;
    }
}

int countNodes(struct Node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void levelOrder(struct Node *root){
    if(root == NULL)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *top = q.front();
        q.pop();
        cout<<top->data<<" ";
        if(top->left != NULL){
            q.push(top->left);
        }
        if(top->right != NULL){
            q.push(top->right);
        }
    }
}

void printZigZagU(struct Node* root, int l, int f){
    if(root == NULL)
        return;
    if(l == 1){
        cout<<root->data<<" ";
    }
    else if(l>1 && f == 0){
        printZigZagU(root->left, l-1, f);
        printZigZagU(root->right, l-1, f);
    }
    else if(l>1 && f == 1){
        printZigZagU(root->right, l-1, f);
        printZigZagU(root->left, l-1, f);
    }
}



void printZigZag(struct Node *root, int h){
    int f = 0;
    for(int i=0;i<h;i++){
        printZigZagU(root, i+1, f);
        f = !f;
        cout<<endl;
    }
}

void printZigZagOn(struct Node* root){
    if(root == NULL)
        return;
    stack<Node*>q1;
    stack<Node*>q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            Node *top = q1.top();
            cout<<top->data<<" ";
            q1.pop();
            if(top->left != NULL)
                q2.push(top->left);
            if(top->right != NULL)
                q2.push(top->right);
        }
        while(!q2.empty()){
            Node *top = q2.top();
            q2.pop();
            cout<<top->data<<" ";
            if(top->right != NULL)
                q1.push(top->right);
            if(top->left != NULL)
                q1.push(top->left);
        }
    }
}

void makeBro(Node* root){
    if(root == NULL)
        return;
    queue<Node*>q;
    q.push(root);
    Node *prev = NULL;
    while(!q.empty()){
        int s = q.size();
        for(int i=0;i<s;i++){
            Node *top = q.front();
            q.pop();
            if(i == 0){
                top->lbro = NULL;
                prev = top;
            }
            else{
                top->lbro = prev;
                prev = top;
            }
            if(top->left != NULL){
                q.push(top->left);
            }
            if(top->right != NULL){
                q.push(top->right);
            }
        }
    }
}

void printSib(Node *root){
    if(root == NULL)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *top = q.front();
        q.pop();
        if(top->lbro != NULL)
            cout<<top->lbro->data<<" ";
        if(top->left != NULL){
            q.push(top->left);
        }
        if(top->right != NULL){
            q.push(top->right);
        }
    }
}

int main(){
    int n;
    cin>>n;
    struct Node *root = NULL;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        ConstructBinaryTree(&root, &data);
    }
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    int h = height(root);
    cout<<"Height is :"<<h<<endl;
    int x = countNodes(root);
    cout<<"Total No of Nodes:"<<x<<endl;
    levelOrder(root);
    cout<<endl;
    printZigZag(root, h);
    printZigZagOn(root);
    cout<<endl;
    makeBro(root);
    printSib(root);
}
