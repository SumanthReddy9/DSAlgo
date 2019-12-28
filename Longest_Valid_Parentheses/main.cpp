#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int l = str.length();
    stack<int>stk;
    stk.push(-1);
    int ans = 0;
    for(int i=0;i<l;i++){
        if(str[i] == '('){
            stk.push(i);
        }
        else{
            stk.pop();
            if(!stk.empty()){
                ans = max(ans, i-stk.top());
            }
            else{
                stk.push(i);
            }
        }
    }
    cout<<ans;
}
