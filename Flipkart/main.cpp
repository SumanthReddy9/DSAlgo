#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string action, stringData;
    int length, startIdx, endIdx;
};

string str = "Hi Hello";
stack<Node*> undo;
stack<Node*> redo;
int lengthStr = str.length();
int flag = 0;

void print(){
    cout<<endl<<str<<endl;
}

void undoPushing(string action, string strTemp, int startidx, int endidx, int len){
    Node *temp = new Node();
    temp->action = action;
    temp->startIdx = startidx;
    temp->endIdx = endidx;
    temp->stringData = strTemp;
    temp->length = len;
    undo.push(temp);
}

void addString(string addstr, int start){
    if(start > lengthStr){
        cout<<"Out of bounds"<<endl;
    }
    else{
        undoPushing("add", addstr, start, start + addstr.length(), addstr.length());
        str.insert(start, addstr);
        lengthStr = str.length();
        print();
    }
}

void deleteString(int a, int b){
    if(a < 0 || b <= 0 || a >= str.length()){
        cout<<"Not Possible"<<endl;
    }
    else{
        string tempStr = str.substr(a, b);
        undoPushing("deleteString", tempStr, a, a + b, b);
        str.erase(a, b);
        lengthStr = str.length();
        print();
    }
}

void undoDel(Node *temp){
    redo.push(temp);
    str.insert(temp->startIdx, temp->stringData);
    lengthStr = str.length();
    print();
}

void undoAdd(Node *temp){
    redo.push(temp);
    str.erase(temp->startIdx, temp->length);
    lengthStr = str.length();
    print();
}

void redoDel(Node *temp){
    undo.push(temp);
    str.erase(temp->startIdx, temp->length);
    lengthStr = str.length();
    print();
}

void redoAdd(Node *temp){
    undo.push(temp);
    str.insert(temp->startIdx, temp->stringData);
    lengthStr = str.length();
    print();
}

void undoOperation(){
    if(undo.empty()){
        cout<<"No UNDO possible"<<endl;
    }
    else{
        Node *temp = undo.top();
        undo.pop();
        if(temp->action == "deleteString"){
            undoDel(temp);
        }
        else if(temp->action == "add"){
            undoAdd(temp);
        }
    }
}

void redoOperation(){
    if(redo.empty()){
        cout<<"No Redo operations possible"<<endl;
    }
    else{
        Node *temp = redo.top();
        redo.pop();
        if(temp->action == "deleteString"){
            redoDel(temp);
        }
        else if(temp->action == "add"){
            redoAdd(temp);
        }
    }
}

int main(){
    while(1){
        cout<<"1) Add String\n2) Delete String\n3) Undo\n4) Redo";
        int t;
        cin>>t;
        if(t == 1)
        {
            string addstr;
            int start;
            cin>>addstr>>start;
            addString(addstr, start);
        }
        else if(t == 2)
        {
            int startIdx, len;
            cin>>startIdx>>len;
            deleteString(startIdx, len);
        }
        else if(t == 3)
        {
            undoOperation();
        }
        else if(t == 4)
        {
            redoOperation();
        }
        else{
            break;
        }
    }
}
