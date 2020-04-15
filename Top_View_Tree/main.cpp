#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int hd, data;
};

Node* newNode(int key){
    Node* node = new Node();
    node->left = NULL;
    node->right = NULL;
    node->data = key;
    return node;
}

void topview(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    map<int, int> m;
    int hd= 0;
    root->hd = 0;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        hd = temp->hd;
        q.pop();
        if(m.count(hd) == 0){
            m[hd] = temp->data;
        }
        if(temp->left){
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }
        if(temp->right){
            temp->right->hd = hd + 1;
            q.push(temp->right);
        }
    }
    map<int, int>::iterator it;
    for(it=m.begin(); it != m.end(); it++){
        cout<<it->second<<" ";
    }
}

void fillMap(struct Node* root, int d, int l, map<int , pair<int, int> > &m){
    if(root == NULL){
        return;
    }
    if(m.count(d) == 0){
        m[d] = make_pair(root->data, l);
    }
    else if(m[d].second > l){
        m[d] = make_pair(root->data, l);
    }
    fillMap(root->left, d-1, l+1, m);
    fillMap(root->right, d+1, l+1, m);
}

void topview2(struct Node* root){
    map<int, pair<int, int> > m;
    fillMap(root, 0, 0, m);
    map<int, pair<int, int> >::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout<<it->second.first<<" ";
    }
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout<<"Following are nodes in top view of Binary Tree\n";
    topview(root);
    return 0;
}
