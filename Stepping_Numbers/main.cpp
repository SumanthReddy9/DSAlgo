#include<bits/stdc++.h>
using namespace std;

void bfs(int i, int n, int m){
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int curNum = q.front();
        q.pop();
        if(curNum >= n && curNum <= m){
            cout<<curNum<<" ";
        }
        if(curNum == 0 || curNum > m)
            continue;
        int lastdigit = curNum%10;
        int stepA = curNum*10 + (lastdigit+1);
        int stepB = curNum*10 + (lastdigit-1);
        if(lastdigit == 0){
            q.push(stepA);
        }
        else if(lastdigit == 9){
            q.push(stepB);
        }
        else{
            q.push(stepA);
            q.push(stepB);
        }
    }
}

void getNums(int n, int m){
    cout<<"0"<<" ";
    for(int i=1;i<=9;i++){
        bfs(i, n, m);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    getNums(n, m);
}
