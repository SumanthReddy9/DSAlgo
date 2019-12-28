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

void removeLoop(struct node* head){
    struct node *slow = head, *fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow == fast){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        cout<<fast->next->data<<endl;
        fast->next = NULL;
    }
}

/*bool IsLooped(struct node* head){
    struct node* temp = (struct node*)malloc(sizeof(node));
    while(head != NULL){
        if(head-> next == NULL)
            return false;
        if(head->next == temp)
            return true;
        struct node* nex = head->next;
        head->next = temp;
        head = nex;
    }
    return false;
}*/

int main(){
    int n;
    cin>>n;
    struct node *LL = NULL;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        insertIntoLL(&LL, t);
    }
    struct node* cur = LL;
    cur->next->next->next->next->next->next = cur->next->next;
    removeLoop(LL);
    while(cur){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    /*if(IsLooped(LL)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    cout<<endl;
    if(IsLooped(LL)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }*/
}
