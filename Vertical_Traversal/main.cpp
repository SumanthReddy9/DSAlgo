#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *left, *right;
    int data;
};

struct Node* newNode(int key){
    struct Node* node  = new Node;
    node->left = NULL;
    node->right = NULL;
    node->data = key;
    return node;
}

void getVerticalOrder(struct Node* root, int hd, map<int, vector<int> > &m){
    if(root == NULL)
        return;
    m[hd].push_back(root->data);
    getVerticalOrder(root->left, hd-1, m);
    getVerticalOrder(root->right, hd+1, m);
}

void printVerticalOrder(struct Node* root){
    map<int, vector<int> > m;
    getVerticalOrder(root, 0, m);
    map<int, vector<int> >::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        for(int i=0;i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}

void printVerticalOrder2(struct Node* root){
    if(!root)
        return;
    map<int, vector<int> > m;
    queue<pair<Node*, int> > q;
    int hd= 0;
    q.push(make_pair(root, hd));
    while(!q.empty()){
        pair<Node*, int> cur = q.front();
        hd = cur.second;
        Node* node = cur.first;
        m[hd].push_back(node->data);
        q.pop();
        if(node->left){
            q.push(make_pair(node->left, hd-1));
        }
        if(node->right){
            q.push(make_pair(node->right, hd+1));
        }
    }
    map<int, vector<int> >::iterator it;
    for(it = m.begin(); it!= m.end(); it++){
        for(int i=0;i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left= newNode(10);
    root->right->right->left->right= newNode(11);
    root->right->right->left->right->right= newNode(12);
    cout << "Vertical order traversal is n"<<endl;
    printVerticalOrder(root);
    printVerticalOrder2(root);
}
