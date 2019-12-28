#include<bits/stdc++.h>

using namespace std;

int prec(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '-' || c == '+')
        return 1;
    else
        return -1;
}

string infixToPostfix(string str){
    int l = str.length();
    stack<char> stk;
    stk.push('N');
    string ans;
    for(int i=0;i<l;i++){
        if((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z')){
            ans += str[i];
        }
        else if(str[i] == '('){
            stk.push('(');
        }
        else if(str[i] == ')'){
            while(stk.top() != 'N' && stk.top() != '('){
                char c = stk.top();
                ans += c;
                stk.pop();
            }
            if(stk.top() == '('){
                stk.pop();
            }
        }
        else{
            while(stk.top() != 'N' && prec(str[i]) <= prec(stk.top())){
                char c = stk.top();
                stk.pop();
                ans += c;
            }
            stk.push(str[i]);
        }
    }
    while(stk.top() != 'N'){
        ans += stk.top();
        stk.pop();
    }
    return ans;
}

string postfixToInfix(string str){
    stack<string> stk;
    int l = str.length();
    for(int i=0;i<l;i++){
        if((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z')){
             stk.push(string(1, str[i]));
        }
        else{
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push("(" + op1 + string(1, str[i]) + op2 + ")");
        }
    }
    return stk.top();
}

string infixToPrefix(string str){
    int l = str.length();
    reverse(str.begin(), str.end());
    for(int i=0;i<l;i++){
        if(str[i] == '(')
            str[i] = ')';
        else if(str[i] == ')')
            str[i] = '(';
    }
    str = infixToPostfix(str);
    reverse(str.begin(), str.end());
    return str;
}

string prefixToPostfix(string str){
    stack<string> stk;
    int l = str.length();
    for(int i=l-1;i>=0;i--){
        if((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z')){
            stk.push(string(1, str[i]));
        }
        else{
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            string temp = op1 + op2 + string(1, str[i]);
            stk.push(temp);
        }
    }
    return stk.top();
}

string postfixToPrefix(string str){
    stack<string> stk;
    int l = str.length();
    for(int i=0;i<l;i++){
        if((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z')){
            stk.push(string(1, str[i]));
        }
        else{
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            string temp = string(1, str[i]) + op2 + op1;
            stk.push(temp);
        }
    }
    return stk.top();
}

int main(){
    string str;
    cin>>str;
    str = infixToPrefix(str);
    cout<<str<<endl;
    str = prefixToPostfix(str);
    cout<<str<<endl;
    str = postfixToPrefix(str);
    cout<<str<<endl;
}
