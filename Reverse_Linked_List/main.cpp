#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void insertIntoLL(struct node** LL, int data){
    struct node* temp = (struct node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(*LL == NULL){
        *LL = temp;
    }
    else{
        struct node* cur = *LL;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = temp;
    }
}

node* reverseLL(struct node* LL){
    struct node *prevNode = NULL, *nextNode = NULL;
    struct node *cur = LL;
    while(cur != NULL){
        nextNode = cur->next;
        cur->next = prevNode;
        prevNode = cur;
        cur = nextNode;
    }
    LL = prevNode;
    return LL;
}

node *reverseLLRecursion(struct node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* rest = reverseLLRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main(){
    int n;
    cin>>n;
    struct node *LL = NULL;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        insertIntoLL(&LL, t);
    }
    LL = reverseLL(LL);
    LL = reverseLLRecursion(LL);
    struct node* cur = LL;
    while(cur){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
}
